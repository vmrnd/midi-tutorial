add_library(midi STATIC midi.c)

target_link_libraries(midi PUBLIC pico_stdlib hardware_i2c)

target_include_directories(midi INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})
