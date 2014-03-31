#include <string>
#include <iostream>
using namespace std;

#include "StudentTestScores.h"

int main(){
	cout << "CREATE new object x, name = Joe numTestScores = 4" << endl << endl;
	StudentTestScores x("joe", 4);
	cout << "READ standard input for values for test scores of joe, and rename joe" << endl << endl;
	cin >> x;
	cout << endl << "CREATE new object y with name = Chris and default numTestScores" << endl << endl;
	StudentTestScores y("Chris");
	cout << "OUTPUT object y via standard output operators" << endl << endl;
	cout << y;
	cout << endl << "ASSIGN to object y object x using assignment operator" << endl << endl;
	y=x;
	cout << "OUTPUT object x via display function." << endl << endl;
	x.Display();
	cout << endl << "ADD a test score of 79 to object x" << endl << endl;
	x.addTestScore(79);
	cout << "OUTPUT final values of object x followed by object y" << endl << endl;
	cout << x;
	cout << y;
	char ch;
	cin >> ch;
	return 0;
}
