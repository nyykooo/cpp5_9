#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << BLD_RED << "Error: could not open the file." << RESET << std::endl;
        return 1;
    }
    try 
    {
        BitcoinExchange exc("data.csv");
        exc.run(av[1]);
    }
    catch (std::exception &e)
    {
        std::cout << BLD_RED << e.what() << RESET << std::endl;
    }
    return 0;
}