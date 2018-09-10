#include <math.h>
#include <assert.h>

#include "Vect4D.h"


Vect4D::Vect4D()
{
	this->_m = _mm_setzero_ps();
	this->w = 1.0;
}

Vect4D::Vect4D(const __m128 x)
{
	this->_m = x;
}


Vect4D::Vect4D(float tx, float ty, float tz, float tw)
{
	this->_m = _mm_set_ps(tw, tz, ty, tx);
}

Vect4D::~Vect4D()
{
	// nothing to delete
}

void Vect4D::norm(Vect4D& out)
{
	__m128 mag = _mm_sqrt_ps(_mm_dp_ps(_m, _m, 0X77));

	if (0.0f < _mm_cvtss_f32(mag))
	{
		out._m = _mm_div_ps(_m, mag);
		out.w = 1.0f;
	}
}

Vect4D Vect4D::operator + (Vect4D &t)
{
	Vect4D tmp;
	tmp._m = _mm_add_ps(this->_m, t._m);
	return tmp;
}

Vect4D Vect4D::operator - (Vect4D &t)
{
	Vect4D tmp;
	tmp._m = _mm_sub_ps(this->_m, t._m);
	return tmp;
}

Vect4D Vect4D::operator *(float scale)
{
	__m128 m = _mm_set1_ps(scale);
	return m;
}

float& Vect4D::operator[](VECT_ENUM e)
{
	switch (e)
	{
	case 0:
		return x;
		break;
	case 1:
		return y;
		break;
	case 2:
		return z;
		break;
	case 3:
		return w;
		break;
	default:
		assert(0);
		return x;
	}
}

void Vect4D::Cross(Vect4D& vin, Vect4D& vout)
{
	vout._m = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(_m, _m, _MM_SHUFFLE(3, 0, 2, 1)),
									_mm_shuffle_ps(vin._m, vin._m, _MM_SHUFFLE(3, 1, 0, 2))),
						 _mm_mul_ps(_mm_shuffle_ps(_m, _m, _MM_SHUFFLE(3, 1, 0, 2)),
									_mm_shuffle_ps(vin._m, vin._m, _MM_SHUFFLE(3, 0, 2, 1))));
}

void Vect4D::set(float tx, float ty, float tz, float tw)
{
	this->_m = _mm_set_ps(tw, tz, ty, tx);
}

// End of file