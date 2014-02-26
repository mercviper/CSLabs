#ifndef STUDENTTESTSCORES_H
#define STUDENTTESTSCORES_H
#include <string>

using namespace std;

 class StudentTestScores{
    private:
	string studentName;
	double *testScores;
	int numTestScores;
   public:
	StudentTestScores(string name = "", int numScores = 0);	// class constructor	StudentTestScores(const StudentTestScores &other);      // class copy constructor
	~StudentTestScores();  				// class destructor
//  *** ADD a display member function that displays a student's test scores in the // following format:
//  student Name <tab> number of test scores <tab> test scores separated by tabs <endl>
	void Display();
								
	
//  *** ADD accessors & mutators HERE	

	
	// void operator=(const StudentTestScores   &other);

// *** Stream I/O operations here
};
#endif 
