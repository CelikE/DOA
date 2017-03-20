
#pragma once

#include <iostream>
#include "BTNode.hpp"

template<class T>
class BTNodeToolkit {
public:
	static void insert(BTNode<T>*& root, const T& data) {
		if (root == NULL) {
			root = new BTNode<T>(data);
		} else if (data <= root->data) {
			if (root->left == NULL) {
				root->left = new BTNode<T>(data);
				root->left->parent = root;
			} else {
				insert(root->left, data);
			}
		} else {
			if (root->right == NULL) {
				root->right = new BTNode<T>(data);
				root->right->parent = root;
			} else {
				insert(root->right, data);
			}
		}
	}

	static bool search(BTNode<T>*& root, const T& data) {
		if (root == NULL) {
			return false;
		} else if (root->data == data) {
			return true;
		} else if (root->data < data) {
			return search(root->right, data);
		} else {
			return search(root->left, data);
		}

	}

	static bool remove(BTNode<T>*& root, T data) {

	}

	static T sum(BTNode<T>* root) {
		if (root == NULL)
			return 0;
		return root->data + sum(root->left) + sum(root->right);
	}

	static void print(BTNode<T>* root, int depth = 0) {
		if (root == NULL)
			return;
		print(root->right, depth + 1);
		std::cout << std::string(depth * 3, ' ') << root->data << "\n";
		print(root->left, depth + 1);
	}
};