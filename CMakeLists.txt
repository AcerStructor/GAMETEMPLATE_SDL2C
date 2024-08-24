cmake_minimum_required (VERSION 3.1)

project (
    GAMETEMPLATE_SDL2C
    VERSION 1.0.0
    LANGUAGES C
)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_MIXER REQUIRED SDL2_mixer)
pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image)
pkg_search_module(SDL2_TTF REQUIRED SDL2_ttf)

set (HEADER_DIR headers)
set (MATH_LIBRARIES m)

# Output Directory:
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

include_directories (
    ${PROJECT_SOURCE_DIR}/${HEADER_DIR}
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_MIXER_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
)

file (
    GLOB SOURCES
    headers/*.h
    src/*.c
    src/*/*.c
    src/*/*/*.c
)

add_executable (${CMAKE_PROJECT_NAME} ${SOURCES})

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:-Wall;-g>
    $<$<CONFIG:Release>:-Wall;-O3;-s>
)

target_link_libraries (
    ${CMAKE_PROJECT_NAME}
    ${SDL2_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${MATH_LIBRARIES}
)
