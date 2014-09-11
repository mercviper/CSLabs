/*Use a linked stack to determine the prime factors of a given number.
Accept a number from the user
Increasingly divide the given number starting from 2 until it divides evenly to find the first prime factor.
  - Push prime factor into stack
Repeat starting from the found prime factor using the quotient as the given number until the quotient becomes 1.
Print prime factors delimited by *. ex. 11 * 7 * 5 * 5 * 3 * 2 * 2
*/

#include <iostream>
using namespace std;

class Stack{
	private:
		class StackNode{
			private:
				int myInt;
				StackNode * next;
			public:
				StackNode(int i=0, StackNode * n = NULL) {myInt=i; next=n;}
				~StackNode(){}
				int getMyInt() {return myInt;}
				void setMyInt(int i) {myInt=i;}
				StackNode * getNext() {return next;}
				void setNext(StackNode * n) {next=n;}
		};
		StackNode * top;
	public:
		Stack(StackNode * h=NULL){top=h;}
		~Stack();
		bool isEmpty();
		void Push(int);
		int Pop();
		void Print() const;
};

int getInt();
void findPrimes(int);

int main(){
	enum menuChoices {PRIME, EXIT};
	int choice=0;
	cout << "Lab exercise for Chapter 7 Linked Stacks" << endl;
	while(choice!=2){
		cout << "Please pick from the following options:" << endl;
		cout << "[1] Find the prime factors of a number" << endl;
		cout << "[2] Exit" << endl << endl;
		choice = getInt();
		cout << endl;
		switch(choice-1){
			case PRIME:
				int newInt;
				cout << "Enter a number." << endl << endl;
				newInt = getInt();
				findPrimes(newInt);
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

void findPrimes(int x){
	int prime = 2;
	Stack * primeStack = new Stack;
	while(x!=1){
		while(x%prime!=0){
			prime++;
		}
		primeStack->Push(prime);
		x/=prime;
	}
	if(primeStack->isEmpty())
		cout << "No prime numbers were found." << endl << endl;
	while(!primeStack->isEmpty()){
		cout << primeStack->Pop();
		if(!primeStack->isEmpty())
			cout << " * ";
	}
	cout << endl << endl;
}

bool Stack::isEmpty(){
	return top==NULL;
}

void Stack::Push(int newInt){
	if(top==NULL){
		StackNode * t = new StackNode(newInt,NULL);
		top=t;
	}
	else{
		StackNode * t = new StackNode(newInt, top);
		top=t;
	}
}

int Stack::Pop(){
	StackNode * tmp = top;
	top = tmp->getNext();
	int topInt = tmp->getMyInt();
	delete tmp;
	return topInt;
}
