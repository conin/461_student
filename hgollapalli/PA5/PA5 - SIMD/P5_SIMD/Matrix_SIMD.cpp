#include "Matrix_SIMD.h"	


Matrix_SIMD Matrix_SIMD::operator * (const Matrix_SIMD &p)
{
	Vect4D_SIMD t,res1, res2, res3, res4 ;
	Vect4D_SIMD part1 = p.v0;
	Vect4D_SIMD part2 = p.v1;
	Vect4D_SIMD part3 = p.v2;
	Vect4D_SIMD part4 = p.v3;

	
	//first row
	t._m = _mm_set_ps1(this->m0);
	part1._m = _mm_mul_ps(t._m, part1._m);

	t._m = _mm_set_ps1(this->m1);
	part2._m = _mm_mul_ps(t._m, part2._m);

	t._m = _mm_set_ps1(this->m2);
	part3._m = _mm_mul_ps(t._m, part3._m);

	t._m = _mm_set_ps1(this->m3);
	part4._m = _mm_mul_ps(t._m, part4._m);

	res1._m = _mm_add_ps(part1._m, part2._m);
	res1._m = _mm_add_ps(res1._m, part3._m);
	res1._m = _mm_add_ps(res1._m, part4._m);
	
	//second row
	part1 = p.v0;
	part2 = p.v1;
	part3 = p.v2;
	part4 = p.v3;

	t._m = _mm_set_ps1(this->m4);
	part1._m = _mm_mul_ps(t._m, part1._m);

	t._m = _mm_set_ps1(this->m5);
	part2._m = _mm_mul_ps(t._m, part2._m);

	t._m = _mm_set_ps1(this->m6);
	part3._m = _mm_mul_ps(t._m, part3._m);

	t._m = _mm_set_ps1(this->m7);
	part4._m = _mm_mul_ps(t._m, part4._m);

	res2._m = _mm_add_ps(part1._m, part2._m);
	res2._m = _mm_add_ps(res2._m, part3._m);
	res2._m = _mm_add_ps(res2._m, part4._m);
	
	//third row
	part1 = p.v0;
	part2 = p.v1;
	part3 = p.v2;
	part4 = p.v3;

	t._m = _mm_set_ps1(this->m8);
	part1._m = _mm_mul_ps(t._m, part1._m);

	t._m = _mm_set_ps1(this->m9);
	part2._m = _mm_mul_ps(t._m, part2._m);

	t._m = _mm_set_ps1(this->m10);
	part3._m = _mm_mul_ps(t._m, part3._m);

	t._m = _mm_set_ps1(this->m11);
	part4._m = _mm_mul_ps(t._m, part4._m);

	res3._m = _mm_add_ps(part1._m, part2._m);
	res3._m = _mm_add_ps(res3._m, part3._m);
	res3._m = _mm_add_ps(res3._m, part4._m);
	
	
	//fourth row
	part1 = p.v0;
	part2 = p.v1;
	part3 = p.v2;
	part4 = p.v3;

	t._m = _mm_set_ps1(this->m12);
	part1._m = _mm_mul_ps(t._m, part1._m);

	t._m = _mm_set_ps1(this->m13);
	part2._m = _mm_mul_ps(t._m, part2._m);

	t._m = _mm_set_ps1(this->m14);
	part3._m = _mm_mul_ps(t._m, part3._m);

	t._m = _mm_set_ps1(this->m15);
	part4._m = _mm_mul_ps(t._m, part4._m);

	res4._m = _mm_add_ps(part1._m, part2._m);
	res4._m = _mm_add_ps(res4._m, part3._m);
	res4._m = _mm_add_ps(res4._m, part4._m);

	Matrix_SIMD res(res1,res2,res3,res4);

	return res;

}

Vect4D_SIMD Matrix_SIMD::operator * (const Vect4D_SIMD &v)
{
	Vect4D_SIMD A, B, C, D, tmp;
	tmp._m = _mm_set_ps1(v.x);
	A._m = _mm_set_ps(this->m12, this->m8, this->m4, this->m0);
	A._m = _mm_mul_ps(A._m, tmp._m);

	tmp._m = _mm_set_ps1(v.y);
	B._m = _mm_set_ps(this->m13, this->m9, this->m5, this->m1);
	B._m = _mm_mul_ps(B._m, tmp._m);

	tmp._m = _mm_set_ps1(v.z);
	C._m = _mm_set_ps(this->m14, this->m10, this->m6, this->m2);
	C._m = _mm_mul_ps(C._m, tmp._m);

	tmp._m = _mm_set_ps1(v.w);
	D._m = _mm_set_ps(this->m15, this->m11, this->m7, this->m3);
	D._m = _mm_mul_ps(D._m, tmp._m);

	float p = A.x + B.x + C.x + D.x;
	float q = A.y + B.y + C.y + D.y;
	float r = A.z + B.z + C.z + D.z;
	float s = A.w + B.w + C.w + D.w;

	return Vect4D_SIMD(p, q, r, s);
}