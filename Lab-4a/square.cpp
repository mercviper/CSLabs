#include <iostream>
using namespace std;

class Square{// FILL IN THE CODE TO DECLARE A CLASS CALLED Square.  TO DO THIS SEE
private:// THE IMPLEMENTATION SECTION.
	float side;
public:
	void setSide(float);
	float findArea() const;
	float findPerimeter() const;

	Square();
	Square(int);  // add these after commiting
	~Square();
};

int main()
{
    Square  box;          // box is defined as an object of the Square class
    float   size;         // size contains the length of a side of the square  

   // FILL IN THE CLIENT CODE THAT WILL ASK THE USER FOR THE LENGTH OF THE SIDE
   // OF THE SQUARE.  (This is stored in size)
   cout << "What is the length of one side of the square?" << endl;
   cin >> size;
	
   // FILL IN THE CODE THAT CALLS SetSide.
   box.setSide(size);

   // FILL IN THE CODE THAT WILL RETURN THE AREA FROM A CALL TO A FUNCTION
   // AND PRINT OUT THE AREA TO THE SCREEN 
   cout << "This is the Area of the square:\n" << box.findArea() << endl;

   // FILL IN THE CODE THAT WILL RETURN THE PERIMETER FROM A CALL TO A 
   // FUNCTION AND PRINT OUT THAT VALUE TO THE SCREEN 
   cout << "This is the Perimeter of the square:\n" << box.findPerimeter();
   
   char st;
   cin >> st;
   
    Square box1(9);
    cout << "The area of box1 is " << box1.findArea() << endl;
    cout << "The perimeter of box1 is "<< box1.findPerimeter() << endl;
    
	return 0;
}

//__________________________________________________________________
//Implementation section     Member function implementation

Square::Square()
{
	side = 1;
}

Square::Square(int x)
{
	side = x;
}
//**************************************************
//                  setSide
//
// task:    This procedure takes the length of a side and
//          places it in the appropriate member data
// data in: length of a side
//***************************************************

void Square::setSide(float length)
 
{
   side = length;	
}
//**************************************************
//                 findArea
//
// task:    This finds the area of a square
// data in: none (uses value of data member side)
// data returned:  area of square
//***************************************************

float Square::findArea() const
{
   return side * side;
}
//**************************************************
//                 findPerimeter
//
// task:    This finds the perimeter of a square
// data in: none (uses value of data member side)
// data returned:  perimeter of square
//***************************************************	
float Square::findPerimeter() const
{
   return 4 * side;
}
