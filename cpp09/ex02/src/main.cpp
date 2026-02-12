#include "../includes/headers.hpp"

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