/*

CS 3304 Data and Information Structures
Chris Chan
last updated 11/25/2014

Lab – Chapter 13
This lab is for Chapter 13.
Write a heapsort program that generates random numbers and insert them in heap. The 
program then performs heapsort to sort the numbers in ascending order. Implement the heap 
using an array and compare its performance to STL heap implementation.
Requirements:
1. Use random number generator to generate integers numbers in range [0..1000]. Your 
program should prompt the user for the total number of numbers to generate. A listing 
of the generated numbers should be printed on screen in the order they are generated.
Allocate a dynamic array to store the numbers.
2. Construct the heap by performing the heapify algorithm. 
3. Once the heap is constructed, perform heapsort algorithm and display the sorted list on 
screen.
4. Use STL heap algorithms to redo Steps 1-3. Take the times of both implementations. 
However, exclude the times for printing numbers on screen. Display the times of both 
implementations on screen.
5. Prompt the user whether he/she wants to work on another list of numbers and repeat 
Step 1-4 if the user answers “Yes”

*/

#include <random>
#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
#include <vector>

using namespace std;

int getInt();
void heapify(int *, int);
void swap(int *, int *);
void heapsort(int *, int);

int main(){
	time_t tp;
	srand(time(&tp));
	bool exit=false;
	string redo="";
	int numRand=0;
	clock_t begin = clock();
	clock_t end = clock();
	double elapsed_secs1 = 0;
	double elapsed_secs2 = 0;
	double elapsed_secs3 = 0;
	while(!exit){
		cout << "How many numbers do you want to generate?" << endl;
		numRand=getInt();
		int * heap = new int[numRand+1];
		cout << "Generating numbers..." << endl << endl;
		for(int i=1; i<=numRand; i++){
			heap[i]=rand()%1001;
			cout << heap[i] << " ";
		}
		cout << endl << endl;

		cout << "Heapifying numbers..." << endl << endl;
		begin = clock();
		heapify(heap, numRand);
		end = clock();
		elapsed_secs1=double(end - begin) / CLOCKS_PER_SEC;
		cout << elapsed_secs1 << " seconds have elapsed while heapifying." << endl << endl;

		for(int i=1; i<=numRand; i++){
			cout << heap[i] << " ";
		}
		cout << endl << endl;

		cout << "Sorting numbers..." << endl << endl;
		begin = clock();
		heapsort(heap, numRand);
		end = clock();
		elapsed_secs2=double(end - begin) / CLOCKS_PER_SEC;
		cout << elapsed_secs2 << " seconds have elapsed while sorting." << endl << endl;

		for(int i=1; i<=numRand; i++){
			cout << heap[i] << " ";
		}
		cout << endl << endl;
		
		elapsed_secs3=elapsed_secs1+elapsed_secs2;
		cout << elapsed_secs3 << " total seconds have elapsed while heapifying & sorting." << endl << endl;
		

		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Press any key to continue and repeat number generation, heapifying, and sorting using STL heap algorithms" << endl;
		cin.get();

		cout << "**********************************************" << endl << endl;

		cout << "Generating numbers for STL algorithms..." << endl << endl;
		for(int i=1; i<=numRand; i++){
			heap[i]=rand()%1001;
			cout << heap[i] << " ";
		}
		cout << endl << endl;
		vector<int> v(heap+1,heap+numRand+1);

		cout << "Heapifying numbers with STL algorithms..." << endl << endl;
		begin = clock();
		make_heap(v.begin(),v.end());
		end = clock();
		for (unsigned i=0; i<v.size(); i++)
			cout << v.at(i) << " ";
		cout << endl << endl;
		elapsed_secs1=double(end - begin) / CLOCKS_PER_SEC;
		cout << elapsed_secs1 << " seconds have elapsed while heapifying with STL algorithms." << endl << endl;
		
		cout << "Sorting numbers with STL algorithms..." << endl << endl;
		begin = clock();
		sort_heap(v.begin(),v.end());
		end = clock();
		for (unsigned i=0; i<v.size(); i++)
			cout << v.at(i) << " ";
		cout << endl << endl;
		elapsed_secs2=double(end - begin) / CLOCKS_PER_SEC;
		cout << elapsed_secs2 << " seconds have elapsed while sorting with STL algorithms." << endl << endl;
		
		cout << elapsed_secs2+elapsed_secs1 << " total seconds have elapsed while heapifying & sorting with STL algorithms." << endl << endl;
		cout << elapsed_secs3 << " total seconds have elapsed while heapifying & sorting without STL algorithms." << endl << endl;

		cout << "Do you want to generate another list? (N to exit)" << endl;
		cin >> redo;
		if(redo=="N" || redo == "n")
			exit=true;
		delete heap;
	}

	cin.clear();
	cin.ignore(INT_MAX, '\n');
	cout << "Press any key to close the window..." << endl;
	cin.get();
	return 0;
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

void heapify(int * heap, int size){
	int c=0;
	int r=0;
	for(int i=size/2;i>0;i--){
		//percolate down
		r=i;
		c=2*i;
		while(r<=size && c<=size){
			if(c<size){
				if(heap[c]<heap[c+1])
					c++;
			}
			if(heap[r]<heap[c]){
				swap(heap[r],heap[c]);
				r=c;
				c=2*c;
			}
			else
				r=size+1;
		}
	}
}

void swap(int * x, int * y){
	int * tmp=x;
	x=y;
	y=tmp;
}

void heapsort(int * heap, int size){
	int r,c;
	for(int i=size; i>=2; i--){
		swap(heap[1],heap[i]);
		//percolate down the root
		r=1;
		c=2;
		while(r<=i-1 && c<=i-1){
			if(c<i-1){
				if(heap[c]<heap[c+1])
					c++;
			}
			if(heap[r]<heap[c]){
				swap(heap[r],heap[c]);
				r=c;
				c=2*c;
			}
			else
				r=i;
		}
	}
}
