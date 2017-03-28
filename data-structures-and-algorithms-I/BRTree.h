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

	void add(BRTreeNode* node);
	void fix(BRTreeNode* node);
public:
	BRTreeNode* getRoot() { return root; }

	void add(type value) { add(new BRTreeNode(value)); }
	void remove(type value);
	void find(type value);
};