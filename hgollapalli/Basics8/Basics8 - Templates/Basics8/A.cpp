#include<math.h>
// CANNOT change anything below this line

#include <assert.h>

		template <typename T>
		inline T const min(T const& a, T const& b)
		{
			
			T val;

			if( a > b )
			{
				val = b;
			}
			else
			{
				val = a;
			}

			return  val;
		}

// CANNOT change anything above this line -------------------

void A()  // Argument Deduction
{

	// Fix this template call without a cast
	// Specify the type or qualify explicity the type of T
	// Only change this call line below:
	double a = 5;
	double b = 4.2;
	double val = min(a,b);

	// LEAVE all asserts in there location, used to verify code
	assert( val == 4.2 );

}