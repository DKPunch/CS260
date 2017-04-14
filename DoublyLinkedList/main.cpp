#include <cstdlib>
#include <iostream>

using namespace std;



struct node
{
	int data;		// data component
	node* next;		// next pointer inside node
	node* prev;		// previous pointer inside node
};

void printFoward(node* head);
void printReverse(node* tail);

int main(int argc, char** argv)
{
	node* head;		// points to front of list
	node* tail;		// points to end of list
	node* n;		// new pointer, helps with list

	// first node in list
	n = new node;	// creates new node (first node on list) that 'n' points to
	n->data = 1;	// fills first node with integer data
					// translate: Go and find node that 'n' points to and fill
					// the data component with '1'
	n->prev = NULL;	// finds same node that 'n' points to and makes sure that the 
					// previous pointer inside node points to NULL (need this for first node)
	head = n;		// makes head point to same node as 'n'
	tail = n;		// makes tail point to same node as 'n'

	// second node in list
	n = new node;	// creates new node and MOVES 'n' to new node
	n->data = 2;	// adds '2' to data side of node
	n->prev = tail;	// links prev ptr to 1st node (tail is still pointing to first node)
	tail->next = n;	// access tail ptr (points to first node) and access the next ptr 
					// in first node, then have next ptr link to 'n' which still points to
					// the second node, this completely links the 1st and 2nd node together.
	tail = n;		// Done using tail, so we can advance tail to where 'n' is, the 2nd node.

	// third node in list
	n = new node;	// creates new node and MOVES 'n' to new node
	n->data = 3;	// adds '3' to data side of node
	n->prev = tail;	// links prev ptr to 1st node (tail is still pointing to first node)
	tail->next = n;	// links 2nd and 3rd node together
	tail = n;		// Done using tail, so we can advance tail to where 'n' is, the 3rd node.

	// 4th node in list (repeat)
	n = new node;
	n->data = 4;
	n->prev = tail;
	tail->next = n;
	tail = n;
	tail->next = NULL;	// Last node in list, verify the 'next' points to null.

	printFoward(head);	// Traverse fwd
	printReverse(tail);	// Traverse reverse

	system("pause");
	return 0;
}

void printFoward(node* head)
{
	node* temp = head;		// creates new 'temp' ptr that points to the same node as 'head'

	while (temp != NULL)	// while not at the end of the list
	{
		cout << temp->data << ", ";		// print the data component of each node
		temp = temp->next;	// moves temp ptr to wherever the next ptr is pointing (next node)
	}
	cout << endl;
}

void printReverse(node* tail)
{
	node* temp = tail;		// creates new 'temp' ptr that points to the same node as 'tail'

	while (temp != NULL)	// while not at the start of the list
	{
		cout << temp->data << ", ";		// print the data component of each node
		temp = temp->prev;	// moves temp ptr to wherever the prev ptr is pointing (prev node)
	}
	cout << endl;
}