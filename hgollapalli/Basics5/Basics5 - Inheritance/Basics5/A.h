#ifndef A_H
#define A_H

#include "bufferManager.h"

// ----------------------------------------------------------------------
//
// Rules:
// FIX class A to prevent the memory leak in the unit tests
// You may not touch class B 
// Only modify class A
//
// ----------------------------------------------------------------------

// -----------------------------------------------------
// MODIFY Class A to prevent the memory leak in the unit tests
// -----------------------------------------------------
class A
{
public:
	A()
	: x(5)
	{
	
	}
	
	virtual ~A()
	{
		this->x=0;
	}

	int getX()
	{
		return this->x;
	}
private:
	int x;
};

// -----------------------------------------------------
// DO NOT MODIFY (below this line) 
// -----------------------------------------------------

class B : public A
{
public:
	B()
	: y(33)
	{
		this->buffer = new int[100];
		bufferManager::getInstance()->increment();
	}

	~B()
	{
		delete[] this->buffer;
		bufferManager::getInstance()->decrement();		
	}


private:
	int y;
	int *buffer;
};

#endif