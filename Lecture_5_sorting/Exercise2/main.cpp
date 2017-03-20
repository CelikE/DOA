#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <chrono>

#define ARRAY_SIZE 100000

template<class T>
void insertionsort(T* arr, const int size) {
	int j;
	for (int i = 1; i < size; ++i) {
		j = i;
		while(j > 0 && arr[j-1] > arr[j]) {
			std::swap(arr[j-1], arr[j]);
			--j;
		}
	}
}

template<class T>
void quicksort2(T data[], int first, int last, int bc) {
	if (first + bc > last) {
		insertionsort<T>(&data[first], last-first+1);
	} else {
		// Set lower and upper
		int lower = first + 1, upper = last;
		// Swip pivot to front
		std::swap(data[first], data[(first + last) / 2]);
		T bound = data[first];
		while (lower <= upper) {
			while (data[lower] < bound)
				++lower;
			while (bound < data[upper])
				--upper;
			if (lower < upper)
				std::swap(data[lower++], data[upper--]);
			else lower++;
		}
		//Move pivot to center
		std::swap(data[upper], data[first]);
		if (first < upper - 1)
			quicksort2(data, first, upper - 1, bc);
		if (upper + 1 < last)
			quicksort2(data, upper + 1, last, bc);
	}
}

template<class T>
void quicksort2(T data[], const int n, const int bc) {
	int i, max;
	if (n < 2)
		return;
	for (i = 1, max = 0; i < n; i++)	// find the largest
		if (data[max] < data[i])	// element and put it
			max = i;		// at the end of data[];
	std::swap(data[n - 1], data[max]);		// largest el is now in its
	quicksort2(data, 0, n - 2, bc);		// final position;
}

template<class T>
void quicksort(T data[], int first, int last) {
	int lower = first + 1, upper = last;
	std::swap(data[first], data[(first + last) / 2]);
	T bound = data[first];
	while (lower <= upper) {
		while (data[lower] < bound)
			lower++;
		while (bound < data[upper])
			upper--;
		if (lower < upper)
			std::swap(data[lower++], data[upper--]);
		else lower++;
	}
	std::swap(data[upper], data[first]);
	if (first < upper - 1)
		quicksort(data, first, upper - 1);
	if (upper + 1 < last)
		quicksort(data, upper + 1, last);
}

template<class T>
void quicksort(T data[], const int n) {
	int i, max;
	if (n < 2)
		return;
	for (i = 1, max = 0; i < n; i++)// find the largest
		if (data[max] < data[i])    // element and put it
			max = i;                // at the end of data[];
	std::swap(data[n - 1], data[max]); // largest el is now in its
	quicksort(data, 0, n - 2);     // final position;
}

void copyArray(const int* from, int* to, const int size) {
	for (int i = 0; i < size; ++i) {
		to[i] = from[i];	
	}
}


int main(void) {
	int resdiv = 1000;
	long long microsec = 0;
	srand (time(NULL));
	int arr_sortme[ARRAY_SIZE];
	int arr_org[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		arr_org[i] = rand() % ARRAY_SIZE;
	}
	for (int j = 1; j < 60; j+=4) {
		copyArray(arr_org, arr_sortme, ARRAY_SIZE);
		auto start = std::chrono::high_resolution_clock::now();
		quicksort2<int>(arr_sortme, ARRAY_SIZE, j);
		auto elapsed = std::chrono::high_resolution_clock::now() - start;
		microsec = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
		std::cout << "C " << std::string(microsec / resdiv, '#') << "  " <<  microsec << "\n";
		copyArray(arr_org, arr_sortme, ARRAY_SIZE);
		start = std::chrono::high_resolution_clock::now();
		quicksort<int>(arr_sortme, ARRAY_SIZE);
		elapsed = std::chrono::high_resolution_clock::now() - start;
		microsec = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
		std::cout << "P " << std::string(microsec / resdiv, '-') << "  " <<  microsec << "\n";
	}
	return 0;
}