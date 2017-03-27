#pragma once

#include "Type.h"
#include "BRTreeNode.h"

class BRTree {
	BRTreeNode* root;
public:
	BRTreeNode* getRoot() { return root; }

	// public for test
	void rotateRight(BRTreeNode* node);
	void rotateLeft(BRTreeNode* node);

};