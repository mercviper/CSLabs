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

void test();

int main(){
	test();
	char ch;
	cin >> ch;
	return 0;
}

void test(){
	List * Head = new List(2);
	Head->Insert(2);
	Head->Insert(2);
	Head->Insert(15);
	Head->Insert(7);
	Head->Insert(15);
	Head->Insert(5);
	Head->Insert(5);
	Head->Print();
	Head->Delete(5);
	Head->Delete(5);
	Head->Delete(5);
	Head->Delete(7);
	Head->Print();
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
