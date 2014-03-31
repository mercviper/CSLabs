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
  cout << endl;
}

void StudentTestScores::operator=(const StudentTestScores &other){
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
	out << endl;
	return out;
}

istream& operator>> (istream &in, StudentTestScores &Student)
{
	cout << "Enter student's name 
