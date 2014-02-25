using namespace std;
#include <iostream>;
#include <string>;

struct Address{
	string streetName, city, state, zipCode;
};

struct DateOfBirth{
	int month, day, year;
};

struct Student{
	string name;
	int ID;
	short yearInSchool;
	double GPA;
	DateOfBirth DOB;
	Address address;
};

Student getStudent();
void printStudent(Student);
void printAddress(Address);
void printDOB(DateOfBirth);

int main(){
	Student bob = getStudent();
	printStudent(bob);
	char ch;
	cin >> ch;
	return 0;
}

Student getStudent(){
	Student x;
	DateOfBirth DOB;
	Address address;


	cout << "What is the name of the student?"<<endl;
	getline(cin, x.name);
	cout << "What is the ID of the student?"<<endl;
	cin >> x.ID;
	cout << "What is the year of the student?"<<endl;
	cin >> x.yearInSchool;
	cout << "What is the GPA of the student?"<<endl;
	cin >> x.GPA;


	DOB.month = 6;
	DOB.day = 23;
	DOB.year = 1986;

	address.streetName="15514 Poplar Springs Ln";
	address.city="Houston";
	address.state="Texas";
	address.zipCode="77062";

	x.DOB=DOB;
	x.address=address;

	return x;
}

void printStudent(Student x){
	cout << x.name << "'s ID is " << x.ID << endl;
	cout << x.name << "'s GPA is " << x.GPA << endl;
	cout << x.name << "'s year in school is " << x.yearInSchool << endl;
	cout << x.name << "'s date of birth is ";
	printDOB(x.DOB);
	cout << x.name << "'s address is :" << endl;
	printAddress(x.address);
}

void printAddress(Address x){
	cout << x.streetName << endl;
	cout << x.city << ", " << x.state << x.zipCode << endl;
}

void printDOB(DateOfBirth x){
	cout << x.month << "/" << x.day << "/" << x.year << endl;
}