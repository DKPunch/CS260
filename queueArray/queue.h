#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>

using namespace std;

static const int	SIZE{5};

class Queue
{
public:
	Queue();
	~Queue();
	bool isEmpty();
	void enqueue(int num);
	void dequeue();
	void showfront();
	void displayQueue();

private:
	int		*qArray;
	int		front;
	int		rear;
};

//ostream& operator<<(ostream& out, Queue *queue);

#endif
