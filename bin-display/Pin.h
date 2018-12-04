#pragma once

#include "PinMode.h"
#include "PinState.h"

class Pin
{
public:
	Pin(int pin, PinMode mode) :physicalPin{ pin }, mode{ mode } { };
	~Pin() { };

	int GetPhysicalPin();
	PinMode GetMode();

	void SetState(PinState);
	PinState GetState();

private:
	PinMode mode;
	int physicalPin;

	/* HIGH - true ; (default) LOW - false */
	PinState state = PinState::LOW;
};

