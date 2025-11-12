/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:24:28 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/11 22:28:11 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

// PRINT METHOD
void PmergeMe::printVec(std::vector<int> vec) const
{
	std::stringstream ss;
	size_t i;
	size_t length = vec.size();
	
	for (i = 0; i < length; ++i)
		ss << vec[i] << " ";
	std::cout << ss.str() << std::endl;
}


// // TODO -> TEMPLATE THIS PAIRING FUNCTION
// void PmergeMe::pairingVec(void)
// {
// 	_depth++;
// 	size_t bucket_size = pow(2, _depth - 1); // in first call will be 1
// 	size_t n_buckets = _vec.size() / (bucket_size * 2);

// 	if (n_buckets == 0)
// 		return ; // end recursive calls

// 	for (size_t compare = 0; compare < n_buckets; ++compare)
// 	{
// 		std::vector<int>::iterator bucket1_start = (_vec.begin() + compare * (bucket_size * 2));
// 		std::vector<int>::iterator bucket2_start = bucket1_start + bucket_size;
// 		// verify if the last element of a chunk is greater than the last of the next chunk
// 		if (getBucketLastValue(bucket1_start, bucket_size) > getBucketLastValue(bucket2_start, bucket_size))
// 			swapBuckets(bucket1_start, bucket2_start, bucket_size);
// 	}
// 	pairingVec();
// }

std::vector<int> PmergeMe::fillMainVec(size_t unity_size, size_t n_unity)
{
	std::vector<int> res;

	// insert unity 1, 2, 4, 6, 8, ... n (where n is pair)
	// use push_back to add from _vec to res
	for (size_t i = 0; i < n_unity; ++i)
		if (i % 2 == 1 || i == 0)
			for (size_t j = 0; j < unity_size; ++j)
				res.push_back(_vec[j + i]);
	return res;
}

std::vector<int> PmergeMe::fillPendVec(size_t unity_size, size_t n_unity)
{
	std::vector<int> res;

	// insert unity 3, 5, 7, 9, ... n (where n is odd)
	for (size_t i = 2; i < n_unity; ++i)
		if (i % 2 == 1)
			for (size_t j = 0; j < unity_size; ++j)
				res.push_back(_vec[j + i]);
	return res;
}

void PmergeMe::initInsertVec(void)
{
	// main = {b1, a1} + a2 + ... + an
	// main is constructed like this because we know for sure that
	// b1 < a1, and a1 is lesser than any other a
	// pend = b2 + ... + bn
	// the remaining numbers won't be used here

	if (_depth == 0)
		return ;

	// one bucket contains a pair of elements {b, a}
	size_t unity_size = pow(2, _depth - 1);
	size_t n_unity = _vec.size() / (unity_size);
	std::cout << "unity_size: " << unity_size << std::endl;
	std::cout << "n_unity: " << n_unity << std::endl;

	_mainVec = fillMainVec(unity_size, n_unity);
	std::cout << "_mainVec -> "; 
	printVec(_mainVec);
	_pendVec = fillPendVec(unity_size, n_unity);
	std::cout << "_pendVec -> "; 
	printVec(_pendVec);
	_depth--;
	initInsertVec();
}

// SORTING ALGORITHM
void PmergeMe::sortVec(void)
{
	std::cout << "_vec -> "; 
	printVec(_vec);
	// 1 - recursevely divide into pairs
	pairing(&_vec); // template version
	// pairingVec(); // specific container version
	std::cout << "_vec -> "; 
	printVec(_vec);
	// 2 - create the main chain recurevely with the depth obtained by step 1
	// 3 - binary insert using jacobsthal numbers
	// steps 2 and 3 are done together
	std::cout << "depth reached: " << _depth << std::endl;
	initInsertVec();
	_depth = 0;
}