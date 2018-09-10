#ifndef PA4_A_H
#define PA4_A_H

#define IMPLICIT_CONVERSIONS 1   // toggle me to see performance differences

class Vect
{
public:
	//*********************************************************************
	// The Givens:  Always define these four
	//*********************************************************************

		// default constructor
		Vect()
			: x(0.0f), y(0.0f), z(0.0)
		{
		};

		// copy constructor
		Vect( const Vect &tmp)
			: x(tmp.x), y(tmp.y), z(tmp.z)
		{
		};

		// assignment vector
		const Vect & operator = (const Vect &tmp )
		{
			this->x = tmp.x;
			this->y = tmp.y;
			this->z = tmp.z;

			return *this;
		};

		// destructor
		~Vect()
		{
		};

	//*********************************************************************
	// Methods and operators that have take implicit conversions
	// These are the functions you need to prevent implicit conversion:
	//*********************************************************************

	// overload constructor
#if IMPLICIT_CONVERSIONS
		Vect operator + (const Vect tmp) const
		{
			return (Vect(this->x + tmp.x, this->y + tmp.y, this->z + tmp.z));

		}
		Vect(const float inX, const float inY, const float inZ)
			: x(inX), y(inY), z(inZ)
		{
		};

		void setX(const float inX)
		{
			this->x = inX;
		};

		void setY(const float inY)
		{
			this->y = inY;
		};

		void setZ(const float inZ)
		{
			this->z = inZ;
		};

		void set(const float inX, const float inY, const float inZ)
		{
			this->x = inX;
			this->y = inY;
			this->z = inZ;
		};

		float getX()
		{
			return this->x;
		};

		float getY()
		{
			return this->y;
		};

		float getZ()
		{
			return this->z;
		};

#else
		Vect operator + (const Vect tmp) const
		{
			return (Vect(this->x + tmp.x, this->y + tmp.y, this->z + tmp.z));

		}
		Vect(const float inX, const float inY, const float inZ)
			: x(inX), y(inY), z(inZ)
		{
		};

		void setX(const float inX)
		{
			this->x = inX;
		};

		void setY(const float inY)
		{
			this->y = inY;
		};

		void setZ(const float inZ)
		{
			this->z = inZ;
		};

		void set(const float inX, const float inY, const float inZ)
		{
			this->x = inX;
			this->y = inY;
			this->z = inZ;
		};

		float getX()
		{
			return this->x;
		};

		float getY()
		{
			return this->y;
		};

		float getZ()
		{
			return this->z;
		};
#endif

private:
	float x;
	float y;
	float z;

	template<class T,class B,class C> Vect(const T inTX, const B inTY, const C inTZ)
		: x(inTX), y(inTY), z(inTZ)
	{
	};

	// set functions
	template<class T> 	void setX(T inx)
	{
		this->x = inX;
	}

	template<class T>	void setY(T inY)
	{
		this->y = inY;
	}

	template<class T>	void setZ(T Z)
	{
		this->z = Z;
	}

	template<class  T, class  r, class  s>	void set(const T inX, const r inY, const s inZ)
	{
		this->x = inX;
		this->y = inY;
		this->z = inZ;
	};

	template<class  T>
	T getX()
	{
		return this->x;
	}

	template<class  T>	T getY()
	{
		return this->y;
	}

	template<class  T>	T getZ()
	{
		return this->z;
	}
};

#endif