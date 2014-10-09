/*
CS 3304
Chris Chan
Last updated 10/9/14

Write a C++ program that uses the queue and stack containers to read string of characters,
pushing each character onto a stack as it is read and simultaneously adding it to a queue. 
When the end of the string is encountered, the program should use the basic stack and queue 
operations to determine if the string is a palindrome.

Requirements:
1. Input string must be read at keyboard, with proper prompting message.
2. When finishing testing one string, the program must empty the stack and the queue and loop back to read the next string. 
The looping should be terminated upon reading string “-1”.
*/

#ifndef stack_h
	#include "stack.h"
#endif

#ifndef queue_h
	#include "queue.h"
#endif

#include <string>
#include <iostream>
using namespace std;

void isAPalindrome(string);

int main(){
	string palindrome="";
	while(palindrome!="-1"){
		cout << "Enter a string." << endl << endl;
		cin >> palindrome;
		cout << endl;
		isAPalindrome(palindrome);
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	
	cout << "Program has ended. Press enter to continue.";
	cin.get();

	return 0;
}

void isAPalindrome(string palin){
	Stack * pstack = new Stack();
	Queue * pqueue = new Queue();
	bool isPalin=true;

	for(int i=0; i<palin.size(); i++){
		pstack->Push(tolower(palin.c_str()[i]));
		pqueue->Enqueue(tolower(palin.c_str()[i]));
	}
	int count=0;
	while(count<palin.size() && isPalin){
		if(pstack->Pop()!=pqueue->Dequeue())
			isPalin=false;
		count++;
	}
	if(isPalin)
		cout << palin << " is a palindrome." << endl << endl;
	else
		cout << palin << " is not a palindrome." << endl << endl;
}
