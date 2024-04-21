# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Include build functions from Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Set name of project and C/C++ standard
project(blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()

# Tell CMake where to find the source files
add_executable(${PROJECT_NAME}
                main.c)

# Create map/bin/uf2/hex output file from building process
pico_add_extra_outputs(${PROJECT_NAME})

# Link libraries that we use in source code
target_link_libraries(${PROJECT_NAME}
                        pico_stdlib)           
