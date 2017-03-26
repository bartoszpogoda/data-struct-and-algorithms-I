#pragma once
#include "BDListNode.h"
#include "Type.h"
#include <iostream>

class BDList {
	BDListNode* head;
	BDListNode* tail;
	int currentSize;

public:
	BDList() : currentSize(0), head(nullptr), tail(nullptr) {} 
	~BDList();

	int size() { return currentSize; }

	BDListNode* getHead() { return head; }
	void setHead(BDListNode* head) { this->head = head; }
	BDListNode* getTail() { return tail; }
	void setTail(BDListNode* tail) { this->tail = tail; }

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