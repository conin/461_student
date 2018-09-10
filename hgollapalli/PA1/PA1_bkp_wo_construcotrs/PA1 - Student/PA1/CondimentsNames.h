#ifndef Condiments_H
#define Condiments_H
#include "Condiments.h"

class CondimentsNames
{
	public:
		Condiments pName;

		CondimentsNames();
		CondimentsNames(Condiments pObj);
		CondimentsNames(const Condiments & p);
		CondimentsNames & operator=(const Condiments & p);
		~CondimentsNames();
};

#endif // ! HotDog_H