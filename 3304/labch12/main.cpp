/*
CS 3304
Chris Chan
Last updated 11/13/14

Chapter 12 Lab

Write a spell checker, that is, a program that reads the words in a piece of text and looks up 
each of them in a dictionary to check its spelling. Use a BST to store this dictionary, reading the 
list of words from a file. While checking the spelling of words in a piece of text, the program 
should print a list of all words not found in the dictionary
*/


#ifndef BinaryTree_h
	#include "BinaryTree.h"
#endif
#include <fstream>
using namespace std;

int main(){
	fstream inFile;
	string filePath;
	BinaryTree * dictionary=new BinaryTree();
	string word;
	

	cout << "Where is the dictionary file located?" << endl;
	cin >> filePath;
	
	cin.get();
	inFile.open(filePath, ios::in);
	
	if(!inFile){
		cout << "Error! Missing File! Please try again with a proper filepath." << endl <<"Press enter to close the window...";
		cin.get();
		return 0;
	}
	else{
		cout << "The dictionary is as follows:" << endl << endl;
		while(!inFile.eof()){
			inFile >> word;
			cout << word << " ";
			dictionary->insertNode(word);
		}
		cout << endl << endl;
	}
	inFile.close();

	cout << "Where is the input file located?" << endl;
	cin >> filePath;

	inFile.open(filePath, ios::in);
	
	if(!inFile){
		cout << "Error! Missing File! Please try again with a proper filepath." << endl <<"Press enter to close the window...";
		cin.get();
		return 0;
	}
	else{
		cout << "The input is as follows:" << endl << endl;
		while(!inFile.eof()){
			inFile >> word;
			cout << word << " ";
		}
		cout << endl << endl;
	}
	inFile.close();

	cout << "The following words are misspelled:" << endl << endl;

	inFile.open(filePath, ios::in);
	
	if(!inFile){
		cout << "Error! Missing File! Please try again with a proper filepath." << endl <<"Press enter to close the window...";
		cin.get();
		return 0;
	}
	else{
		while(!inFile.eof()){
			inFile >> word;
			if(dictionary->findNode(word)==-1)
				cout << word << endl;
		}
	}
	inFile.close();
	cin.get();
	cin.get();
	return 0;
}
