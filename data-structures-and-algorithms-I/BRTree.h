#pragma once

#include "Type.h"
#include "BRTreeNode.h"

class BRTree {
	BRTreeNode* root;

	void rotateRight(BRTreeNode* node);
	void rotateLeft(BRTreeNode* node);

	BRTreeNode* min(BRTreeNode* node);
	BRTreeNode* max(BRTreeNode* node);

	BRTreeNode* successor(BRTreeNode* node);
	BRTreeNode* predecessor(BRTreeNode* node);
	BRTreeNode* findNode(type value);

	void add(BRTreeNode* node);
	void fixAdd(BRTreeNode* node);
public:
	BRTreeNode* getRoot() { return root; }

	void add(type value) { add(new BRTreeNode(value)); }
	bool find(type value);
};