/* Exercise 7.1 */

/*
The following function provides absolutely no checking of either possible bad date
or possible failure of an operation. Identify all the things that might possibly go
wrong within the function(in this exercise, we don't yet worry about possible
exceptions raised).

int *alloc_and_init(string file_name)
{
    ifstream infile(file_name);
    int elem_cnt;
    infile >> elem_cnt;
    int *pi = allocate_array(elem_cnt);

    int elem;
    int index = 0;
    while (infile >> elem)
        pi[index++] = elem;

    sort_array(pi, elem_cnt);
    register_data(pi);

    return pi;
}
*/

int *alloc_and_init(string file_name)
{
    ifstream infile(file_name.c_str());
    if (! infile)
        cout << "open " << file_name << " fail!\n";

    int elem_cnt;
    infile >> elem_cnt;
    if (! infile)
        cout << "read the first line of " << file_name << " fail!\n";

    int *pi = allocate_array(elem_cnt);
    if (! pi)
        cout << "allocate array fail!\n";

    int elem;
    int index = 0;
    while (infile >> elem)
        pi[index++] = elem; // index < elem_cnt ?

    sort_array(pi, elem_cnt);
    register_data(pi);

    return pi;
}