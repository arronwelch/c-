
#include <iostream>
using namespace std;

// extern int gl;

class A
{
    // private:
    //     int i;
public:
    int i;
    void f();
};

void A::f()
{
    i = 20;
    cout << i << endl;
}

int main()
{
    A a;
    A b;
    a.i = 10;
    cout << a.i << endl;
    a.f();
    cout << a.i << endl;

    cout << "-------" << endl;
    b.f();
    cout << b.i << endl;
}
