/*
CS 3304
Chris Chan
Last updated 12/4/14
Chapter 15 Lab

Write a program to compress a file using a Huffman code and to decompose a file generated 
using this code. The program should first read through the file and determine the number of 
occurrences of each character in the file and the total number of characters in the file. The 
weight of each character will be the frequency count for that character. The program should 
then use these weights to construct the Huffman codes for the characters in the file. It should 
then read the file again and encode it using these Huffman codes and generate a file containing 
this encoded data. Compute the compression ratio, which is the number of bits in the 
compressed file divided by the total number of bits in the original file (eight times the number 
of characters in the file). The program should also provide the option of decompressing a file 
that was encoded using this Huffman code.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Characters{
	char data;
	int frequency;
	string encoding;
};

struct treeNode{
	char data;
	treeNode * left;
	treeNode * right;
	double weight;
};

treeNode * encodedRoot = new treeNode;

void encode();
void mapEncoding(treeNode *,string,Characters *);
void decode();
void heapify(treeNode *, int);
void swap(treeNode *, treeNode *);
void heapsort(treeNode *, int);
void menu();
int getInt();

int main(){
	menu();
	cin.ignore(INT_MAX, '\n');
	cin.get();
	return 0;
}

void menu(){
	int choice=0;
	enum menuChoices {ENCODE, DECODE, EXIT};
	cout << "Lab exercise for Chapter 15 - Huffman Codes" << endl;
	while(choice!=3){
		cout << "Please pick from the following options:" << endl;
		cout << "[1] Encode a file" << endl;
		cout << "[2] Decode a file" << endl;
		cout << "[3] Exit" << endl << endl;
		choice = getInt();
		cout << endl;
		switch(choice-1){
			case ENCODE:
				encode();
				break;
			case DECODE:
				decode();
				break;
			case EXIT:
				cout << "Goodbye." << endl << endl << "Press enter to close the window...";
				break;
			default:
				cout << "Please enter a valid option." << endl << endl;
		}
	}

}

int getInt(){
	int input;
	do{
		if(cin.fail()){ //if stream buffer had previously failed, clear and reset for valid input
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		cin >> input;

		if(cin.fail()){
			cout << "Not an integer." << endl << endl;
		}
	}while(cin.fail());
	return input;
}

void decode(){	
	fstream inFile;
	string inputFile;
	string outputFile;
	treeNode * p = encodedRoot;
	string input;
	
	cout << "What is the input file to be decoded? (Requires filepath if not in base folder)" << endl;
	cin >> inputFile;
	cout << endl;
	
	cin.ignore(INT_MAX, '\n');
	inFile.open(inputFile, ios::in);
	cout << "Input file reads as follows:" << endl << endl;
	while(!inFile.eof()){//reads file, but not \n characters, will need to add as needed.
		getline(inFile,input);
		cout << input << endl;
	}
	inFile.close();
	
	cout << endl;

	cout << "What is the name of the output file?" << endl;
	cin >> outputFile;
	cout << endl;
	
	ofstream outFile;
	outFile.open(outputFile);

	cin.ignore(INT_MAX, '\n');
	
	inFile.open(inputFile, ios::in);
	cout << "Decoding file..." << endl << endl;
	while(!inFile.eof()){//reads file, but not \n characters, will need to add as needed.
		getline(inFile,input);
		for(int i=0; i<input.length(); i++){
			if(input.at(i)=='1'){
				p=p->right;
				if(p->data!=NULL){
					cout << p->data;
					outFile << p->data;
					p=encodedRoot;
				}
			}
			if(input.at(i)=='0'){
				p=p->left;
				if(p->data!=NULL){
					cout << p->data;
					outFile << p->data;
					p=encodedRoot;
				}
			}
		}
	}
	inFile.close();
	outFile.close();
}

void encode(){
	
	fstream inFile;
	string inputFile;
	string outputFile;
	
	cout << "What is the input file to be encoded? (Requires filepath if not in base folder)" << endl;
	cin >> inputFile;
	cout << endl;
	
	cin.ignore(INT_MAX, '\n');
	
	inFile.open(inputFile, ios::in);
	
	string input;
	string wholeFile="";
	char a;
	bool found=false;
	int x=1;
	Characters * encoding = new Characters[100];
	int encodingSize=0;
	int numChars=0;
	int total=0;

	while(!inFile.eof()){//reads file, but not \n characters, will need to add as needed.
		getline(inFile,input);
		for(int i=0; i<input.length(); i++){
			a=input.at(i);
			while(!found && x<encodingSize){
				if(a==(encoding+x)->data){
					(encoding+x)->frequency++;
					found=true;
				}
				x++;
			}
			if(!found){
				(encoding+encodingSize+1)->data=a;
				(encoding+encodingSize+1)->frequency=1;
				encodingSize++;
			}
			x=1;
			found=false;
		}

		//add the newline here
		a='\n';
		while(!found && x<=encodingSize){
			if(a==(encoding+x)->data){
				(encoding+x)->frequency++;
				found=true;
			}
			x++;
		}
		if(!found){
			(encoding+encodingSize+1)->data=a;
			(encoding+encodingSize+1)->frequency=1;
			encodingSize++;
		}
		x=1;
		found=false;

		total+=input.length()+1;
		wholeFile+=input;
		wholeFile+='\n';
	}
	
	cout << "Input file reads as follows:" << endl << endl << wholeFile << endl;
	cout << "Filesize: " << wholeFile.length()*8 << " bits" << endl << endl;
	cout << "What is the name of the output file?" << endl;
	cin >> outputFile;
	cout << endl;
	
	cin.ignore(INT_MAX, '\n');

	treeNode * encodedTree = new treeNode[encodingSize];
	numChars=encodingSize;

	for(int i=1; i<=encodingSize; i++){ //create weighted binary trees here
		(encodedTree+i)->data=(encoding+i)->data;
		(encodedTree+i)->weight=(double) (encoding+i)->frequency/total;
	}

	//sort the weights
	heapify(encodedTree,encodingSize);
	heapsort(encodedTree,encodingSize);

	//create encoded tree
	treeNode * newNode;
	treeNode * tmpNode;
	while(encodingSize>1){

		//find lowest two weights (end of the list)
		//make tree with those weights
		tmpNode=new treeNode;
		tmpNode->data=encodedTree[encodingSize-1].data;
		tmpNode->left=encodedTree[encodingSize-1].left;
		tmpNode->right=encodedTree[encodingSize-1].right;
		tmpNode->weight=encodedTree[encodingSize-1].weight;

		newNode=new treeNode;
		newNode->data=NULL;
		newNode->weight=(encodedTree+encodingSize)->weight+tmpNode->weight;
		newNode->left=(encodedTree+encodingSize);
		newNode->right=tmpNode;

		encodedTree[encodingSize-1].data=newNode->data;
		encodedTree[encodingSize-1].left=newNode->left;
		encodedTree[encodingSize-1].right=newNode->right;
		encodedTree[encodingSize-1].weight=newNode->weight;
		encodingSize--;
	
		//resort list
		heapify(encodedTree,encodingSize);
		heapsort(encodedTree,encodingSize);
	}
	
	encodedRoot=encodedTree+1;

	mapEncoding(encodedRoot, "", encoding+1);
	string encodedFile="";
	for(int i=0; i<wholeFile.length(); i++){
		found=false;
		a=wholeFile.at(i);
		for(int i=1; !found; i++){
			if((encoding+i)->data==a){
				found=true;
				encodedFile+=(encoding+i)->encoding;
			}
		}
	}
	cout << "Encoded file, " + outputFile + ", is as follows:" << endl << endl << encodedFile << endl << endl;
	cout << "Filesize: " << encodedFile.length() << " bits" << endl << endl;
	cout << "Compression Ratio: " << encodedFile.length() << "/" << wholeFile.length()*8 << " = " << (double)encodedFile.length()/(wholeFile.length()*8)*100 << "%" << endl << endl;

	
	inFile.close();
	ofstream outFile;
	outFile.open(outputFile);
	outFile << encodedFile;
	outFile.close();
}

void heapify(treeNode * heap, int size){
	int c=0;
	int r=0;
	for(int i=size/2;i>0;i--){
		//percolate down
		r=i;
		c=2*i;
		while(r<=size && c<=size){
			if(c<size){
				if(heap[c].weight>heap[c+1].weight)
					c++;
			}
			if(heap[r].weight>heap[c].weight){
				swap(heap[r],heap[c]);
				r=c;
				c=2*c;
			}
			else
				r=size+1;
		}
	}
}

void swap(treeNode * x, treeNode * y){
	treeNode * tmp=x;
	x=y;
	y=tmp;
}

void heapsort(treeNode * heap, int size){
	int r,c;
	for(int i=size; i>=2; i--){
		swap(heap[1],heap[i]);
		//percolate down the root
		r=1;
		c=2;
		while(r<=i-1 && c<=i-1){
			if(c<i-1){
				if(heap[c].weight>heap[c+1].weight)
					c++;
			}
			if(heap[r].weight>heap[c].weight){
				swap(heap[r],heap[c]);
				r=c;
				c=2*c;
			}
			else
				r=i;
		}
	}
}

void mapEncoding(treeNode * p, string bitmap, Characters * charList){
	if(p->data!=NULL){
		bool found=false;
		for(int i=0; !found; i++){
			if((charList+i)->data==p->data){
				found=true;
				(charList+i)->encoding=bitmap;
			}
		}
	}
	else{
		mapEncoding(p->left,bitmap+"0", charList);
		mapEncoding(p->right,bitmap+"1", charList);
	}
}
