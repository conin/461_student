#include <stdio.h>

// ----------------------------------------------------------------------
// Problem 1:
//
// Rules: fix the smal bug in the function, called findBitsInNibble
//        to output the correct number of '1' bits of any given number
// ----------------------------------------------------------------------

#define NUM_BITS 16

// ----------------------------------------------------------------------
// Function: returns the number of 1 bits in a the data
// ----------------------------------------------------------------------
int findBitsInNibble(unsigned int data)  
{
	int n(0);
	int bitPattern[NUM_BITS] = { 0, 1, 1, 2, 1, 2, 2, 2, 1, 2, 2, 3, 2, 3, 4 };
	         
	printf("%u",data);
	while( data > 0 )
	{
		//n += bitPattern[ data & 0xF ];
		printf("%u", data);
		n += data & 1;
		data >>= 1;
	}
	return n;
}


// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------
int main()
{
	// test 1 header
	
	printf("\nTest_1\n\n");

	// This function should return 7, but it returns 3
	printf( "-->expected:7  actual:%d\n", findBitsInNibble( 0x2F81 ) );

	return 0;
}

