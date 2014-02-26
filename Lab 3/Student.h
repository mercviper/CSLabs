

enum month {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

struct Address{
	string streetName, city, state, zipCode;
};

struct DateOfBirth{
	int  day, year;
	month m;
};

struct Student{
	string fname;
	string lname;
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


void printStudent(Student x){
	cout << "Name: "<< x.fname << "\t" << x.lname << endl;
	cout << "ID: " << x.ID << endl;
	cout << "GPA: " << x.GPA << endl;

	cout << "DOB: ";
	printDOB(x.DOB);
	cout << "Address:" << endl;
	printAddress(x.address);
}

void printAddress(Address x){
	cout << x.streetName << endl;
	cout << x.city << "\t" << x.state << ", " << x.zipCode << endl;
}

void printDOB(DateOfBirth x){
	cout << x.m+1 << "/" << x.day << "/" << x.year << endl;
}


Student getStudent(){
	Student x;
	DateOfBirth DOB;
	Address address;


	cout << "What is the first name of the student?"<<endl;
	getline(cin, x.fname);
	cout << "What is the last name of the student?"<<endl;
	getline(cin, x.lname);
	cout << "What is the ID of the student?"<<endl;
	cin >> x.ID;
	
	cout << "What is the GPA of the student?"<<endl;
	cin >> x.GPA;

	int m;

	cout << "What month was the student born? (mm)"<<endl;
	cin >> m;
	DOB.m = static_cast<month> (m - 1);
	
	cout << "What day was the student born? (dd)"<<endl;
	cin >> DOB.day;
	cout << "What year was the student born? (yyyy)"<<endl;
	cin >> DOB.year;
	/*DOB.month = 6;
	DOB.day = 23;
	DOB.year = 1986;*/
	 //flush the \n
	string endLine;
	getline(cin, endLine);
	
	cout << "What is the Street Address of the student?"<<endl;
	getline(cin, address.streetName);
	cout << "What is the City of the student?"<<endl;
	getline(cin, address.city);
	cout << "What is the State of the student?"<<endl;
	getline(cin, address.state);
	cout << "What is the Zip Code of the student?"<<endl;
	getline(cin, address.zipCode);
	/*address.streetName="15514 Poplar Springs Ln";
	address.city="Houston";
	address.state="Texas";
	address.zipCode="77062";*/

	x.DOB=DOB;
	x.address=address;

	return x;
}
