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
<<<<<<< HEAD
	for (int element = 0; element < Student.getNumTestScores(); element++) //modify size variable accordingly 
		out << Student.testScores[element] << endl;
	out << Student.getNumTestScores() << endl;
=======
	for (int i = 0; i < Student.NumTestScores; i++) 
		cout << Student.testScores[i] << endl;
	out << Student.numTestScores << endl;
	return out;
>>>>>>> Input/Output-Overloads
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
