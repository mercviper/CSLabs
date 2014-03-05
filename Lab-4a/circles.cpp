#include <iostream>
using namespace std;
//_________________________________________________________________________
// This program declares a class for a circle that will have 
// member functions that set the center, find the area, find
// the circumference and display these attributes.
// The program as written does not allow the user to input data, but
// rather has the radii and center coordinates of the circles (spheres in the program) 
// initialized  at declaration or set by a function.

//class declaration section   (header file)

class Circles    
{
public:
   void setCenter(int x, int y);
   double findArea();   
   double findCircumference(); 
   void printCircleStats(); // This outputs the radius and center of the circle. 
   Circles (float r);       // Constructor
   Circles();               // Default constructor
private: 
   float  radius;
   int    center_x;
   int    center_y;
};      


const double PI = 3.14;

//Client section   

int main()
{
   Circles sphere(8);
   sphere.setCenter(9,10);
   sphere.printCircleStats();
   char ch;
   cin >> ch;

   return 0;
}

//___________________________________________________________________________
//Implementation section     Member function implementation

Circles::Circles()
{
   radius = 1;
   center_y = 0;
   center_x = 0;
}
// Fill in the code to implement the non-default constructor
Circles::Circles(float r)
{
   radius = r;
   center_y = 0;
   center_x = 0;
}

// Fill in the code to implement the findArea member function
double Circles::findArea(){
	double area=0;
	area = PI*radius*radius;
	return area;
}

// Fill in the code to implement the findCircumference member function
double Circles::findCircumference(){
	double circ=0;
	circ = 2*PI*radius;
	return circ;
}

void Circles::printCircleStats()
// This procedure prints out the radius and center coordinates of the circle
// object that calls it.

{
   cout << "The radius of the circle is " << radius << endl;
   cout << "The center of the circle is (" << center_x 
        << "," << center_y << ")" << endl;
   cout << "The area of the circle is " << findArea() << endl;
   cout << "The circumference of the circle is (" << findCircumference() << endl;
}

void Circles::setCenter(int x, int y)
// This procedure will take the coordinates of the center of the circle from 
// the user and place them in the appropriate member data.

{
   center_x = x;
   center_y = y;
} 
