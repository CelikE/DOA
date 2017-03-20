
#pragma once

#include <iostream>
#include <algorithm>
#include "BTNode.hpp"
#include "BTNodeToolkit.hpp"

template<class T>
class AVLNodeToolkit : public BTNodeToolkit<T> {
public:
	static void rotateRight(BTNode<T>* root) {
		//Move old root parent to new root parent
		root->left->parent = root->parent;
		//Move new root to old root parent
		root->parent = root->left;
		//Move new root right to old root left
		root->left = root->parent->right;
		//Move old root to new root right
		root->parent->right = root;

		//Update moved node
		if (root->left != NULL) 
			root->left->parent = root;

		//Update old parent
		if (root->parent->parent != NULL) {
			if (root->parent->parent->right == root->parent->right) {
				root->parent->parent->right = root->parent;
			} else {
				root->parent->parent->left = root->parent;
			}
		}
	}

	static void rotateLeft(BTNode<T>* root) {
		//Move old root parent to new root parent
		root->right->parent = root->parent;
		//Move new root to old root parent
		root->parent = root->right;
		//Move new root left to old root right
		root->right = root->parent->left;
		//Move old root to new to new root left
		root->parent->left = root;

		//Update moved node
		if (root->right != NULL) 
			root->right->parent = root->left->right;

		//Update old parent
		if (root->parent->parent != NULL) {
			if (root->parent->parent->right == root->parent->left) {
				root->parent->parent->right = root->parent;
			} else {
				root->parent->parent->left = root->parent;
			}
		}
	}

	static void rebalance(BTNode<T>*& root, BTNode<T>* node, bool single = false) {
		if (node == NULL)
			return;
		while (node->parent != NULL)
			node = node->parent;
		root = node;
	}

	static void remove(BTNode<T>*& root, BTNode<T>*& node) {
		BTNodeToolkit<T>::remove(root, node);
		rebalance(root, node);
	}

	static void insert(BTNode<T>*& root, const T& data) {
		if (root == NULL)
			root = new BTNode<T>(data);
		else if (data < root->data) {
			if (root->left == NULL) {
				root->left = new BTNode<T>(data);
				root->left->parent = root;
			} else {
				insert(root->left, data);
			}
		} else if (data > root->data) {
			if (root->right == NULL) {
				root->right = new BTNode<T>(data);
				root->right->parent = root;
			} else {
				insert(root->right, data);
			}
		}
	}

	static void remove(BTNode<T>*& root, T data) {
		BTNode<T>* node = NULL;
		if (BTNodeToolkit<T>::search(root, node, data)) 
			remove(root, node);
	}
};