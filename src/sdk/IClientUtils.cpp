#include "IClientUtils.hpp"

#include "../memhlp.hpp"
#include "../hooks.hpp"
#include "../vftableinfo.hpp"

#include <cstdint>

uint32_t* IClientUtils::getPipeIndex()
{
	//Offset found in IClientUtils::GetAppId
	return reinterpret_cast<uint32_t*>(this - 0x944);
}


uint32_t IClientUtils::getAppId()
{
	return MemHlp::callVFunc<uint32_t(*)(void*)>(VFTIndexes::IClientUtils::GetAppId, this);
}

bool IClientUtils::getOfflineMode()
{
	return Hooks::IClientUtils_GetOfflineMode.originalFn.fn(this);
}

IClientUtils* g_pClientUtils;
