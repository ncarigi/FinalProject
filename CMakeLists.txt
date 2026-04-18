cmake_minimum_required(VERSION 4.1)
project(FinalProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(FinalProject main.cpp
        patient.cpp
        patient.h
        patient.h
        hospital.cpp
        hospital.h
        doctor.cpp
        doctor.h)

file(COPY patients.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY doctors.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
