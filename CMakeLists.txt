cmake_minimum_required(VERSION 3.19)
project(client C)

set(CMAKE_C_STANDARD 99)
link_directories("C:\\Program Files (x86)\\mingw-w64\\i686-8.1.0-posix-dwarf-rt_v6-rev0\\mingw32\\lib")
link_libraries(ws2_32)
add_executable(client main.c)
target_link_libraries(client ws2_32)