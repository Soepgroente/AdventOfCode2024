#include "day13.hpp"

Point	parseOne(std::string& line)
{
	Point	tmp;

	while (std::isdigit(line[0]) == false)
		line.erase(line.begin());
	tmp.x = atoi(line.c_str());
	while (line[0] != ' ')
		line.erase(line.begin());
	while (std::isdigit(line[0]) == false)
		line.erase(line.begin());
	tmp.y = atoi(line.c_str());
	return (tmp);
}

std::vector<SlotMachine>	parseInput(std::string location)
{
	std::ifstream	file;
	std::string		line;
	SlotMachine		tmp;
	std::vector<SlotMachine>	input;

	file.open(location);
	if (file.is_open() == false)
	{
		std::cerr << "Couldn't open input file" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	while (file.eof() == false)
	{
		std::getline(file, line, '\n');
		tmp.buttonA = parseOne(line);
		std::getline(file, line, '\n');
		tmp.buttonB = parseOne(line);
		std::getline(file, line, '\n');
		tmp.Prize = parseOne(line);
		input.emplace_back(std::move(tmp));
		std::getline(file, line, '\n');
	}
	file.close();
	return (input);
}
