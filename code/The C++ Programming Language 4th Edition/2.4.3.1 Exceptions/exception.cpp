
#include <iostream>
#include "Vector.h"
using namespace std;

double &Vector::operator[](int i)
{
    if (i < 0 || size() <= i)
        throw out_of_range{"Vector::operator[]"};
    return elem[i];
}

void f(Vector &v)
{
    // ...
    try
    {
        v[v.size()] = 7; // try to access beyond the end of v
    }
    catch (out_of_range) // opps: out_of_range error
    {
        // ... handle range error ...
    }
    // ...
}