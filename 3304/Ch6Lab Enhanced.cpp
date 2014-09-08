#include <iostream>
using namespace std;

class List{
private:
	int myInt;
	List * next;
public:
	List(int myInt=0, List * next=NULL);
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
	List * Head = NULL;
	char choice='0';
	cout << "Lab exercise for Chapter 6 Lists" << endl;
	while(choice!='4'){
		cout << "Please pick from the following options:" << endl;
		cout << "[1] Print current list" << endl;
		cout << "[2] Insert integer to list" << endl;
		cout << "[3] Delete integer from list" << endl;
		cout << "[4] Exit" << endl;
		cin >> choice;
		switch(choice){
		case '1':
			if(Head==NULL)
				cout << "The list is currently empty" << endl;
			else
				Head->Print();
			break;
		case '2':
			int newInt;
			cout << "Enter the new integer to be added" << endl;
			cin >> newInt;
			if(Head==NULL)
				Head=new List(newInt);
			else
				Head->Insert(newInt);
			break;
		case '3': //doesn't work to continue program if first element (Head) is deleted because Head variable no longer exists
			int tarInt;
			cout << "Enter the integer to be deleted" << endl;
			cin >> tarInt;
			Head->Delete(tarInt);
			break;
		default:
			cout << "Please enter a valid option." << endl;
		}
	}

}

List::List(int x, List * y){
	myInt=x;
	next=y;
}

List::~List(){
	cout << "Deleting list node " << myInt << endl;
}

void List::Print() const {
	cout << this->myInt << endl;
	if(this->next!=NULL){
		this->next->Print();
	}
}

void List::Insert(int newInt){
	List * index=this;
	List * prev=this;
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
		index->next=newList;
}

void List::Delete(int tarInt){
	List * index=this;
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
		cout << "Target Integer not found in list" << endl;
}
