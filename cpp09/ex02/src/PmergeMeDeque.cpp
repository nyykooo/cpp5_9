#include "../includes/headers.hpp"

// PRINT METHOD
void PmergeMe::printDeque(std::deque<int> deque) const
{
	std::stringstream ss;
	size_t i;
	size_t length = deque.size();
	
	for (i = 0; i < length; ++i)
		ss << deque[i] << " ";
	std::cout << ss.str() << std::endl;
}

void PmergeMe::insertDeque(void)
{
	std::deque<int> js;

	getJacobsthalNumber(&js, _pendDeque.size());

	// insert backwards (using jacobsthal sequence)
	size_t size = js.size();


	std::deque<int>::iterator posInsertion = _mainDeque.begin();
	_mainDeque.insert(posInsertion, _pendDeque[0]);
	int g_inserted = 0;
	for (size_t i = 1; i < size; i++)
	{
		int amount_to_insert = js[i] - js[i-1];
		int inserted = 0;
		while (amount_to_insert > 0)
		{
			binaryInsert(js[i] - 1, inserted, _mainDeque, _pendDeque);
			inserted++;
			g_inserted++;
			amount_to_insert--;
		}
	}

	// insert remaining values from pend
	int pend_size = _pendDeque.size();
	if (static_cast<int>(pend_size) > g_inserted)
	{
		int amount_to_insert = pend_size - g_inserted - 1;
		int inserted = 0;
		while (amount_to_insert > 0)
		{
			binaryInsert(pend_size - 1, inserted, _mainDeque, _pendDeque);
			inserted++;
			g_inserted++;
			amount_to_insert--;
		}
	}

	_deque = _mainDeque;
}

void PmergeMe::initChainsDeque(void)
{
	// main = a1 + a2 + ... + an
	// main is constructed like this because we know for sure that
	// a1 < a2 < a3 ... < an
	// pend = b1 + b2 + ... + bn + (remaining numbers)

	size_t size = _pairedDeque.size();

	for (size_t i = 0; i < size; i++)
	{
		_mainDeque.push_back(_pairedDeque[i].large);
		_pendDeque.push_back(_pairedDeque[i].small);
	}
	if (_vec.size() % 2 == 1)
		_pendDeque.push_back(_vec[_vec.size() - 1]);
}

void PmergeMe::initPairsDeque(void)
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
		_pairedDeque.push_back(newPair);
	}
}

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void PmergeMe::mergeDeque(int left, int mid, int right)
{               
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    std::deque<s_pair> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = _pairedDeque[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = _pairedDeque[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into _pairedDeque[left..right]
    while (i < n1 && j < n2) {
        if (L[i].large <= R[j].large)
            _pairedDeque[k] = L[i++];
        else 
            _pairedDeque[k] = R[j++];
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1)
        _pairedDeque[k++] = L[i++];

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2)
        _pairedDeque[k++] = R[j++];
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void PmergeMe::mergeSortDeque(int left, int right){
    
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSortDeque(left, mid);
    mergeSortDeque(mid + 1, right);
    mergeDeque(left, mid, right);
}

// SORTING ALGORITHM
void PmergeMe::sortDeque(void)
{

	// 1 - divide into pairs
	initPairsDeque();
	// 2 - merge sort _pairedDeque by 'large'
	mergeSortDeque(0, _pairedDeque.size() - 1);
	// 3 - create the main chain and pend using the paired numbers from step 1
	initChainsDeque();
	// 4 - binary insert using jacobsthal numbers sequence
	insertDeque();
}