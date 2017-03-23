#pragma once

#include "SkipListElement.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

template<typename T>
class SkipList
{
public:
	SkipList(int maxHeight) : MAX_HEIGHT(maxHeight) {
		srand((int)time(0));
		head = new SkipListElement<T>(INT_MIN, MAX_HEIGHT);
	}

	~SkipList() {
		SkipListElement<T>* curr = head->links[0];
		
		// Traverse list on level 0, delete all nodes found
		if (curr) {
			SkipListElement<T>* next = curr->links[0];
			while (next) {
				delete curr;
				curr = next;
				next = curr->links[0];
			}
			delete curr;
		}
		
		delete head;
	}


	bool search(const T& data) {
		// YOUR IMPLEMENTATION GOES HERE!

	}


	void insert(T data) {
		// YOUR IMPLEMENTATION GOES HERE!
	}

	void remove(T data)
	{
		// YOUR IMPLEMENTATION GOES HERE!
	}


	bool isEmpty()
	{
		return head->links[0] == NULL;
	}


	void dump() {
		for(int i=MAX_HEIGHT-1; i>=0; --i) {
			
			SkipListElement<T>* sle = head->links[i];
			if(!sle) cout << "/";
			else
				while(sle != NULL) {
					cout << sle->data << "-->";
					sle = sle->links[i];
				}
			cout << endl;
		}
	}

private:
	size_t genLevel() {
		size_t level = 1;
		double prob; 
		while(true) {
			prob = ((double)(rand()) / RAND_MAX);
			if( (prob < 0.5 ) && ( level < MAX_HEIGHT)) ++level;
			else break;
		}
		return level;
	}

	SkipListElement<T>* head;
	const std::size_t MAX_HEIGHT;
};