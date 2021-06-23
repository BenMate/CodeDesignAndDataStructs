#pragma once
#include <iostream>

template<class T>
class LinkedList
{
public:
	struct Node
	{
		T value;
		Node* next = nullptr;
		Node* prev = nullptr;
	};

	struct Iterator
	{
		Node* node = nullptr;

		// Constructors
		Iterator() : node(nullptr) {}
		Iterator(Node* node) : node(node) {}

		// Increment operators
		Iterator& operator ++ () { return Next(); }
		Iterator operator ++ (int) { return Next(); }

		// Decrement operators
		Iterator operator -- () { return Prev(); }
		Iterator operator -- (int) { return Prev(); }

		// Equality chek operators
		bool operator == (const Iterator& rhs) { return node == rhs.node; }
		bool operator != (const Iterator& rhs) { return node != rhs.node; }

		// Dereference operators
		T& operator * () { return node->value; }
		T* operator -> () { return &node->value; }

		// Move to the next value
		Iterator& Next()
		{
			if (node != nullptr)
				node = node->next;

			return *this;
		}

		// move to the previous value
		Iterator& Prev()
		{
			if (node != nullptr)
				node = node->prev;

			return *this;
		}
	};

	LinkedList()
	{
	}

	LinkedList(std::initializer_list<T> list) {
		for (auto iter = list.begin(); iter != list.end(); iter++)
			PushBack(*iter);
	}

	~LinkedList()
	{
	}

	void PushBack(T value)
	{
		Node* n = new Node();
		n->value = value;

		if (m_first != nullptr && m_last != nullptr) {
			n->prev = m_last;
			m_last->next = n;
			m_last = n;
			m_count++;
		}
		else {
			m_first = n;
			m_last = n;
			m_count++;
		}

	}

	void PopBack()
	{
		if (m_last != nullptr)
		{
			auto* n = m_last;
			if (m_last->prev != nullptr)
			{
				m_last->prev->next = nullptr;
			}

			m_last = m_last->prev;

			if (m_last == nullptr)
			{
				m_first = nullptr;
			}

			delete n;

			m_count--;
		}
	}

	void PushFront(T value)
	{
		Node* n = new Node();
		n->value = value;

		if (m_first != nullptr && m_last != nullptr) {
			n->next = m_first;
			m_first->prev = n;
			m_first = n;
			m_count++;
		}
		else {
			m_first = n;
			m_last = n;
			m_count++;
		}
	}

	void PopFront()
	{
		if (m_first != nullptr)
		{
			auto* n = m_first;
			if (m_first->next != nullptr)
			{
				m_first->next->prev = nullptr;
			}
			m_first = m_first->next;

			if (m_first == nullptr)
			{
				m_last = nullptr;
			}

			delete n;
		}
		m_count--;
	}

	void Clear() {
		Node* prevNode;
		LinkedList<T>::Node* newNode = m_last;
		while (newNode != nullptr)
		{
			prevNode = newNode->prev;
			delete newNode;
			newNode = prevNode;
		}
		m_first = nullptr;
		m_last = nullptr;
		m_count = 0;
	}

	void Sort() {
		//TODO
		bool isSorted = false;
		int lastUnsorted = Count() - 1;

		while (!isSorted)
		{
			LinkedList<T>::Node* nodeA = m_first;
			Node* nodeB = nodeA->next;
			isSorted = true;

			for (int i = 0; i < lastUnsorted; i++)
			{
				if (nodeA->value < nodeB->value)
				{
					T tmp = nodeA->value;
					nodeA->value = nodeB->value;
					nodeB->value = tmp;
					isSorted = false;
				}
				nodeA = nodeB;
				nodeB = nodeB->next;
			}
			lastUnsorted--;
		}
	}


	Iterator Search(const T& value) {
		return std::find(begin(), end(), value);
	}

	unsigned int Count() {
		return m_count;
	}

	bool IsEmpty() {
		return m_first == nullptr && m_last == nullptr;
	}

	Iterator Insert(Iterator iter, const T& value) {
		Node* nodeA = iter.node;

		Node* newNodeb = new Node();
		newNodeb->value = value;

		Node* nodeC = nodeA->next;

		if (iter.node == m_first) {
			PushFront(value);
		}
		else if (iter.node == m_last) {
			PushBack(value);
		}
		else {
			newNodeb->prev = nodeA;
			nodeC->prev = newNodeb;

			newNodeb->next = nodeC;
			nodeA->next = newNodeb;

			m_count++;
		}
		//return an iterator to the newly created node
		return Iterator(newNodeb);
	}

	Iterator Remove(Iterator iterator) {
		Node* node = iterator.node;

		if (iterator.node == m_first) {
			PopFront();
		}
		else if (iterator.node == m_last) {
			PopBack();
		}
		else {
			node->prev->next = node->next;
			node->next->prev = node->prev;
			delete node;
			m_count--;
		}
		return Iterator(iterator.node->next);
	}

	Iterator begin() { return Iterator(m_first); }
	Iterator end() { return Iterator(nullptr); }

	Node* FirstNode() { return m_first; }
	Node* LastNode() { return m_last; }

protected:
private:
	Node* m_first = nullptr;
	Node* m_last = nullptr;
	unsigned int m_count = 0;
};