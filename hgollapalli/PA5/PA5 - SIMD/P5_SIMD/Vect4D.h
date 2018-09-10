#ifndef VECT4D_H
#define VECT4D_H

#define UNUSED_VAR(v) ((void )v)


class Matrix;

class Vect4D
{
public:

	Vect4D()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->w = 0;
	}

	Vect4D(const Vect4D &t)
	{
		this->x = t.x;
		this->y = t.y;
		this->z = t.z;
		this->w = t.w;
	}

	Vect4D( const float tx, const float ty, const float tz,const float tw )
	{
		// there to force errors in unit test
		// please change
		this->x = tx;
		this->y = ty;
		this->z = tz;
		this->w = tw;
	}


	~Vect4D()
	{
	}

	Vect4D &operator = (const Vect4D &tmp)
	{
		this->x = tmp.x;
		this->y = tmp.y;
		this->z = tmp.z;
		this->w = tmp.w;
        return *this;
	}

	void set( float xVal, float yVal, float zVal, float wVal )
	{
		this->x = xVal;
		this->y = yVal;
		this->z = zVal;
		this->w = wVal;
	}

	Vect4D operator + (const Vect4D &t)
	{
		Vect4D tmp;

		tmp.x = this->x + t.x;
		tmp.y = this->y + t.y;
		tmp.z = this->z + t.z;
		tmp.w = this->w + t.w;

		return tmp;
	}

	void operator += (const Vect4D &t)
	{
		this->x +=  t.x;
		this->y +=  t.y;
		this->z +=  t.z;
		this->w +=  t.w;
	}

	friend Vect4D operator*(float s,Vect4D &a)
	{
		Vect4D tmp;
		tmp.x = a.x * s;
		tmp.y = a.y * s;
		tmp.z = a.z * s;
		tmp.w = a.w * s;
		return tmp;
	}

	Vect4D operator - ( const Vect4D &t)
	{
		Vect4D tmp;

		tmp.x = this->x - t.x;
		tmp.y = this->y - t.y;
		tmp.z = this->z - t.z;
		tmp.w = this->w - t.w;

		return tmp;
	}

	void operator -= (const Vect4D &t)
	{
		this->x -= t.x;
		this->y -= t.y;
		this->z -= t.z;
		this->w -= t.w;
	}

	Vect4D operator * (const  Vect4D &t)
	{
		Vect4D tmp;

		tmp.x = this->x * t.x;
		tmp.y = this->y * t.y;
		tmp.z = this->z * t.z;
		tmp.w = this->w * t.w;

		return tmp;
	}

	Vect4D operator * (const float s)
	{
		//Vect4D tmp;
		Vect4D tmp;

		tmp.x = this->x * s;
		tmp.y = this->y * s;
		tmp.z = this->z * s;
		tmp.w = this->w * s;

		return tmp;
	}

	void operator *= (const  Vect4D &t)
	{
		this->x *= t.x;
		this->y *= t.y;
		this->z *= t.z;
		this->w *= t.w;
	}

	Vect4D operator / (const  Vect4D &t)
	{
		Vect4D tmp;

		tmp.x = this->x / t.x;
		tmp.y = this->y / t.y;
		tmp.z = this->z / t.z;
		tmp.w = this->w / t.w;
		return tmp;
	}

	void operator /= (const Vect4D &t)
	{
		this->x /= t.x;
		this->y /= t.y;
		this->z /= t.z;
		this->w /= t.w;
	}
	
	Vect4D operator * (const Matrix &m);

	float dot( Vect4D &t )
	{
		return (x * t.x + y * t.y + z * t.z + w * t.w); 
	}

public:
	float x;
	float y;
	float z;
	float w;

};

#endif



