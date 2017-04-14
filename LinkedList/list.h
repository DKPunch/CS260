#ifndef LIST_H
#define LIST_H

class List
{
private:
	struct node			// basic node inside private
	{
		int data;		// int data component of node
		node* next;		// next ptr inside node
	};

	node* head;			// private ptr head - for start of list
	node* curr;			// private ptr curr - for current ptr
	node* temp;			// private ptr temp - for ???

public:					// public functions
	List();							// default constructor to set all ptrs to NULL
	void addNode(int addData);		// function adds a new node
	void deleteNode(int delData);	// function deletes a node
	void printList();				// function prints list of nodes
};


#endif // !

