#include "CAppTicket.hpp"

uint32_t CAppTicket::getSize() const
{
	for (int i = sizeof(CAppTicket); i >= 0; i--)
	{
		const uint8_t byte = reinterpret_cast<const uint8_t*>(this)[i];

		if (byte > 0)
		{
			return i + 1;
		}
	}

	return 0;
}
