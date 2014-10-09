#ifndef queue_h
	#include "queue.h"
#endif

bool Queue::isEmpty(){
	return front==NULL;
}

void Queue::Enqueue(char newChar){
	if(front==NULL){
		QueueNode * t = new QueueNode(newChar);
		front=t;
		back=t;
	}
	else{
		QueueNode * t = new QueueNode(newChar);
		back->setNext(t);
		back=t;
	}
}

char Queue::Dequeue(){
	QueueNode * tmp = front;
	front = tmp->getNext();
	char frontChar = tmp->getMyChar();
	delete tmp;
	return frontChar;
}
