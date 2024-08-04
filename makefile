###################################################
# Written by Jerico G. Despe
###################################################

TARGET = SDL2_CTemplate

# COMPILER CONFIG
# ---------------------
CC      = gcc
CFLAGS  = -Wall -std=c99

# BUILD TYPE
# ---------------------
# RELEASE - builds the program in release mode
#           much more optimized and ready to publish
# DEBUG   - builds the program in debug mode
#           for debugging purposes to fix errors
#           (DEFAULT)
BUILD    ?= DEBUG

# PLATFORNS
# ---------------------
# WINDOWS
# LINUX
# TODO MS-DOS
#
PLATFORM ?= LINUX

# PROGRAM ARCHITECTURE 
# ---------------------
# X86   - 32bit
# X64   - 64bit (Default)
#
ARCHITECTURE ?= X64

# Output Directory
BIN_DIR := bin

# Resources Directory
RES_DIR := res

# Directories
SRC_DIR := src
OBJ_DIR := obj

# 3rd Party Library directory
LIB_DIR := libs

DEBUG_DIR   := debug
RELEASE_DIR := release

# Build Directories
INCLUDE = -I headers

# Find all .c files inside SRC_DIR and its subdirectories
SRC_SUBDIRS = $(wildcard $(SRC_DIR)/*/ $(SRC_DIR)/*/*/)
SRC         = $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c $(SRC_DIR)/*/*/*.c)

# Define corresponding .o files in OBJ_DIR
OBJ_SUBDIRS = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC_SUBDIRS))
OBJ         = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# SDL2 CONFIGURATION
SDL2_CFLAGS = $(shell $(SDL2_CONFIG) --cflags)
SDL2_LIBS   = $(shell $(SDL2_CONFIG) --libs) -lSDL2_image

# Check if ARCHITECTURE is set to 32bit
ifeq ($(ARCHITECTURE), X86)
	PROG_ARCHITECTURE = -m32
endif

# Check what platform is selected for build process
# C COMPILER CONFIGURATION
ifeq ($(PLATFORM), WINDOWS)
	CC            = x86_64-w64-mingw32-gcc
	
	# set SDL2 config
	SDL2_CONFIG   = $(SDL2_LIB_PATH)/bin/sdl2-config
	
	# set SDL2 lib path to 64bit directory
	SDL2_LIB_PATH = $(LIB_DIR)/x86_64/SDL2
	
	# OUTPUT DIRECTORY	
	PLATFORM_DIR := windows
	
	# if ARCHITECTURE is set to 32bit
	ifeq ($(ARCHITECTURE), X86)
		# C COMPILER CONFIGURATION
		CC = i686-w64-mingw32-gcc
	
		# Set SDL2 lib path to 32bit directory
		SDL2_LIB_PATH = $(LIB_DIR)/i686/SDL2
	endif
	
	# Set DLL path to be duplicated to output directory 
	INIT_DLL = @echo "[BUILD LOG] Setting dll files..."; \
	           cp -f $(SDL2_LIB_PATH)/bin/*.dll $(BUILD_DIR)
else # Sets to LINUX by default
	# SDL2 CONFIGURATION
	SDL2_CONFIG  := sdl2-config
	PLATFORM_DIR := linux
	
	# If ARCHITECTURE is set to 32bit
	ifeq ($(ARCHITECTURE), X86)
		# Explicitly set SDL2 Library configuration to 32bit
		SDL2_LIBS = -L/usr/lib32 -lSDL2 -lSDL2_image
	endif 
endif

# Check what build type is selected
ifeq ($(BUILD), RELEASE)
	CFLAGS    += -O3 -s
	BUILD_DIR  = $(BIN_DIR)/$(PLATFORM_DIR)/$(RELEASE_DIR)
	
else # Sets to DEBUG by default
	CFLAGS     += -g
	BUILD_DIR   = $(BIN_DIR)/$(PLATFORM_DIR)/$(DEBUG_DIR)
	
endif

# OUTPUT PROCESS SETUP
CREATE_BIN_DIR = @echo "[BUILD LOG] Creating bin directory... "; \
                 mkdir -p $(BUILD_DIR)

INIT_RESOURCES = @echo "[BUILD LOG] Initializing resources to the build path... "; \
                 rm -rf $(BUILD_DIR)/$(RES_DIR); \
                 cp -r $(RES_DIR) $(BUILD_DIR)

# BUILD THE PROGRAM
$(TARGET): $(OBJ)
	$(CREATE_BIN_DIR)
	$(INIT_DLL)
	$(INIT_RESOURCES)
	$(CC) $(PROG_ARCHITECTURE) $(OBJ) -o $(BUILD_DIR)/$@ $(SDL2_LIBS)

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR) $(OBJ_SUBDIRS)
	$(CC) $(PROG_ARCHITECTURE) -c $< -o $@ $(CFLAGS) $(INCLUDE) $(SDL2_CFLAGS)

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_SUBDIRS):
	@mkdir -p $@

clean:
	@rm $(OBJ_DIR)/*.o

cleanbin:
	@rm -rf $(BIN_DIR)

# Removes both bin and obj
cleanall:
	@rm -rf $(BIN_DIR) $(OBJ_DIR)

.PHONY: clean cleanbin cleanall
