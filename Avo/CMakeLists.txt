set(SOURCE_FILES
	EntryPoint.h
	include/Avo.h
	AvoApplication.h
	AvoApplication.cpp
)

add_library(Avo STATIC ${SOURCE_FILES})

target_compile_definitions(Avo 
		PRIVATE 
			AVO_LIB
		PUBLIC
			$<$<CONFIG:Debug>:AVO_DEBUG=2>
			$<$<CONFIG:RelWithDebInfo>:AVO_DEBUG=1>
			AVO_OPENGL_STBI		
)

if(MSVC)
	target_compile_definitions(Avo PUBLIC AVO_MS_COMPILER)
endif()

target_precompile_headers(Avo PRIVATE pch.h)

target_link_libraries(Avo glfw)