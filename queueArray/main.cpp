/* Created by: Joseph Schell
*/
#include <iostream>
#include "queue.h"

Queue::Queue() :
	qArray{new int[SIZE]},
	front{-1},					// new array starts the front before 0
	rear{-1}					// new array starts the rear before 0 also
{
}

Queue::~Queue(void)
{
	delete[] qArray;
}

bool Queue::isEmpty()
{
	if (front == -1 && rear == -1)	// if both values are -1, queue is empty
	{
		return true;
	}
	else
	{
		return false;	// any other values make the queue not empty
	}
}

void Queue::enqueue(int num)
{
	if ((rear + 1) % SIZE == front)			// Check if queue is full
	{
	cout << "The queue is full!! \n";
	}
	else
	{
		if (front == -1)					// first element inserted
		{
			front = 0;
		}
		//insert element at rear
		rear = (rear + 1) % SIZE;
		qArray[rear] = num;
	}
}

void Queue::dequeue()
{
	if (isEmpty())
		cout << "Queue is empty\n";
	else
		//only one element
		if (front == rear)
			front = rear = -1;
		else
			front = (front + 1) % SIZE;
}

//function to show the element at front
void Queue::showfront()
{
	if (isEmpty())
		cout << "Queue is empty\n";
	else
		cout << "element at front is:" << qArray[front];
}

//function to display queue
void Queue::displayQueue()
{
	if (isEmpty())
		cout << "Queue is empty\n";
	else
	{
		int i;
		if (front <= rear)
		{
			for (i = front; i <= rear; i++)
				cout << qArray[i] << " ";
		}
		else
		{
			i = front;
			while (i < SIZE)
			{
				cout << qArray[i] << " ";
				i++;
			}
			i = 0;
			while (i <= rear)
			{
				cout << qArray[i] << " ";
				i++;
			}
		}
	}
}

int main()
{
	Queue q;
	int choice, value, flag = 1;

	while (flag == 1)
	{
		cout << "\n1.enqueue 2.dequeue 3.showfront 4.displayQueue 5.exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Enter Value:\n";
			cin >> value;
			q.enqueue(value);
			break;
		case 2: q.dequeue();
			break;
		case 3: q.showfront();
			break;
		case 4: q.displayQueue();
			break;
		case 5: flag = 0;
			break;
		}
	}

	system("pause");
	return 0;
}
