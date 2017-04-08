#pragma once

#include "Type.h"
#include "BSTreeNode.h"

class BSTree {
	BSTreeNode* root;
	int nodeCounter;

	void rotateRight(BSTreeNode* node);
	void rotateLeft(BSTreeNode* node);

	BSTreeNode* min(BSTreeNode* node);
	BSTreeNode* max(BSTreeNode* node);

	BSTreeNode* successor(BSTreeNode* node);
	BSTreeNode* predecessor(BSTreeNode* node);
	BSTreeNode* findNode(type value);

	void straighten();
	void balance();

	void addNode(BSTreeNode* node);
	void removeNode(BSTreeNode* node);
public:
	BSTree() : root(nullptr), nodeCounter(0) {}
	BSTreeNode* getRoot() { return root; }
	bool isEmpty() { return root == nullptr;  }

	void add(type value) { addNode(new BSTreeNode(value)); }
	bool remove(type value);
	bool find(type value) { return findNode(value) != nullptr; }

	bool rotateLeftAt(type value);
	bool rotateRightAt(type value);
	void performDSW();
};