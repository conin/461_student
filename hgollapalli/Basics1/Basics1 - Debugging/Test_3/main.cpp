#include <stdio.h>

// ----------------------------------------------------------------------
// Problem 3:
//
// Rules: There is a subtle bug
//        If you break point and walk it, you wont see the bug
//        Leave as much as possible of the original function alone
//        The bug is very small and subtle
// ----------------------------------------------------------------------

// allocates an array of n integers
int *arrayOfInt(unsigned int num)
{
	return  new int[num];
}


int main() 
{	 
	// test 3 header
	printf("\nTest_3: \n\n"); 

	printf("Actual\n");
	for(int j = 0; j < 10; j++)
	{
		printf("   %d\n",j);
	}

	// Create the array
	int *pData = arrayOfInt(10);
	
	// initialize the array
	for( int i = 0; i < 10; i++ )
	{
		pData[i] = i;
	}

	printf("Expected\n");
	// print the array members
	for( int i = 0; i < 10; i++ )
	{
		printf( "   %d\n", pData[i] );    
	}

	return 0;
    
}

