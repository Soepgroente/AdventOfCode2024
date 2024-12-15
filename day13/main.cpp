#include "day13.hpp"

int main()
{
	std::vector<SlotMachine>	slots = parseInput("testinput.txt");

	silver(slots);
	gold(slots);
}

