using namespace std;
#include <iostream>;
#include <string>;
#include "Student.h";

int main(){
	Student bob = getStudent();
	printStudent(bob);
	char ch;
	cin >> ch;
	return 0;
}


