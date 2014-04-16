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
	
	letterGrade='F';
	if(avg>60){
		letterGrade='D';
	}
	if(avg>70){
		letterGrade='C';
	}
	if(avg>80){
		letterGrade='B';
	}
	if(avg>90){
		letterGrade='A';
	}
	
	return avg;
}

void StudentTestScores::Display(){
  cout << studentName << "\t" << numTestScores;
  for(int i=0; i<numTestScores; i++){
    cout << "\t" << testScores[i];
  }
  cout << '\t' << averageTestScore() << '\t' <<  letterGrade << endl;
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

ofstream& operator<< (ofstream &out, const StudentTestScores &Student) //look at this in the morning
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
	string name;
	double score;
	int numScores;
	in.getline(Student.studentName, 80, '\t'); 
	in.getline(Student.numTestScores, 80, '\t');
	
	for (int i=0; i < Student.numTestScores; i++)
		in.getline(Student.testScores[i], 80,'\t');
	return in;
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
 }*/
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
