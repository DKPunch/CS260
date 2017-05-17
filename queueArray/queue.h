#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <ostream>

using namespace std;

static const int	SIZE{5};

class Queue
{
public:
	Queue(int size);
	~Queue();
	bool isEmpty();
	bool isFull();
	bool enqueue(char ch);
	bool dequeue(char& ch);



	friend ostream& operator<<(ostream& out, Queue& queue);

private:
	//int		size;
	char	*qArray;
	int		front;
	int		rear;
};

//ostream& operator<<(ostream& out, Queue *queue);

#endif
