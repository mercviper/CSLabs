/*
CS 3304
Chris Chan
Last updated 9/25/14
Use a linked queue to convert a base-10 fraction to an equivalent fraction in base-2 to base-9 based on user input.
Prompt user for a decimal fraction between 0 and 1.
Prompt user for a number base to convert the fraction to. (radix)
Multiply the given fraction by radix, ignoring the value in the units place, until the product reaches zero, or until the desired number of binary places have been reached
The ignored values will be enqueued and then dequeued to represent the converted fraction.
*/

#include <iostream>
using namespace std;

class Queue{
	private:
		class QueueNode{
			private:
				int myInt;
				QueueNode * next;
			public:
				QueueNode(int i=0, QueueNode * n = NULL) {myInt=i; next=n;}
				~QueueNode(){}
				int getMyInt() {return myInt;}
				void setMyInt(int i) {myInt=i;}
				QueueNode * getNext() {return next;}
				void setNext(QueueNode * n) {next=n;}
		};
		QueueNode * front;
		QueueNode * back;
	public:
		Queue(QueueNode * h=NULL){front=h; back=h;}
		~Queue();
		bool isEmpty();
		void Enqueue(int);
		int Dequeue();
};

int getInt();
void findPrimes(int);

int main(){
	enum menuChoices {PRIME, EXIT};
	int choice=0;
	cout << "Lab Exercise for Chapter 8 for Linked Queues" << endl;
	while(choice!=2){
		cout << "Please pick from the following options:" << endl;
		cout << "[1] Convert a decimal fraction to another base." << endl;
		cout << "[2] Exit" << endl << endl;
		choice = getInt();
		cout << endl;
		switch(choice-1){
			case PRIME:
				float newNum;
				int newInt;
				cout << "Enter a decimal." << endl << endl;
				newNum = getDecimal();
				cout << endl;
				cout << "Enter a base to convert to." << endl << endl;
				newInt = getInt();
				cout << endl;
				convertBase(newNum, base);
				break;
			case EXIT:
				cout << "Goodbye." << endl << endl;
				break;
			default:
				cout << "Please enter a valid option." << endl << endl;
		}
	}
  return 0;
}

float getDecimal(){
	float input;
	do{
		if(cin.fail()){ //if stream buffer had previously failed, clear and reset for valid input
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		cin >> input;

		if(cin.fail()){
			cout << "Not a decimal." << endl << endl;
		}
	}while(cin.fail());
	return input;
}

int getInt(){
	int input;
	do{
		if(cin.fail()){ //if stream buffer had previously failed, clear and reset for valid input
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		cin >> input;

		if(cin.fail()){
			cout << "Not an integer." << endl << endl;
		}
	}while(cin.fail());
	return input;
}

void convertBase(float decimal, int newBase){
}

bool Queue::isEmpty(){
	return front==NULL;
}

void Queue::Enqueue(int newInt){
	if(front==NULL){
		QueueNode * t = new QueueNode(newInt);
		front=t;
		back=t;
	}
	else{
		QueueNode * t = new QueueNode(newInt);
		back->setNext(t);
		back=t;
	}
}

int Queue::Dequeue(){
	QueueNode * tmp = front;
	front = tmp->getNext();
	int frontInt = tmp->getMyInt();
	delete tmp;
	return frontInt;
}
