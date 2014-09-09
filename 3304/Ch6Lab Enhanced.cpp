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
				~ListNode(){ cout << "Node has been deleted with a value of " << myInt << "." << endl << endl;}
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
int getInt();

int main(){
	menu();
	cin.ignore(INT_MAX, '\n');
	cin.get();
	return 0;
}

void menu(){
	List * intList = new List;
	int choice=0;
	enum menuChoices {PRINT, INSERT, DELETE, EXIT};
	cout << "Lab exercise for Chapter 6 Lists" << endl;
	while(choice!=4){
		cout << "Please pick from the following options:" << endl;
		cout << "[1] Print current list" << endl;
		cout << "[2] Insert integer to list" << endl;
		cout << "[3] Delete integer from list" << endl;
		cout << "[4] Exit" << endl << endl;
		choice = getInt();
		cout << endl;
		switch(choice-1){
			case PRINT:
				intList->Print();
				break;
			case INSERT:
				int newInt;
				cout << "Enter the new integer to be added" << endl << endl;
				newInt = getInt();
				cout << endl;
				intList->Insert(newInt);
				break;
			case DELETE: 
				int tarInt;
				cout << "Enter the integer to be deleted" << endl << endl;
				tarInt = getInt();
				cout << endl;
				intList->Delete(tarInt);
				break;
			case EXIT:
				cout << "Goodbye." << endl << endl;
				delete intList;
				break;
			default:
				cout << "Please enter a valid option." << endl << endl;
		}
	}

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

List::~List(){
	while(head!=NULL){
		Delete(head->getMyInt());
	}
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
				head=newListNode;
		}
		else
			index->setNext(newListNode);
	}
}

void List::Delete(int tarInt){
	ListNode * index=head;
	ListNode * prev=NULL;
	while(index->getNext()!=NULL && index->getMyInt()!=tarInt){
		prev=index;
		index=index->getNext();
	}
	if(index->getMyInt()==tarInt){
		if(prev!=NULL)
			prev->setNext(index->getNext());
		else
			head = index->getNext();
		index->setNext(NULL);
		delete index;
	}
	else
		cout << "Target Integer not found in list" << endl << endl;
}
