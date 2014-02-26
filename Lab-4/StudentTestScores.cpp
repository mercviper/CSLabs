StudentTestScores::StudentTestScores(string name, int numScores){
  studentName=name;
  numTestScores=numScores;
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

/*StudentTestScores::operator=(const StudentTestScores &other){
  studentName=other.studentName;
  testScores=other.testScores;
  numTestScores=other.numTestScores;
}*/
