#include <Math.h>
#include <assert.h>
#include "Vect4d.h"
#include "Matrix.h"

Matrix::Matrix(const Vect4D &a, const Vect4D &b, const Vect4D &c, const Vect4D &d)
{
	this->v0 = a;
	this->v1 = b;
	this->v2 = c;
	this->v3 = d;
}

Matrix::Matrix()
{	// constructor for the matrix
	this->v0._m = _mm_set1_ps(0.0f);
	this->v1._m = _mm_set1_ps(0.0f);
	this->v2._m = _mm_set1_ps(0.0f);
	this->v3._m = _mm_set1_ps(0.0f);
}

Matrix::Matrix(const Matrix& t)
{ // copy constructor
	this->v0 = t.v0;
	this->v1 = t.v1;
	this->v2 = t.v2;
	this->v3 = t.v3;

}

Matrix::~Matrix()
{
	// nothign to delete
}

void Matrix::setIdentMatrix()
{ // initialize to the identity matrix
	this->v0._m = _mm_set_ps(0.0f, 0.0f, 0.0f, 1.0f);
	this->v1._m = _mm_set_ps(0.0f, 0.0f, 1.0f, 0.0f);
	this->v2._m = _mm_set_ps(0.0f, 1.0f, 0.0f, 0.0f);
	this->v3._m = _mm_set_ps(1.0f, 0.0f, 0.0f, 0.0f);
}

void Matrix::setTransMatrix(const Vect4D * const t)
{ // set the translation matrix (note: we are row major)
	this->v0._m = _mm_set_ps(0.0f, 0.0f, 0.0f, 1.0f);
	this->v1._m = _mm_set_ps(0.0f, 0.0f, 1.0f, 0.0f);
	this->v2._m = _mm_set_ps(0.0f, 1.0f, 0.0f, 0.0f);
	this->v3._m = _mm_set_ps(1.0f, t->z, t->y, t->x);
}

void Matrix::set(const MatrixRowEnum row, const Vect4D *const t)
{
	// initialize the rows of the matrix
	switch (row)
	{
	case MATRIX_ROW_0:
		this->v0._m = _mm_setr_ps(t->x, t->y, t->z, t->w);
		break;

	case MATRIX_ROW_1:
		this->v1._m = _mm_setr_ps(t->x, t->y, t->z, t->w);
		break;

	case MATRIX_ROW_2:
		this->v2._m = _mm_setr_ps(t->x, t->y, t->z, t->w);
		break;

	case MATRIX_ROW_3:
		this->v3._m = _mm_setr_ps(t->x, t->y, t->z, t->w);
		break;

	default:
		// should never get here, if we are here something bad has happened
		assert(0);
	}
}

float &Matrix::operator[](INDEX_ENUM e)
{
	// get the individual elements
	switch (e)
	{
	case 0:
		return m0;
		break;
	case 1:
		return m1;
		break;
	case 2:
		return m2;
		break;
	case 3:
		return m3;
		break;
	case 4:
		return m4;
		break;
	case 5:
		return m5;
		break;
	case 6:
		return m6;
		break;
	case 7:
		return m7;
		break;
	case 8:
		return m8;
		break;
	case 9:
		return m9;
		break;
	case 10:
		return m10;
		break;
	case 11:
		return m11;
		break;
	case 12:
		return m12;
		break;
	case 13:
		return m13;
		break;
	case 14:
		return m14;
		break;
	case 15:
		return m15;
		break;
	default:
		assert(0);
		return m0;
		break;
	}
}


void Matrix::get(const MatrixRowEnum row, Vect4D *const t)const
{ // get a row of the matrix
	switch (row)
	{
	case MATRIX_ROW_0:
		t->_m = this->v0._m;
		break;

	case MATRIX_ROW_1:
		t->_m = this->v1._m;
		break;

	case MATRIX_ROW_2:
		t->_m = this->v2._m;
		break;

	case MATRIX_ROW_3:
		t->_m = this->v3._m;
		break;

	default:
		assert(0);
	}
}


const Matrix Matrix::operator*(const Matrix& p)const
{ // matrix multiplications
	Vect4D  t, res1, res2, res3, res4;
	Vect4D  part1 = p.v0;
	Vect4D  part2 = p.v1;
	Vect4D  part3 = p.v2;
	Vect4D  part4 = p.v3;


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

	return Matrix(res1, res2, res3, res4);

}

