#pragma once
#include<iostream>
using namespace std;

template<class T>
class Node {
public:
	T data;
	Node* next;

	Node() :next(NULL) {
	}
};

template<class T>
class Stack {
	Node<T>* top;

public:
	Stack(int ignored = 0) :top(NULL) {
	}

	bool isEmpty() {
		if (top == NULL) {
			return true;
		}
		return false;
	}

	Node<T>* getTop() {
		return top;
	}

	T TOP() {
		return top->data;
	}

	void push(T dataItem) {
		Node<T>* temp = new Node<T>;
		temp->data = dataItem;
		temp->next = top;
		top = temp;
	}

	T pop() {
		if (!isEmpty()) {
			T data = top->data;
			Node<T>* temp = top;
			top = top->next;
			delete temp;
			return data;
		}
	}

	void clear() {
		while (top != NULL) {
			pop();
		}
	}

	~Stack() {
		clear();
	}
};