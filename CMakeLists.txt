cmake_minimum_required(VERSION 2.8)

project(fsm)
 
include_directories(include)
  
file(GLOB SOURCES "src/*.c")
    
add_executable(fsm ${SOURCES})
