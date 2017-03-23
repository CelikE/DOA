#include "skipList.cpp"

struct skipNode {
	int key;
	std::string value;

	// Pointers to successor nodes
	std::vector<skipNode> forward;

	skipNode(int k, const std::string& val, int level);
};

class skipList {
public:
	skipList();
	~skipList();

	// non-modifying member functions
	void print();
	skipNode * find(int searchKey);

	// modifying member functions
	void insert(int searchKey, std::string newValue);
	void erase(int searchKey);

private:
	//Pointer to first node
	skipNode * head;
	// last node
	skipNode * NIL;

	// implicitly used member functions
	int randomlevel();
	int nodeLevel(const std::vector<skipNode*>& val);
	skipNode * makeNode(int key, std::string val, int level);

	// data members
	fload probability;
	int maxLevel;
};

