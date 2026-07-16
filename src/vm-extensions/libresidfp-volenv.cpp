#include "vm-extensions/libresidfp-volenv.h"

#include <cstdint>
#include <memory>

// Keep Visual Music's note-extraction hook out of upstream-looking reSIDfp files.
// This translation unit intentionally exposes private state only while compiling
// the VM extension, so the public/residfp headers can stay untouched.
#define private public
#include "residfp/residfp.h"
#include "SID.h"
#undef private

namespace reSIDfp
{
	void vm_getEnvelopeOutputs(const residfp& sid, uint8_t envelopes[3])
	{
		if (!envelopes)
			return;

		for (int i = 0; i < 3; i++)
			envelopes[i] = static_cast<uint8_t>(sid.sid.voice[i].envelope()->output());
	}

	void vm_getEnvelopeAttackStates(const residfp& sid, bool attack[3])
	{
		if (!attack)
			return;

		for (int i = 0; i < 3; i++)
		{
			const EnvelopeGenerator* env = sid.sid.voice[i].envelope();
			//next_state covers the few-cycle pipeline delay between the gate write and
			//state actually switching to ATTACK.
			attack[i] = env->state == EnvelopeGenerator::State::ATTACK
				|| env->next_state == EnvelopeGenerator::State::ATTACK;
		}
	}
}
