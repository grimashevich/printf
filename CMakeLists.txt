cmake_minimum_required(VERSION 3.20)
project(printf C)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES
        libft/libft.h
        libft/*.c)

add_executable(printf main.c ${SOURCES})