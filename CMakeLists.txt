cmake_minimum_required(VERSION 3.26)
project(matrix_ C)

set(CMAKE_C_STANDARD 11)

add_executable(matrix_ main.c
        s21_matrix.h
        s21_matrix.c
        s21_test.c)


