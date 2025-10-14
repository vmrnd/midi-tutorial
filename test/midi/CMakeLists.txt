add_executable(test_midi
    test_midi.c
)

target_link_libraries(test_midi midi Unity)
pico_enable_stdio_uart(test_midi 1)
pico_add_extra_outputs(test_midi)
