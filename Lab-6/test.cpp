#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "StudentTestScores.h"


int main(){
	StudentTestScores * scores;
	fstream inFile;
	string filePath;
	int numStudents=0;
//-	Prompt user for input filepath name.
	cout << "Where is the file located?" << endl;
	cin >> filePath;
	cin.get();
	inFile.open(filePath, ios::in);

	if(!inFile){
		cout << "Error! Missing File! Please enter a proper filepath.";
		return 0;
	}
	else	{
		inFile >> numStudents;
		scores = new StudentTestScores[numStudents];
		inFile.get();
		for(int i = 0; i < numStudents; i++){
			inFile >> scores[i];
			inFile.get();
		}
	}
//-	Read file data to program.
//o	Create fstream variable
	//fstream variable >> scores;
//-	Generate Report & Output to standard output
//o	For each student in the array, generate an average score to determine the letter grade
//o	Then output according to instructions.
	for(int i=0; i<numStudents; i++){
		scores[i].Display();
	}
	cin.get();
	return 0;
}
