add_executable(main main.c)
target_link_libraries(main mpr121)
pico_enable_stdio_uart(main 1)
pico_add_extra_outputs(main)
