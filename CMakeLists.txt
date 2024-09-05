# Set cmake version required
cmake_minimum_required (VERSION 3.26)

# Set project info
project (
    GAMETEMPLATE_SDL2C
    VERSION 1.0.0
    LANGUAGES C
)

if (PROJECT_BINARY_DIR STREQUAL PROJECT_SOURCE_DIR)
    message(
        FATAL_ERROR 
        "In-source builds not allowed. Please create a new directory (called a \"build\" director) and run CMake from there."
    )
endif()

# Set output directory
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Find required packages
include (FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_MIXER REQUIRED SDL2_mixer)
pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image)
pkg_search_module(SDL2_TTF REQUIRED SDL2_ttf)

# Set C Language Standard
set (CMAKE_C_STANDARD 99)

include (cmake/AddResources.cmake)

# Subdirectories
add_subdirectory(game)
