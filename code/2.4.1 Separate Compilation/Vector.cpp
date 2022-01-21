
// Vector.cpp

#include "Vector.h" // get the interface

Vector::Vector(int s)
    :elem{new double[s]},sz{s}
{
    // code
}

double& Vector::operator[](int i)
{
    return elem[i];
}

int Vector::size()
{
    return sz;
}

