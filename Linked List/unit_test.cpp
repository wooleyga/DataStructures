#include <iostream>
#include <cassert>
#include "LinkedList.hpp"

void addTest(LinkedList& list);
void getTest(LinkedList& list);
void removeTest(LinkedList& list);

int main()
{
	LinkedList testList;

	addTest(testList);
	getTest(testList);
	removeTest(testList);

	std::cout << testList << std::endl;

	return 0;
}

void addTest(LinkedList& list)
{
	assert(list.getSize() == 0);
	list.add(1);
	assert(list.getSize() == 1);
	assert(list.contains(1));
	list.add(3);
	list.add(5);
	list.add(7);
	list.add(9);
	list.add(11);
	assert(list.contains(11));
	assert(list.getSize() == 6);
}

void getTest(LinkedList& list)
{
	assert(list.get(0) == 1);
	assert(list.get(1) == 3);
	assert(list.get(2) == 5);
	assert(list.get(5) == 11);
}

void removeTest(LinkedList& list)
{
	assert(list.remove(1));
	assert(!list.contains(1));
	assert(!list.remove(2));
	assert(list.remove(7));
	assert(list.getSize() == 4);
}