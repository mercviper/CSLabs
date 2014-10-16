/*
CS 3304
Chris Chan
Last updated 10/16/14

Chapter 10 Lab
1. Use random number generator to generate 12 prices in range $1 ~ $100 inclusively.
2. Generated numbers must be displayed on screen. On a separate line, the sequence of 
price differences are displayed, properly aligned with generated numbers. Then the 
numbers are sorted using STL Sort algorithm and the sorted list is displayed. The trading 
range is displayed in the last line. All output must be properly labeled.
3. The program must run in cyclic fashion, each time asking the user whether he/she wants 
to repeat. Using a different seed to initialize the random number generator each time so
that a different sequence of numbers is generated.
*/

#include <random>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

int getInt();
void generatePrices();

int main(){
	enum menuChoices {PRICE, EXIT};
	int choice=0;
	cout << "Lab exercise for Chapter 10 Rand numbers" << endl;
	while(choice!=2){
		cout << "Please pick from the following options:" << endl;
		cout << "[1] Generate 12 prices" << endl;
		cout << "[2] Exit" << endl << endl;
		choice = getInt();
		cout << endl;
		switch(choice-1){
			case PRICE:
				generatePrices();
				break;
			case EXIT:
				cout << "Goodbye." << endl << endl;
				break;
			default:
				cout << "Please enter a valid option." << endl << endl;
		}
	}
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

void generatePrices(){
	time_t tp;
	srand(time(&tp));
	vector<int> prices;

	cout << "Prices over a 12-day period:" << endl << endl;
	for(int i=0; i<12; i++){
		prices.push_back(rand()%100+1);
		cout << "Day " << i+1 << ": $" << prices.at(i) << "\t";
	}
	cout << endl << endl;
	
	cout << "Change in prices:" << endl << endl;
	
	cout << "Day 1: N/A\t";
	for(int i=1; i<12; i++){
		if(prices.at(i)-prices.at(i-1)<0){
			cout << "Day " << i+1 << ": -$" << abs(prices.at(i)-prices.at(i-1)) << "\t";
		}
		else{
			cout << "Day " << i+1 << ": $" << prices.at(i)-prices.at(i-1) << "\t";
		}
	}
	cout << endl << endl;

	//sort prices
	sort(prices.begin(), prices.end());

	cout << "Sorted prices:" << endl << endl;
	for(int i=0; i<12; i++){
		cout << "$" << prices.at(i) << " ";
	}
	cout << endl << endl;

	cout << "Range of prices: $" << prices.at(0) << " - $" << prices.at(11) << endl << endl;
}
