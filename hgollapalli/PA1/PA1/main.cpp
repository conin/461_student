#include <assert.h>

#include "MemTracker.h"

#include"Condiments.h"
#include"HotDog.h"
#include "OrderNames.h"
#include"HotDogstand.h"

// I will be testing this code
// Add files to the project to make these functions work
// Do not add source code to main.cpp
// ONLY add header files
// Make sure the output looks the same

int main()
{
MEM_TRACKER_START
	
// Remove for grading

	// Jaime order:
	HotDog  hotdog_A;
		hotdog_A.Add(Condiments::Everything);

	HotDog  hotdog_B;
		hotdog_B.Add(Condiments::Yellow_Mustard);
		hotdog_B.Add(Condiments::Sport_Peppers);

	HotDog  hotdog_C;
		hotdog_C.Add(Condiments::Celery_Salt);
		hotdog_C.Add(Condiments::Tomato_Wedge);
		hotdog_C.Add(Condiments::Green_Relish);

	Order order_Jamie(Name::Jaime);
		order_Jamie.Add(hotdog_A);
		order_Jamie.Add(hotdog_B);
		order_Jamie.Add(hotdog_C);


		

	 //Cersei order:
	HotDog hotdog_D;
		hotdog_D.Add(Condiments::Plain);

	Order order_Cersei(Name::Cersei);
		order_Cersei.Add(hotdog_D);
		order_Cersei.Add(hotdog_D);

		

	// Arya order:
	HotDog hotdog_E;
		hotdog_E.Add(Condiments::Everything);
		hotdog_E.Minus(Condiments::Sport_Peppers);

	Order order_Arya(Name::Arya);
	   order_Arya.Add(hotdog_E);

	   

	// Sansa order:
	HotDog hotdog_F;
		hotdog_F.Add(Condiments::Chopped_Onions);
		hotdog_F.Add(Condiments::Yellow_Mustard);
		hotdog_F.Add(Condiments::Green_Relish);

	HotDog hotdog_G;
		hotdog_G.Add(Condiments::Everything);

	Order order_Sansa(Name::Sansa);
		order_Sansa.Add(hotdog_F);
		order_Sansa.Add(hotdog_G);
		
		


	// Create Hot Dog stand
	Stand stand;
		stand.Add(order_Jamie);
		stand.Add(order_Cersei);
		stand.Add(order_Arya);
		stand.Add(order_Sansa);
		stand.Print();

	// Remove
		stand.Remove(Name::Cersei);
		stand.Print();

	// Remove
		stand.Remove(Name::Sansa);
		stand.Print();

	// Remove
		stand.Remove(Name::Jaime);
		stand.Print();

	// Remove
		stand.Remove(Name::Arya);
		stand.Print();

MEM_TRACKER_END

}