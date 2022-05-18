#ifndef NODE_H
#define NODE_H

class Node {
	private:
		int m_data;
		Node* m_next;
	public:
		Node(int data, Node* next);
		void set_data(int data);
		void set_next(Node* next);
		int get_data();
		Node* get_next();

};

#endif