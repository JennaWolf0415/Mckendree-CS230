//program: lab10_p2
//purpose: This program is used to test out abstract base classes. It has an abstract base class named basic shape
//with a pure virtual function called calcArea. It has two inheritaed classes that give calcArea their own defenitions.
//name: Jenna Wolf
//student id: 0347845
//date: May 1st, 2023
#include <iostream>

using namespace std;

class BasicShape
{
    protected:
        double area;    //holds the area data
    public:
        double getArea();
        virtual void calcArea() = 0;
};

class Circle : public BasicShape
{
    private:
        long centerX;   //holds the centerX data
        long centerY;   //holds the centerY data
        double radius;
    public:
        Circle(long, long, double);
        long getCenterX();
        long getCenterY();
        void calcArea();
};

class Rectangle : public BasicShape
{
    private:
        long width;     //holds the width data
        long length;    //holds the length data
    public:
        Rectangle(long, long);
        long getWidth();
        long getLength();
        void calcArea();
};

int main()
{
    Circle c(5, 6, 7);  //holds the c data and sets its data
    Rectangle r(8, 10); //holds the r data and sets its data
    
    //says what this program does
    cout << "This progam tests out abstract base classes and pure virtual classes. c and r will display differebt" << endl;
    cout << "areas due to their base class of BasicShape being an abstract base class and the calcArea function" << endl;
    cout << "being a pure virtual class" << endl;
    
    
    //displays the data in c and r
    cout << c.getCenterX() << " " << c.getCenterY() << " " << c.getArea() << endl;
    cout << r.getWidth() << " " << r.getLength() << " " << r.getArea() << endl;

    return 0;
}

//prupose: Returns the data stored in area
//arguments: no arguments
double BasicShape::getArea()
{
    return area;    //returns the data stored in area
}

//purpose: sets the elements of circle and calls the calcArea function
//arguments: a, b, and c all hold the data that the elements of c are being set to
Circle::Circle(long a, long b, double c)
{
    centerX = a;    //sets centerX to a
    centerY = b;    //sets centerY to b
    radius = c;     //sets radius to c
    calcArea();     //calcs the calcArea function
}

//purpose: returns the data in centerX
//arguments: no arguments
long Circle::getCenterX()
{
    return centerX; //returns centerX
}

//purpose: returns the data in centerY
//arguments: no arguments
long Circle::getCenterY()
{
    return centerY; //returns centerY
}

//purpose: calculates the area of a circle
//argmuents: no arguments
void Circle::calcArea()
{
    area = 3.14159 * radius * radius; //sets area to pi times radius squared
}

//purpose: sets the elements of rectangle and calls calcArea
//arguments: a and b hold the data width and length get set to
Rectangle::Rectangle(long a, long b)
{
    width = a;      //sets width to a
    length = b;     //sets length to b
    calcArea();     //calls calcArea
}

//purpose: return the data stored in width
//arguments: no arguments
long Rectangle::getWidth()
{
    return width;   //returns the data stored in width
}

//purpose: return the data stored in length
//arguments: no arguments
long Rectangle::getLength()
{
    return length;  //returns the data stored in length
}

//purpose: calculated the area of a rectangle
//arguments: none
void Rectangle::calcArea()
{
    area = length * width;  //sets area to length times width
}