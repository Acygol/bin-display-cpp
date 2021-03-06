// bin-clock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "LedDisplay.h"

int main()
{
	/* output pins: 2 -> 9 */
	LedDisplay display{ 2, 3, 4, 5, 6, 7, 8, 9 };
	
	display.Blink(6, std::chrono::milliseconds(150));
	// display.BinConvert(255);

	/* keep window open */
	std::cin.ignore();
}
