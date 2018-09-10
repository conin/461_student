#include "Nibble.h"

Nibble::Nibble()
{
	this->data = 0;
}

Nibble::~Nibble() 
{
	this->data = 0;
}

Nibble::Nibble(unsigned int p) 
{
	this->data =(unsigned char) p;
}


Nibble Nibble::operator=(const Nibble &p)
{
	this->data = p.data;
	return *this;
}

Nibble::Nibble(const Nibble &p)
{
	this->data = p.data;
}

Nibble Nibble::operator+(const Nibble &p)
{
	return Nibble((unsigned char)(this->data+p.data));
}

Nibble Nibble::operator+=(const Nibble &p)
{
	this->data = (unsigned char)(this->data + p.data);
	return *this;
}

Nibble Nibble::operator+(int x)
{
	this->data = (unsigned char)(this->data + x);
	return *this;
}

Nibble operator+(int x, const Nibble &p)
{
	return Nibble((unsigned char)(x+p.data));
}

Nibble operator~(const Nibble &p)
{
	return Nibble((unsigned char)~p.data);
}

Nibble operator+(const Nibble &p)
{
	return Nibble((unsigned char)+p.data);
}

Nibble operator++(const Nibble &p)
{
	return Nibble((unsigned char)(p.data+(unsigned char)1));
}

Nibble operator<<(const Nibble &p, int x)
{
	return Nibble((unsigned char)(p.data << x));
}

unsigned char Nibble::getData()
{
	return this->data;
}


// End of file