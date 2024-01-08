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
	src/GEPEngine/ModelRenderer.cpp
	src/GEPEngine/ModelRenderer.h
	src/GEPEngine/NativeWindow.cpp
	src/GEPEngine/NativeWindow.h
	src/GEPEngine/Core.cpp
	src/GEPEngine/Core.h
	src/GEPEngine/Component.cpp
	src/GEPEngine/Component.h
	src/GEPEngine/Environment.cpp
	src/GEPEngine/Environment.h
	src/GEPEngine/Input.cpp
	src/GEPEngine/Input.h
	src/GEPEngine/Entity.cpp
	src/GEPEngine/Entity.h
	src/GEPEngine/Transform.cpp
	src/GEPEngine/Transform.h
	src/GEPEngine/Resource.h
	src/GEPEngine/Resource.cpp
	src/GEPEngine/Resources.h
	src/GEPEngine/Resources.cpp
	src/GEPEngine/Model.cpp
	src/GEPEngine/Model.h
	src/GEPEngine/Shader.cpp
	src/GEPEngine/Shader.h
	src/GEPEngine/Texture.cpp
	src/GEPEngine/Texture.h
	src/GEPEngine/BoxCollider.cpp
	src/GEPEngine/BoxCollider.h
	src/GEPEngine/Rigidbody.cpp
	src/GEPEngine/Rigidbody.h
	src/GEPEngine/ALSoundSrc.cpp
	src/GEPEngine/ALSoundSrc.h
	src/GEPEngine/ALAudio.cpp
	src/GEPEngine/ALAudio.h
	src/GEPEngine/Camera.cpp
	src/GEPEngine/Camera.h
	src/GEPEngine/Light.cpp
	src/GEPEngine/Light.h
	src/GEPEngine/MyEngine.h
	src/GEPEngine/stb_vorbis.c
)

target_link_libraries(GEPEngine
 Graphics
 SDL2
 openal32
)

add_executable(demo
	src/demo/main.cpp
	src/demo/Curuthers.cpp
	src/demo/Curuthers.h
	src/demo/evilBloke.cpp
	src/demo/evilBloke.h
)

target_link_libraries(demo GEPEngine)

