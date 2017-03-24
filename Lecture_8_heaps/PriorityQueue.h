
#include "MinHeap.h"

template<typename T>
class PriorityQueue {
public:
	PriorityQueue() {};

	void push(T item) {
		item.insert(item);
	}

	void top() const {
		return item.peek();
	}

	void pop() const {
		item.remove();
	}

	bool isEmpty() const {
		return item.isEmpty();
	}

private:
	MinHeap<T> item;
};