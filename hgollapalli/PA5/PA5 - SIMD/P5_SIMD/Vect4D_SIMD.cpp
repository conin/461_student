#include "Vect4D_SIMD.h"
#include "Matrix_SIMD.h"

#include <xmmintrin.h>
#include <smmintrin.h> 



Vect4D_SIMD Vect4D_SIMD::operator * ( const Matrix_SIMD &M)
{		
	Vect4D_SIMD t,res;

	Vect4D_SIMD part1 = M.v0;
	Vect4D_SIMD part2 = M.v1;
	Vect4D_SIMD part3 = M.v2;
	Vect4D_SIMD part4 = M.v3;

	t._m = _mm_set_ps1(this->x);
	part1._m = _mm_mul_ps(t._m, part1._m);

	t._m = _mm_set_ps1(this->y);
	part2._m = _mm_mul_ps(t._m, part2._m);

	t._m = _mm_set_ps1(this->z);
	part3._m = _mm_mul_ps(t._m, part3._m);

	t._m = _mm_set_ps1(this->w);
	part4._m = _mm_mul_ps(t._m, part4._m);

	res._m = _mm_add_ps(part1._m, part2._m);
	res._m = _mm_add_ps(res._m, part3._m);
	res._m = _mm_add_ps(res._m, part4._m);
	return res;
}
