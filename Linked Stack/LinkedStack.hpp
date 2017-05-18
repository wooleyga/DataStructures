#ifndef _LINKEDSTACK_HPP_
#define _LINKEDSTACK_HPP_

#pragma once
#include <iostream>
#include <exception>

class LinkedStack {
public:
	LinkedStack();
	~LinkedStack();
	void push(int x);
	int pop();
	int peek();
	int getSize();
	bool isEmpty();

	class EmptyStackException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Empty Stack Exception\n";
		}
	};

private:
	struct Node {
		int val;
		Node* next;
		Node(int x) : val(x), next(NULL) {}
	};
	Node* top;
	int size;
};

#endif