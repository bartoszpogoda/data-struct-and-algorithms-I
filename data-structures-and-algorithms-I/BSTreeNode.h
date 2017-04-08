#pragma once
#include "Type.h"

class BSTreeNode {
	BSTreeNode* parent;
	BSTreeNode* leftChild;
	BSTreeNode* rightChild;

	type data;
public:
	BSTreeNode(type data) : data(data), parent(nullptr), leftChild(nullptr), rightChild(nullptr) {}

	BSTreeNode* getParent() { return parent; }
	void setParent(BSTreeNode* parent) { this->parent = parent; }

	BSTreeNode* getLeftChild() { return leftChild; }
	void setLeftChild(BSTreeNode* leftChild) { this->leftChild = leftChild; }

	BSTreeNode* getRightChild() { return rightChild; }
	void setRightChild(BSTreeNode* rightChild) { this->rightChild = rightChild; }

	type getData() { return data; }
	void setData(type data) { this->data = data; }
};