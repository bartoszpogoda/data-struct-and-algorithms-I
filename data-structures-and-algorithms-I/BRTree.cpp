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

	// change BL parent
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

	// change BR parent
	A->getLeftChild()->setParent(A);

	// set A as B right child
	B->setRightChild(A);
}

void BRTree::postorder(BRTreeNode* p, int indent)
{
	if (p != NULL) {
		if (p->getLeftChild()) postorder(p->getLeftChild(), indent + 4);
		if (p->getRightChild()) postorder(p->getRightChild(), indent + 4);
		if (indent) {
			std::cout << std::setw(indent) << ' ';
		}
		std::cout << p->getData() << "\n ";
	}
}