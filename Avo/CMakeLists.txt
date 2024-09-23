set(SOURCE_FILES
	EntryPoint.h
	include/Avo.h
	AvoApplication.h
	AvoApplication.cpp
)

add_library(Avo STATIC ${SOURCE_FILES})

target_compile_definitions(Avo PRIVATE AVO_LIB)

if(MSVC)
	target_compile_definitions(Avo PUBLIC AVO_MS_COMPILER)
endif()