#include"CondimentsNames.h"



CondimentsNames::CondimentsNames()
{
	this->pName = Condiments::Everything;
}

CondimentsNames::CondimentsNames(Condiments pObj)
{
	this->pName = pObj;
}

CondimentsNames::CondimentsNames(const Condiments &p)
{
	this->pName = p;
}

CondimentsNames & CondimentsNames::operator= (const Condiments &p)
{
	this->pName = p;
	return *this;
}


CondimentsNames::~CondimentsNames()
{
}