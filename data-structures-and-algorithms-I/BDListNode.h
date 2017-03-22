#pragma once
#include "Type.h"

class BDListNode {
	BDListNode* prev;
	BDListNode* next;
	type data;

public:
	BDListNode(type data) : data(data), prev(nullptr), next(nullptr) {}

	BDListNode* getPrev() { return prev; }
	void setPrev(BDListNode* prev) { this->prev = prev; }

	BDListNode* getNext() { return next; }
	void setNext(BDListNode* next) { this->next = next; }

	type getData() { return data; }
	void setData(type data) { this->data = data; }

};