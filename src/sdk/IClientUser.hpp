#pragma once

#include <cstdint>

class IClientUser
{
public:
	bool isLoggedOn();
	uint32_t updateOwnershipInfo(uint32_t appId, bool staleOnly);
};

extern IClientUser* g_pClientUser;
