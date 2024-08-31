cmake_minimum_required (VERSION 3.1)

project (
    GAMETEMPLATE_SDL2C
    VERSION 1.0.0
    LANGUAGES C
)

# Find required packages
include (FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_MIXER REQUIRED SDL2_mixer)
pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image)
pkg_search_module(SDL2_TTF REQUIRED SDL2_ttf)

# Define directorie names
set (RESOURCES res)
set (HEADERS headers)
set (GAMEDATA data)

# Define directory locations
set (RESOURCES_SOURCE_DIR ${PROJECT_SOURCE_DIR}/${RESOURCES})
set (HEADERS_SOURCE_DIR ${PROJECT_SOURCE_DIR}/${HEADERS})
set (GAMEDATA_SOURCE_DIR ${PROJECT_SOURCE_DIR}/${GAMEDATA})

set (BIN_DIR ${CMAKE_BINARY_DIR}/bin) # OUTPUT DIRECTORY

# Include directories
include_directories (
    ${HEADERS_SOURCE_DIR}
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_MIXER_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
)

# Grab source files
file (
    GLOB SOURCES
    src/*.c
    src/*/*.c
    src/*/*/*.c
)

# Create custom targets
add_custom_target(
    bin_directory_setup ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${BIN_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${RESOURCES_SOURCE_DIR} ${BIN_DIR}/${RESOURCES}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${GAMEDATA_SOURCE_DIR} ${BIN_DIR}/${GAMEDATA}
    COMMENT "Setting up bin directory"
)

add_custom_target(
    cleanall
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${BIN_DIR}
    COMMENT "Clean bin directory"
)

# Set output directory
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

# Define executable target
add_executable (${CMAKE_PROJECT_NAME} ${SOURCES})

# Compier options
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:-Wall;-g>
    $<$<CONFIG:Release>:-Wall;-O3;-s>
)

# Link libraries
target_link_libraries (
    ${CMAKE_PROJECT_NAME}
    ${SDL2_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    m
)
