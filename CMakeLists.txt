cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(GEPENGINE)

include_directories(
	src
)

add_library(GEPEngine
	src/GEPEngine/Core.h
	src/GEPEngine/Component.h
	src/GEPEngine/Environment.h
	src/GEPEngine/Keyboard.h
	src/GEPEngine/Entity.h
	src/GEPEngine/Core.cpp
	src/GEPEngine/Component.cpp
	src/GEPEngine/Keyboard.cpp
	src/GEPEngine/Environment.cpp
	src/GEPEngine/Entity.cpp
)

add_executable(demo
	src/demo/main.cpp
)

target_link_libraries(demo GEPEngine)
