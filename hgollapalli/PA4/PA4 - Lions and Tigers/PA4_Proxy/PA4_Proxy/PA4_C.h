
#ifndef PA4_C_H
#define PA4_C_H

#define PROXY_ENABLE  1 // use this toggle to flip back and forth with your proxies


class Vect2D
{
public:

	// default constructor
	Vect2D()
		: x(0.0f), y(0.0f)
	{
	};

	Vect2D(const float _x, const float _y)
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
	// Convert these methods to proxys
	//*********************************************************************

#if ! PROXY_ENABLE 
	Vect2D operator + ( const Vect2D &tmp ) const;
#endif

private:
	friend struct VaddV;
	friend struct VaddVaddV;
	friend struct VaddVaddVaddV;
	friend struct VaddVaddVaddVaddV;
	float x;
	float y;
};
#endif

#if PROXY_ENABLE
struct VaddV
{
	const Vect2D v1;
	const Vect2D v2;

	VaddV(const Vect2D &a, const Vect2D &b) 
		: v1(a), v2(b) 
	{
	
	};
	
	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x, v1.y + v2.y);
	}

	const VaddV operator = (const VaddV &v) = delete;
	
	~VaddV() 
	{
	
	}
};

inline VaddV operator + (const Vect2D &a, const Vect2D &b)
{
	return VaddV(a, b);
}

struct VaddVaddV
{
	const Vect2D v1;
	const Vect2D v2;
	const Vect2D v3;

	VaddVaddV(const VaddV &a, const Vect2D &b) 
		: v1(a.v1), v2(a.v2), v3(b) 
	{
	
	}

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x, v1.y + v2.y + v2.y);
	}

	const VaddVaddV operator = (const VaddVaddV &a) = delete;

	~VaddVaddV() 
	{
	
	}
};

inline VaddVaddV operator + (const VaddV &a, const Vect2D &b)
{
	return VaddVaddV(a, b);
}

struct VaddVaddVaddV
{
	const Vect2D v1;
	const Vect2D v2;
	const Vect2D v3;
	const Vect2D v4;

	VaddVaddVaddV(const VaddVaddV &a, const Vect2D &b)
		:v1(a.v1), v2(a.v2), v3(a.v3), v4(b) 
	{

	}

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x, v1.y + v2.y + v3.y + v4.y);
	}

	const VaddVaddVaddV operator = (const VaddVaddVaddV &inVec) = delete;

	~VaddVaddVaddV() 
	{
	
	}
};

inline VaddVaddVaddV operator + (const VaddVaddV &a, const Vect2D &b)
{
	return VaddVaddVaddV(a, b);
}


struct VaddVaddVaddVaddV
{
	const Vect2D v1;
	const Vect2D v2;
	const Vect2D v3;
	const Vect2D v4;
	const Vect2D v5;

	VaddVaddVaddVaddV(const VaddVaddVaddV &a, const Vect2D &b)
		:v1(a.v1), v2(a.v2), v3(a.v3), v4(a.v4), v5(b)
	{	
	
	}

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x + v3.x + v4.x + v5.x, v1.y + v2.y + v3.y + v4.y + v5.y);
	}

	const VaddVaddVaddVaddV operator = (const VaddVaddVaddVaddV &a) = delete;

	~VaddVaddVaddVaddV() 
	{
	
	}
};

inline VaddVaddVaddVaddV operator + (const VaddVaddVaddV &a, const Vect2D &b)
{
	return VaddVaddVaddVaddV(a, b);
}

#endif

