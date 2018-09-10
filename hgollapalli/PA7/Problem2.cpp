#include<math.h>
#include<stdio.h>

struct Vect  // Vector struct for positions
{
	float x;
	float y;
	float z;

	Vect()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}

	Vect(float x,float y,float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void Normalize()
	{
		float den = 0;

		den = x*x;
		den += (y*y);
		den += (z*z);
		den = sqrtf(den);

		x /= den;
		y /= den;
		z /= den;
	}
} Vect_t;

int main()
{
	Vect v(1,1,1);
	printf("\n%f %f %f", v.x, v.y, v.z);
	v.Normalize();
	printf("\n%f %f %f", v.x, v.y, v.z);
	return 0;
}
}
}