const Matrix& Matrix::operator/=(const float rhs)
{
	// divide each element by a value
	// using inverse multiply trick, faster that individual divides
	__m128 tmp;
	tmp = _mm_set1_ps(1.0f / rhs);
	this->v0._m = _mm_mul_ps(this->v0._m, tmp);
	this->v1._m = _mm_mul_ps(this->v1._m, tmp);
	this->v2._m = _mm_mul_ps(this->v2._m, tmp);
	this->v3._m = _mm_mul_ps(this->v3._m, tmp);
	return *this;
}


void Matrix::Inverse(Matrix &out)
{
	__m128 m01, m_1, m, m1_3, r0, r1, r2, r3, det, tmp1;
	float *src = &this->m0;


	tmp1 = _mm_setr_ps(1.0f, 0.0f, 0.0f, 0.0f);
	det = tmp1;
	r3 = r2 = r1 = tmp1;
	tmp1 = _mm_loadh_pi(_mm_loadl_pi(tmp1, (__m64*)(src)), (__m64*)(src + 4));
	r1 = _mm_loadh_pi(_mm_loadl_pi(r1, (__m64*)(src + 8)), (__m64*)(src + 12));
	r0 = _mm_shuffle_ps(tmp1, r1, 0x88);
	r1 = _mm_shuffle_ps(r1, tmp1, 0xDD);
	tmp1 = _mm_loadh_pi(_mm_loadl_pi(tmp1, (__m64*)(src + 2)), (__m64*)(src + 6));
	r3 = _mm_loadh_pi(_mm_loadl_pi(r3, (__m64*)(src + 10)), (__m64*)(src + 14));
	r2 = _mm_shuffle_ps(tmp1, r3, 0x88);
	r3 = _mm_shuffle_ps(r3, tmp1, 0xDD);

	tmp1 = _mm_mul_ps(r2, r3);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
	m01 = _mm_mul_ps(r1, tmp1);
	m_1 = _mm_mul_ps(r0, tmp1);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
	m01 = _mm_sub_ps(_mm_mul_ps(r1, tmp1), m01);
	m_1 = _mm_sub_ps(_mm_mul_ps(r0, tmp1), m_1);
	m_1 = _mm_shuffle_ps(m_1, m_1, 0x4E);
	// -----------------------------------------------
	tmp1 = _mm_mul_ps(r1, r2);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
	m01 = _mm_add_ps(_mm_mul_ps(r3, tmp1), m01);
	m1_3 = _mm_mul_ps(r0, tmp1);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
	m01 = _mm_sub_ps(m01, _mm_mul_ps(r3, tmp1));
	m1_3 = _mm_sub_ps(_mm_mul_ps(r0, tmp1), m1_3);
	m1_3 = _mm_shuffle_ps(m1_3, m1_3, 0x4E);
	// -----------------------------------------------
	tmp1 = _mm_mul_ps(_mm_shuffle_ps(r1, r1, 0x4E), r3);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
	r2 = _mm_shuffle_ps(r2, r2, 0x4E);
	m01 = _mm_add_ps(_mm_mul_ps(r2, tmp1), m01);
	m = _mm_mul_ps(r0, tmp1);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
	m01 = _mm_sub_ps(m01, _mm_mul_ps(r2, tmp1));
	m = _mm_sub_ps(_mm_mul_ps(r0, tmp1), m);
	m = _mm_shuffle_ps(m, m, 0x4E);
	// -----------------------------------------------
	tmp1 = _mm_mul_ps(r0, r1);

	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
	m = _mm_add_ps(_mm_mul_ps(r3, tmp1), m);
	m1_3 = _mm_sub_ps(_mm_mul_ps(r2, tmp1), m1_3);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
	m = _mm_sub_ps(_mm_mul_ps(r3, tmp1), m);
	m1_3 = _mm_sub_ps(m1_3, _mm_mul_ps(r2, tmp1));
	// -----------------------------------------------
	tmp1 = _mm_mul_ps(r0, r3);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
	m_1 = _mm_sub_ps(m_1, _mm_mul_ps(r2, tmp1));
	m = _mm_add_ps(_mm_mul_ps(r1, tmp1), m);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
	m_1 = _mm_add_ps(_mm_mul_ps(r2, tmp1), m_1);
	m = _mm_sub_ps(m, _mm_mul_ps(r1, tmp1));
	// -----------------------------------------------
	tmp1 = _mm_mul_ps(r0, r2);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
	m_1 = _mm_add_ps(_mm_mul_ps(r3, tmp1), m_1);
	m1_3 = _mm_sub_ps(m1_3, _mm_mul_ps(r1, tmp1));
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
	m_1 = _mm_sub_ps(m_1, _mm_mul_ps(r3, tmp1));
	m1_3 = _mm_add_ps(_mm_mul_ps(r1, tmp1), m1_3);
	// -----------------------------------------------
	det = _mm_mul_ps(r0, m01);
	det = _mm_add_ps(_mm_shuffle_ps(det, det, 0x4E), det);
	det = _mm_add_ss(_mm_shuffle_ps(det, det, 0xB1), det);
	tmp1 = _mm_rcp_ss(det);
	det = _mm_sub_ss(_mm_add_ss(tmp1, tmp1), _mm_mul_ss(det, _mm_mul_ss(tmp1, tmp1)));
	det = _mm_shuffle_ps(det, det, 0x00);
	m01 = _mm_mul_ps(det, m01);
	_mm_storel_pi((__m64*)(src), m01);
	_mm_storeh_pi((__m64*)(src + 2), m01);
	m_1 = _mm_mul_ps(det, m_1);
	_mm_storel_pi((__m64*)(src + 4), m_1);
	_mm_storeh_pi((__m64*)(src + 6), m_1);
	m = _mm_mul_ps(det, m);
	_mm_storel_pi((__m64*)(src + 8), m);
	_mm_storeh_pi((__m64*)(src + 10), m);
	m1_3 = _mm_mul_ps(det, m1_3);
	_mm_storel_pi((__m64*)(src + 12), m1_3);
	_mm_storeh_pi((__m64*)(src + 14), m1_3);

	out.v0._m = m01;
	out.v1._m = m_1;
	out.v2._m = m;
	out.v3._m = m1_3;

}

