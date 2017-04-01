#include "BSTree.h"
#include <iostream>
#include <iomanip>

void BSTree::rotateRight(BSTreeNode * A) {
	if (A == nullptr || A->getLeftChild() == nullptr)
		return;

	BSTreeNode* B = A->getLeftChild();

	// change B parent
	B->setParent(A->getParent());
	if (A->getParent() == nullptr)
		root = B;
	else {
		if (A->getParent()->getRightChild() == A) {
			A->getParent()->setRightChild(B);
		}
		else
			A->getParent()->setLeftChild(B);
	}

	// change A parent
	A->setParent(B);

	// transfer BR to AL - ok with nullptr
	A->setLeftChild(B->getRightChild());

	// change BR parent if it exists
	if (A->getLeftChild() != nullptr)
		A->getLeftChild()->setParent(A);

	// set A as B right child
	B->setRightChild(A);
}

void BSTree::rotateLeft(BSTreeNode * A) {
	if (A == nullptr || A->getRightChild() == nullptr)
		return;

	BSTreeNode* B = A->getRightChild();

	// change B parent
	B->setParent(A->getParent());
	if (A->getParent() == nullptr)
		root = B;
	else {
		if (A->getParent()->getRightChild() == A) {
			A->getParent()->setRightChild(B);
		}
		else
			A->getParent()->setLeftChild(B);
	}

	// change A parent
	A->setParent(B);

	// transfer BL to AR - ok with nullptr
	A->setRightChild(B->getLeftChild());

	// change BL parent if it exists
	if(A->getRightChild() != nullptr)
		A->getRightChild()->setParent(A);

	// set A as B left child
	B->setLeftChild(A);
}

BSTreeNode * BSTree::min(BSTreeNode * node) {
	while (node->getLeftChild() != nullptr) {
		node = node->getLeftChild();
	}
	return node;
}

BSTreeNode * BSTree::max(BSTreeNode * node) {
	while (node->getRightChild() != nullptr) {
		node = node->getRightChild();
	}
	return node;
}

BSTreeNode * BSTree::successor(BSTreeNode * node) {
	if (node->getRightChild() == nullptr) {

		BSTreeNode* parent = node->getParent();
		while (parent != nullptr && parent->getLeftChild() != node) {
			node = parent;
			parent = parent->getParent();
		} 
		return parent;
	}
	else
		return min(node->getRightChild());

}

BSTreeNode * BSTree::predecessor(BSTreeNode * node) {
	if (node->getLeftChild() == nullptr) {

		BSTreeNode* parent = node->getParent();
		while (parent != nullptr && parent->getRightChild() != node) {
			node = parent;
			parent = parent->getParent();
		}
		return parent;
	}
	else
		return max(node->getLeftChild());
}

BSTreeNode * BSTree::findNode(type value) {
	BSTreeNode* iterator = root;
	if (iterator == nullptr)
		return nullptr;

	while (iterator->getData() != value) {
		if (iterator->getData() < value) {
			if (iterator->getRightChild() == nullptr)
				return nullptr;
			else
				iterator = iterator->getRightChild();
		}
		else {
			if (iterator->getLeftChild() == nullptr)
				return nullptr;
			else
				iterator = iterator->getLeftChild();
		}
	}
	return iterator;
}

void BSTree::add(BSTreeNode * node) {
	BSTreeNode* parent = nullptr;
	BSTreeNode* iterator = root;

	while (iterator != nullptr) {
		parent = iterator;

		if (node->getData() < iterator->getData())
			iterator = iterator->getLeftChild();
		else
			iterator = iterator->getRightChild();
	}

	node->setParent(parent);

	if (parent == nullptr) { // tree was empty
		root = node;
	}
	else {
		if (node->getData() < parent->getData())
			parent->setLeftChild(node);
		else
			parent->setRightChild(node);
	}

}

bool BSTree::find(type value) {
	BSTreeNode* iterator = root;
	if (iterator == nullptr)
		return false;

	while (iterator->getData() != value) {
		if (iterator->getData() < value) {
			if (iterator->getRightChild() == nullptr)
				return false;
			else
				iterator = iterator->getRightChild();
		}
		else {
			if (iterator->getLeftChild() == nullptr)
				return false;
			else
				iterator = iterator->getLeftChild();
		}
	}
	return true;
}

