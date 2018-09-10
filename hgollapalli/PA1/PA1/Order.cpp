#include "OrderNames.h"
#include "Names.h"


Order::Order()
{
	if(this->Head==0)
	{
		this->Head = 0;
		this->Prev = 0;
		this->Next = 0;
	}
	/*else
	{
		this->Prev = 0;
		this->Next = 0;
	}*/
}

Order::Order(Name p)
{
	this->OrderName = p;
}

Order::Order(const Order &p)
{
	if(p.Head!=0)
	{
		this->Head = p.Head;
		this->OrderName = p.OrderName;
	}
	else
	{
		this->OrderName = p.OrderName;
		this->pHot = p.pHot;
	}
	
}

Order & Order::operator= (const Order &p)
{
	if(p.Head)
	{
		/*Order ob = p;
		this->Head = &ob;*/
		this->OrderName = p.Head->OrderName;
		this->pHot = p.Head->pHot;
		this->Next = p.Head->Next;
	}
	return *this;
}


Order:: ~Order()
{
	
}

void Order::Add(HotDog p)
{
	Order *tmp = new Order();
	tmp->OrderName = this->OrderName;
	tmp->pHot = *p.head;

	if(Head==0)
	{
		Head = tmp;
		tmp->Next = 0;
		tmp->Prev = 0;
	}
	else
	{
		tmp->Prev = 0;
		tmp->Next = Head;
		tmp->Next->Prev = tmp;
		Head = tmp;		
	}
}

void Order::Print()
{
	Order *tmp = Head;

	switch (tmp->OrderName)
	{
	case Name::Arya:
		Trace::out("Arya");
		break;

	case Name::Cersei:
		Trace::out("Cersei");
		break;

	case Name::Jaime:
		Trace::out("Jaime");
		break;

	case Name::Jon:
		Trace::out("Jon");
		break;

	case Name::Samwell:
		Trace::out("Samwell");
		break;

	case Name::Sansa:
		Trace::out("Sansa");
		break;

	case Name::Tyrion:
		Trace::out("Tyrion");
		break;

	default:
		break;
	}
	Trace::out("\n");

	while (tmp!=0)
	{
		HotDog *tmp2 = &tmp->pHot;

		while (tmp2!=0)
		{
			switch (tmp2->pName)
			{
				case Condiments::Celery_Salt:
					Trace::out("\tCelery_Salt");
					break;

				case Condiments::Chopped_Onions:
					Trace::out("\tChopped_Onions");
					break;

				case Condiments::Everything:
					Trace::out("\tEverything");
					break;

				case Condiments::Green_Relish:
					Trace::out("\tGreen_Relish");
					break;

				case Condiments::Ketchup:
					Trace::out("\tKetchup");
					break;

				case Condiments::Pickle_Spear:
					Trace::out("\tPickle_Spear");
					break;

				case Condiments::Plain:
					Trace::out("\tPlain");
					break;

				case Condiments::Sport_Peppers:
					Trace::out("\tSport_Peppers");
					break;

				case Condiments::Tomato_Wedge:
					Trace::out("\tTomato_Wedge");
					break;

				case Condiments::Yellow_Mustard:
					Trace::out("\tYellow_Mustard");
					break;

				default:
				break;
			}
			Trace::out("\n");
			tmp2 = (HotDog*) tmp2->Next;
		}
		tmp = (Order*) tmp->Next;
		Trace::out("\n");
	}
}