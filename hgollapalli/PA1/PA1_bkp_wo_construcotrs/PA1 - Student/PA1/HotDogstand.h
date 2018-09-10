#ifndef stand_h
#define stand_h

#include"OrderNames.h"

class Stand
{
public:
	int currNumOrders = 0,peakNumOrders=0;
	
	Order *pOrder;
	Stand *Next;
	Stand *Prev;
	Stand *Head;

	Stand();
	Stand(Order ob);
	//Stand(const Name  & p);
	//Stand & operator=(const Name & p);
	~Stand();


	void Add(Order p);
	void Print();
	void Remove(Name pobj);
};

#endif // !stand_h

