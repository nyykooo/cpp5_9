/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:14:54 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/14 22:17:09 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

		std::list<int>		_list;
		std::list<int>		_pendList;
		std::list<int>		_mainList;
		
	public:
		// ORTHODOX CANONICAL FORM
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &other);

		// LIFE CYCLE
		PmergeMe(int ac, char** av);

		// GETTERS
		std::list<int>		getList();
		std::vector<int>	getVec();

		// VEC METHODS
		// void pairingVec(void);
		void				printVec(std::vector<int> vec) const;
		void				sortVec(void);
		void				insertVec(void);
		void				initChainsVec(void);
		void				initPairsVec(void);
		void				mergeVec(int left, int mid, int right);
		void				mergeSortVec(int left, int right);

		std::vector<int>	prepareInsertionVec(void);
		void				binaryInsertVec(int js, int inserted, int g_inserted);
		int					binarySearch(int to_insert, int low, int high);

		// LIST METHODS
		// void pairingList(void);
		void printList(void) const;
		void sortList(void);


		// UTILS
		// int					getJacobsthalNumber(size_t size);

		// TEMPLATE PAIRING - ACESS TO CLASS MEMBERS
		template<typename T>
		void swapBuckets(T bucket_one, T bucket_two, size_t unity_size)
		{
			int temp;

			for (size_t i = 0; i < unity_size; ++i)
			{
				temp = *(bucket_one);
				*(bucket_one) = *(bucket_two);
				*(bucket_two) = temp;
				++bucket_one;
				++bucket_two;
			}
		}

		template<typename T>
		int getBucketLastValue(T bucket_begin, size_t unity_size)
		{
			std::advance(bucket_begin, unity_size - 1);
			return (*(bucket_begin));
		}

		template<typename T>
		void pairing(T *container, int depth)
		{
			size_t unity_size = pow(2, depth - 1); // in first call will be 1
			size_t n_buckets = container->size() / (unity_size * 2);

			if (n_buckets == 0)
			{
				// depth--; // remove last depth reached
				return ; // end recursive calls
			}

			for (size_t compare = 0; compare < n_buckets; ++compare)
			{
				typename T::iterator bucket1_start = (container->begin() + compare * (unity_size * 2));
				typename T::iterator bucket2_start = bucket1_start + unity_size;
				// verify if the last element of a chunk is greater than the last of the next chunk
				if (getBucketLastValue(bucket1_start, unity_size) > getBucketLastValue(bucket2_start, unity_size))
					swapBuckets(bucket1_start, bucket2_start, unity_size);
			}
			pairing(container, depth + 1);
		}

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

	std::cout << "pend size: " << size << std::endl;

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

#endif