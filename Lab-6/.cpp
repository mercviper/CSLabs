#include <iostream>
#include <fstream>

using namespace std;

main(){
  cout << "Please enter file location." << endl; 	    //Prompt user for input filepath name.
  getline(cin, fileLocation);                         //Read file data to program.
  ifstream fileName;                                  //Create fstream variable
  fileName.open(fileLocation);                        //open file
  cout << "Opening file...\n"; 
  getline(fileName, #students);                       //	First line data = #students
  int StudentTestScores[#students];                   //	Create StudentTestScores array Scores of #students
  while (i < #students, getline(fileName,line){       //	For each i < #students, read a line from the fstream into Scores[i]
    fileName >> StudentTestScores[i];
    i++;
  }
  fileName.close();
