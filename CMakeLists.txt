cmake_minimum_required(VERSION 3.20)
project(task_manager)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(task_manager
        CsvHelper.cpp
        CsvHelper.hpp
        main.cpp
        Task.cpp
        Task.hpp
        TaskManager.cpp
        TaskManager.hpp)
