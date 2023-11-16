cmake_minimum_required(VERSION 3.20)
project(homew02 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_COMPILER clang)

add_executable(homew02 src/main.c src/init.c src/eval_input.c src/data.c)
target_link_libraries(${PROJECT_NAME} m)