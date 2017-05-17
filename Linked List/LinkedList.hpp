#ifndef _LINKEDLIST_HPP_
#define _LINKEDLIST_HPP_

#include <iostream>

class LinkedList {
public:
	LinkedList();
	~LinkedList();
	void add(int x);
	bool remove(int x);
	bool contains(int x);
	int getSize();
	friend std::ostream& operator<< (std::ostream& stream, const LinkedList& list);
private:
	struct Node{
		int val;
		Node* next;
		Node(int x) : val(x), next(NULL) {}
	};
	Node* head;
	int size;
};

#endif