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

//accessors
string StudentTestScores::getStudentName(){ //returns studentName
}

int StudentTestScores::getTestScores(){ //returns testScores
}

int StudentTestScores::getNumTestScores(){ // returns numTestScores
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
