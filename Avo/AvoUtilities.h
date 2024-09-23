#pragma once

#ifdef AVO_MS_COMPILER
	#ifdef AVO_LIB
		#define AVO_API __declspec(dllexport)
	#else
		#define AVO_API __declspec(dllimport)
	#endif
#else
	#define AVO_API
#endif