#include <iostream>
#include <cassert>
using namespace std;

void area (float width, float height)
// Precondition: width > 0 and height > 0
// Postcondition: shows area of rectangle ...
// ... "area is" + width+height shown via cout <<
{
    assert(width > 0 && height > 0);
    cout << "Area is " << width * height << endl;
}

void perimeter (float width, float height)
// Precondition: width > 0 and height > 0
// Postcondition: shows area of rectangle...
// ... "area is" + width + height shown via cout <<
{
    assert(width > 0 && height > 0);
    cout << "Perimeter is " << 2* (width + height) << endl;
}

