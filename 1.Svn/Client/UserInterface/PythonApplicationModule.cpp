///Add
#if defined(__BL_MOVE_CHANNEL__)
	PyModule_AddIntConstant(poModule, "BL_MOVE_CHANNEL", true);
#else
	PyModule_AddIntConstant(poModule, "BL_MOVE_CHANNEL", false);
#endif
	PyModule_AddStringConstant(poModule, "VERSION", "Ver. 21,2,10");