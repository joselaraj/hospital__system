cmake_minimum_required(VERSION 3.31)
project(hospital_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(hospital_system main.cpp
        registration.cpp
        registration.h
        staff_manager.cpp
        staff_manager.h)
