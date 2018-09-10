#include "output.h"

#include <vector>
#include <algorithm>
#include "Trace.h"

std::vector<int> A_Vector_orig;
std::vector<int> A_Vector_insert;
std::vector<int> A_Vector_sort;
std::vector<int>::iterator iTmp;

int A[] = 
{
	6,
	7,
	3,
	2,
	8,
	1,
	9,
	4
};


void Problem_1( )
{
	
	
	// create file
	io::create( "problem1.txt" );

	// Original data
	
	int *p = &A[0],size=0;
	fprintf(io::getHandle(),"original\n");
	for( int i = 0; i < (sizeof(A)/sizeof(A[0])); i++)
	{
		fprintf(io::getHandle(),"        A[%2d]: %d   \n", i, *p++ );
		size++;
	}

	// a) Load the A[] data into a vector, called A_Vector
	//    print it to the file (begin to end) order
	std::vector<int>  A_Vector(A, A + size);

	iTmp = A_Vector.begin();
	fprintf(io::getHandle(), "\n STL  vector  \n");
	for (int i = 0; i < size; i++)
	{
		fprintf(io::getHandle(), "        A[%2d]: %d   \n", i, *iTmp++);
	}

	// Copies STL to gobal for unit test
	      // DO not remove
	      A_Vector_orig = A_Vector;
	
	// b) Insert the number '5' between 2 and 8
	//    No brute force, assume there are 1000000 numbers before 2 and after 8.
	//    No iterative, simple approach, use the appropriate STL calls for efficency.
	//    print it to the file (begin to end) order
		  
		  iTmp = find(A_Vector.begin(), A_Vector.end(), 8);

		  if (iTmp != A_Vector.begin())
		  {
			  A_Vector.insert(iTmp, 5);
		  }

		  iTmp = A_Vector.begin();
		  fprintf(io::getHandle(), "\n Insert 5 into STL  vector  \n");
		  for (int i = 0; i <= size; i++)
		  {
			  fprintf(io::getHandle(), "        A[%2d]: %d   \n", i, *iTmp++);
		  }

	      // Copies STL to gobal for unit test
     	      // DO not remove
	      A_Vector_insert = A_Vector;

		  


	// c) sort the vector
	//    print it to the file (begin to end) order
		  std::sort(A_Vector.begin(), A_Vector.end());

		  iTmp = A_Vector.begin();
		  fprintf(io::getHandle(), "\n After Sorting \n");
		  for (int i = 0; i <= size; i++)
		  {
			  fprintf(io::getHandle(), "        A[%2d]: %d   \n", i, *iTmp++);
		  }


	      // Copies STL to gobal for unit test
     	      // DO not remove
	      A_Vector_sort = A_Vector;
	// bye bye
	fprintf(io::getHandle(),"\n");
	io::destroy();
}