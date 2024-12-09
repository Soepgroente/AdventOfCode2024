#include "day9.hpp"

static int	getIndex(std::vector<int>& hd)
{
	auto it = std::find(hd.begin(), hd.end(), -1);

	if (it != hd.end())
		return (std::distance(hd.begin(), it));
	return (-1);
}

static void	reorderHardDisc(std::vector<int>& hd)
{
	while (getIndex(hd) != -1)
	{
		if (hd.back() != -1)
			hd[getIndex(hd)] = hd.back();
		hd.pop_back();
	}
}

void	silver(std::string& input)
{
	std::vector<int>	transformedInput;
	size_t result = 0;

	transformedInput = transform(input.size(), input.c_str());
	reorderHardDisc(transformedInput);
	for (size_t i = 0; i < transformedInput.size(); i++)
	{
		result += i * transformedInput[i];
	}
	std::cout << "Silver: " << result << std::endl;
}