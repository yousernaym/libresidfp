#pragma once

#include <cstdint>

namespace reSIDfp
{
	class residfp;

	void vm_getEnvelopeOutputs(const residfp& sid, uint8_t envelopes[3]);

	//True per voice while its envelope is in (or entering) the ATTACK state. The envelope only
	//enters ATTACK on a gate 0->1 write, so a false->true edge is an exact retrigger signal even
	//when the gate off+on happened between two register polls.
	void vm_getEnvelopeAttackStates(const residfp& sid, bool attack[3]);
}

