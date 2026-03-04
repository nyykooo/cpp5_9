#include "../includes/headers.hpp"

// ################ LIFE CYCLE ################

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	this->_deque = other._deque;
	this->_vec = other._vec;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	if(this != &other)
	{
		this->_deque = other._deque;
		this->_vec = other._vec;
	}
	return *this;
}

// ################ LIFE CYCLE ################

PmergeMe::PmergeMe(int ac, char **av)
{
	if (ac == 1)
		throw PmergeMe::ParseException("Error >> Invalid arguments!\nUsage: ./PmergeMe <list of numbers unsorted>");
	else
	{
		char				*endptr = NULL;
		if (av[1][0] == '\0')
			throw PmergeMe::ParseException("Error >> Invalid arguments!\nUsage: ./PmergeMe <list of numbers unsorted>");

		for (int i = 1; i < ac; ++i)
		{
			std::string str = av[i];
			long	num;
			errno = 0;
			num = std::strtol(str.c_str(), &endptr, 10);
			if (*endptr || errno == ERANGE || num < 0 || num > INT_MAX)
				throw std::runtime_error(str + " :Invalid input!");
			_vec.push_back(static_cast<int>(num));
			_deque.push_back(static_cast<int>(num));
		}
	}

	std::cout << "Before: ";
	printVec(_vec);
	std::clock_t vecStart = std::clock();
	sortVec();
    std::clock_t vecEnd = std::clock();
    double timeVec = double(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000000;
	std::cout << "After: ";
	printVec(_vec);


	std::cout << "Before: ";
	printDeque(_deque);
	std::clock_t dequeStart = std::clock();
	sortDeque();
    std::clock_t dequeEnd = std::clock();
    double timeDeque = double(dequeEnd - dequeStart) / CLOCKS_PER_SEC * 1000000;
	std::cout << "After: ";
	printDeque(_deque);


    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque  : " << timeDeque << " us" << std::endl;
}

// ################ EXCEPTIONS ################
PmergeMe::ParseException::ParseException(const char *msg) : _message(msg) {}

const char *PmergeMe::ParseException::what() const throw()
{
	return _message;
}