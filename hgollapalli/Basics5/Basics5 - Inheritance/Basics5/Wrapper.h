#ifndef WRAPPER_H
#define WRAPPER_H

#include "MiddlewareNative.h"


// ----------------------------------------------------------------------
//
// Rules: 
// For this problem, you are wrapping a poor interface provided by the middleware vendors
// Feel free to modify and add to this class
//
// The class needs to derive privately from Vect2D_Native
//
// Requirements:
//
// 1) variables:  x, y should be private
// 2) prevent methods setID() and getID() from being called
// 3) Rework getX() and getY() to take float references
// 4) prevent the original getX() and getY() from being called
// 5) allow setX() and setY() to be called as is.
//
// The unit test has a section that is #if 0 - toggle it to make sure your code is producing the correct errors
//
// ----------------------------------------------------------------------

class GameVect: private Vect2D_Native
{
public:
	GameVect():Vect2D_Native()
	{
		this->x = (int)Vect2D_Native::x;
		this->y = (int)Vect2D_Native::y;
		this->id= (int)Vect2D_Native::id;
	}

	void setX(float val)
	{
		this->x = (int)val;
	}

	void setY(float val)
	{
		this->y = (int)val;
	}

	float getX(float &xVal)
	{
		xVal = (float)this->x;
		return xVal;
	}

	float getY(float &yVal)
	{
		yVal = (float)this->y;
		return yVal;
	}

	float getX()
	{
		return (float)this->x;
	}

	float getY()
	{
		return (float)this->y;
	}

	int getX(int &a)
	{
		a = this->x;
		return this->x;
	}

	int getY(int &a)
	{
		a= this->y;
		return this->y;
	}

	void setID(int val)
	{
		id = val;
	}

	int getID()
	{
		return id;
	}


	int x;
	int y;
	int id;
private:
};


#endif