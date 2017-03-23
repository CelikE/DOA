
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

// Struct skipNode member implementation
// constructor
skipNodde::skipNode(int k, const std::string& val, int level) 
	: key(k), value(val) {
	for(int i = 0; i < level; i++)
		forward.emplace_back(nullptr);
}

// Class skipList member implementation
// constructor
skipList::skipList() : probability(0.5), maxLevel(16) {
	// Initialize the head of the skip list

	// smallest possible key
	int headKey = std::numeric_limits<int>::min();
	head = new skipNode(headKey, "head", maxLevel);

	// Initialize the last element of the list
	int nilKey = std::numeric_limits<int>::max();
	NIL = new skipNode(nilKey, "NIL", maxLevel);

	// Connect start to end
	// connect all the levels/forward pointers of the header to NIL
	for (size_t i = 0; i < head->forward.size(), i++)
		head->forward[i] = nil;
}

