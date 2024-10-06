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


#if AVO_DEBUG==2
	#define AVO_LOG(x) std::cout << x << std::endl;
	#define AVO_ERROR(x) std::cout << x << std::endl;
#elif AVO_DEBUG==1
	#define AVO_LOG(x)
	#define AVO_ERROR(x) std::cout << x << std::endl;
#else
	#define AVO_LOG(x)
	#define AVO_ERROR(x)
#endif

// AVO_LOG("REACHED HERE");