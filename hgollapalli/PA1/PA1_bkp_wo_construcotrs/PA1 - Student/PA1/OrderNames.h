#ifndef Order_h
#define Order_h

#include"Trace.h"
#include "Names.h"
#include "HotDog.h"


class  Order 
{
public:
	Name OrderName;
	Order *Prev;
	Order *Next;
	HotDog pHot;
	Order *Head=0 ;

	Order();
	Order(Name p);
	/*Order(const Order & p);
	Order & operator=(const Order & p);*/
	~Order();

	void Add(HotDog p);
	void Print();
};
#endif // !Order_h