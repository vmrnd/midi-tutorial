add_library(mpr121 STATIC mpr121.c)

target_link_libraries(mpr121 PUBLIC pico_stdlib hardware_i2c)

target_include_directories(mpr121 INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})
