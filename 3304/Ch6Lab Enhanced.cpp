#include <iostream>
using namespace std;

class List{
	private:
		class ListNode{
			private:
				int myInt;
				ListNode * next;
			public:
				ListNode(int i=0, ListNode * n = NULL) {myInt=i; next=n;}
				~ListNode(){ cout << "Node has been deleted." << endl;}
				int getMyInt() {return myInt;}
				void setMyInt(int i) {myInt=i;}
				ListNode * getNext() {return next;}
				void setNext(ListNode * n) {next=n;}
		};
		ListNode * head;
	public:
		List(ListNode * h=NULL){head=h;}
		~List();
		void Print() const;
		void Insert(int);
		void Delete(int);
};

void menu();

int main(){
	menu();
	return 0;
}

void menu(){
	List * intList = new List;
	int choice=0;
	cout << "Lab exercise for Chapter 6 Lists" << endl;
	while(choice!=4){
		cout << "Please pick from the following options:" << endl;
		cout << "[1] Print current list" << endl;
		cout << "[2] Insert integer to list" << endl;
		cout << "[3] Delete integer from list" << endl;
		cout << "[4] Exit" << endl;
		cin >> choice;
		cout << endl << endl;
		switch(choice){
		case 1:
			intList->Print();
			break;
		case 2:
			int newInt;
			cout << "Enter the new integer to be added" << endl;
			cin >> newInt;
			cout << endl << endl;
			intList->Insert(newInt);
			break;
		case 3: 
			int tarInt;
			cout << "Enter the integer to be deleted" << endl ;
			cin >> tarInt;
			cout << endl << endl;
			intList->Delete(tarInt);
			break;
		default:
			cout << "Please enter a valid option." << endl << endl;
		}
	}

}

List::~List(){
}

void List::Print() const {
	if(head==NULL)
		cout << "The list is empty." << endl << endl;
	else{
		cout << "The current list is as follows:" << endl << endl;
		ListNode * index = head;
		cout << index->getMyInt() << endl;
		while(index->getNext()!=NULL){
			index=index->getNext();
			cout << index->getMyInt() << endl;
		}
		cout << endl << endl;
	}
}

void List::Insert(int newInt){
	if(head==NULL){
		ListNode * h = new ListNode(newInt,NULL);
		head=h;
	}
	else{
		ListNode * index = head;
		ListNode * prev = NULL;
		ListNode * newListNode = new ListNode(newInt);
		while(index->getNext()!=NULL && index->getMyInt()<=newInt){
			prev=index;
			index=index->getNext();
		}
		if(index->getMyInt()>newInt){
			newListNode->setNext(index);
			if(prev!=NULL)
				prev->setNext(newListNode);
			else
				head->setNext(newListNode);
		}
		else
			index->setNext(newListNode);
	}
/*	List * index=this;
	List * prev=NULL;
	List * newList = new List(newInt);
	while(index->next!=NULL && index->myInt<=newInt){
		prev=index;
		index=index->next;
	}
	if(index->myInt>newInt){
		newList->next=index;
		prev->next=newList;
	}
	else
		index->next=newList;*/
}

void List::Delete(int tarInt){
	/*List * index=this;
	List * prev=this;
	while(index->next!=NULL && index->myInt!=tarInt){
		prev=index;
		index=index->next;
	}
	if(index->myInt==tarInt){
		prev->next=index->next;
		index->next=NULL;
		delete index;
	}
	else
		cout << "Target Integer not found in list" << endl << endl;*/
}
