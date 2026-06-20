#pragma once

#include <cstdint>

namespace reSIDfp
{
	class residfp;

	void vm_getEnvelopeOutputs(const residfp& sid, uint8_t envelopes[3]);
}

