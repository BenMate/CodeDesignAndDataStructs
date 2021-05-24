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

	LinkedList()
	{
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
		// TODO
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
		// TODO
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
		// TODO
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


	Node* FirstNode() { return m_first; }
	Node* LastNode() { return m_last; }


protected:
private:
	Node* m_first = nullptr;
	Node* m_last = nullptr;
};

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
}