void Matrix::setScaleMatrix(const Vect4D *const scale)
{
	//	{	sx		0		0		0	}
	//	{	0		sy		0		0	}
	//	{	0		0		sz		0	}
	//	{	0		0		0		1	}

	this->v0._m = _mm_set_ps(0.0f, 0.0f, 0.0f, scale->x);
	this->v1._m = _mm_set_ps(0.0f, 0.0f, scale->y, 0.0f);
	this->v2._m = _mm_set_ps(0.0f, scale->z, 0.0f, 0.0f);
	this->v3._m = _mm_set_ps(1.0f, 0.0f, 0.0f, 0.0f);
}

void Matrix::UpdateRotTransMatrix(Vect4D &s, float &az)
{
	float a = sinf(az), b = (float)cosf(az);

	this->v0._m = _mm_set_ps(0.0f, 0.0f, -a*s.x, b*s.x);
	this->v1._m = _mm_set_ps(0.0f, 0.0f, b*s.y, a*s.y);
	this->v2._m = _mm_set_ps(0.0f, s.z, 0.0f, 0.0f);
	this->v3._m = _mm_set_ps(1.0f, 0.0f, 0.0f, 0.0f);
}

void Matrix::UpdateCameraScale(Matrix &p)
{
	Vect4D t,part1,part2,part3,part4;

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

	t._m = _mm_add_ps(part1._m, part2._m);
	t._m = _mm_add_ps(t._m, part3._m);
	t._m = _mm_add_ps(t._m, part4._m);

	this->v3._m = t._m;
}

void Matrix::setRotZMatrix(float az)
{
	//	{	cos		-sin	0		0	}
	//	{	sin		cos		0		0	}
	//	{	0		0		1		0	}
	//	{	0		0		0		1	}

	float a = sinf(az), b = (float)cosf(az);

	this->v0._m = _mm_set_ps(0.0f, 0.0f, -a, b);
	this->v1._m = _mm_set_ps(0.0f, 0.0f, b, a);
	this->v2._m = _mm_set_ps(0.0f, 1.0f, 0.0f, 0.0f);
	this->v3._m = _mm_set_ps(1.0f, 0.0f, 0.0f, 0.0f);
}

// End of file