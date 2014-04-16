#include <string>
#include <iostream>
using namespace std;

class StudentTestScores{
    private:
	string studentName;
	double *testScores;
	int numTestScores;
	char letterGrade;
    public:
    StudentTestScores(string name="", int numScores=0, char grade=' '){
		studentName=name;
		numTestScores=numScores;
		letterGrade=grade;
		testScores = new double[numTestScores];
	} //default constructor, sets studentName to "" and numTestScores to 0;
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
	double averageTestScore();
	

	
	void operator=(const StudentTestScores &other);

// *** Stream I/O operations here
	
	friend ostream& operator<< (ostream &out, const StudentTestScores &);
	friend istream& operator>> (istream &out, StudentTestScores &);
	
};
