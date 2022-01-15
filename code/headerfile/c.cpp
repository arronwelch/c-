#include <stdio.h>

//#include <iostream>
//using namespace std;

class A
{
public:
    A(int initialize);
    ~A();
    int i;
    void f();
};

struct B
{
    int i;
};

void A::f()
{
    i = 20;
    printf("&i = %p\n",&i);
}

void A::A( int initialize)
{
    i = initialize;
    printf("In init\n");
}

void A::~A()
{
    printf("In de\n");
}  

void f(struct B* p)
{
    p->i = 21;
}

int main()
{
    A a(10);
    B b;
    //cout << a.i << endl;
    printf("&a = %p\n",&a);
    printf("&a.i=%p\n",&a.i);
    a.f();
    //cout << a.i << endl;

    //cout << "-------" << endl;
    b.i = 11;
    //cout << b.i << endl;
    f(&b);
    //cout << b.i << endl;
}
