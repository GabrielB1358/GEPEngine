cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(GEPENGINE)

include_directories(
	src
	contrib/windows-cl-amd64/include
)

link_directories(
	${PROJECT_SOURCE_DIR}/contrib/windows-cl-amd64/lib
	
)

add_library(Graphics
	src/Graphics/Camera.cpp
	src/Graphics/Camera.h
	src/Graphics/RenderTexture.cpp
	src/Graphics/RenderTexture.h
	src/Graphics/Shader.cpp
	src/Graphics/Shader.h
	src/Graphics/Texture.cpp
	src/Graphics/Texture.h
	src/Graphics/Vao.cpp
	src/Graphics/Vao.h
	src/Graphics/Vbo.cpp
	src/Graphics/Vbo.h
	src/Graphics/WavefrontMesh.cpp
	src/Graphics/WavefrontMesh.h
	src/Graphics/Rend.h
	src/Graphics/stb_image.h
)

target_link_libraries(Graphics glew32 opengl32)

add_library(GEPEngine
	src/GEPEngine/TriangleRenderer.cpp
	src/GEPEngine/TriangleRenderer.h
	src/GEPEngine/NativeWindow.cpp
	src/GEPEngine/NativeWindow.h
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
	src/GEPEngine/Transform.h
	src/GEPEngine/Transform.cpp
	src/GEPEngine/MyEngine.h
)

target_link_libraries(GEPEngine
 Graphics
 SDL2
)

add_executable(demo
	src/demo/main.cpp
)

target_link_libraries(demo GEPEngine)

