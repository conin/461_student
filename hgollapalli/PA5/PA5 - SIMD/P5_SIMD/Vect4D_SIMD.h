#ifndef VECT4D_SIMD_H
#define VECT4D_SIMD_H

#include <xmmintrin.h>
#include <smmintrin.h>  


#define UNUSED_VAR(v) ((void )v)

class Matrix_SIMD;

class Vect4D_SIMD
{
public:

	Vect4D_SIMD()
	{
		this->_m = _mm_setzero_ps();
	};

	Vect4D_SIMD( const Vect4D_SIMD &tmp)
	{
		this->_m = tmp._m;
	}

	Vect4D_SIMD( const float tx,const float ty, const float tz, const float tw )
	{
		this->_m = _mm_set_ps(tw,tz, ty, tx );
	}

	~Vect4D_SIMD()
	{
	};

	void operator = ( const Vect4D_SIMD &tmp)
	{
		this->_m = tmp._m;
	}

	void set( float xVal, float yVal, float zVal, float wVal )
	{
		this->_m = _mm_set_ps(wVal, zVal, yVal, xVal);
	}

	Vect4D_SIMD operator + (Vect4D_SIMD &tmp)
	{
		Vect4D_SIMD A;
		A._m = _mm_add_ps(this->_m , tmp._m);
		return A;
	}

	void operator += (Vect4D_SIMD &tmp)
	{
		this->_m = _mm_add_ps(this->_m, tmp._m);
	}

	Vect4D_SIMD operator - (Vect4D_SIMD &tmp)
	{
		Vect4D_SIMD A;
		A._m = _mm_sub_ps(this->_m, tmp._m);
		return A;
	}

	void operator -= ( Vect4D_SIMD &tmp)
	{
		this->_m = _mm_sub_ps(this->_m, tmp._m);
	}

	Vect4D_SIMD operator * (Vect4D_SIMD &tmp)
	{
		Vect4D_SIMD A;
		A._m = _mm_mul_ps(this->_m, tmp._m);
		return A;
	}

	void operator *= ( Vect4D_SIMD &tmp)
	{
		this->_m = _mm_mul_ps(this->_m, tmp._m);
	}

	Vect4D_SIMD operator / (Vect4D_SIMD &tmp)
	{
		Vect4D_SIMD A;
		A._m = _mm_div_ps(this->_m, tmp._m);
		return A;
	}

	void operator /= (Vect4D_SIMD &tmp)
	{
		this->_m = _mm_div_ps(this->_m, tmp._m);
	}

	float dot( Vect4D_SIMD &tmp )
	{
		Vect4D_SIMD A;
		A._m = _mm_dp_ps(this->_m, tmp._m,0xf1);
		return (A.x);
	}

	Vect4D_SIMD Vect4D_SIMD::operator * (const Matrix_SIMD &m);

public:

	// anonymous union
	union 
	{
		__m128	_m;

		// anonymous struct
		struct 
			{
			float x;
			float y;
			float z;
			float w;
			};
	};
};

#endif