#include <stdio.h>
#include <string.h>

#include "Monkey.h"
#include "Trace.h"

Monkey::Monkey()
{
	this->x = 222;
	this->y = 333;
	this->pStatus = new char[30];
	memset(pStatus,'\0',30);
	this->numStringsCreated++;
	strcpy_s(this->pStatus,26,"Initialized with default!");	
}

Monkey::~Monkey() 
{
	this->x = 0;
	this->y = 0;
	this->pStatus = '\0';
	this->numStringsDestroyed--;
}

//Monkey::Monkey(Monkey &p)
//{
//	this->x = p.x;
//	this->y = p.y;
//	this->pStatus = p.pStatus; 
//}

Monkey Monkey::operator=(Monkey &p)
{
	this->x = p.x;
	this->y = p.y;
	this->pStatus = p.pStatus;
	this->numStringsCreated++;
	return *this;
}

Monkey::Monkey(int x)
{
	this->x = x;
	this->pStatus = new char[21];
	memset(pStatus, '\0', 21);
	this->numStringsCreated++;
	strcpy_s(this->pStatus, 21, "Initialized by user!");
}


Monkey::Monkey(int x, int y) 
{
	this->x = x;
	this->y = y;
	this->pStatus = new char[21];
	this->numStringsCreated++;
	memset(pStatus, '\0', 21);
	strcpy_s(this->pStatus, 21, "Initialized by user!");
}

int Monkey::getX()
{
	return this->x;
}

int Monkey::getY()
{
	return this->y;
}

char *Monkey::getStatus()
{
	return this->pStatus;
};

void Monkey::printStatus()
{
	Trace::out("Monkey (Status): %s\n", this->pStatus);
}


// END of File