#include "day13.hpp"

int	gcd(int a, int b)
{
    while (b != 0)
	{
        b = a % b;
        if (a < b)
		{
            a = a ^ b;
            b = a ^ b;
            a = a ^ b;
        }
    }
    return (a);
}
