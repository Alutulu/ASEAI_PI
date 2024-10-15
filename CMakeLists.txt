# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Set the project name and language
project(ASEAI_PI C)

# Set C standard (e.g., C11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find all C source files in the src directory
set(SOURCES
        src/motor.c
        src/MyGPIO.c
        src/MyPWM.c
)

# Create an executable from the source files
add_executable(${PROJECT_NAME} ${SOURCES}
        src/motor.c)
