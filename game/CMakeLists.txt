set (MAIN_TARGET game)

file (
    GLOB SOURCES
    src/*.c
    src/*/*.c
    src/*/*/*.c
)

add_executable(${MAIN_TARGET} ${SOURCES})

target_include_directories (
    ${MAIN_TARGET} PUBLIC
    headers
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_MIXER_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
)

target_compile_options (
    ${MAIN_TARGET} PRIVATE
    $<$<CONFIG:Debug>:-Wall;-g>
    $<$<CONFIG:Release>:-Wall;-O3;-s>
)

target_link_libraries (
    ${MAIN_TARGET} PUBLIC
    ${SDL2_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    m
)

add_resources(TARGET resources IN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res OUT_DIR res)
add_dependencies(${MAIN_TARGET} Duplicate-resources)
