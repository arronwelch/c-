#include <iostream>

double sqrt(double);    // the square root function takes a double and returns a double

class Vector{
private:
    double *elem;   // elem points to an array of sz doubles
    int sz;
public:
    Vector(int s);
    double& operator[](int i);
    int size();
};

double sqrt(double d)   // definition of sqrt
{
    // ... algorithm as found in math textbook ...
    return 0.0;
}

Vector::Vector(int s)           //definition of the constructor
    : elem{new double[s]},sz{s} //initialize menbers
{
    // code
}

double& Vector::operator[](int i)   // definition of subscripting
{
    return elem[i];
}

int Vector::size()  // definition of size()
{
    return sz;
}

int main()
{

    return 0;
}