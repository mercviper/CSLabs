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
    	StudentTestScores(string name="", int numScores=0) {studentName=name; numTestScores=numScores;} //default constructor, sets studentName to "" and numTestScores to 0;
	StudentTestScores(const StudentTestScores &other);      // class copy constructor
	~StudentTestScores();  				// class destructor
//  *** ADD a display member function that displays a student's test scores in the // following format:
//  student Name <tab> number of test scores <tab> test scores separated by tabs <endl>
	void Display();
								
	
//  *** ADD accessors & mutators HERE	
	/* accessors*/
	string getStudentName(); //returns studentName
	double * getTestScores(); //returns testScores
	int getNumTestScores(); // returns numTestScores
	
	/*mutators*/
	
	void setStudentName(string); //Sets the student's name to the passed string
	void addTestScore(double); //Adds the passed int as a new test score and increments numTestScores by 1
	

	
	void operator=(const StudentTestScores &other);

// *** Stream I/O operations here
	
	friend ofstream& operator<< (ostream &out, const StudentTestScores &);
	friend ifstream& operator>> (ostream &out, StudentTestScores &);
	
};
#endif 
