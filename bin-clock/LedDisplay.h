#pragma once

#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <memory>
#include <iostream>
#include <bitset>
#include <chrono>
#include <thread>

#include "PinMode.h"
#include "PinState.h"

class Pin;
class LedDisplay
{
public:
	LedDisplay(std::initializer_list<int>);
	~LedDisplay() { };

	void On(int);
	void Off(int);
	void Blink(int, std::chrono::milliseconds);
	void BinConvert(int);
	void BinCount();
	void BinAdd(int, int);

private:
	void Print_();
	void Pause_(std::chrono::milliseconds secs);
	bool Set_(int, PinState);
	std::shared_ptr<Pin> PhysicalToObj_(int);
	std::vector<std::shared_ptr<Pin>> pins;
};

