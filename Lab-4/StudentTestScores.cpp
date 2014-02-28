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
