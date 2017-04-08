#pragma once
#include "BDListNode.h"
#include "Type.h"
#include <iostream>

class BDList {
	BDListNode* head;
	BDListNode* tail;
	int currentSize;

	void addEnd(BDListNode* node);

public:
	BDList() : currentSize(0), head(nullptr), tail(nullptr) {} 
	BDList(BDListNode** nodes, int size);
	~BDList();

	int size() { return currentSize; }

	void addAt(type element, int position);
	void addFront(type element);
	void addEnd(type element);
	void addRandom(type element);

	void deleteAt(int position);
	void deleteFront();
	void deleteEnd();
	void deleteRandom();

	int find(type element);
	type get(int position);

	std::string toString();
};