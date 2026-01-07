#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open the file." << std::endl;
        return 1;
    }
    try 
    {
        BitcoinExchange exc("data.csv");
        exc.run(av[1]);
    }
    catch (std::exception &e)
    {

    }
}