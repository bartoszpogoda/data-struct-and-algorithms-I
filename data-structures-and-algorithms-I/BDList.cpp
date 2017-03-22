#include "BDList.h"
#include <time.h>      
#include <string>


void BDList::addElementAt(type element, int position) {
	// could hold some size variable and then based on position/size iterate from head or tail
	BDListNode* newNode = new BDListNode(element);
	if (position < 0) position = 0;

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		return;
	}

	BDListNode* iterator = head;

	while (iterator->getNext() != nullptr && position--) {
		iterator = iterator->getNext();
	}

	if (iterator->getPrev() == nullptr) {
		iterator->setPrev(newNode);
		newNode->setNext(iterator);
		head = newNode;
		return;
	}

	if (iterator->getNext() == nullptr && position != 0) {
		iterator->setNext(newNode);
		newNode->setPrev(iterator);
		tail = newNode;
		return;
	}

	iterator->getPrev()->setNext(newNode);
	newNode->setNext(iterator);
	newNode->setPrev(iterator->getPrev());
	iterator->setPrev(newNode);

}

void BDList::addElementFront(type element) {
	BDListNode* newNode = new BDListNode(element);
	
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->setNext(head);
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

	//int position = rand() % currentSize;
	//addElementAt(element, position);
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
	} else if (iterator->getPrev() == nullptr) {
		if (iterator->getNext() != nullptr) {
			iterator->getNext()->setPrev(nullptr);
			head = iterator->getNext();
		}
		else {
			tail = head = nullptr;
		}
		
	} else {
		iterator->getNext()->setPrev(iterator->getPrev());
		iterator->getPrev()->setNext(iterator->getNext());
	}

	delete iterator;
	currentSize--;
}

void BDList::deleteElementFront() {
	if (head == nullptr) {
		return;
	}

	head = head->getNext();
	delete head->getPrev();
	head->setPrev(nullptr);
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
