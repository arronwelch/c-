
bool a;   // Boolean,possible values are true and false.
char c;   // character,for example,'a','z',and '9'
int i;    // integer,for example,1,42,and 1066
double d; // double-precision floating-point number,for example,3.14 and 299793.0
/*
 bool   []
 char   []
 int    [][][][]
 double [][][][][][][][]
 sizeof(char) equals 1 and sizeof(int) is often 4.
*/

/*

x+y // plus
+x  // unary plus
x-y // minus
-x  // unary minus
x*y // multiply
x/y // divide
x%y // remainder (modulus) for integers.

x==y    //equal
x!=y    //not equal
x<y     //less than
x>y     //greater than
x<=y    //less than or equal
x>=y    //greater than or equal

*/

/* meaningful conversions(10.5.3) */
void some_function() // function that doesn't return a value
{
    double d = 2.2; // initialize floating-point number
    int i = 7;      // initialize integer
    d = d + i;      // assign sum to d
    i = d * i;      // assign product to i(turncating the double d*i to an int)
    /* Note that = is the assignment operator and == tests equality */
}

double d1 = 2.3;
double d2{2.3};

#include <complex>
#include <iostream>
using namespace std;

/* {}-list form(6.3.5.2) */
complex<double> z = 1; // a complex number with double-precision floating-point scalars
complex<double> z2{d1, d2};
complex<double> z3 = {1, 2}; // the = is optional with {...}

#include <vector>
vector<int> v{1, 2, 3, 4, 5, 6}; // a vector of ints

/* narrowing conversions(10.5) */
int i1 = 7.2; // i1 becomes 7
// error: narrowing conversion of ‘7.2000000000000002e+0’ from ‘double’ to ‘int’ [-Wnarrowing]
// int i2{7.2};    // error:floating-point to integer conversion [-Wnarrowing]
// int i3={7.2};   // error:floating-point to integer conversion(the = is redundant)

/*
User-defined types(such as string, vector, Matrix, Motor_controller, and Orc_warrior) can be defined to be
implicitly initialized(3.2.1.1)
*/

/*
you don't actually need to state its type explicity when it can be
deduced from the initializer.
*/
auto b = true;      // a bool
auto ch = 'x';      // a character
auto ia = 123;      // an integer
auto da = 1.2;      // a double
auto za = sqrt(da); // z has the type of whatever sqrt(y) returns

/*
conventional arithmetic and logical operators(10.3)

x+=y    // x = x + y
++x     // increment: x = x + 1
x-=y    // x = x - y
--x     // decrement: x = x - 1
x*=y    // scaling: x = x*y
x/=y    // scaling: x = x/y
x%=y    // x = x%y

These operators are concise, convenient, and very frequently used.
*/

int main() {}