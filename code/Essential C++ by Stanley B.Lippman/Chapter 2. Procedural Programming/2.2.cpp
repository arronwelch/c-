// 2.2 Invoking a Function

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void display(vector<int> vec)
{
	for(int ix = 0; ix < vec.size(); ++ix)
		cout << vec[ix] << ' ';
	cout << endl;
}

/*
 * OK: by declaring val1 and val2 as references
 *     changes to the two parameters within swap()
 *     are reflected in the objects passed to swap()
 */

// ofstream ofil("text_out1");
void swap(int & val1, int & val2)
{
	// cout << "swap(" << val1
	// 	 << ", " << val2 << ")\n";

	// what is the relationship between
	// the formal parameters val1, val2

	// and the actual arguments vec[ix] and vec[jx]?

	/*
	 * note that our code within swap()
	 * does not change -- only the relationship
	 * between the parameters of swap() and the
	 * objects passed to swap() changes
	 */
	int temp = val1;
	val1 = val2;
	val2 = temp;
	// cout << "after swap(): val1 " << val1
	// 	 << " val2:" << val2 << "\n";
}

// void swap(int &val1, int &val2)
// {
// 	int temp = val1;
// 	val1 = val2;
// 	val2 = temp;
// }

// ofstream ofil("text_out1");
void bubble_sort(vector<int> &vec)
{
	for(int ix = 0; ix < vec.size(); ++ix)
		for (int jx = ix + 1; jx < vec.size(); ++jx)
			if(vec[ix] > vec[jx]) {
				// cout << "about to call swap!"
				// 	 << " ix: " << ix << " jx: " << jx << '\t'
				// 	 << " swapping: " << vec[ix]
				// 	 << " with " << vec[jx] << endl;
				// display(vec);

					// ok: actual swap code ...
				swap(vec[ix], vec[jx]);
			}
}

int main(void)
{
	int ia[8] = { 8, 34, 3, 13, 1, 21, 5, 2};
	vector<int> vec(ia, ia+8);

	cout << "vector before sort: ";
	display(vec);

	bubble_sort(vec);

	cout << "vector after sort: ";
	display(vec);

	return 0;
}
