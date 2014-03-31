#include <string>
#include <iostream>
using namespace std;

#include "StudentTestScores.h"

int main(){
	StudentTestScores x("joe", 4);
	cin >> x;
	StudentTestScores y("Chris");
	cout << y;
	y=x;
	cout << x;
	x.addTestScore(79);
	cout << x;
	cout << y;
	char ch;
	cin >> ch;
	return 0;
}
