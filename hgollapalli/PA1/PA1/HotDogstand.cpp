#include<stdio.h>

#include"HotDogstand.h"
#include "Trace.h"

Stand::Stand()
{
	this->Next = 0;
	this->Prev = 0;
	this->Head = 0;
	if (this->Head==0)
		Trace::out("\n currNumOrders : %d peakNumOrders : %d ", currNumOrders, peakNumOrders);
	 
}

Stand::Stand(Order ob)
{
	this->pOrder = ob;
	if (this->Head != 0)
		this->Head = 0;
}

Stand::Stand(const Name &p)
{
	this->pOrder.OrderName = p;
}

Stand & Stand::operator= (const Name &p)
{
	this->pOrder.OrderName = p;
	return *this;
}

Stand::~Stand()
{
	/*delete this->Next;
	delete this->Prev;*/
}

void printOrderName(Name tmp)
{
	
		switch (tmp)
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
}

void printCondimentsName(HotDog *tmp2)
{
	HotDog *t = tmp2;
	if (t!=0)
	{
	
	}

	switch (tmp2->pName)
	{
	case Condiments::Celery_Salt:
		Trace::out("\t\tCelery_Salt");
		break;

	case Condiments::Chopped_Onions:
		Trace::out("\t\tChopped_Onions");
		break;

	case Condiments::Everything:
		Trace::out("\t\tEverything");
		break;

	case Condiments::Green_Relish:
		Trace::out("\t\tGreen_Relish");
		break;

	case Condiments::Ketchup:
		Trace::out("\t\tKetchup");
		break;

	case Condiments::Pickle_Spear:
		Trace::out("\t\tPickle_Spear");
		break;

	case Condiments::Plain:
		Trace::out("\t\tPlain");
		break;

	case Condiments::Sport_Peppers:
		Trace::out("\t\tSport_Peppers");
		break;

	case Condiments::Tomato_Wedge:
		Trace::out("\t\tTomato_Wedge");
		break;

	case Condiments::Yellow_Mustard:
		Trace::out("\t\tYellow_Mustard");
		break;

	default:
		break;
	}
	Trace::out("\n");
}

void Stand::Add(Order p)
{
	Stand *tmp = new Stand(p);
	tmp->pOrder = *p.Head;
	//tmp->pOrder=*p.Head->Next
	tmp->pOrder.OrderName = p.OrderName;
	
	Trace::out("\n  Add -> Order :");
	printOrderName(tmp->pOrder.OrderName);

	if (Head == 0)
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

	this->currNumOrders++;

	if (this->currNumOrders> this->peakNumOrders)
		peakNumOrders +=(currNumOrders-peakNumOrders);
}

void Stand::Print()
{
	Stand *stand = this;

	
	Order *tmp;
	Trace::out("\n****************************************************\n");
	Trace::out("\n Hot Dog Stand ::");
	Trace::out(" Current Orders %d ", currNumOrders);
	Trace::out("\t Peek Number Orders %d", peakNumOrders);

	if (this->currNumOrders == 0)
		Trace::out(" \n No Orders...!\n");
	stand = stand->Head;

	while(stand !=0 && this->currNumOrders > 0)
	{
		tmp = &stand->pOrder;

			Trace::out("\nOrder : ");
			printOrderName(tmp->OrderName);

			Trace::out("\n");
			int ind = 1;


			while (tmp != 0)
			{
				HotDog *tmp2 = &tmp->pHot;
				Trace::out("  HotDog %d", ind);
				Trace::out("\n");

				while (tmp2 != 0)
				{
					printCondimentsName(tmp2);
					tmp2 = (HotDog*)tmp2->Next;
				}
				
				ind++;
				tmp = tmp->Next;
				Trace::out("\n");
			}
			stand = stand->Next;
	}
}

void Stand::Remove(Name p)
{
	Stand *tmp = Head;

	if (Head == 0)
	{
		Trace::out("No Orders to be deleted");
	}
	else
	{
		Trace::out("*********************\n ");
		Trace::out("Remove -> Order : ");
		Order *t = new Order();
		t->OrderName = p;
		printOrderName(t->OrderName);
		Trace::out("\n");
		delete t;

		while (tmp != 0)
		{
			if (tmp->pOrder.OrderName == p)
				break;

			tmp = tmp->Next;
		}

		if (tmp != 0 && tmp->Prev == 0 && tmp->Next != 0)
		{
			Head = tmp->Next;
			tmp->Prev = 0;
			delete tmp;
			this->currNumOrders--;
		}
		else if (tmp != 0 && tmp->Prev == 0 && tmp->Next == 0)
		{
			Head = 0;
			delete tmp;
			this->currNumOrders--;
		}
		else if (tmp != 0 && tmp->Prev != 0 && tmp->Next != 0)
		{
			tmp->Next->Prev = tmp->Prev;
			tmp->Prev->Next = tmp->Next;
			delete tmp;
			this->currNumOrders--;
		}
		else if (tmp != 0 && tmp->Prev != 0 && tmp->Next == 0)
		{
			tmp->Prev->Next = 0;
			delete tmp;
			this->currNumOrders--;
		}
	}
}