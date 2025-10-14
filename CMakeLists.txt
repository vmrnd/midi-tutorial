cmake_minimum_required(VERSION 3.13...3.27)

include(extern/pico-sdk/pico_sdk_init.cmake)
project(my_project)
pico_sdk_init()

add_subdirectory(lib)
add_subdirectory(apps)
add_subdirectory(extern/unity_cmake)
add_subdirectory(test)
