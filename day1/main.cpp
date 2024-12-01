#include "day1.hpp"


void	createArrays(std::vector<std::string>& input, \
	std::array<int, 1000>& left, std::array<int, 1000>& right)
{
	 for (size_t i = 0; i < input.size(); ++i)
    {
        std::istringstream iss(input[i]);
        
        if (!(iss >> left[i] >> right[i]))
		{
            std::cerr << "Error parsing line: " << input[i] << std::endl;
			std::exit(EXIT_FAILURE);
        }
    }
}

int main()
{
	std::vector<std::string>	input = parseInput();
	std::array<int, 1000>	left;
	std::array<int, 1000>	right;

	createArrays(input, left, right);

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

	silver(left, right);
	gold(left, right);
}