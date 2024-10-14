cmake_minimum_required(VERSION 3.29)
project(ASEAI_PI C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(ASEAI_PI
    include/MyGPIO.h
    src/alarme.c
    src/motor.c
    src/MyGPIO.c
    src/signaux.c)
