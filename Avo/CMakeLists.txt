set(SOURCE_FILES
	EntryPoint.h
	include/Avo.h
	AvoApplication.h
	AvoApplication.cpp
	Image.h
	Image.cpp
	ImageImpl.h
	codeOpenGL/OpenGLImage.h
	codeOpenGL/OpenGLImage.cpp
	Shaders.h
	Shaders.cpp
	ShadersImpl.h
	codeOpenGL/OpenGLShaders.h
	codeOpenGL/OpenGLShaders.cpp
	Renderer.h
	Renderer.cpp
	RendererImpl.h
	codeOpenGL/OpenGLRenderer.h
	codeOpenGL/OpenGLRenderer.cpp
	AvoWindow.h
	AvoWindow.cpp
	WindowImpl.h
	codeGLFW/WindowGLFW.h
	codeGLFW/WindowGLFW.cpp
	KeyCodes.h
	AvoEvents.h
	AvoEvents.cpp
	AvoUtilities.h
	Unit.h
	Unit.cpp
)

add_library(Avo SHARED ${SOURCE_FILES})

target_compile_definitions(Avo 
		PRIVATE 
			AVO_LIB
		PUBLIC
			$<$<CONFIG:Debug>:AVO_DEBUG=2>
			$<$<CONFIG:RelWithDebInfo>:AVO_DEBUG=1>
			AVO_OPENGL_STBI
			AVO_GLFW		
)

if(MSVC)
	target_compile_definitions(Avo PUBLIC AVO_MS_COMPILER)
endif()

target_precompile_headers(Avo PRIVATE pch.h)

target_link_libraries(Avo glfw glad stbi)

include_directories("../glad/include")
include_directories("../glfw/include")
include_directories("../stbi")
include_directories("../Avo")