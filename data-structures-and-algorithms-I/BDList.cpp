#include "BDList.h"
#include <string>

void BDList::addElementAt(type element, int position) {
	// could hold some size variable and then based on position/size iterate from head or tail
	BDListNode* newNode = new BDListNode(element);

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		return;
	}

	BDListNode* iterator = head;

	while (iterator->getNext() != nullptr && --position) {
		iterator = iterator->getNext();
	}

	if (iterator->getNext() == nullptr) {
		iterator->setNext(newNode);
		newNode->setPrev(iterator);
		tail = newNode;
		return;
	}

	iterator->getNext()->setPrev(newNode);
	newNode->setNext(iterator->getNext());
	newNode->setPrev(iterator);
	iterator->setNext(newNode);

}

void BDList::addElementFront(type element) {
	BDListNode* newNode = new BDListNode(element);
	
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		return;
	}

	newNode->setNext(head);
	head = newNode;
}

void BDList::addElementEnd(type element) {
	BDListNode* newNode = new BDListNode(element);

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		return;
	}

	tail->setNext(newNode);
	newNode->setPrev(tail);
	tail = newNode;
}

void BDList::addElementRandom(type element)
{
}

void BDList::deleteElementAt(int position) {
	// could hold some size variable and then based on position/size iterate from head or tail

	if (head == nullptr) {
		return;
	}

	BDListNode* iterator = head;

	while (iterator->getNext() != nullptr && position--) {
		iterator = iterator->getNext();
	}

	if (iterator->getNext() == nullptr) {
		if (iterator->getPrev() != nullptr) {
			iterator->getPrev()->setNext(nullptr);
			tail = iterator->getPrev();
		}
		else {
			tail = head = nullptr;
		}
		delete iterator;

		return;
	}

	if (iterator->getPrev() == nullptr) {
		if (iterator->getNext() != nullptr) {
			iterator->getNext()->setPrev(nullptr);
			head = iterator->getNext();
		}
		else {
			tail = head = nullptr;
		}
		
		delete iterator;

		return;
	}

	iterator->getNext()->setPrev(iterator->getPrev());
	iterator->getPrev()->setNext(iterator->getNext());
	delete iterator;
}

void BDList::deleteElementFront() {
	if (head == nullptr) {
		return;
	}

	head = head->getNext();
	delete head->getPrev();
	head->setPrev(nullptr);
}

void BDList::deleteElementEnd() {

	if (head == nullptr) {
		return;
	}

	tail = tail->getPrev();
	delete tail->getNext();
	tail->setNext(nullptr);
}

void BDList::deleteElementRandom()
{
}

int BDList::findElement(type element)
{
	return 0;
}
/**
 format: [32 <-> 23 <-> 32 <-> 32]
*/
std::string BDList::toString() {
	std::string result = "[";

	if (head == nullptr) {
		result += "empty]";
		return result;
	} else {
		result += std::to_string(head->getData());
	}

	BDListNode* iterator = head;

	while (iterator->getNext() != nullptr) {
		iterator = iterator->getNext();
		result += " <-> " + std::to_string(iterator->getData());
	}

	result += "]";

	return result;
}
