#include <vector>
#include <assert.h>

template <typename T>
class Stack 
{

public:
	// Write the following functions (cut & paste from E.cpp)
    void push(T const & data);      // push element
    void pop();               // pop element
    T top() const;            // return top element
    bool empty() const;      // return whether the stack is empty

private:
    std::vector<T> elems;     // elements
};

template<typename T>
bool Stack<T>::empty() const
{
	return elems.empty();
}


template<typename T>
void Stack<T>::push(T const & data)
{
	elems.push_back(data);
	elems.push_back(data);
}

template<typename T>
void Stack<T>::pop()
{
	if (elems.empty()) {
		printf("Stack<>::pop(): empty stack");
	}
	else
	{
		elems.pop_back();
	}
}


template<typename T>
T Stack<T>::top() const
{
	if (elems.empty()) {
		printf("Stack<>::top(): empty stack");
	}

	// return copy of last element 
	return elems.back();
}


// Write a full class specialization for float
// in this class when you push() a float it double pushes
// in this class when you pop() it pops a singe element off the stack
// top() and empty() behave the same.

void F()
{
	// Cut & Paste from E.cpp for the general class template

	// Write a full class specialization for float
	// in this class when you push() a float it double pushes
	// in this class when you pop() it pops a singe element off the stack
	// top() and empty() behave the same.

// Do not change the code below is a no no -----------------------

			// LEAVE all asserts in there location, used to verify code

			int val;
			bool bval;
			Stack<int> Stack_int;

			bval = Stack_int.empty();
			assert( bval == true );

			Stack_int.push( 5 );
			val = Stack_int.top();
			assert( val == 5 );

			bval = Stack_int.empty();
			assert( bval == false );

			Stack_int.push( 6 );
			val = Stack_int.top();
			assert( val == 6);

			Stack_int.push( 7 );
			val = Stack_int.top();
			assert( val == 7 );

			Stack_int.push( 8 );
			val = Stack_int.top();
			assert( val == 8 );

			Stack_int.pop();
			val = Stack_int.top();
			assert( val == 7 );

			Stack_int.pop();
			val = Stack_int.top();
			assert( val == 6);

			Stack_int.pop();
			val = Stack_int.top();
			assert( val == 5 );

			bval = Stack_int.empty();
			assert( bval == false );

			Stack_int.pop();
			bval = Stack_int.empty();
			assert( bval == true);

			// ----- float ---------------

			float fval;
			Stack<float> Stack_float;

			bval = Stack_float.empty();
			assert( bval == true );

			Stack_float.push( 55.0f );
			fval = Stack_float.top();
			assert( fval == 55.0f );

			bval = Stack_float.empty();
			assert( bval == false );

			Stack_float.push( 88.0f );
			fval = Stack_float.top();
			assert( fval == 88.0f );

			// ---- start to pop -------------
			Stack_float.pop();
			fval = Stack_float.top();
			assert( fval == 88.0f );

			bval = Stack_float.empty();
			assert( bval == false );

			Stack_float.pop();
			fval = Stack_float.top();
			assert( fval == 55.0f );

			bval = Stack_float.empty();
			assert( bval == false );

			Stack_float.pop();
			fval = Stack_float.top();
			assert( fval == 55.0f );

			bval = Stack_float.empty();
			assert( bval == false );

			Stack_float.pop();
			bval = Stack_float.empty();
			assert( bval == true );



// Do not change the code above -----------------------

}