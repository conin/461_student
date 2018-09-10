#include "output.h"

#include <vector>
#include <algorithm>

#include "Vect.h"

std::vector< Vect > v_Vect_orig;
std::vector< Vect > v_Vect_sort;
std::vector< Vect > v;
std::vector< Vect >::iterator Iterator;

Vect V[] =
{
	{3,5,6},
	{6,5,3},
	{3,4,7},
	{7,2,5},
	{1,3,5},
	{3,2,5},
	{2,3,4},
	{3,5,5},
	{7,3,2},
	{4,3,2},
	{1,7,1}
};

bool acompare(Vect lhs, Vect rhs) 
{ 
	if (lhs.a != rhs.a)
	{
		return  lhs.a < rhs.a;
	}
	if (lhs.b != rhs.b)
	{
		return lhs.b < rhs.b;
	}
	if (lhs.c != rhs.c)
	{
		return lhs.c < rhs.c;
	}
	return false;
}

void Problem_4( )
{
	// create file
	io::create( "problem4.txt" );
	
	// Original data
	
	Vect *p = &V[0];
	int size = 0;
	fprintf(io::getHandle(),"original\n");	
	for( int i = 0; i < 11; i++)
	{
		fprintf(io::getHandle(),"        V[%2d]: %d  %d  %d \n", i, p->a, p->b, p->c );
		p++;
		size++;
	}

	// a) Load the V[] data into a vector, called v
	//    print it to the file (begin to end) order
	int i = 0;
	p = &V[0];
	while (i<size)
	{
		v.push_back(*p++);
		i++;
	}

	fprintf(io::getHandle(), "stl: vector\n");
	Iterator = v.begin();
	for (i = 0; i < size; i++)
	{
		fprintf(io::getHandle(), "        V[%2d]: %d  %d  %d \n", i,Iterator->a, Iterator->b, Iterator->c);
		Iterator++;
	}

	// Copies STL to gobal for unit test
	    // DO not remove
	    v_Vect_orig = v;

	// b) Sort the new STL vector with strict weak ordering
	//    print it to the file (begin to end) order
	sort(v.begin(), v.end(),acompare);

	fprintf(io::getHandle(), "stl: strict weak ordering \n");
	 Iterator = v.begin();
	 for (i = 0; i < size; i++)
	 {
		 fprintf(io::getHandle(), "        V[%2d]: %d  %d  %d \n", i, Iterator->a, Iterator->b, Iterator->c);
		 Iterator++;
	 }

	// Copies STL to gobal for unit test
		// DO not remove
	v_Vect_sort = v;

	// bye bye
	fprintf(io::getHandle(),"\n");
	io::destroy();

}