// bin-clock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "LedDisplay.h"

int main()
{
	/* output pins: 2 -> 9 */
	LedDisplay display{ 2, 3, 4, 5, 6, 7, 8, 9 };
	
	display.Blink(4, std::chrono::milliseconds(1000));
	// display.BinAdd(4, 4);

	/* keep window open */
	std::cin.ignore();
}
