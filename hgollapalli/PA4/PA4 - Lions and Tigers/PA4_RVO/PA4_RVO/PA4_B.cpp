#include "PA4_B.h"

#if ! RVO_ENABLE
Vect2D Vect2D::operator + (const Vect2D &tmp) const
{ 
	return Vect2D(this->x + tmp.x, this->y + tmp.y);
};

Vect2D Vect2D::operator - (const Vect2D &tmp) const
{
	return Vect2D(this->x - tmp.x, this->y - tmp.y);
};

Vect2D Vect2D::operator * (const float scale) const
{
	return Vect2D(this->x * scale, this->y * scale);
};

Vect2D Vect2D::operator / (const float scale) const
{
	return Vect2D(this->x / scale, this->y / scale);
};
#endif 

#if RVO_ENABLE
Vect2D Vect2D::operator + ( const Vect2D &tmp ) const
{
	return Vect2D(this->x + tmp.x, this->y+tmp.y);
};

Vect2D Vect2D::operator+= (const Vect2D &tmp) const
{
		return Vect2D(this->x + tmp.x, this->y + tmp.y);
};

Vect2D Vect2D::operator-= (const Vect2D &tmp) const
{
	return Vect2D(this->x - tmp.x, this->y - tmp.y);
};

Vect2D Vect2D::operator/= (const float scale) const
{
	return Vect2D(this->x / scale, this->y / scale);
};

Vect2D Vect2D::operator*= (const float scale) const
{
	return Vect2D(this->x * scale, this->y * scale);
};


Vect2D Vect2D::operator - ( const Vect2D &tmp ) const
{
	return Vect2D(this->x - tmp.x, this->y - tmp.y);
};

Vect2D Vect2D::operator * ( const float scale ) const
{
	return Vect2D(this->x * scale, this->y * scale);
};

Vect2D Vect2D::operator / ( const float scale ) const
{
	return Vect2D(x / scale, y / scale);
};

#endif // RVO_ENABLE