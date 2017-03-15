#include <iostream>
#include <stdlib.h>

#define ARRAY_SIZE 20

void insertionSort(int* array, int size) {
	int mover;
	for (int i = 1; i < size; i++) {
		int j = 1;
		while(j > 0 && array[j - 1] > array[j]) {
			mover = array[j - 1];
			array[j - 1] = array[j];
			array[j] = mover;
			j--;
		}
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int array[ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE; i++) {
		array[i] = rand() % 100;
		std::cout << array[i] << " ";
	}
	std::cout << "\n";

	insertionSort(array, ARRAY_SIZE);

	for (int i = 0; i < ARRAY_SIZE; i++)
		std::cout << array[i] << " ";
	std::cout << "\n";

	return 0;
}