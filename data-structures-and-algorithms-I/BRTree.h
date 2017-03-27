#pragma once

#include "Type.h"
#include "BRTreeNode.h"

class BRTree {
	BRTreeNode* root;
public:
	// public for test
	void rotateRight(BRTreeNode* node);
	void rotateLeft(BRTreeNode* node);

	void postorder(BRTreeNode* p, int indent = 0); //stack do napisania
};