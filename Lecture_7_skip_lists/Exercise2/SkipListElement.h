#pragma once
#include<vector>
#include<cstdlib>
using namespace std;

template<typename T>
class SkipListElement {
public:
	SkipListElement(const T& d = T(), size_t h=1) : data(d), height(h) {
		links = new SkipListElement*[height];
		for(size_t n=0; n<height; n++) links[n] = NULL;
	}
	
	~SkipListElement(void) {
		delete[] links;
	}
	
	T data;
	SkipListElement** links;
	size_t height;
};

