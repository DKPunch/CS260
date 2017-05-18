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
		return false;		// any other values make the queue not empty
	}
}

void Queue::enqueue(int num)
{
	if ((rear + 1) % SIZE == front)				// Check if queue is full
	{
		cout << "The queue is full!! \n";
	}
	else
	{
		if (front == -1)				// first element inserted
		{
			front = 0;
		}
		// inserts element at rear
		rear = (rear + 1) % SIZE;			// allows the rear to reset to the 0 element in the array after array is full
		qArray[rear] = num;				// this is key to making this a circular array
	}
}

void Queue::dequeue()
{
	if (isEmpty())						// Check if queue is full
	{
		cout << "Queue is empty\n";
	}
	else
	{
		if (front == rear)				// if only one element in array
		{
			front = rear = -1;			// set front and rear to -1, dequeueing rear front element
		}
		else
		{
			front = (front + 1) % SIZE;		// else, move front in circular array motion, 
		}						// similar to rear from above function
	}
}

void Queue::showFront()
{
	if (isEmpty())
	{
		cout << "Queue is empty\n";
	}
	else
	{
		cout << "element at front is:" << qArray[front];	// shows first element, first to pop on dequeue
	}
}

//function to display queue
void Queue::displayQueue()
{
	if (isEmpty())
	{
		cout << "Queue is empty\n";
	}
	else
	{
		int i;
		if (front <= rear)					// first case, front element smaller than rear
		{
			for (i = front; i <= rear; i++)			// traverse array
				cout << qArray[i] << " ";
		}
		else
		{
			i = front;
			while (i < SIZE)				// while front is less than SIZE
			{
				cout << qArray[i] << " ";		// traverses one side of circular array, after position of front
				i++;
			}
			i = 0;
			while (i <= rear)				// while element is less than rear...
			{
				cout << qArray[i] << " ";		// increment everything up to rear position
				i++;					// which is everything behind front that wasnt printed in prev loop
			}
		}
	}
}

int main()
{
	Queue q;
	int choice, value, flag = 1;

	// display menu
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
		case 3: q.showFront();
			break;
		case 4: q.displayQueue();
			break;
		case 5: flag = 0;
			break;
		}
	}

	return 0;
}
