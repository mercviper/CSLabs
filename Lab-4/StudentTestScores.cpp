#include "StudentTestScores.h"
#include <iostream>


StudentTestScores::StudentTestScores(const StudentTestScores &other){
  studentName=other.studentName;
  numTestScores=other.numTestScores;
  testScores = new double[numTestScores];
  for(int i=0; i<other.numTestScores; i++){
	  testScores[i]=other.testScores[i];
  }
}

StudentTestScores::~StudentTestScores(){
	delete[] testScores;
}

void StudentTestScores::Display(){
  cout << studentName << "\t" << numTestScores;
  for(int i=0; i<numTestScores; i++){
    cout << "\t" << testScores[i];
  }
  cout << endl << endl;
}

void StudentTestScores::operator=(const StudentTestScores &other){
  delete[] testScores;
  studentName=other.studentName;
  numTestScores=other.numTestScores;
  testScores = new double[numTestScores];
  for(int i=0; i<other.numTestScores; i++){
	  testScores[i]=other.testScores[i];
  }
}

ostream& operator<< (ostream &out, const StudentTestScores &Student)
{
	out << "Name: " << Student.studentName << endl;
	out << "Num Test Scores:" << Student.numTestScores << endl;
	out << "Test Scores: ";
	for (int i = 0; i < Student.numTestScores; i++) 
		out << Student.testScores[i] << "\t";
	out << endl << endl;
	return out;
}

istream& operator>> (istream &in, StudentTestScores &Student)
{
	cout << "Enter student's name and test scores." << endl;
	in >> Student.studentName; 		
	for (int i=0; i < Student.numTestScores; i++)
		cin >> Student.testScores[i];
	return in;
}										


//accessors
string StudentTestScores::getStudentName()//returns studentName
{
  return studentName;
}

double * StudentTestScores::getTestScores() //returns testScores
{
  return testScores;
}

int StudentTestScores::getNumTestScores() // returns numTestScores
{
  return numTestScores;
}

//mutators	
void StudentTestScores::setStudentName(string NameofStudent){ //Sets the student's name to the passed string
  studentName = NameofStudent;
}

void StudentTestScores::addTestScore(double NewScore){ //Adds the passed int as a new test score and increments numTestScores by 1
 
  numTestScores++;
  double * Scores = new double[numTestScores];
  double * tmp=testScores;
  for(int i=0; i<numTestScores-1; i++)
  {
  	Scores[i]=testScores[i];
  }
  delete[] tmp;
  
  Scores[numTestScores-1] = NewScore;
  
  testScores = Scores; 
  
}
