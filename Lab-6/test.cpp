#include <string>
#include <iostream>
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
	inFile.open(filePath, ios::in);

	if(!inFile){
		cout << "Error! Missing File! Please enter a proper filepath." 
		return 0;
	}
	else	{
		inFile >> numStudents;
		scores = new StudentTestScores[numStudents];
		inFile.get();

		cout << "here we input scores from file" << endl;
		for(int i = 0; i < numStudents; i++){
			inFile >> scores[i];
			inFile.get();
		}

		 
		cout << "here we have finished inputting scores from file" << endl;
		cin.get();
	}
		cout << "here parse scores from file and generate the report" << endl;
		cin.get();
//-	Read file data to program.
//o	Create fstream variable
	//fstream variable >> scores;
//-	Generate Report & Output to standard output
//o	For each student in the array, generate an average score to determine the letter grade
//o	Then output according to instructions.
	for(int i=0; i<numStudents; i++){
		scores[i].display();
	}
	return 0;
}

/*
istream &operator >>(istream &inFile , StudentTestScores &student)
 {
 	cin.ignore();
 	char line[50];
 	inFile.getline( line, 50, '\t' );
 	student.studentName = line;
 	cout << line;

 	 
 	inFile >> student.numTestScores;
 	cout << "\t" << student.numTestScores << "\t";
 	  
 	double *temp;
 	temp = new double[student.numTestScores];

 	for (int i = 0; i < student.numTestScores; i++)
 	{
 	  
 	 inFile >> temp[i] ; 
 	 cout << temp[i] << '\t';
 	  
 	}
 student.testScores = temp;
 	return inFile;
 }
 
 fstream inFile;
 StudentTestScores *students;
 string file;
 char answer;


 cout << "Enter Document name(Case sensitive): " ;
 cin >> file;
 file = file + ".txt";

  
 inFile.open(file, ios::in);

 if(!inFile)
 {	cout << "Error! Missing File!" << endl << endl;
 	cin.get();
 	cout << "Would you like to create it? (y/n):" ;
 	cin >> answer;
 	if (answer == 'y')
 	 inFile.open(file,ios::out);
 	else if(answer == 'n')
 	 {cout << "Thanks!" << endl;}
 	inFile.close();
 	cin.get();
 	 
 }
 else
 {
 	int tempNum;
 	inFile >> tempNum;
 	students = new StudentTestScores[tempNum];

  
 	for(int i = 0; i < tempNum; i++)
 	{
 	 inFile >> students[i];
 	}

 	 
 }
 cin.get();
 cin.get();


 return 0;
}
 */