StudentTestScores::StudentTestScores(){
  studentName="";
  numTestScores=0;
}

StudentTestScores::StudentTestScores(string name){
  studentName=name;
  numTestScores=0;
}


StudentTestScores::StudentTestScores(const StudentTestScores &other){
  studentName=other.studentName;
  testScores=other.testScores;
  numTestScores=other.numTestScores;
}

StudentTestScores::~StudentTestScores(){
  delete [] testScores;
}

StudentTestScores::Display(){
  cout << studentName << "\t" << numTestScores;
  for(int i=0; i<numTestScores; i++){
    cout << "\t" << testScores[i];
  }
  cout << endl;
}

StudentTestScores::operator=(const StudentTestScores &other){
  studentName=other.studentName;
  testScores=other.testScores;
  numTestScores=other.numTestScores;
}

friend ofstream& operator<< (ofstream &out, const StudentTestScores &Student)
{
	out << "Name: " << Student.getStudentName() << endl;
	out << "Test Scores: ";
	for (int element = 0; element < Student.getNumTestScores(); element++) //modify size variable accordingly 
		cout << Student.testScores[element] << endl;
	out << Student.getNumTestScores() << endl;
}

friend ifstream& operator>> (ifstream &in, StudentTestScores &Student)
{
	cout << "Enter student's name and test score." << endl;
	in >> Student.setStudentName() >> Student.setStudentScores() >> endl; //Use private data members
									      //instead of function members
									      //Add returns.
}										


//accessors
string StudentTestScores::getStudentName()//returns studentName
{
  return studentName;
}

int StudentTestScores::getTestScores() //returns testScores
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
  if(numTestScores == 1)
  {
    double Scores[numTestScores];
  }
  
  Scores[numTestScores-1] = NewScore;
  
  testScores = Scores; 
  
}
