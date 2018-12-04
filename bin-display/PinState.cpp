#include "pch.h"
#include "PinState.h"

/* !(PinState::HIGH) == PinState::LOW and vice versa */
PinState operator!(PinState ps)
{
	return (ps == PinState::HIGH) ? PinState::LOW : PinState::HIGH;
}