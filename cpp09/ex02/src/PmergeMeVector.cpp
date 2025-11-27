/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:24:28 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/19 19:09:26 by ncampbel         ###   ########.fr       */
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

int PmergeMe::binarySearch(int to_insert, int low, int high)
{
    if (high <= low)
        return (to_insert > _mainVec[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

	_compairsons++;

    if (to_insert == _mainVec[mid])
        return mid + 1;

    if (to_insert > _mainVec[mid])
        return binarySearch(to_insert, mid + 1, high);
	else
    	return binarySearch(to_insert, low, mid - 1);
}

void PmergeMe::binaryInsertVec(int js, int inserted, int g_inserted)
{
	int index = js - inserted;

	// locate _pend[index] and use it to start binary insertion at _main[index - 1]
	int to_insert = _pendVec[index];

	// boundaries to search in _mainVec
	int low = 0;
	int high = index + g_inserted;

	int pos = binarySearch(to_insert, low, high);

	std::vector<int>::iterator posInsertion = _mainVec.begin() + pos;
	_mainVec.insert(posInsertion, _pendVec[index]);
}

std::vector<int> PmergeMe::prepareInsertionVec(void)
{
	std::vector<int> js;

	getJacobsthalNumber(&js, _pendVec.size());

	// insert backwards (using jacobsthal sequence)
	size_t size = js.size();


	std::vector<int>::iterator posInsertion = _mainVec.begin();
	_mainVec.insert(posInsertion, _pendVec[0]);
	int g_inserted = 0;
	for (size_t i = 1; i < size; i++)
	{
		int amount_to_insert = js[i] - js[i-1];
		int inserted = 0;
		// std::cout << "amount to insert: " << amount_to_insert << std::endl;
		while (amount_to_insert > 0)
		{
			binaryInsertVec(js[i] - 1, inserted, g_inserted);
			inserted++;
			g_inserted++;
			amount_to_insert--;
		}
	}

	// insert remaining values from pend
	int pend_size = _pendVec.size();
	if (static_cast<int>(pend_size) > g_inserted)
	{
		int amount_to_insert = pend_size - g_inserted - 1;
		int inserted = 0;
		while (amount_to_insert > 0)
		{
			binaryInsertVec(pend_size - 1, inserted, g_inserted);
			inserted++;
			g_inserted++;
			amount_to_insert--;
		}
	}

	return _mainVec; // TODO: push back remaining numbers
}

void PmergeMe::insertVec(void)
{
	prepareInsertionVec();

	_vec = _mainVec;
}

void PmergeMe::initChainsVec(void)
{
	// main = a1 + a2 + ... + an
	// main is constructed like this because we know for sure that
	// a1 < a2 < a3 ... < an
	// pend = b1 + b2 + ... + bn + (remaining numbers)

	size_t size = _pairedVec.size();

	for (size_t i = 0; i < size; i++)
	{
		_mainVec.push_back(_pairedVec[i].large);
		_pendVec.push_back(_pairedVec[i].small);
	}
	if (_vec.size() % 2 == 1)
		_pendVec.push_back(_vec[_vec.size() - 1]);
}

void PmergeMe::initPairsVec(void)
{
	size_t size = _vec.size() % 2 == 0 ? _vec.size() : _vec.size() - 1;
	for (size_t i = 0; i < size; i += 2)
	{
		s_pair newPair;
		if (_vec[i] > _vec[i+1])
		{
			newPair.large = _vec[i];
			newPair.small = _vec[i+1];	
		}
		else if (_vec[i] < _vec[i+1])
		{
			newPair.large = _vec[i+1];	
			newPair.small = _vec[i];
		}
		else
		{
			// foundDuplicateException
		}
		_pairedVec.push_back(newPair);
	}
}

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void PmergeMe::mergeVec(int left, int mid, int right)
{
                         
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    std::vector<s_pair> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = _pairedVec[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = _pairedVec[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into _pairedVec[left..right]
    while (i < n1 && j < n2) {
		_compairsons++;
        if (L[i].large <= R[j].large)
            _pairedVec[k] = L[i++];
        else 
            _pairedVec[k] = R[j++];
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1)
        _pairedVec[k++] = L[i++];

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2)
        _pairedVec[k++] = R[j++];
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void PmergeMe::mergeSortVec(int left, int right){
    
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSortVec(left, mid);
    mergeSortVec(mid + 1, right);
    mergeVec(left, mid, right);
}

// SORTING ALGORITHM
void PmergeMe::sortVec(void)
{
	// 1 - divide into pairs
	initPairsVec();
	// 2 - merge sort _pairedVec by 'large'
	mergeSortVec(0, _pairedVec.size() - 1);
	// 3 - create the main chain and pend using the paired numbers from step 1
	initChainsVec();
	// 4 - binary insert using jacobsthal numbers sequence
	insertVec();
}