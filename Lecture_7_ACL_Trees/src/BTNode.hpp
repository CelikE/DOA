#pragma once

template <class T> 
class BTNode
{
public:
	BTNode(T data) : data(data), right(NULL), left(NULL), parent(NULL) {}
	T data;
	BTNode<T>* left;
	BTNode<T>* right;
	BTNode<T>* parent;
};