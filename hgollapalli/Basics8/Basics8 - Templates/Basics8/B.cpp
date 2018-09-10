// CANNOT change anything below this line  ------------

#include <assert.h>

		template <typename R, typename S, typename T>
		T const min (R const& a, S const& b)
		{
			T val;

			if( a > b )
			{
				// need a cast incase type T != type S
				val = static_cast<T>( b );
			}
			else
			{
				// need a cast incase type T != type R
				val = static_cast<T>( a );
			}
			return  val;
		}

// CANNOT change anything above this line  --------------------


void B() //Template parameters
{
	int val = 0;
	float a = 5;
	float b = 4.2f;

	// Fix this template call without a cast
	// Specify the type or qualify explicity the type of T
	// Only change the next line
	
	val = min<float,float,int>(a,b);

	// LEAVE all asserts in there location, used to verify code
	assert( val == 4 );


}