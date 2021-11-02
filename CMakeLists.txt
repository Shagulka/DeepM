cmake_minimum_required(VERSION 3.16.3)
project(DeepM)

set(CMAKE_CXX_STANDARD 20)

add_executable(DeepM main.cpp src/LettersDivision.cpp src/Mistake.cpp src/FixLetter.cpp src/Generator.cpp)

find_package(DataFrame)

target_include_directories(DeepM PRIVATE DataFrame)

target_link_libraries(DeepM PRIVATE ${DataFrame})


