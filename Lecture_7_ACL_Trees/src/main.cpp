#include <iostream>
#include <string>

#include "BTNode.hpp"
#include "BTNodeToolkit.hpp"

int main(void) {
	BTNode<int>* root = NULL;
	BTNodeToolkit<int>::insert(root, 5);
	BTNodeToolkit<int>::insert(root, 6);
	BTNodeToolkit<int>::insert(root, 7);
	BTNodeToolkit<int>::insert(root, 8);
	BTNodeToolkit<int>::insert(root, 0);
	BTNodeToolkit<int>::insert(root, 6);
	BTNodeToolkit<int>::insert(root, 6);
	BTNodeToolkit<int>::insert(root, 7);
	std::cout << "Sum: " << BTNodeToolkit<int>::sum(root) << "\n";
	BTNodeToolkit<int>::print(root);
	std::cout << "Search 4: " << BTNodeToolkit<int>::search(root, 4) << "\n";
	std::cout << "Search 7: " << BTNodeToolkit<int>::search(root, 7) << "\n";
}