/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:14:54 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/11 22:31:48 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "headers.hpp"

class PmergeMe
{
	private:
		int					_depth;
		std::vector<int>	_vec;
		std::vector<int>	_pendVec;
		std::list<int>		_list;
		std::list<int>		_pendList;
		
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
		void printVec(void) const;
		void sortVec(void);
		void initInsertVec(void);

		// LIST METHODS
		// void pairingList(void);
		void printList(void) const;
		void sortList(void);


		// TEMPLATE PAIRING - ACESS TO CLASS MEMBERS
		template<typename T>
		void swapBuckets(T chunk_one_it, T chunk_two_it, size_t chunk_size)
		{
			int temp;

			for (size_t i = 0; i < chunk_size; ++i)
			{
				temp = *(chunk_one_it);
				*(chunk_one_it) = *(chunk_two_it);
				*(chunk_two_it) = temp;
				++chunk_one_it;
				++chunk_two_it;
			}
		}

		template<typename T>
		int getBucketLastValue(T chunk_begin, size_t chunk_size)
		{
			std::advance(chunk_begin, chunk_size - 1);
			return (*(chunk_begin));
		}

		template<typename T>
		void pairing(T *container)
		{
			_depth++;
			size_t bucket_size = pow(2, _depth - 1); // in first call will be 1
			size_t n_buckets = container->size() / (bucket_size * 2);

			if (n_buckets == 0)
			{
				_depth--; // remove last depth reached
				return ; // end recursive calls
			}

			for (size_t compare = 0; compare < n_buckets; ++compare)
			{
				typename T::iterator bucket1_start = (container->begin() + compare * (bucket_size * 2));
				typename T::iterator bucket2_start = bucket1_start + bucket_size;
				// verify if the last element of a chunk is greater than the last of the next chunk
				if (getBucketLastValue(bucket1_start, bucket_size) > getBucketLastValue(bucket2_start, bucket_size))
					swapBuckets(bucket1_start, bucket2_start, bucket_size);
			}
			pairing(container);
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

#endif