# cmake_minimum_required(VERSION <specify CMake version here>)
project(server C)
cmake_minimum_required(VERSION 3.19)
set(CMAKE_C_STANDARD 99)
link_directories("C:\\Program Files (x86)\\mingw-w64\\i686-8.1.0-posix-dwarf-rt_v6-rev0\\mingw32\\lib")
link_libraries(ws2_32)
add_executable(server main.c)
target_link_libraries(server ws2_32)

