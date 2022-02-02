#include <iostream>
using namespace std;

class Distance {
private:
    int meter;
public:
    //constructor
    Distance (int m) {
        meter = m;
    }
    // overload
    bool operator < (const Distance d) {
        return meter < d.meter;
    }
    bool operator > (const Distance d) {
        return meter > d.meter;
    }
    // overload ==
    bool operator == (const Distance &d) {
        return meter == d.meter;
    }
    // overload <=
    bool operator <= (const Distance &d) {
        return meter <= d.meter;
    }
    // overload >=
    bool operator >= (const Distance &d) {
        return meter >= d.meter;
    }
    // overload !=
    bool operator != (const Distance &d) {
        return meter != d.meter;
    }
    // overload =
    bool operator = (const Distance &d) {
        return meter != d.meter;
    }
    // overload +
    Distance operator + (const Distance &d){
        Distance dist(0);
        dist.meter = this->meter + d.meter; // "this" = di; d = d2
        return dist;
    }
    // overload -
    Distance operator - (const Distance &d){
        Distance dist(0);
        dist.meter = this->meter - d.meter; // "this" = di; d = d2
        return dist;
    }
    // overload /
    Distance operator / (const Distance &d){
        Distance dist(0);
        dist.meter = this->meter / d.meter; // "this" = di; d = d2
        return dist;
    }
    // overload *
    Distance operator * (const Distance &d){
        Distance dist(0);
        dist.meter = this->meter * d.meter; // "this" = di; d = d2
        return dist;
    }
    // overload <<
    friend ostream &operator << ( ostream &output, const Distance &D){
        output << D.meter << "m" << endl;
        return output; // missing return statement
    }
    // over load >>
    friend istream &operator >> (istream &input, Distance &D){
        input >> D.meter;
        return input;
    }
};

int main() {
    Distance d1(4), d2(2), d3(0), d4(4);
    cout << boolalpha;
    cout << "d1 = " << d1; // overload << for d1, d2, d3, d4
    cout << "d2 = " << d2;
    cout << "d3 = " << d3;
    cout << "d4 = " << d4;
    d4 = d1+d2;
    cout << "d1 + d2 = d4 = " << d2 + d1;
    cout << "d1 - d2 = d4 = " << d2 - d1;
    cout << "d2 * d1 = d4 = " << d2 * d1;
    cout << "d2 / d1 = d4 = " << d2 / d1;
    cout << "(d1 < d2) is " << (d1 < d2) << endl;
    cout << "(d3 < d1) is " << (d3 < d1) << endl;
    cout << "(d2 > d3) is " << (d2 > d3) << endl;
    cout << "(d1 > d2) is " << (d1 > d2) << endl;
    cout << "(d4 == d1) is " << (d4 == d1) << endl;
    cout << "(d4 != d1) is " << (d4 != d1) << endl;
    cout << "(d1 <= d4) is " << (d1 <= d4) << endl;
    cout << "(d3 >= d2) is " << (d3 >= d2) << endl;
    cout << "Enter d4:";
    cin >> d4;
    cout << "d4 = " << d4;
}

/*
C:\Users\siddi\CLionProjects\p8p2\cmake-build-debug\p8p2.exe
d1 = 4m
d2 = 2m
d3 = 0m
d4 = 4m
d1 + d2 = d4 = 6m
d1 - d2 = d4 = -2m // Override -
d2 * d1 = d4 = 8m // Override *
d2 / d1 = d4 = 0m // Override /
(d1 < d2) is false // Override >
(d3 < d1) is true
(d2 > d3) is true // Override <
(d1 > d2) is true
(d4 == d1) is true
(d4 != d1) is false
(d1 <= d4) is true // Override <=
(d3 >= d2) is false // Override >=
Enter d4: 68
d4 = 68m

Process finished with exit code 0

 */