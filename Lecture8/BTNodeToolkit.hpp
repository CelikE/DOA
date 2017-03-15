#pragma once

#include <iostream>
#include <algorithm>
#include <utility>
#include "BTNode.hpp"

template <class T>
class BTNodeToolkit
{
public:
	static int getDepth(BTNode<T>*& root)
	{
		if (root == NULL)
			return 0;
		return 1 + std::max(getDepth(root->left), getDepth(root->right));
	}

	static void insert(BTNode<T>*& root, const T& data)
	{
		if (root == NULL) {
			root = new BTNode<T>(data);
		}
		else if (data <= root->data) {
			if (root->left == NULL) {
				root->left = new BTNode<T>(data);
				root->left->parent = root;
			} else {
				insert(root->left, data);
			}
		}
		else if (data > root->data) {
			if (root->right == NULL) {
				root->right = new BTNode<T>(data);
				root->right->parent = root;
			} else {
				insert(root->right, data);
			}
		}
	}
	static bool search(BTNode<T>* root, BTNode<T>*& result, const T& data)
	{
		if (root == NULL) {
			result = root;
			return false;
		}
		else if (root->data == data) {
			result = root;
			return true;
		}
		else if (root->data < data) {
			return search(root->right, result, data);
		} else {
			return search(root->left, result, data);
		}
		
	}

	static void swap(BTNode<T>* n1, BTNode<T>* n2)
	{
		if (n1->parent == n2 || n2->parent == n1) { 
			if (n1->parent == n2)
				std::swap(n1, n2);
			n2->parent = n1->parent;
			n1->parent = n2;

			if (n1->left == n2) {
				std::swap(n1->right, n2->right);
				n1->left = n2->left;
				n2->left = n1;
			} else 
			{
				std::swap(n1->left, n2->left);
				n2->right = n1->right;
				n2->right = n1;
			}
		}
		else {
			std::swap(n1->parent, n2->parent);
			std::swap(n1->left, n2->left);
			std::swap(n1->right, n2->right);
			if (n1->parent != NULL)
			{
				if (n1->parent->right == n2) {
					n1->parent->right = n1;
				} else {
					n1->parent->left = n1;
				}
			}
		}
		if (n1->left != NULL)
			n1->left->parent = n1;
		if (n1->right != NULL)
			n1->right->parent = n1;
		if (n2->left != NULL)
			n2->left->parent = n2;
		if (n2->right != NULL)
			n2->right->parent = n2;
		if (n2->parent != NULL)
		{
			if (n2->parent->right == n1) {
				n2->parent->right = n2;
			} else {
				n2->parent->left = n2;
			}
		}
	}

	static void remove(BTNode<T>*& root, BTNode<T>*& node)
	{
		BTNode<T>* cand = NULL;

		if (node->left != NULL && node->right != NULL) {
			cand = node->left;
			while (cand->right != NULL)
				cand = cand->right;
			swap(node, cand);
		}


		if (node->right == NULL) {
			cand = node->left;
		}
		else {
			cand = node->right;
		}

		//Update parent
		if (node->parent != NULL) {
			if (node->parent->left == node) {
				node->parent->left = cand;
			}
			else {
				node->parent->right = cand;
			}
		}

		if (cand == NULL) {
			cand = node->parent;
		} else {
			cand->parent = node->parent;
		}

		root = cand;
		if (root != NULL)
			while (root->parent != NULL)
				root = root->parent;

		std::swap(node, cand);
		delete cand;;
	}

	static void remove(BTNode<T>*& root, T data)
	{
		BTNode<T>* node = NULL;
		if (search(root, node, data));
		{
			remove(root, node);
		}
	}

	static T sum(BTNode<T>* root)
	{
		if (root == NULL)
			return 0;
		return root->data + sum(root->left) + sum(root->right);
	}

	static void printFull(BTNode<T>* root, int offset = 0, const int& tabsize = 1) {
		while (root->parent != NULL)
			root = root->parent;
		print(root, offset, tabsize);
	}

	static void print(BTNode<T>* root, int offset = 0, const int& tabsize = 1)
	{
		if (root == NULL)
		{
			return;
		}
		print(root->right, offset + 1, tabsize);
		std::cout << std::string(offset*tabsize, ' ') << root->data << "\n";
		print(root->left, offset + 1, tabsize);
	}

};