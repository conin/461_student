#ifndef HotDog_H
#define HotDog_H

#include "CondimentsNames.h"


class HotDog : public CondimentsNames
{
	
	public:
		HotDog *Next;
		HotDog *Prev;
		HotDog *head = 0;

		HotDog();
		HotDog(const Condiments &);
		HotDog& operator=(const Condiments &a);
		~HotDog();

		void addEveryThing();
		int Add(Condiments pObj);
		void Minus(Condiments pObj);
		void print();
};

#endif // ! HotDog_H
