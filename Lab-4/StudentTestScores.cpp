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

friend ostream& operator<< (ostream &out, const StudentTestScores &)
{
	cout << "Name: " << StudentTestScores.getStudentName() << endl;
	cout << "Test Scores: ";
	for (int element = 0; element < StudentTestScores.getNumTestScores(); element++) //modify size variable accordingly 
		cout << StudentTestScores.getTestScores(element) << endl;
	cout << StudentTestScores.getNumTestScores() << endl;
}

friend ostream& operator>> (ostream &out, StudentTestScores &)
{
	cout << "Enter student's name and test score." << endl;
	cin >> StudentTestScores.setStudentName() >> StudentTestScores.setStudentScores() >> endl;
}


//accessors
string StudentTestScores::getStudentName(){ //returns studentName
}

int StudentTestScores::getTestScores(){ //returns testScores
}

int StudentTestScores::getNumTestScores(){ // returns numTestScores
}

//mutators	
void StudentTestScores::setStudentName(string){ //Sets the student's name to the passed string
}

void StudentTestScores::addTestScore(int){ //Adds the passed int as a new test score and increments numTestScores by 1
}
