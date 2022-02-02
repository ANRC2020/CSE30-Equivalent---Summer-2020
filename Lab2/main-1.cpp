//CLASS and OOP
#include <iostream>
using namespace std;

class Person {
    private: // age is private, so we can't access age via "alex.age"
        int age;
        double weight;
    public: // provides ways to access(show/change) the private age
        void showAge();
        void changeAge(int newAge);
        void showWeight();
        void changeWeight(double weight);
        Person(); // Default Constructor
        Person(int newAge); // Explicit Constructor
};

void Person::showAge()
{
    cout << age << endl;
}
void Person::changeAge(int newAge)
{
    age = newAge;
}
void Person::showWeight()
{
    cout << weight << endl;
}
void Person::changeWeight(double newWeight)
{
    weight = newWeight;
}
Person:: Person() { // default constructor
    age = 101;
    weight = 101;
}
Person::Person(int newAge) { // explicit constructor
    age = newAge;
}

int main()
{
    Person alex; // use Default Constructor
    alex.showAge(); // Garbage w/o Default Constructor, 101 with
    alex.changeAge(36);
    alex.showAge();
    alex.showWeight();
    alex.changeWeight(50);
    alex.showWeight();

    Person child(8);
    child.showAge();
}

/*
C:\Users\siddi\CLionProjects\untitled\cmake-build-debug\untitled.exe
101
36
101
50
8

Process finished with exit code 0
*/