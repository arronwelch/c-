// 2.1 How to Write a Function

#include <cstdlib>

// a declaration of our function
int fibon_elem(int pos);

/* A second form of comment delimiter
 *
 * 1st and 2nd elements of the Fibonacci Sequence
 * are 1; each subsequent element is the sum of
 * the preceding two elements
 *
 * elem: holds value to be returned
 * n_2, n_1: holds preceding values
 * pos: element position position user requested
 */
int fibon_elem(int pos)
{
	//check for invalid position
	if (pos <= 0)
		// ok, now what?
		exit(-1);

	int elem = 1;	// holds return value
	int n_2 = 1, n_1 = 1;
	for (int ix = 3; ix <= pos; ++ix)
	{
		elem = n_2 + n_1;
		n_2 = n_1; n_1 = elem;
	}
	
	return elem;
}

int main(void)
{

	return 0;
}
