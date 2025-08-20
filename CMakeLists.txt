cmake_minimum_required(VERSION 3.15)
project(bpe-tokenizer-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS regex)

add_executable(main src/main.cpp)
target_link_libraries(main Boost::regex)
