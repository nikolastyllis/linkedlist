#include "Node.h"

Node::Node(int data, Node* next)
{
	m_data = data;
	m_next = next;
}

void Node::set_data(int data)
{
	m_data = data;
}

void Node::set_next(Node* next)
{
	m_next = next;
}

int Node::get_data()
{
	return m_data;
}

Node* Node::get_next()
{
	return m_next;
}