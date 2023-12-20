cmake_minimum_required(VERSION 3.25)
project(AES_128_CLI)

set(CMAKE_CXX_STANDARD 17)

add_executable(AES_128_CLI main.cpp Program.cpp FileManager.cpp AESCryptographer.cpp)
