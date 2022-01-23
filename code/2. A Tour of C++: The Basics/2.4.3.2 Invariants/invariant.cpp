
#include <iostream>
#include "Vector.h"
using namespace std;

Vector::Vector(int s)
{
    if (s < 0)
        throw length_error{"Vector::Vector()"};
    elem = new double[s];
    sz = s;
}

void test()
{
    try
    {
        Vector v(-27);
    }
    catch (length_error)
    {
        // handle negative error
    }
    catch (bad_alloc)
    {
        // handle memory exhaustion
    }
}