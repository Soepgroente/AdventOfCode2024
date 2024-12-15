#include "day14.hpp"

void	parsePoint(std::vector<std::pair<Point, Point>>& input, std::string& line)
{
	int x[2], y[2];

	while (std::isdigit(line[0]) == false)
		line.erase(line.begin());

	x[0] = atoi(line.c_str());
	while (std::isdigit(line[0]) != false)
		line.erase(line.begin());
	while (std::isdigit(line[0]) == false)
		line.erase(line.begin());

	y[0] = atoi(line.c_str());
	while (std::isdigit(line[0]) != false)
		line.erase(line.begin());
	while (std::isdigit(line[0]) == false && line[0] != '-')
		line.erase(line.begin());

	x[1] = atoi(line.c_str());
	if (line[0] == '-')
		line.erase(line.begin());
	while (std::isdigit(line[0]) != false)
		line.erase(line.begin());
	while (std::isdigit(line[0]) == false && line[0] != '-')
		line.erase(line.begin());

	y[1] = atoi(line.c_str());
	input.emplace_back(std::pair{Point{x[0], y[0]}, Point{x[1], y[1]}});
}

std::vector<std::pair<Point, Point>>	parseInput(std::string location)
{
	std::ifstream	file;
	std::string		line;
	std::vector<std::pair<Point, Point>>	input;

	file.open(location);
	if (file.is_open() == false)
	{
		std::cerr << "Couldn't open input file" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	while (file.eof() == false)
	{
		std::getline(file, line, '\n');
		parsePoint(input, line);
	}
	file.close();
	return (input);
}
