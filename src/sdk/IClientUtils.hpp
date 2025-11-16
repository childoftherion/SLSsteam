#pragma once

#include <cstdint>

class IClientUtils
{
public:
	uint32_t* getPipeIndex();
	uint32_t getAppId();
	bool getOfflineMode();
};

extern IClientUtils* g_pClientUtils;
