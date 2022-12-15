/* Exercise 7.2 */

/*
The following functions invoked in alloc_and_init() raise the following exception
types if they should fail:

allocate_array() noMem
sort_array() int
register_data() string

Insert one or more try blocks and associated catch clauses where appropriate to handle
these exceptions. Simply print the occurrence of the error within the catch clause.

*/

#include <iostream>
#include <exception>
#include <fstream>

using namespace std;

int* allocate_array(int);
void sort_array(int*, int);
void register_data(int*);

class noMem : public exception {}; // what is type noMem

int* alloc_and_init(string file_name)
{
    ifstream infile(file_name.c_str());
    if (! infile) return 0;

    int elem_cnt;
    infile >> elem_cnt;
    if (! infile) return 0;

    try {
        int *pi = allocate_array(elem_cnt);
        int elem;
        int index = 0;
        while (infile >> elem && index < elem_cnt)
            pi[index++] = elem;

        sort_array(pi, elem_cnt);
        register_data(pi);

        return pi;
    }
    catch(const noMem &memFail) {
        cerr << "alloc_and_init(): allocate_array failure!\n"
             << memFail.what() << endl;
        return 0;
    }
    catch(int &sortFail) {
        cerr << "alloc_and_init(): sort_array failure!\n"
             << "thrown integer value: " << sortFail << endl;
        return 0;
    }
    catch(string &registerFail) {
        cerr << "alloc_and_init(): register_data failure!\n"
             << "thrown string value: "
             << registerFail << endl;
        return 0;
    }
//    return pi; // pi is locate variable ???
}