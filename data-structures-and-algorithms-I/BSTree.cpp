#include "BSTree.h"
#include <math.h>

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

void BSTree::straighten() {
	BSTreeNode* iterator = root;

	while (iterator != nullptr) {
		while (iterator->getLeftChild() != nullptr) {
			rotateRight(iterator);
			iterator = iterator->getParent();
		}
		iterator = iterator->getRightChild();
	}
}

void BSTree::balance(){
	int m = pow(2, (int)log2(nodeCounter + 1)) - 1;

	BSTreeNode* iterator = root;
	for (int i = 0; i < nodeCounter - m; i++) {
		// nodeCounter - m  rotations
		rotateLeft(iterator);
		iterator = iterator->getParent()->getRightChild();
	}

	while (m > 1) {
		m = m / 2;
		iterator = root;
		for (int i = 0; i < m; i++) {
			// m  rotations
			rotateLeft(iterator);
			iterator = iterator->getParent()->getRightChild();
		}
	}
}

void BSTree::addNode(BSTreeNode * node) {
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

	nodeCounter++;
}

void BSTree::removeNode(BSTreeNode * node) {
	if (node->getLeftChild() != nullptr && node->getRightChild() != nullptr) {	// both childs

		BSTreeNode* succ = successor(node);
		node->setData(succ->getData());
		removeNode(succ);
		return;
	} 
	else if (node->getLeftChild() != nullptr) { // only left child

		if (node->getParent() == nullptr)
			root = node->getLeftChild();
		else if (node->getParent()->getLeftChild() == node)
			node->getParent()->setLeftChild(node->getLeftChild());
		else
			node->getParent()->setRightChild(node->getLeftChild());

		node->getLeftChild()->setParent(node->getParent());
		delete node;
	}
	else if (node->getRightChild() != nullptr) { // only right child

		if (node->getParent() == nullptr)
			root = node->getRightChild();
		else if (node->getParent()->getLeftChild() == node)
			node->getParent()->setLeftChild(node->getRightChild());
		else
			node->getParent()->setRightChild(node->getRightChild());

		node->getRightChild()->setParent(node->getParent());
		delete node;
	}
	else {	// node is a leaf

		if (node->getParent() == nullptr)
			root = nullptr;
		else if (node->getParent()->getLeftChild() == node)
			node->getParent()->setLeftChild(nullptr);
		else
			node->getParent()->setRightChild(nullptr);

		delete node;
	}

	nodeCounter--;
}

bool BSTree::remove(type value) {
	BSTreeNode* node = findNode(value);

	if (node == nullptr)
		return false;
	
	removeNode(node);
	return true;
}

bool BSTree::rotateLeftAt(type value) {
	BSTreeNode* node = findNode(value);
	if (node == nullptr)
		return false;
	
	rotateLeft(node);
	return true;
}

bool BSTree::rotateRightAt(type value) {
	BSTreeNode* node = findNode(value);
	if (node == nullptr)
		return false;

	rotateRight(node);
	return true;
}

void BSTree::performDSW() {
	if (root == nullptr)
		return;

	straighten();
	balance();
}
