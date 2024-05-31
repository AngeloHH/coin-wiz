cmake_minimum_required(VERSION 3.28)
project(coin_wiz)

set(CMAKE_CXX_STANDARD 17)

add_executable(coin_wiz main.cpp
        wallet.cpp
        wallet.h)
