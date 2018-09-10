#include <stdio.h>

// ----------------------------------------------------------------------
// Problem 9:
//
// Rules: Fix the code to correctly calculated the triangular sum
//        You can make this work with a small addition
// ----------------------------------------------------------------------

const int Num = 9;
int array[Num];

int getTriangularSum()
{
	// calculate the triangular Nth Number
	// number: 1 + 2 + 3 + ... + N
	int total = 0;
	for (int i = 0; i < Num; i++)
	{
		total += array[i];
	}

	return total;
}

// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------
void prepareArray()
{
	int n = 0;
	// ascending array 
	// integers:  1, 
	//            2, 
	//            3,
	//            4,... , N
	for (int i = 0; i < Num; i++)
	{
		array[i] = ++n;
	}

}

// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------
int main()
{
	// test 9 header
	printf("\nTest_9: \n\n");\

	// initialize the array
	prepareArray();

	//compute the Nth Triangular Number
	int sum = getTriangularSum();

	/* for N == 9 this should be 45 */
	printf( "expected:45  actual:%d\n", sum );
}