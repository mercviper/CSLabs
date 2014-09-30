/*
Write a program using C++ to find the minimal spanning tree of a graph. The graph is 
represented by an adjacency matrix.
*/

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	fstream inFile;
	string filePath;
	int adjMatrix[10][10]; //will not have matrix bigger than 10x10
	int numVertices=0, startVertex=0;
//-	Prompt user for input filepath name.
	cout << "Where is the file located?" << endl;
	cin >> filePath;
	cin.get();
	inFile.open(filePath, ios::in);

	if(!inFile){
		cout << "Error! Missing File! Please enter a proper filepath.";
		return 0;
	}
	else{
		inFile >> numVertices;
		inFile >> startVertex;
		inFile.get(); //grabs rest of the line.
		/*scores = new StudentTestScores[numStudents];
		for(int i = 0; i < numStudents; i++){
			inFile >> scores[i];
			inFile.get();
		}*/
	}
	cin.get();
	return 0;
}
