#include <string>
#include <iostream>
using namespace std;

#include "StudentTestScores.h"

int main(){
	int startingNumTestScores=4;
	cout << "CREATE new object x, name = Joe numTestScores = "<< startingNumTestScores << endl << endl;
	StudentTestScores x("Joe", startingNumTestScores);
	cout << "READ standard input for values for test scores of object y, and rename object y" << endl << endl;
	cin >> x;
	cout << "CREATE new object y with name = Chris and default numTestScores" << endl << endl;
	StudentTestScores y("Chris");
	cout << "OUTPUT object y via standard output operators" << endl << endl;
	cout << y;
	cout << "ASSIGN to object y object x using assignment operator" << endl << endl;
	y=x;
	cout << "DISPLAY object x via display function." << endl << endl;
	x.Display();
	cout << "ADD a test score of 79 to object x" << endl << endl;
	x.addTestScore(79);
	cout << "OUTPUT final values of object x followed by object y" << endl << endl;
	cout << x;
	cout << y;

	cout << "CREATE new object z as a copy of object y" << endl << endl;
	StudentTestScores z(y);
	cout << "OUTPUT object z via standard output operators" << endl << endl;
	cout << z;
	cout << "ADD a test score of 91 to object z" << endl << endl;
	z.addTestScore(91);
	cout << "OUTPUT final values of object y followed by object z" << endl << endl;
	cout << y;
	cout << z;

	char ch;
	cin >> ch;
	return 0;
}
