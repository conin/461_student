#include <vector>
#include <assert.h>

template <typename T>
class Stack 
{

public:
	// Write the following functions
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


void E()
{

	// Write the methods missing in the class template
	// You cannot change the private data

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

// Do not change the code above -----------------------

}