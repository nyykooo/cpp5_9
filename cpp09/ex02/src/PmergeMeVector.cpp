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
void PmergeMe::printVec(void) const
{
	std::cout << BLD_CYAN << "PmergeMeVec >> printVec >> _vec: ";
	size_t i;
	size_t length = _vec.size();
	
	for (i = 0; i < length; ++i)
		std::cout << _vec[i] << " ";
	std::cout << RESET << std::endl;
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

// SORTING ALGORITHM
void PmergeMe::sortVec(void)
{
	printVec();
	// 1 - recursevely divide into pairs
	pairing(&_vec, 1);
	// pairingVec();
	printVec();
	// 2 - create the main chain
	// 3 - binary insert using jacobsthal numbers
	_depth = 0;
}