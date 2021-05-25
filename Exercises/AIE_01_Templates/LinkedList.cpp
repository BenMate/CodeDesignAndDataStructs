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
		}
		else {
			m_first = n;
			m_last = n;
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
			delete n;
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
		}
		else {
			m_first = n;
			m_last = n;
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
			delete n;
		}
	}

	void clear() {

	}

	void remove() {

	}

	void add() {

	}

	Iterator begin() { return Iterator(m_first); }
	Iterator end() { return Iterator(nullptr); }

	Node* FirstNode() { return m_first; }
	Node* LastNode() { return m_last; }

protected:
private:
	Node* m_first = nullptr;
	Node* m_last = nullptr;
};