/*
    const---"I promise not to change this value"(7.5)
        data can be passed to functions without fear of it being modified.
    const---"to be evaluated at compile time"(10.4)
*/

constexpr double square(double x)
{
    return x * x;
}

const int dmv = 17;                        // dmv is a named constant
int var = 17;                              // var is not a constant
constexpr double max1 = 1.4 * square(dmv); // OK if square(17) is a constant expression
// constexpr double max2 = 1.4 * square(var); // error: var is not a constant expression
const double max3 = 1.4 * square(var);     // OK, may be evaluated at run time

#include <iostream>
#include <vector>
using namespace std;

double sum(const vector<double>&);  // sum will not modify its argument(2.2.5)
vector<double> v {1.2, 3.4, 4.5};   // v is not a constant
const double s1 = sum(v);           // OK, evaluated at run time
// constexpr double s2 = sum(v);           // error:sum(v) not constant expression


int main()
{
    cout << "17*17 = " << 1.4 * 17 * 17 << "\n";
    cout << "square(dmv) = " << 1.4 * square(dmv) << "\n";
    cout << "max1 = " << max1 << "\n";
}

double sum(const vector<double>&)
{
    return 1.0;
}