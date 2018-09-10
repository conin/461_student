#ifndef PA4_B_H
#define PA4_B_H

#define RVO_ENABLE 1  // toggle this to test

class Vect2D
{
public:

	// default constructor
	Vect2D()
		: x(0.0f), y(0.0f)
	{
	};

	Vect2D(float _x,float _y)
		: x(_x), y(_y)
	{
	};

	// destructor
	~Vect2D()
	{
	};



	// set functions
	void setX( const float inX )
	{
		this->x = inX;
	};

	void setY( const float inY )
	{
		this->y = inY;
	};

	void set( const float inX, const float inY )
	{
		this->x = inX;
		this->y = inY;
	};

	float getX()
	{
		return this->x;
	};

	float getY()
	{
		return this->y;
	};

	//*********************************************************************
	// Convert these methods to Return Value Optimization
	//*********************************************************************

#if ! RVO_ENABLE
	Vect2D operator + (const Vect2D &tmp) const;
	Vect2D operator - (const Vect2D &tmp) const;
	Vect2D operator * (const float scale) const;
	Vect2D operator / (const float scale) const;
#endif

#if RVO_ENABLE
	Vect2D operator + (const Vect2D &tmp) const;
	Vect2D operator - (const Vect2D &tmp) const;
	Vect2D operator * (const float scale) const;
	Vect2D operator / (const float scale) const;
	Vect2D operator += (const Vect2D &tmp) const;
	Vect2D operator *= (const float scale) const;
	Vect2D operator -= (const Vect2D &tmp) const;
	Vect2D operator /= (const  float scale) const;
#endif

	

private:
	float x;
	float y;

};

#endif