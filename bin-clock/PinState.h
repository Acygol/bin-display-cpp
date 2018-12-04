#pragma once

enum class PinState
{
	HIGH,
	LOW
};

PinState operator!(PinState ps);
