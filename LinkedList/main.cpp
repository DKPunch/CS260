#include <cstdlib>
#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	List joe;	//create object to access class.

	// test adding some nodes and print
	joe.addNode(3);
	joe.addNode(5);
	joe.addNode(1);
	joe.addNode(7);
	joe.addNode(2);
	joe.printList();

	// test deleting some nodes and print
	joe.deleteNode(5);
	joe.deleteNode(3);
	joe.printList();
	joe.deleteNode(8);
	joe.printList();

	system("pause");
	return 0;
}

List::List()
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void List::addNode(int addData)
{
	node* n = new node;		// creates a new ptr 'n' that points at a new 'node'
	n->next = NULL;			// find the node that 'n' is pointing to, 
							// and make the 'next' ptr point to NULL
	n->data = addData;		// put some data into node that 'n' points to. 
							// Data input is variable passed to function.

	if (head != NULL)		// if head is not NULL, and we have stuff inside list....then
	{
		curr = head;		// make current ptr point to head or the front of list
		while (curr->next != NULL)	// advance curr ptr untill it gets to last node in list
		{
			curr = curr->next;		// advance curr ptr
		}
		curr->next = n;		// curr will point to 'n' and link the new node between last node and NULL
	}
	// if there is no list then...
	else
	{
		head = n;			// tell new node that it is the front of the list, head = 'n'
	}
}

void List::deleteNode(int delData)
{
	node* delPtr = NULL;		// make new ptr for deletion

	// mission: traverse curr ptr while temp point follows behind. As curr ptr looks for delData,
	// a following temp ptr will allow us to patch up the list after we delete the desired node.
	temp = head;				// set temp to same as head, so its at the beginning.
	curr = head;				// set curr to same as head, so its at the beginning.
	// keep going till at end of list. Also will exit loop if data is actually found so we can
	// proceed with commands to delete the desired node.
	while (curr != NULL && curr->data != delData)	// if not at end AND delData still not found...then
	{
		temp = curr;			// sets temp to curr, in order to keep temp one step behind.
		curr = curr->next;		// after temp is set, moves curr along to next node.
	}
	if (curr == NULL)			// if at end of list, did not find desired node.
	{
		cout << delData << " was not in the list.\n";
		delete delPtr;			// delete delPtr anyways.
	}
	else						// if desired node was found...then
	{
		delPtr = curr;			// make delPtr point to node we want to delete.
		curr = curr->next;		// advance curr ptr so it does not get deleted.
		temp->next = curr;		// patches list by moving temp to where curr is pointing.
		if (delPtr == head)		// special condition if first node is to be deleted
		{
			head = head->next;	// advance head ptr to next node
			temp = NULL;		// temp ptr to NULL
		}
		// now the list is completeing patched while delPtr is pointing to desired node to delete.
		delete delPtr;			// finalizes deletion of delData.
		cout << "The value " << delData << " was deleted.\n";
	}
}

void List::printList()
{
	curr = head;				// make curr point to beginning -> head ptr.
	while (curr != NULL)		// while not at end of list...
	{
		cout << curr->data << " ";	// print data inside node
		curr = curr->next;			// advance curr to next node
	}
	cout << endl;
}