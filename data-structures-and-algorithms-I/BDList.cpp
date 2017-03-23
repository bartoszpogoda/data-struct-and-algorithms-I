#include "BDList.h"
#include <time.h>      
#include <string>


BDList::~BDList() {
	if (head == nullptr)
		return;

	BDListNode* iterator = tail;

	while (iterator->getPrev() != nullptr) {
		iterator = iterator->getPrev();
		delete iterator->getNext();
	}

	delete iterator;
}

void BDList::addElementAt(type element, int position) {
	if (position <= 0)
		addElementFront(element);
	else if (position >= currentSize)
		addElementEnd(element);
	else {
		BDListNode* newNode = new BDListNode(element);
		BDListNode* iterator;

		if (position < currentSize / 2) {
			iterator = head;

			while (position--) {
				iterator = iterator->getNext();
			}
		}
		else {
			iterator = tail;
	
			position = currentSize - position - 1;
			while (position--) {
				iterator = iterator->getPrev();
			}
		}

		iterator->getPrev()->setNext(newNode);
		newNode->setNext(iterator);
		newNode->setPrev(iterator->getPrev());
		iterator->setPrev(newNode);

		currentSize++;
	}
}

void BDList::addElementFront(type element) {
	BDListNode* newNode = new BDListNode(element);
	
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->setNext(head);
		head->setPrev(newNode);
		head = newNode;
	}
	currentSize++;
}

void BDList::addElementEnd(type element) {
	BDListNode* newNode = new BDListNode(element);

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->setNext(newNode);
		newNode->setPrev(tail);
		tail = newNode;
	}
	currentSize++;
}

void BDList::addElementRandom(type element) {
	srand(time(NULL));

	int position = rand() % currentSize;
	addElementAt(element, position);
}

void BDList::deleteElementAt(int position) {
	if (position == 0)
		deleteElementFront();
	else if (position == currentSize - 1)
		deleteElementEnd();
	else if (position < 0 || position >= currentSize)
		return;
	else {
		BDListNode* iterator;

		if (position < currentSize / 2) {
			iterator = head;

			while (position--) {
				iterator = iterator->getNext();
			}
		}
		else {
			iterator = tail;

			position = currentSize - position - 1;
			while (position--) {
				iterator = iterator->getPrev();
			}
		}

		iterator->getNext()->setPrev(iterator->getPrev());
		iterator->getPrev()->setNext(iterator->getNext());

		delete iterator;
		currentSize--;
	}
}

void BDList::deleteElementFront() {
	if (head == nullptr) {
		return;
	}
	if (head->getNext() == nullptr) {
		delete head;
		head = nullptr;
	}
	else {
		head = head->getNext();
		delete head->getPrev();
		head->setPrev(nullptr);
	}
	
	currentSize--;
}

void BDList::deleteElementEnd() {

	if (head == nullptr) {
		return;
	}

	tail = tail->getPrev();
	delete tail->getNext();
	tail->setNext(nullptr);
	currentSize--;
}

void BDList::deleteElementRandom() {
	srand(time(NULL));

	int position = rand() % currentSize;
	deleteElementAt(position);
}

int BDList::findElement(type element) {
	BDListNode* iterator = head;
	int indexCounter = 0;
	while (iterator->getNext() != nullptr && iterator->getData() != element) {
		iterator = iterator->getNext();
		indexCounter++;
	}

	if (iterator->getData() == element)
		return indexCounter;
	else return -1;
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
