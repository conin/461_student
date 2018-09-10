#include <stdio.h>

// Add any includes as you see fit
#include "Trace.h"
#include "Data.h"
#include <new>



int main()
{
	// Print the classes here:

	// I would create some helper functions, to make it easy
	// Print outputs for A,B,C,D,E,F,Vect,H,I,J 
	//      (do both original and rework data structures)
	// Remember: no STL, Templates or Boost, just simple C++
	
	char *c = new char[128];
	memset(c, 0xAA, 128);

	Test_A *tA = new(c)Test_A[0];
	tA->r = 0x00;
	tA->b = 0x00;
	tA->g = 0x00;
	tA->print();

	memset(c, 0xAA, 128);
	Test_A_Rework *tArework = new(c)Test_A_Rework[0];
	tA->r = 0x00;
	tA->b = 0x00;
	tA->g = 0x00;
	tArework->print();

	memset(c, 0xAA, 128);
	Test_B *tB = new(c)Test_B[0];
	tB->x = 0x00;
	tB->y = 0x00;
	tB->print();

	memset(c, 0xAA, 128);
	Test_B_Rework *tBrWork = new(c)Test_B_Rework[0];
	tBrWork->x = 0x00;
	tBrWork->y = 0x00;
	tBrWork->print();

	memset(c, 0xAA, 128);
	Test_C *tC = new(c)Test_C[0];
	tC->set();
	tC->print();

	memset(c, 0xAA, 128);
	Test_C_Rework *tCrWork = new(c)Test_C_Rework[0];
	tCrWork->set();
	tCrWork->print();

	memset(c, 0xAA, 128);
	Test_D *tD = new(c)Test_D[0];
	tD->set();
	tD->print();

	memset(c, 0xAA, 128);
	Test_D_Rework *tDrWork = new(c)Test_D_Rework[0];
	tDrWork->set();
	tDrWork->print();

	memset(c, 0xAA, 128);
	Test_E *tE = new(c)Test_E[0];
	tE->a = 0x00;
	tE->b = 0x00;
	tE->c = 0x00;
	tE->p = 0x00;
	tE->pad1 = 0x12;
	tE->pad2 = 0x12;
	tE->pad3 = 0x12;
	tE->pad4 = 0x12;
	tE->pad5 = 0x12;
	tE->pad6 = 0x12;
	tE->pad7 = 0x12;
	tE->pad8 = 0x12;
	tE->pad9 = 0x12;
	tE->x = 0x00;
	tE->y = 0x00;
	tE->print();

	memset(c, 0xAA, 128);
	Test_E_Rework *tER = new(c)Test_E_Rework[0];
	tER->a = 0x00;
	tER->b = 0x00;
	tER->c = 0x00;
	tER->p = 0x00;
	tER->pad1 = 0x11;
	tER->x = 0x00;
	tER->y = 0x00;
	tER->print();

	memset(c, 0xAA, 128);
	Test_F *tF = new(c)Test_F[0];
	tF->set();
	tF->print();

	memset(c, 0xAA, 128);
	Test_F_Rework *tFR = new(c)Test_F_Rework[0];
	tFR->set();
	tFR->print();

	memset(c, 0xAA, 128);
	Vect *tv = new(c)Vect[0];
	tv->set();
	tv->print();

	memset(c, 0xAA, 128);
	Vect_Rework *tvR = new(c)Vect_Rework[0];
	tvR->print();

	memset(c, 0xAA, 128);
	Test_H *tH = new(c)Test_H[0];
	tH->set();
	tH->print();

	memset(c, 0xAA, 128);
	Test_H_Rework *tHR = new(c)Test_H_Rework[0];
	tHR->print();

	memset(c, 0xAA, 128);
	Test_I *tI = new(c)Test_I[0];
	tI->set();
	tI->print();

	memset(c, 0xAA, 128);
	Test_I_Rework *tIR = new(c)Test_I_Rework[0];
	tIR->set();
	tIR->print();

	Trace::out("\n");
	char *ptrJ = new char[200];
	memset(ptrJ, 0xAA, 200);
	Test_J *ovrJ = new (ptrJ) Test_J[3];
	ovrJ[0].set();
	ovrJ->Print();

	
	memset(c, 0xAA, 300);
	Test_J_Rework *tJR = new(c)Test_J_Rework[0];
	memset(tJR->name, 0x00, 122);
	tJR->d = 0x00;
	tJR->y = 0x00;
	tJR->x = 0x00;
	tJR->z = 0x00;
	tJR->p = 0x00;
	tJR->c = 0x00;
	tJR->y = 0x00;
	tJR->Print();
	
	system("pause");
}