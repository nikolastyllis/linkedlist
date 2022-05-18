#include "LinkedList.h"

LinkedList::LinkedList()
{
	m_head = nullptr;
}

LinkedList::LinkedList(int nums[], int size)
{
	m_head = nullptr;

	for(int i=0;i<size;i++)
	{
		addEnd(nums[i]);
	}
}

void LinkedList::addFront(int newItem)
{
	Node* newNode = new Node(newItem, m_head);
	m_head = newNode;
}

void LinkedList::addEnd(int newItem)
{
	Node* currentNode = m_head;

	if(currentNode==nullptr)
	{
		Node* newNode = new Node(newItem, m_head);
		m_head = newNode;
		return;
	}

	while(currentNode->get_next()!=nullptr)
	{
		currentNode = currentNode->get_next();
	}

	Node* newNode = new Node(newItem, nullptr);
	currentNode->set_next(newNode);
}

void LinkedList::addAtPosition(int position, int newItem)
{
	if(position<=1)
	{
		addFront(newItem);
		return;
	}  

	Node* currentNode = m_head;
	Node* previousNode = m_head;
	currentNode = currentNode->get_next();

	int i=2;
	while(currentNode!=nullptr)
	{
		if(i==position)
		{
			Node* newNode = new Node(newItem, currentNode);
			previousNode->set_next(newNode);
			return;
		}

		previousNode = currentNode;
		currentNode = currentNode->get_next();
		i++;
	}

	addEnd(newItem);
}

int LinkedList::search(int item)
{
	if(m_head == nullptr)
	{
		printf("%d ", 0);
		return 0;
	}

	Node* currentNode = m_head;

	int i=1;
	while(currentNode!=nullptr)
	{
		if(currentNode->get_data() == item)
		{
			printf("%d ", i);
			return i;
		}

		i++;
		currentNode = currentNode->get_next();
	}

	printf("%d ", 0);
	return 0;
}

void LinkedList::deleteFront()
{
	if(m_head!=nullptr)
	{
		Node* temp = m_head;
		m_head = m_head->get_next();
		delete temp;
	}
}

void LinkedList::deleteEnd()
{
	if(m_head == nullptr) return;

	Node* previousNode;
	Node* currentNode = m_head;

	while(currentNode->get_next()!=nullptr)
	{
		previousNode = currentNode;
		currentNode = currentNode->get_next();
	}

	delete currentNode;
	previousNode->set_next(nullptr);
}

void LinkedList::deletePosition(int position)
{
	if(position<1 || m_head == nullptr)
	{
		printf("outside range");
		return;
	}  
	if(position==1) 
	{
		deleteFront();
		return;
	}

	Node* currentNode = m_head;
	Node* previousNode = m_head;

	currentNode = currentNode->get_next();

	int i=2;
	while(currentNode!=nullptr)
	{
		if(i==position)
		{
			previousNode->set_next(currentNode->get_next());
			delete currentNode;
			return;
		}

		previousNode = currentNode;
		currentNode = currentNode->get_next();
		i++;
	}

	printf("outside range");
	return;
}

int LinkedList::getItem(int position)
{
	if(position<1 || m_head == nullptr)
	{
		printf("%d ", std::numeric_limits<int>::max());
		return std::numeric_limits<int>::max();
	} 

	Node* currentNode = m_head;

	int i=1;
	while(currentNode!=nullptr)
	{
		if(i==position)
		{
			int item = currentNode->get_data();
			printf("%d ", item);
			return item;
		}

		currentNode = currentNode->get_next();
		i++;
	}

	printf("%d ", std::numeric_limits<int>::max());
	return std::numeric_limits<int>::max();
}

void LinkedList::printItems()
{
	if(m_head==nullptr) return;

	Node* currentNode = m_head;

	while(currentNode!=nullptr)
	{
		printf("%d ", currentNode->get_data());

		currentNode = currentNode->get_next();
	}
	printf("\n");
}

LinkedList::~LinkedList()
{
	Node* currentNode = m_head;
	Node* temp;

	while(currentNode->get_next()!=nullptr)
	{	
		temp = currentNode->get_next();
		delete currentNode;
		currentNode = temp;
	}

	delete currentNode;
}