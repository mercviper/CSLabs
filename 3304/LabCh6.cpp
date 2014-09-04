#include <iostream>
using namespace std;

class List{
public:
	int myInt;
	List * next;
private:
	List();
	~List();
	void Print() const;
	void Insert(int);
	void Delete(int);
};

List::List(){
	myInt=0;
	next=NULL;
}

List::~List(){
	while(next!=NULL){
		this->next->Delete(this->next->myInt);
	}
	Delete(myInt);
}
