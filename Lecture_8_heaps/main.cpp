
#include <iostream>
#include "MinHeap.h"

int main(int argc, char const *argv[])
{
	MinHeap<int> h;
	h.insert(1);
	h.insert(4);
	h.insert(7);
	h.insert(12);
	h.insert(31);
	h.insert(32);
	h.insert(54);
	h.insert(17);
	h.insert(79);
	h.insert(44);
	h.insert(59);
	h.insert(2);

	if (h.isHeap()) 
		std::cout << "Is Heap " << std::endl;
	else
		std::cout << "Is NOT Heap " << std::endl;

	h.print();

	std::vector<int> j;
	j.push_back(23);
	j.push_back(21);
	j.push_back(13);
	j.push_back(54);
	j.push_back(9);
	j.push_back(0);
	j.push_back(4);
	j.push_back(12);
	j.push_back(14);

	MinHeap<int> h2(j);
	h2.print();
	return 0;
}