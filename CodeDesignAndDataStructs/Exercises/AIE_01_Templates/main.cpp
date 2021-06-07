﻿#include <iostream>
#include "LinkedList.h"

int main(int argc, char** argv)
{
	LinkedList<int> myList;

	myList.PushBack(10);
	myList.PushBack(20);
	myList.PushBack(30);

	myList.PushFront(5);
	myList.PushFront(4);
	myList.PushFront(3);

	myList.PopFront(); // should remove 3
	myList.PopBack(); // should remove 30

	// loop through each node in the linked list
	// print its value
	LinkedList<int>::Node* iter = myList.FirstNode();
	while (iter != nullptr)
	{
		std::cout << iter->value << std::endl;
		iter = iter->next;
	}

	std::cout << std::endl << std::endl;

	// loop backward through the linked list - print its value
	LinkedList<int>::Node* rIter = myList.LastNode();
	while (rIter != nullptr)
	{
		std::cout << rIter->value << std::endl;
		rIter = rIter->prev;
	}

	std::cout << std::endl << std::endl;

	//creates a list
	LinkedList<int> NewList2 = { 10,20,30,40 };
	//example of remove
	auto iter2 = std::find(NewList2.begin(), NewList2.end(), 10);
	NewList2.Remove(iter2);

	NewList2.PopBack();
	NewList2.PopBack();
	NewList2.PopBack();

	//looping through and displays new list
	for (auto& iter2 : NewList2) {
		std::cout << iter2 << std::endl;
	}	
};