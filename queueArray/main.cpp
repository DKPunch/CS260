#include "queue.h"

Queue::Queue(int size) :
	//size{size},
	qArray{new char[size]},		// Auto create new queue array as long as "size"
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

bool Queue::isFull() 
{
	return rear == SIZE - 1;
}

ostream& operator<<(ostream& out, Queue& queue)
{
	out << '[';
	if (queue.isEmpty())
		out << "empty";
	else
		for (int i = 0; i <= queue.rear; i++)
			out << queue.qArray[i] << (i < queue.rear ? ", " : "");
	out << ']' << endl;
	return out;
}

int main()
{
	return 0;
}