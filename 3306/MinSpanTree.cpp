/*
CS 3306
Chris Chan
Last updated 9/30/14
Write a program using C++ to find the minimal spanning tree of a graph. The graph is 
represented by an adjacency matrix.
*/

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

bool isInMST(int, int[], int); //first param is what wer're looking for, 2nd is the array we're checking, 3rd is size.

int main(){
	fstream inFile;
	string filePath;
	bool complete=false;
	int adjMatrix[10][10]={
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	}, minSpanMatrix[10][10]={
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	}, minSpanVertices[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; //will not have matrix bigger than 10x10
	int numVertices=-1, minVertex=-1, minEdge=-1;
//-	Prompt user for input filepath name.
	cout << "Where is the file located?" << endl;
	cin >> filePath;
	cin.get();
	inFile.open(filePath, ios::in);

	if(!inFile){
		cout << "Error! Missing File! Please try again with a proper filepath." << endl <<"Press enter to close the window...";
		cin.get();
		return 0;
	}
	else{
		inFile >> numVertices;
		inFile >> minSpanVertices[0];
		minSpanVertices[0]-=1;
		minSpanMatrix[minSpanVertices[0]][minSpanVertices[0]]=0;
		inFile.get();	//grabs rest of the line.
		for(int i=0; i<numVertices;i++){
			for(int j=0; j<numVertices;j++){
				inFile >> adjMatrix[i][j];
			}
			inFile.get();
		}
	}
	cout << "File found!" << endl;
	cout << "Adjacency matrix of the input is as follows:" << endl << endl;
	for(int i=0; i<numVertices;i++){
		for(int j=0; j<numVertices;j++){
			cout << adjMatrix[i][j] << "\t";
		}
		cout << endl << endl;
	}
	cout << endl;
	
	cout << "Calculating minimal spanning tree..." << endl;
	while(!complete){
		//determine if the process is complete; e.g. all vertices have been added to the min span tree
		complete=true;
		for(int i=0; i<numVertices; i++){
			if(minSpanVertices[i]==-1){
				complete=false;
				
			}
		}
		if(!complete){
			//find the closest vertex to the existing minimal spanning tree
			int row, col, minRow, minCol;
			for(row=0; row<numVertices;row++){
				if(!isInMST(row,minSpanVertices,numVertices)){
					for(col=0; col<numVertices;col++){
						if(isInMST(col,minSpanVertices,numVertices)){
							if(minEdge<1||(adjMatrix[row][col]<minEdge && adjMatrix[row][col]!=-1)){
								minEdge=adjMatrix[row][col];
								minVertex=row;
								minRow=row;
								minCol=col;
							}
						}
					}
				}
			}

			//add the found vertex to the min span tree
		
			//cout << "Adding this vertex to MST: " << minVertex << endl;
			int count=0;
			while(minSpanVertices[count]!=-1){
				count++;
			}
			minSpanVertices[count]=minVertex;

			//add edge to min span tree
			//cout << "adding this edge to row " << minRow << " and col " << minCol << ":" << minEdge << endl;
			minSpanMatrix[minRow][minCol]=minEdge;
			minSpanMatrix[minCol][minRow]=minEdge;
			minSpanMatrix[minRow][minRow]=0;

			//reset min edge to undefined;
			minEdge=-1;
		}
	}

	cout << "Minimal spanning tree of the given input is as follows:" << endl << endl;
	for(int i=0; i<numVertices;i++){
		for(int j=0; j<numVertices;j++){
			cout << minSpanMatrix[i][j] << "\t";
		}
		cout << endl << endl;
	}
	cout << "Press enter to close the window...";
	cin.get();
	return 0;
}

bool isInMST(int x, int intArr[], int size){
	for(int i=0; i<size; i++)
		if(x==intArr[i])
			return true;
	return false;
}
