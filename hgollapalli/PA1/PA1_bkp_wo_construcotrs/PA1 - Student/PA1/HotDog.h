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
		HotDog(Condiments p);
		/*HotDog(const HotDog &);
		HotDog& operator=(const HotDog &a);*/
		~HotDog();

		void addEveryThing();
		int Add(Condiments pObj);
		void Minus(Condiments pObj);
		void print();
};

#endif // ! HotDog_H
