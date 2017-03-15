#include <iostream>
#include <string>

#include "BTNode.hpp"
#include "AVLNodeToolkit.hpp"

int main(void)
{
	BTNode<int>* root = NULL;
	BTNode<int>* result = NULL;
	AVLNodeToolkit<int>::insert(root, 5);
	AVLNodeToolkit<int>::insert(root, 6);
	AVLNodeToolkit<int>::insert(root, 7);
	AVLNodeToolkit<int>::insert(root, 8);
	AVLNodeToolkit<int>::insert(root, 0);
	AVLNodeToolkit<int>::insert(root, 6);
	AVLNodeToolkit<int>::insert(root, 6);
	AVLNodeToolkit<int>::insert(root, 2);
	std::cout << "Sum: " << AVLNodeToolkit<int>::sum(root) << "\n";
	std::cout << "Search 4: " << AVLNodeToolkit<int>::search(root, result, 4) << "\n";
	std::cout << "Search 7: " << AVLNodeToolkit<int>::search(root, result, 7);
	std::cout << " " << result->data  << "\n";
	std::cout << "Depth : " << AVLNodeToolkit<int>::getDepth(root) << "\n";
	std::cout << "Print:\n";
	AVLNodeToolkit<int>::printFull(root, 0, 3);
	AVLNodeToolkit<int>::rotateRight(root);
	root = root->parent;
	std::cout << "Print Rotate right:\n";
	AVLNodeToolkit<int>::printFull(root, 0, 3);
	std::cout << "Print Remove:\n";
	AVLNodeToolkit<int>::remove(root,6);
	AVLNodeToolkit<int>::printFull(root, 0, 3);
	std::cout << "Print Remove:\n";
	AVLNodeToolkit<int>::remove(root,8);
	AVLNodeToolkit<int>::printFull(root, 0, 3);
	std::cout << "Print Remove:\n";
	AVLNodeToolkit<int>::remove(root,2);
	AVLNodeToolkit<int>::printFull(root, 0, 3);
}