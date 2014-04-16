#include "StudentTestScores.h"
#include <iostream>


StudentTestScores::StudentTestScores(const StudentTestScores &other){
  studentName=other.studentName;
  numTestScores=other.numTestScores;
  letterGrade=other.letterGrade;
  testScores = new double[numTestScores];
  for(int i=0; i<other.numTestScores; i++){
	  testScores[i]=other.testScores[i];
  }
}

StudentTestScores::~StudentTestScores(){
	delete[] testScores;
}

double StudentTestScores::averageTestScore(){
	double sum=0;
	double avg=0;
	if(numTestScores==0){
		letterGrade = 'U';
		return avg;
	}
	
	for(int i=0; i< numTestScores;i++){
		sum+=testScores[i];
	}
	
	avg = sum/numTestScores;
	
	return avg;
}

void StudentTestScores::Display(){
	double avg=averageTestScore();
  cout << studentName << "\t" << numTestScores;
  for(int i=0; i<numTestScores; i++){
    cout << "\t" << testScores[i];
  }
	if(numTestScores==0){
		letterGrade = 'U';
	}
  
	letterGrade='F';
	if(avg>=60){
		letterGrade='D';
	}
	if(avg>=70){
		letterGrade='C';
	}
	if(avg>=80){
		letterGrade='B';
	}
	if(avg>=90){
		letterGrade='A';
	}

  cout << '\t' << avg << '\t' <<  letterGrade << endl;
}

void StudentTestScores::operator=(const StudentTestScores &other){
  delete[] testScores;
  studentName=other.studentName;
  numTestScores=other.numTestScores;
  letterGrade=other.letterGrade;
  testScores = new double[numTestScores];
  for(int i=0; i<other.numTestScores; i++){
	  testScores[i]=other.testScores[i];
  }
}

ostream& operator<< (ostream &out, const StudentTestScores &Student) //look at this in the morning
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
//o	First line data = #students
//o	Create StudentTestScores array Scores of #students
//o	For each i < #students, read a line from the fstream into Scores[i]
	char name[80];
	double score;
 	in.getline(name, 80, '\t' );
	Student.studentName=name;
	in >> Student.numTestScores;
	Student.testScores=new double[Student.numTestScores];
	for (int i=0; i < Student.numTestScores; i++){
		in >> score;
		Student.testScores[i]=score;
		//cout << "this is the score : " << score;
	}
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
