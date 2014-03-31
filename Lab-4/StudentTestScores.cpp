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
	out << "Name: " << Student.studentName << endl;
	out << "Test Scores: ";
	for (int i = 0; i < Student.NumTestScores; i++) 
		cout << Student.testScores[i] << endl;
	out << Student.numTestScores << endl;
	return out;
}

friend ifstream& operator>> (ifstream &in, StudentTestScores &Student)
{
	cout << "Enter student's name and test scores." << endl;
	in >> Student.studentName >> endl; 		
	for (int i=0; i < Student.numTestScores; i++)
		cin >> Student.*testScores[i] >> endl;
	return in;
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
