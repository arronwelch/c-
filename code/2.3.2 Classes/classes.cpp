#include <iostream>
using namespace std;

struct Vector
{
private:
    double *elem; // pointer to the elements
    int sz;       // the number of elements

public:
    Vector(int s) : elem{new double[s]}, sz{s} {}   //construct a Vector
    double &operator[](int i) { return elem[i];}    //element access:subscripting
    int size() { return sz;}
};

double read_and_sum(int s)
{
    Vector v(s);    // make a vevtor of s elements
    for(int i=0; i!= v.size();++i)
        cin >> v[i];    // read into elements
    
    double sum = 0;
    for(int i=0; i!=v.size(); ++i)
        sum+=v[i];  // take the sum of the elements
    return sum;
}

int main()
{
    int sum = 0;
    cout << "please input v[5] (splite by space):\n";
    sum = read_and_sum(5);
    cout << "sum = " << sum << "\n";

    return 0;
}

/*
test input:
>> 1 2 3 4 5
<< 15
*/