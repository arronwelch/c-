
#include <iostream>
using namespace std;

bool accept()
{
    cout << "Do you want to proceed(y or n)?\n";    // write question

    char answer = 0;
    cin >> answer;  // read answer

    if (answer == 'y')
    {
        return true;
    }
    return false; 
}

bool accept2()
{
    cout << "Do you want to procced(y or n)?\n";    // write question

    char answer = 0;
    cin >> answer;  // read answer

    switch (answer)
    {
    case 'y':
        return true;
    case 'n':
        return false;
    default:
        cout << "I'll take that for a no.\n";
        return false;
    }
}

bool accept3()
{
    int tries = 1;
    while ( tries < 4)
    {
        cout << "Do you want to procced(y or n)?\n";    // write question
        char answer = 0;
        cin >> answer;  // read answer

        switch (answer)
        {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            cout << "Sorry,I don't understand that.\n";
            ++tries;    // increment
            break;
        }
    }
    cout << "I'll take that for a no.\n";
    return false;
}

void copy_fct()
{
    int v[10] = {0,1,2,3,4,5,6,7,8,9};
    int v2[10]; // to become a copy of v;

    for (auto i = 0; i != 10; i++)   //copy elements
    {
        v2[i] = v[i];
    }
    //...
}

void print()
{
    int v[] = {0,1,2,3,4,5,6,7,8,9};

    for(auto x : v) // for each x in v
        cout << x << "\n";
    
    for(auto x : {10,21,32,43,54,65})
        cout << x << "\n";
    //...
}

void increment()
{
    int v[] = {0,1,2,3,4,5,6,7,8,9};

    for(auto x:v)
        cout << x << " ";
    cout << "\n";

    for(auto &x:v) // "reference to"
        ++x;
    
    for(auto x:v)
        cout << x << " ";
    cout << "\n";
}

typedef int32_t T;
#define n 10
int rts = 0;

T at[n];//  array of n T
T *pt; // pointer to T
T &rt = rts; // reference to T rts
T ft(void); // function taking an argument of type A returning a result of type T

int main()
{
    // cout << accept() << endl;
    // cout << accept2() << endl;
    // cout << accept3() << endl;

    char v[6];  // array of 6 characters
    char *p;    // pointer to character

    char *pp = &v[3];   // pp points to b=v's fourth element
    char x = *pp;       // *pp is the object that pp points to

    // print();
    increment();

    return 0;
}

double *pd = nullptr;
// Link<Record>* lst = nullptr;    // pointer to a Link to a Record
// int x = nullptr;    // error: nullptr is a pointer not an integer

int count_x(char* p, char x)
// count the number of occurrence of x in p[]
// p is assumed to point to a zero-terminated array of char (or to nothing)
{
    if(p== nullptr) return 0;
    int count = 0;
    for(;*p!=0;p++)
        if(*p == x)
            ++count;
    return count;
}