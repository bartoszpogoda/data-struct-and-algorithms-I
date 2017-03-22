#include "BDList.h"

void BDList::addElementAt(type element, int position) {
	BDListNode* newNode = new BDListNode(element);
	BDListNode* iterator = head;
	if (head == nullptr) {
		head = newNode;
		return;
	}

	while (iterator->getNext() != nullptr && position--) {
		iterator = iterator->getNext();
	}

	iterator->setNext(newNode);
}

void BDList::addElementFront(type element)
{
}

void BDList::addElementEnd(type element)
{
}

void BDList::addElementRandom(type element)
{
}

void BDList::deleteElementAt(int position)
{
}

void BDList::deleteElementFront()
{
}

void BDList::deleteElementEnd()
{
}

void BDList::deleteElementRandom()
{
}

int BDList::findElement(type element)
{
	return 0;
}

std::string BDList::toString()
{
	return std::string();
}
