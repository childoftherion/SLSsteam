#pragma once

#include <cstdint>

class CAppTicket
{
public:
	uint32_t signatureOffset;	//0x0
	uint32_t version;			//0x4
	uint32_t steamId;			//0x8
	char __pad_0xC[0x4];		//0xC
	uint32_t appId;				//0x10
	char __pad_0x14[0xC];		//0x14
	uint32_t issueTime;			//0x20
	char __pad_0x24[0x3DC];		//0x24
	
	uint32_t getSize() const;
}; //0x400

class CEncryptedAppTicket
{
public:
	uint32_t steamId;
	uint32_t size;
	uint8_t bytes[0x1000];
};
