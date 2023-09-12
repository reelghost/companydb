cmake_minimum_required(VERSION 3.26)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        Person.h
        Person.cpp
        Employee.cpp
        Employee.h
        Purchase.cpp
        Purchase.h
        Customer.cpp
        Customer.h
        Company.h
        Company.cpp)
