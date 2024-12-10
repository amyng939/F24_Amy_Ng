#pragma once

#ifdef AVO_GLFW

	#define AVO_KEY_SPACE              32
	#define AVO_KEY_APOSTROPHE         39  /* ' */
	#define AVO_KEY_COMMA              44  /* , */
	#define AVO_KEY_MINUS              45  /* - */
	#define AVO_KEY_PERIOD             46  /* . */
	#define AVO_KEY_SLASH              47  /* / */
	#define AVO_KEY_0                  48
	#define AVO_KEY_1                  49
	#define AVO_KEY_2                  50
	#define AVO_KEY_3                  51
	#define AVO_KEY_4                  52
	#define AVO_KEY_5                  53
	#define AVO_KEY_6                  54
	#define AVO_KEY_7                  55
	#define AVO_KEY_8                  56
	#define AVO_KEY_9                  57
	#define AVO_KEY_SEMICOLON          59  /* ; */
	#define AVO_KEY_EQUAL              61  /* = */
	#define AVO_KEY_A                  65
	#define AVO_KEY_B                  66
	#define AVO_KEY_C                  67
	#define AVO_KEY_D                  68
	#define AVO_KEY_E                  69
	#define AVO_KEY_F                  70
	#define AVO_KEY_G                  71
	#define AVO_KEY_H                  72
	#define AVO_KEY_I                  73
	#define AVO_KEY_J                  74
	#define AVO_KEY_K                  75
	#define AVO_KEY_L                  76
	#define AVO_KEY_M                  77
	#define AVO_KEY_N                  78
	#define AVO_KEY_O                  79
	#define AVO_KEY_P                  80
	#define AVO_KEY_Q                  81
	#define AVO_KEY_R                  82
	#define AVO_KEY_S                  83
	#define AVO_KEY_T                  84
	#define AVO_KEY_U                  85
	#define AVO_KEY_V                  86
	#define AVO_KEY_W                  87
	#define AVO_KEY_X                  88
	#define AVO_KEY_Y                  89
	#define AVO_KEY_Z                  90
	#define AVO_KEY_LEFT_BRACKET       91  /* [ */
	#define AVO_KEY_BACKSLASH          92  /* \ */
	#define AVO_KEY_RIGHT_BRACKET      93  /* ] */
	#define AVO_KEY_GRAVE_ACCENT       96  /* ` */
	#define AVO_KEY_WORLD_1            161 /* non-US #1 */
	#define AVO_KEY_WORLD_2            162 /* non-US #2 */

	/* Function keys */
	#define AVO_KEY_ESCAPE             256
	#define AVO_KEY_ENTER              257
	#define AVO_KEY_TAB                258
	#define AVO_KEY_BACKSPACE          259
	#define AVO_KEY_INSERT             260
	#define AVO_KEY_DELETE             261
	#define AVO_KEY_RIGHT              262
	#define AVO_KEY_LEFT               263
	#define AVO_KEY_DOWN               264
	#define AVO_KEY_UP                 265
	#define AVO_KEY_PAGE_UP            266
	#define AVO_KEY_PAGE_DOWN          267
	#define AVO_KEY_HOME               268
	#define AVO_KEY_END                269
	#define AVO_KEY_CAPS_LOCK          280
	#define AVO_KEY_SCROLL_LOCK        281
	#define AVO_KEY_NUM_LOCK           282
	#define AVO_KEY_PRINT_SCREEN       283
	#define AVO_KEY_PAUSE              284
	#define AVO_KEY_F1                 290
	#define AVO_KEY_F2                 291
	#define AVO_KEY_F3                 292
	#define AVO_KEY_F4                 293
	#define AVO_KEY_F5                 294
	#define AVO_KEY_F6                 295
	#define AVO_KEY_F7                 296
	#define AVO_KEY_F8                 297
	#define AVO_KEY_F9                 298
	#define AVO_KEY_F10                299
	#define AVO_KEY_F11                300
	#define AVO_KEY_F12                301
	#define AVO_KEY_F13                302
	#define AVO_KEY_F14                303
	#define AVO_KEY_F15                304
	#define AVO_KEY_F16                305
	#define AVO_KEY_F17                306
	#define AVO_KEY_F18                307
	#define AVO_KEY_F19                308
	#define AVO_KEY_F20                309
	#define AVO_KEY_F21                310
	#define AVO_KEY_F22                311
	#define AVO_KEY_F23                312
	#define AVO_KEY_F24                313
	#define AVO_KEY_F25                314
	#define AVO_KEY_KP_0               320
	#define AVO_KEY_KP_1               321
	#define AVO_KEY_KP_2               322
	#define AVO_KEY_KP_3               323
	#define AVO_KEY_KP_4               324
	#define AVO_KEY_KP_5               325
	#define AVO_KEY_KP_6               326
	#define AVO_KEY_KP_7               327
	#define AVO_KEY_KP_8               328
	#define AVO_KEY_KP_9               329
	#define AVO_KEY_KP_DECIMAL         330
	#define AVO_KEY_KP_DIVIDE          331
	#define AVO_KEY_KP_MULTIPLY        332
	#define AVO_KEY_KP_SUBTRACT        333
	#define AVO_KEY_KP_ADD             334
	#define AVO_KEY_KP_ENTER           335
	#define AVO_KEY_KP_EQUAL           336
	#define AVO_KEY_LEFT_SHIFT         340
	#define AVO_KEY_LEFT_CONTROL       341
	#define AVO_KEY_LEFT_ALT           342
	#define AVO_KEY_LEFT_SUPER         343
	#define AVO_KEY_RIGHT_SHIFT        344
	#define AVO_KEY_RIGHT_CONTROL      345
	#define AVO_KEY_RIGHT_ALT          346
	#define AVO_KEY_RIGHT_SUPER        347
	#define AVO_KEY_MENU               348

#else
	#only_GLFW_is_supported_for_now
#endif