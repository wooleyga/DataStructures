#include "LinkedList.hpp"

LinkedList::LinkedList() : head(NULL), size(0) {}

LinkedList::~LinkedList()
{
	Node* current;
	current = head;
	while (current != NULL)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}
}

void LinkedList::add(int x)
{
	if (head == NULL)
		head = new Node(x);
	else
	{
		Node* current;
		current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = new Node(x);
	}
	++size;
}

bool LinkedList::remove(int x)
{
	Node* current;
	current = head;
	while (current->next != NULL)
	{
		if (current->val == x)
		{
			current->val = current->next->val;
			current->next = current->next->next;
			--size;
			return true;
		}
		current = current->next;
	}

	if (current->val == x)
	{
		current = NULL;
		--size;
		return true;
	}

	return false;
}

bool LinkedList::contains(int x)
{
	Node* current;
	current = head;
	while (current->next != NULL)
	{
		if (current->val == x)
			return true;
		current = current->next;
	}
	if (current->val == x)
		return true;

	return false;
}

int LinkedList::get(int index)
{
	if (index < 0 || index >= size)
		throw "Index out of bounds.";

	Node* current;
	current = head;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}
	return current->val;
}

int LinkedList::getSize()
{
	return size;
}

bool LinkedList::isEmpty()
{
	return size == 0;
}

std::ostream& operator<<(std::ostream& os, const LinkedList & list)
{
	LinkedList::Node* current;
	current = list.head;
	while (current != NULL)
	{
		os << current->val << " ";
		current = current->next;
	}

	return os;
}
