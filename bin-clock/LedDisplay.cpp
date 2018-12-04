#include "pch.h"
#include "LedDisplay.h"
#include "Pin.h"

LedDisplay::LedDisplay(std::initializer_list<int> args)
{
	if (args.size() < 1 || args.size() > 8)
		throw std::invalid_argument("invalid # of pins in LedDisplay constructor");

	for (auto& arg : args)
	{
		pins.push_back(std::make_shared<Pin>(arg, PinMode::OUTPUT));
	}
}

void LedDisplay::Print_()
{
	for (auto& pin : pins)
		std::cout << ((pin->GetState() == PinState::HIGH) ? 'X' : 'O');

	std::cout << std::endl;
}

void LedDisplay::Pause_(std::chrono::milliseconds ms)
{
	using std::chrono::system_clock;
	std::this_thread::sleep_until(system_clock::now() + std::chrono::duration_cast<std::chrono::seconds>(ms));
}

bool LedDisplay::Set_(int pin, PinState state)
{
	auto p{ this->PhysicalToObj_(pin) };
	if (p)
	{
		p->SetState(state);
	}

	/* to bool conversion - a simple error return code */
	return !!(p);
}

std::shared_ptr<Pin> LedDisplay::PhysicalToObj_(int pin)
{
	for (auto& p : pins)
		if (p->GetPhysicalPin() == pin)
			return p;

	return nullptr;
}

void LedDisplay::On(int pin)
{
	if (!this->Set_(pin, PinState::HIGH))
		std::cout << "WARNING (LedDisplay::On): pin " << pin << " isn't valid.\n";
}

void LedDisplay::Off(int pin)
{
	if (!this->Set_(pin, PinState::LOW))
		std::cout << "WARNING (LedDisplay::Off): pin " << pin << " isn't valid.\n";
}

void LedDisplay::Blink(int pin, std::chrono::milliseconds delay)
{
	auto p{ this->PhysicalToObj_(pin) };
	if (p)
	{
		PinState current_state = p->GetState();
		while (true)
		{
			current_state = !current_state;
			p->SetState(current_state);

			this->Print_();
			this->Pause_(delay);
		}
	}
}

void LedDisplay::BinConvert(int dec_val)
{
	/* Index:  7 6 5 4 3 2 1 0   */
	/* e.g., { 1,1,0,1,0,0,1,1 } */
	std::bitset<8> bin{ std::bitset<8>(dec_val) };

	/* assign an individual bit to each pin */
	for (size_t i = (pins.size() - 1), j = 0; i >= 0 && j < pins.size(); --i, ++j)
	{
		pins.at(i)->SetState(bin[j] ? PinState::HIGH : PinState::LOW);
	}
}

void LedDisplay::BinCount()
{
	/* keep num scoped to this for loop */
	for (int num{ 0 }; num < 257; ++num)
	{
		this->BinConvert(num);
		this->Print_();

		this->Pause_(std::chrono::milliseconds(150));
	}
}

void LedDisplay::BinAdd(int term1, int term2)
{
	this->BinConvert(term1);
	this->Print_();
	this->Pause_(std::chrono::milliseconds(1000));

	this->BinConvert(term2);
	this->Print_();
	this->Pause_(std::chrono::milliseconds(1000));

	this->BinConvert(term1+term2);
	this->Print_();
	this->Pause_(std::chrono::milliseconds(1500));
}
