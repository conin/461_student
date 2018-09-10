#ifndef LERP_H
#define LERP_H

#include "Vect4D.h"

#define UNUSED_VAR(v) ((void )v)

#include <xmmintrin.h>
#include <smmintrin.h>  

class VectApp
{
		
public:

	// lerp
	static void Lerp(Vect4D &out,  Vect4D &a,   Vect4D &b,  float t );

};


#endif