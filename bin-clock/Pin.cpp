#include "pch.h"
#include "Pin.h"

int Pin::GetPhysicalPin()
{
	return physicalPin;
}

PinMode Pin::GetMode()
{
	return mode;
}

void Pin::SetState(PinState s)
{
	state = s;
}

PinState Pin::GetState()
{
	return state;
}
