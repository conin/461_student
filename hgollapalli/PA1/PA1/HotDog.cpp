#include "HotDog.h"

HotDog::HotDog() 
{
	this->Next = 0;
	this->Prev = 0;
}

HotDog::HotDog(const Condiments &p)
{
	this->pName = p;
}

HotDog & HotDog::operator= (const Condiments &p)
{
	this->pName = p;
	return *this;
}

HotDog::~HotDog()
{
	/*delete Next;
	delete Prev;
	delete head;*/
}

void HotDog::addEveryThing()
{
	Add(Condiments::Celery_Salt);
	Add(Condiments::Chopped_Onions);
	Add(Condiments::Green_Relish);
	Add(Condiments::Pickle_Spear);
	Add(Condiments::Sport_Peppers);
	Add(Condiments::Tomato_Wedge);
	Add(Condiments::Yellow_Mustard);
}

int HotDog::Add(Condiments pObj)
{
	HotDog *h = new HotDog(pObj);
	
	if (pObj == Condiments::Everything)
	{
		addEveryThing();
		return 0;
	}
		

	if(head==0)
	{
		h->pName = pObj;
		h->Next = 0;
		h->Prev = 0;
		head = h;
	}
	else
	{
		h->pName = pObj;
		
		h->Prev = 0;		
		h->Next = head;
		h->Next->Prev = h;
		head = h;
	}
	return 0;
}

void HotDog::Minus(Condiments pObj)
{	
	HotDog *tmp = head;

	while (tmp!=0)
	{
		if (tmp->pName == pObj)
			break;

		tmp = tmp->Next;
	}

	if(tmp != 0 && tmp->Prev==0 && tmp->Next!=0)
	{
		head = tmp->Next;
		tmp->Prev = 0;
	}
	else if (tmp != 0 && tmp->Prev == 0 && tmp->Next == 0)
	{
		head = 0;
		delete tmp;
	}
	else if (tmp != 0 && tmp->Prev != 0 && tmp->Next != 0)
	{
		tmp->Next->Prev = tmp->Prev;
		tmp->Prev->Next = tmp->Next;
		delete tmp;
	}
	else if (tmp != 0 && tmp->Prev != 0 && tmp->Next == 0)
	{
		tmp->Prev->Next = 0;
		delete tmp;
	}
}

void HotDog::print()
{
	HotDog *tmp = head;

	while (tmp!=0)
	{
		tmp = tmp->Next;
	}
}
