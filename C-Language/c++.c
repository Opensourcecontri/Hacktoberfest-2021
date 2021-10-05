#include<iostream.h>
#include<conio.h>

// create a class

class Room
{
   public:
    double length;
    double breadth;
    double height;

    double calculateArea()
   {
        return length * breadth;
    }

    double calculateVolume()
    {
        return length * breadth * height;
    }
};

void main()

{

    // create object of Room class
    Room lectureroom;

    // assign values to data members
   lectureroom.length = 42.5;
lectureroom.breadth = 30.8;
    lectureroom.height = 19.2;

    // calculate and display the area and volume of the room

    cout << "Area of Room =  " << lectureroom.calculateArea() << endl;
    cout << "Volume of Room =  " << lectureroom.calculateVolume() << endl;

    getch();
}
