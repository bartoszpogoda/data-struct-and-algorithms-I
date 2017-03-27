#include "BRTree.h"
#include <iostream>
#include <iomanip>

void BRTree::rotateLeft(BRTreeNode * A) {
	if (A == nullptr || A->getRightChild() == nullptr)
		return;

	BRTreeNode* B = A->getRightChild();

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

BRTreeNode * BRTree::min(BRTreeNode * node) {
	while (node->getLeftChild() != nullptr) {
		node = node->getLeftChild();
	}
	return node;
}

BRTreeNode * BRTree::max(BRTreeNode * node) {
	while (node->getRightChild() != nullptr) {
		node = node->getRightChild();
	}
	return node;
}

BRTreeNode * BRTree::successor(BRTreeNode * node) {
	if (node->getRightChild() == nullptr) {

		BRTreeNode* parent = node->getParent();
		while (parent != nullptr && parent->getLeftChild() != node) {
			node = parent;
			parent = parent->getParent();
		} 
		return parent;
	}
	else
		return min(node->getRightChild());

}

BRTreeNode * BRTree::predecessor(BRTreeNode * node) {
	if (node->getLeftChild() == nullptr) {

		BRTreeNode* parent = node->getParent();
		while (parent != nullptr && parent->getRightChild() != node) {
			node = parent;
			parent = parent->getParent();
		}
		return parent;
	}
	else
		return max(node->getLeftChild());
}

void BRTree::add(BRTreeNode * node) {
	BRTreeNode* parent = nullptr;
	BRTreeNode* iterator = root;
	node->setRed(); // new node should be initially red 

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

	fix(node);
}

void BRTree::fix(BRTreeNode * node) { 
	if (node == root && node->isRed()) // root should be black
		node->setBlack();
	else {
		if (node->getParent()->isRed()) { // parent is also red - can't be
		// red parent means that was not the root so parent->getParent() shouldnt return null
	
		bool parentIsLeftChild = node->getParent()->getParent()->getLeftChild() == node->getParent();
		// find uncle
		BRTreeNode* uncle = parentIsLeftChild ?  node->getParent()->getParent()->getRightChild() : node->getParent()->getParent()->getLeftChild();
		if (uncle != nullptr && uncle->isRed()) { // uncle also red case
			// change parent and uncle color to black, grandpa to red
			node->getParent()->setBlack();
			uncle->setBlack();
			uncle->getParent()->setRed();
			// fix further
			fix(uncle->getParent());
		} 
		else { // uncle is black (null is also black)
			if (parentIsLeftChild && node->getParent()->getRightChild() == node) { // uncle black and node is right child
				rotateLeft(node->getParent()); // rotate left on parent
				node = node->getLeftChild();
			}
			else if (!parentIsLeftChild && node->getParent()->getLeftChild() == node) {
				rotateRight(node->getParent());
				node = node->getRightChild();
			}

			if (parentIsLeftChild) {
				rotateRight(node->getParent()->getParent());
				node->getParent()->setBlack();
				//if (node->getParent()->getRightChild() != nullptr) // should not be needed
				node->getParent()->getRightChild()->setRed();
			}
			else {
				rotateLeft(node->getParent()->getParent());
				node->getParent()->setBlack();
				//if (node->getParent()->getLeftChild() != nullptr) // should not be needed
				node->getParent()->getLeftChild()->setRed();
			}
		}
		}
	}
}

void BRTree::rotateRight(BRTreeNode * A) {
	if (A == nullptr || A->getLeftChild() == nullptr)
		return;
	
	BRTreeNode* B = A->getLeftChild();

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
