#include "LinkedStack.hpp"

LinkedStack::LinkedStack() : top(NULL), size(0){}

LinkedStack::~LinkedStack()
{
	Node* current;
	current = top;
	while (current != NULL)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}
}

void LinkedStack::push(int x)
{
	if (top == NULL)
		top = new Node(x);
	else {
		Node* newTop = new Node(x);
		newTop->next = top;
		top = newTop;
	}
	++size;
}

int LinkedStack::pop()
{
	if (size == 0)
		throw new EmptyStackException;

	int poppedVal = top->val;
	top = top->next;
	--size;

	return poppedVal;
}

int LinkedStack::peek()
{
	if (size == 0)
		throw new EmptyStackException;

	return top->val;
}

int LinkedStack::getSize()
{
	return size;
}

bool LinkedStack::isEmpty()
{
	return size == 0;
}
