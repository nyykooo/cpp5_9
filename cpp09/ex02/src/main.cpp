#include "../includes/headers.hpp"

// test for pairing: 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

int main(int ac, char **av)
{
	try
	{
		PmergeMe PmergeMe(ac, av);
	}
	catch(const std::exception& e)
	{
		std::cout << BLK_RED << e.what() << RESET << '\n';
	}
}