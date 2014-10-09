#include <string>
using namespace std;

class Stack{
	private:
		class StackNode{
			private:
				char myChar;
				StackNode * next;
			public:
				StackNode(char i=NULL, StackNode * n = NULL) {myChar=i; next=n;}
				~StackNode(){}
				char getMyChar() {return myChar;}
				void setMyChar(char i) {myChar=i;}
				StackNode * getNext() {return next;}
				void setNext(StackNode * n) {next=n;}
		};
		StackNode * top;
	public:
		Stack(StackNode * h=NULL){top=h;}
		~Stack();
		bool isEmpty();
		void Push(char);
		char Pop();
};
