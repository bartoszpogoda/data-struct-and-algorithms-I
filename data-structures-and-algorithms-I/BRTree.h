#pragma once

#include "Type.h"
#include "BRTreeNode.h"

class BRTree {
	BRTreeNode* root;
public:
	BRTreeNode* getRoot() { return root; }
	void add(type value) { add(new BRTreeNode(value)); }

	// public for test
	void rotateRight(BRTreeNode* node);
	void rotateLeft(BRTreeNode* node);

	BRTreeNode* min(BRTreeNode* node);
	BRTreeNode* max(BRTreeNode* node);

	BRTreeNode* successor(BRTreeNode* node);
	BRTreeNode* predecessor(BRTreeNode* node);

	void add(BRTreeNode* node);

	void fix(BRTreeNode* node);

	// temp for test
	void setRoot(BRTreeNode* root) { this->root = root; }
};