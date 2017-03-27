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
