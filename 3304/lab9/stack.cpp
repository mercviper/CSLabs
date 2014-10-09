#ifndef stack_h
	#include "stack.h"
#endif

bool Stack::isEmpty(){
	return top==NULL;
}

void Stack::Push(char newChar){
	if(top==NULL){
		StackNode * t = new StackNode(newChar,NULL);
		top=t;
	}
	else{
		StackNode * t = new StackNode(newChar, top);
		top=t;
	}
}

char Stack::Pop(){
	StackNode * tmp = top;
	top = tmp->getNext();
	char topChar = tmp->getMyChar();
	delete tmp;
	return topChar;
}
