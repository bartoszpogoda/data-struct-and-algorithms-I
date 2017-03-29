#pragma once
#include "Type.h"

class BRTreeNode {
	BRTreeNode* parent;
	BRTreeNode* leftChild;
	BRTreeNode* rightChild;

	type data;
	bool black;

public:
	BRTreeNode(type data) : data(data), parent(nullptr), leftChild(nullptr), rightChild(nullptr) {}

	BRTreeNode* getParent() { return parent; }
	void setParent(BRTreeNode* parent) { this->parent = parent; }

	BRTreeNode* getLeftChild() { return leftChild; }
	void setLeftChild(BRTreeNode* leftChild) { this->leftChild = leftChild; }

	BRTreeNode* getRightChild() { return rightChild; }
	void setRightChild(BRTreeNode* rightChild) { this->rightChild = rightChild; }

	bool isBlack() { return black; }
	void setBlack() { black = true; }

	bool isRed() { return !black; }
	void setRed() { black = false; }

	bool getColor() { return black; }
	void setColor(bool black) { this->black = black; }

	void changeColor() { black = !black; }

	type getData() { return data; }
	void setData(type data) { this->data = data; }
};