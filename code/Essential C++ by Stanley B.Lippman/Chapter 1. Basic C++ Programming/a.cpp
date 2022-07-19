#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    const int seq_size = 18;
    int pell_seq_array[seq_size];
    vector<int> pell_seq_vector(seq_size);
    pell_seq_array[0] = 1; // assign 1 to first element
    pell_seq_array[1] = 2; // assign 2 to second element

    for (int ix = 2; ix < seq_size; ix++)
    {
        pell_seq_array[ix] = pell_seq_array[ix - 2] + 2*pell_seq_array[ix - 1];
    }

    cout << "The first " << seq_size 
         << " elements of the Pell Series:\n\t";

    for (int ix = 0; ix < seq_size; ix++)
        cout << pell_seq_array[ix] << ' ';
    cout << '\n';

    int elem_seq_style1[seq_size] = {
        1,  2,  3,   // Fibonacci
        3,  4,  7,   // Lucas
        2,  5, 12,   // Pell
        3,  6, 10,   // Triangular
        4,  9, 16,   // Square
        5, 12, 22,   // Pentagonal
    };

    // compiler computers a size of 18 elements
    int elem_seq_style2[] = {
        1, 2,  3, 3, 4,  7, 2,  5, 12,
        3, 6, 10, 4, 9, 16, 5, 12, 22
    };

    // compiler computers a size of 18 elements
    int elem_val[seq_size] = {
        1, 2,  3, 3, 4,  7, 2,  5, 12,
        3, 6, 10, 4, 9, 16, 5, 12, 22
    };

    vector<int> elem_seq(elem_val, elem_val + seq_size);

    cout << "elem_seq.size() = " << elem_seq.size(); // returns the number of elements
    cout << '\n';

    // contained within the vector elem_seq
    cout << "The first " << elem_seq.size()
         << " elements of the Pell Series\n\t";
    
    for (int  ix = 0; ix < elem_seq.size(); ix++)
        cout << elem_seq[ix] << ' ';
    cout << '\n'; 

    return 0;
}
