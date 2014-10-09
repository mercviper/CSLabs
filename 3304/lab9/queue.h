#include <string>
using namespace std;

class Queue{
	private:
		class QueueNode{
			private:
				char myChar;
				QueueNode * next;
			public:
				QueueNode(char i=NULL, QueueNode * n = NULL) {myChar=i; next=n;}
				~QueueNode(){}
				char getMyChar() {return myChar;}
				void setMyChar(char i) {myChar=i;}
				QueueNode * getNext() {return next;}
				void setNext(QueueNode * n) {next=n;}
		};
		QueueNode * front;
		QueueNode * back;
	public:
		Queue(QueueNode * h=NULL){front=h; back=h;}
		~Queue();
		bool isEmpty();
		void Enqueue(char);
		char Dequeue();
};
