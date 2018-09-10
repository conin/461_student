#include "Vect4D_SIMD.h"
#include "LERP_SIMD.h"


/*****************************************************************************
* LERP - linear interpolation
*
* This function returns a point on a line segment given in parametric form. 
* Where the inputs are point a (starting point), point b (ending point) of  
* the line segment and the parametric variable t.  If t is in the range of  
* ranging from t=0.0 to 1.0, this function returns a point on the line      
* segment. If t=0.0 this function returns point a, if t=1.0 this returns    
* point b.  Values of t<0.0 return points on the infinite line defined      
* before point a. Values of t>1.0 returns points on the infinite line       
* defined after point b.                                                    
*
* inputs:
*		a - point A
*		b - point B
*		t - parametric t
*
* @return Vector (point) linearly interpolated based on parametric t
*
* Example:
*
*     Vect   v1(1.0f, 2.0f, 3.0f);   // create v1=[1,2,3,1]
*     Vect   v2(-5.0f, 2.0f, 7.0f);  // create v2=[-5,2,7,1]
*     Vect   out;                    // create out vector
*
*     out =	lineParametric (v1, v2, 0.4f );  // t = 0.4f

******************************************************************************/

void VectApp_SIMD :: Lerp(Vect4D_SIMD &out, const Vect4D_SIMD &a, const Vect4D_SIMD &b, const float t)
{
	Vect4D_SIMD tmp,val;

	//out = a + t * (b-a);

	//b-a
	tmp._m = _mm_sub_ps(b._m, a._m);
	//t
	val._m = _mm_set_ps1(t);
	//t*(b-a)
	tmp._m = _mm_mul_ps(val._m, tmp._m);

	//a + t*(b-a)
	out._m = _mm_add_ps(a._m, tmp._m);
} 
