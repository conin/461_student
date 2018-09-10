#include <assert.h>		

// do not modify anything below this line --------

		#define UNUSED_VAR(x)	x

		enum ReturnType
		{
			TEMPLATE_3_ARG,
			NON_TEMPLATE_INT_ARG,
			TEMPLATE_2_ARG
		};

		template <typename T>
		ReturnType const min(T const& a, T const& b)
		{	
				UNUSED_VAR(&a);
				UNUSED_VAR(&b);
			return  TEMPLATE_2_ARG;
		}

		ReturnType const min(int const& a, int const& b)
		{	
				UNUSED_VAR(&a);
				UNUSED_VAR(&b);
			return NON_TEMPLATE_INT_ARG;
		}

		template <typename T>
		ReturnType const min(T const& a, T const& b, T const& c)
		{	
				UNUSED_VAR(&a);
				UNUSED_VAR(&b);
				UNUSED_VAR(&c);
			return  TEMPLATE_3_ARG;
		}

// do not modify anything above this line is no no -----------

void C() // Overloading Function Templates
{
	ReturnType val;

	// Add the function/template to get the desired effect

		
		// LEAVE all asserts in there location, used to verify code

		// call min with 3 ints:  42, 7, 68
		// example: val = blahblah(42,7,68);
		val = min(42, 7, 68);
		assert( val == TEMPLATE_3_ARG);

		{
			double a = 42.0;
			double b = 7.0;
			val = min(a, b);
			// call min with 2 doubles by argument deduction:  42.0, 7.0
			assert(val == TEMPLATE_2_ARG);
		}

		// call min with 2 characters by argument deduction: 'a', 'b'
		val = min('a', 'b');
		assert( val == TEMPLATE_2_ARG);

		// call min with 2 int:  42, 7
		val = min(42, 7);
		assert( val == NON_TEMPLATE_INT_ARG);

		// call min with 2 int by argument deduction:  42, 7
		{
			int a = 42;
			int b = 7;
			val = min<int>(a, b);
			assert(val == TEMPLATE_2_ARG);
		}
		

		// call min with 2 double no argument deduction:  42, 7
		{
			double a = 42;
			double b = 7;
			val = min(a, b);
			assert(val == TEMPLATE_2_ARG); 
		}

		// call min with 2 ints:  42, 'a'
		val = min(42, 'a');
		assert( val == NON_TEMPLATE_INT_ARG);

}