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

	int size() { return currentSize; }

	BDListNode* getHead() { return head; }
	void setHead(BDListNode* head) { this->head = head; }
	BDListNode* getTail() { return tail; }
	void setTail(BDListNode* tail) { this->tail = tail; }

	void addElementAt(type element, int position);
	void addElementFront(type element);
	void addElementEnd(type element);
	void addElementRandom(type element);

	void deleteElementAt(int position);
	void deleteElementFront();
	void deleteElementEnd();
	void deleteElementRandom();

	int findElement(type element);

	std::string toString();
};