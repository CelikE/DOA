#include <vector>
#include <iostream>
#include <iterator>


//==================================================
// CLASS MinHeap
//==================================================
template<typename T>
class MinHeap {
public:
	MinHeap() {};

	MinHeap(const std::vector<T> & ar) {
		heap = ar;
		size_t start = parent(heap.size() - 1);
		for (size_t i = start; i > 0; i--) {
			percolateDown(i);
		}
		percolateDown(0);
	}

	void insert(const T& x) {
		heap.push_back(x);
		percolateUp(heap.size() - 1);
	}
	
	void remove() {
		swap(0, heap.size() - 1);
		heap.pop_back();
		percolateDown(0);
	}
	
	bool isEmpty() const { 
		return heap.size() == 0;
	}
	
	T peek() const { 
		return heap[0];
	}

	void print() const {
		for(auto it = heap.begin(); it != heap.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	bool isHeap() const {
		for(size_t i=0; i< (heap.size()-1)/2; i++)
		{
			if(smallest(i) != i) return false;
		}
		return true;
	}

private:
	
	std::vector<T> heap;

	size_t right(size_t i) const {
		return (i + 1) * 2;
	}

	size_t left(size_t i) const {
		return (i + 2) + 1;
	}

	size_t parent(size_t i) const {
		return (i - 1) / 2;
	}

	/*
	 * Perculate up/down functions
	 */
	void percolateUp(size_t i) {
		if(i == 0)
			return;

		if(heap[i] < heap[parent(i)]) {
			swap(i, parent(i));
			percolateUp(parent(i));
		}
	}

	void percolateDown(size_t i) {
		size_t small = smallest(i);
		if(i != small) {
			swap(i, small);
			percolateDown(small);
		}
	}
	
	size_t smallest(size_t i) const {// returns index of smallest of i and its parents 
		size_t small = i;
	
		if(left(i)  < heap.size() && 
			heap[i] > heap[left(i)]) 
			small = left(i);
		
		if(right(i) < heap.size() && 
			heap[i] > heap[right(i)] && 
			heap[right(i)] < heap[left(i)]) 
			small = right(i);

		return small;
	}

	void swap(size_t x, size_t y) { 
		T temp  = heap[x]; 
		heap[x] = heap[y]; 
		heap[y] = temp;
	}
	

};

