#pragma once

#include "Type.h"
#include "BSTreeNode.h"

class BSTree {
	BSTreeNode* root;

	void rotateRight(BSTreeNode* node);
	void rotateLeft(BSTreeNode* node);

	BSTreeNode* min(BSTreeNode* node);
	BSTreeNode* max(BSTreeNode* node);

	BSTreeNode* successor(BSTreeNode* node);
	BSTreeNode* predecessor(BSTreeNode* node);
	BSTreeNode* findNode(type value);

	void add(BSTreeNode* node);
public:
	BSTreeNode* getRoot() { return root; }

	void add(type value) { add(new BSTreeNode(value)); }
	bool find(type value);
};