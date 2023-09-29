cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(GEPENGINE)

include_directories(
	src
)

add_executable(demo
	src/demo/main.cpp
	src/demo/Player.h
)

add_library(GEPEngine
	src/GEPEngine/Core.h
	src/GEPEngine/Core.cpp
)