#include "output.h"

#include <list>
#include <algorithm>
#include <functional>

std::list<int> B_List_orig;
std::list<int> B_List_insert;
std::list<int> B_List_sort;
std::list<int> B_List;
std::list<int>::iterator iTeratorB;

int B[] = 
{
	66,
	77,
	33,
	22,
	88,
	11,
	99,
	44
};


void Problem_2( )
{
	// create file
	io::create( "problem2.txt" );

	// Original data
	
	int *p = &B[0],size=0;
	fprintf(io::getHandle(),"original\n");
	for( int i = 0; i < 8; i++)
	{
		fprintf(io::getHandle(),"        B[%2d]: %d   \n", i, *p++ );
		size++;
	}

	// a) Load the B[] data into a list, called B_List
	//    print it to the file (begin to end) order
	int i = 0;
	p = &B[0];
	while(i<size)
	{
		B_List.push_back(*p++);
		i++;
	}

	iTeratorB = B_List.begin();
	fprintf(io::getHandle(), "\n STL List \n");
	for (i = 0; i < size; i++)
	{
		fprintf(io::getHandle(), "        B[%2d]: %d   \n", i, *iTeratorB++);
	}

    // Copies STL to gobal for unit test
	// DO not remove
	B_List_orig = B_List;

	// b) Insert the number '55' between 22 and 88
	//    No brute force, assume there are 1000000 numbers before 22 and after 88.
	//    No iterative, simple approach, use the appropriate STL calls for efficency.
	//    print it to the file (begin to end) order

	iTeratorB = find(B_List.begin(), B_List.end(), 88);

	if(iTeratorB!=B_List.end())
	{
		B_List.insert(iTeratorB, 55);
	}
	iTeratorB = B_List.begin();
	fprintf(io::getHandle(), "\n Insert 88 into STL List  \n");
	for (i = 0; i <= size; i++)
	{
		fprintf(io::getHandle(), "        B[%2d]: %d   \n", i, *iTeratorB++);
	}

	// Copies STL to gobal for unit test
	// DO not remove
	B_List_insert = B_List;

	// c) sort the list in reverse order using the built in functional functions
	//    print it to the file (begin to end) order
	//std::sort(B_List.begin(), B_List.end());
	B_List.sort(std::greater<int>());

	iTeratorB = B_List.begin();
	fprintf(io::getHandle(), "\n After Sorting list in reverse order using built in function \n");
	for (i = 0; i <= size; i++)
	{
		fprintf(io::getHandle(), "        B[%2d]: %d   \n", i, *iTeratorB++);
	}
	// Copies STL to gobal for unit test
	// DO not remove
	B_List_sort = B_List;

	// bye bye
	fprintf(io::getHandle(),"\n");
	io::destroy();
}