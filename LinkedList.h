#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include <stdio.h>
#include <limits>

class LinkedList {
	private:
		Node* m_head;
	public:
		LinkedList();
		LinkedList(int nums[], int size);
		void addFront(int newItem);
		void addEnd(int newItem);
		void addAtPosition(int position, int newItem);
		int search(int item);
		void deleteFront();
		void deleteEnd();
		void deletePosition(int position);
		int getItem(int position);
		void printItems();
		~LinkedList();

};

#endif