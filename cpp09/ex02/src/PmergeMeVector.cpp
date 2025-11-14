/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:24:28 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/14 22:20:55 by ncampbel         ###   ########.fr       */
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

std::vector<int> PmergeMe::binaryInsert(size_t unity_size)
{
	// jacobsthal numbers sequence logic:
	// current = previous + 2 × (previous of the previous)
	// it starts with 0 and 1 (which are fixed), after that follows the above equation
	// The next number is: 1 + 2 × 0 = 1 So, the sequence becomes: 0, 1, 1.
    // After that: 1 + 2 × 1 = 3 The sequence is now: 0, 1, 1, 3.
    // After that: 3 + 2 × 1 = 5 The sequence is now: 0, 1, 1, 3, 5.
    // After that: 5 + 2 × 3 = 11 The sequence is now: 0, 1, 1, 3, 5, 11.

	// Why do we need the Jacobsthal sequence?

	std::vector<int>::iterator main_it = _mainVec.begin();
	
	if (_pendVec.size() == 0)
		return _vec;
	
	std::vector<int>::iterator insert_start = _pendVec.begin();
	std::vector<int>::iterator insert_end = insert_start + unity_size;

	_mainVec.insert(main_it + unity_size, insert_start, insert_end);

	
	std::vector<int>::iterator main_end = _mainVec.end();
	_mainVec.insert(main_end, _remainingVec.begin(), _remainingVec.end());
	return _mainVec; // TODO: push back remaining numbers
}

std::vector<int> PmergeMe::fillMainVec(size_t unity_size, size_t n_unity)
{
	std::vector<int> res;

	// insert unity 1, 2, 4, 6, 8, ... n (where n is pair)
	// this means i == 0, 1, 3, 5, 7 ... (where i is odd or 0)
	// use push_back to add from _vec to res
	for (size_t i = 0; i < n_unity; i++)
		if (i % 2 == 1 || i == 0)
			for (size_t j = 0; j < unity_size; j++)
				res.push_back(_vec[j + i*unity_size]);
	return res;
}

std::vector<int> PmergeMe::fillRemainingVec(void)
{
	std::vector<int> res;

	// insert unity _vec from _mainVec.size() + _pendVec.size()
	size_t start = _mainVec.size() + _pendVec.size();
	size_t end = _vec.size();

	for (size_t i = start; i < end; i++)
		res.push_back(_vec[i]);
	return res;
}

std::vector<int> PmergeMe::fillPendVec(size_t unity_size, size_t n_unity)
{
	std::vector<int> res;

	// insert unity 3, 5, 7, 9, ... n (where n is odd)
	// this means i == 2, 4, 6, 8 ... (whee i is pair)
	for (size_t i = 2; i < n_unity; i++)
		if (i % 2 == 0)
			for (size_t j = 0; j < unity_size; j++)
				res.push_back(_vec[j + i*unity_size]);
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
	_pendVec = fillPendVec(unity_size, n_unity);

	// TODO: CREATE REMAINING NUMBERS
	_remainingVec = fillRemainingVec();
	
	_vec = binaryInsert(unity_size);
	std::cout << "_vec -> "; 
	printVec(_vec);
	_depth--;
	initInsertVec();
}

// SORTING ALGORITHM
void PmergeMe::sortVec(void)
{
	// std::cout << "_vec -> "; 
	// printVec(_vec);
	// 1 - recursevely divide into pairs
	pairing(&_vec); // template version
	// pairingVec(); // specific container version
	// std::cout << "_vec -> "; 
	// printVec(_vec);
	// 2 - create the main chain recurevely with the depth obtained by step 1
	// 3 - binary insert using jacobsthal numbers
	// steps 2 and 3 are done together
	// std::cout << "depth reached: " << _depth << std::endl;
	initInsertVec();
	_depth = 0;
}