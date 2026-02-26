#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "headers.hpp"

typedef struct t_pair 
{
	int large;
	int small;
} s_pair;

class PmergeMe
{
	private:
		std::vector<int>	_vec; // original vector
		std::vector<int>	_pendVec; // lesser numbers of the paired vec + remaining if _vec.size() is odd
		std::vector<int>	_mainVec; // bigger numbers of the paired vec -> will receive the insertion
		std::vector<s_pair>	_pairedVec; // originial vector paired to merge
		
		std::deque<int>		_deque;
		std::deque<int>		_pendDeque;
		std::deque<int>		_mainDeque;
		std::deque<s_pair>	_pairedDeque;
	
	public:
		// ORTHODOX CANONICAL FORM
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &other);

		// LIFE CYCLE
		PmergeMe(int ac, char** av);

		// VEC METHODS
		void				printVec(std::vector<int> vec) const;
		void				sortVec(void);
		void				insertVec(void);
		void				initChainsVec(void);
		void				initPairsVec(void);
		void				mergeVec(int left, int mid, int right);
		void				mergeSortVec(int left, int right);

		// LIST METHODS
		void				printDeque(std::deque<int> list) const;
		void				sortDeque(void);
		void				insertDeque(void);
		void				initChainsDeque(void);
		void				initPairsDeque(void);
		void				mergeDeque(int left, int mid, int right);
		void				mergeSortDeque(int left, int right);

		// EXCEPTIONS
		class ParseException : public std::exception
		{
			private:
				const char	*_message;

			public:
				ParseException(const char *msg);

				const char *what() const throw();
		};
};

template<typename T>
void getJacobsthalNumber(T *jsConainer, size_t size)
{
	// jacobsthal numbers sequence logic:
	// current = previous + 2 × (previous of the previous)
	// it starts with 0 and 1 (which are fixed), after that follows the above equation
	// The next number is: 1 + 2 × 0 = 1 So, the sequence becomes: 0, 1, 1.
    // After that: 1 + 2 × 1 = 3 The sequence is now: 0, 1, 1, 3.
    // After that: 3 + 2 × 1 = 5 The sequence is now: 0, 1, 1, 3, 5.
    // After that: 5 + 2 × 3 = 11 The sequence is now: 0, 1, 1, 3, 5, 11.

	size_t js = 1;
	int prev = 0;
	int prev_prev = 0;

	// jsConainer->push_back(0); // this helps to insert b1 in the main later
	while (1)
	{
		prev_prev = prev;
		prev = js;
		js = prev + 2*(prev_prev);
		if (js <= size)
			jsConainer->push_back(js);
		else
			break ;
	}
}

template<typename T>
void binaryInsert(int js, int inserted, T &container, T &pend)
{
	int p_index = js - inserted;

	// locate _pend[p_index] and use it to start binary insertion at _main[p_index - 1]
	int to_insert = pend[p_index];
	
	typename T::iterator pos = std::lower_bound(container.begin(), container.end(), to_insert); // lower bound executes a binary search algorithm
	container.insert(pos, to_insert);
}

#endif