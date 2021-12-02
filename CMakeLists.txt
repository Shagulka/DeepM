cmake_minimum_required(VERSION 3.16.3)
project(DeepM)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp src/LettersDivision.cpp src/Mistake.cpp src/FixLetter.cpp src/Generator.cpp)

add_definitions(-DLOCAL)

set_property(
        TARGET ${PROJECT_NAME}
        APPEND PROPERTY
        INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/rapidjson"
)


