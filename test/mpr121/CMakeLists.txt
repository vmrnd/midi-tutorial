add_executable(test_mpr121
    test_mpr121.c
)

target_link_libraries(test_mpr121 mpr121 Unity)
pico_enable_stdio_uart(test_mpr121 1)
pico_add_extra_outputs(test_mpr121)
