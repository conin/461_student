#include <stdio.h>

// Add any includes as you see fit
#include "Trace.h"
#include "Data.h"
#include <new>
int main()
{
	//Test_A
	char *c = new char[128];
	memset(c, 0xAA, 128);

	Test_A *tA = new(c)Test_A[0];
	tA->r = 0x00;
	tA->b = 0x00;
	tA->g = 0x00;
	tA->Print();

	memset(c, 0xAA, 128);
	Test_A_Rework *tArework = new(c)Test_A_Rework[0];
	tArework->r = 0x00;
	tArework->b = 0x00;
	tArework->g = 0x00;
	tArework->Print();

	memset(c, 0xAA, 128);
	Test_B *tB = new(c)Test_B[0];
	tB->x = 0x00;
	tB->y = 0x00;
	tB->Print();

	memset(c, 0xAA, 128);
	Test_B_Rework *tBrWork = new(c)Test_B_Rework[0];
	tBrWork->x = 0x00;
	tBrWork->y = 0x00;
	tBrWork->Print();

	memset(c, 0xAA, 128);
	Test_C *tC = new(c)Test_C[0];
	tC->set();
	tC->Print();

	memset(c, 0xAA, 128);
	Test_C_Rework *tCWork = new(c)Test_C_Rework[0];
	tCWork->set();
	tCWork->Print();

	memset(c, 0xAA, 128);
	Test_D *tD = new(c)Test_D[0];
	tD->set();
	tD->Print();

	memset(c, 0xAA, 128);
	Test_D_Rework *tDrWork = new(c)Test_D_Rework[0];
	tDrWork->set();
	tDrWork->Print();

	memset(c, 0xAA, 128);
	Test_E *tE = new(c)Test_E[0];
	tE->a = 0x00;
	tE->b = 0x00;
	tE->c = 0x00;
	tE->p = 0x00;
	tE->x = 0x00;
	tE->y = 0x00;
	tE->Print();

	memset(c, 0xAA, 128);
	Test_E_Rework *tER = new(c)Test_E_Rework[0];
	tER->a = 0x00;
	tER->b = 0x00;
	tER->c = 0x00;
	tER->p = 0x00;
	tER->x = 0x00;
	tER->y = 0x00;
	tER->Print();

	memset(c, 0xAA, 128);
	Test_F *tF = new(c)Test_F[0];
	tF->set();
	tF->Print();

	memset(c, 0xAA, 128);
	Test_F_Rework *tFR = new(c)Test_F_Rework[0];
	tFR->set();
	tFR->Print();

	memset(c, 0xAA, 128);
	Vect *tv = new(c)Vect[0];
	tv->set();
	tv->Print();

	memset(c, 0xAA, 128);
	Vect_Rework *tvR = new(c)Vect_Rework[0];
	tvR->set();
	tvR->Print();

	memset(c, 0xAA, 128);
	Test_H *tH = new(c)Test_H[0];
	tH->a = 0x00;
	tH->b = 0x00;
	tH->c = 0x00;
	tH->v1.vx = 0x00;
	tH->v1.vy = 0x00;
	tH->v1.vz = 0x00;
	tH->v1.vw = 0x00;
	tH->v1.d = 0x00;
	tH->v1.e = 0x00;
	tH->Print();

	memset(c, 0xAA, 128);
	Test_H_Rework *tHR = new(c)Test_H_Rework[0];
	tHR->a = 0x00;
	tHR->b = 0x00;
	tHR->c = 0x00;
	tHR->v1.vx = 0x00;
	tHR->v1.vy = 0x00;
	tHR->v1.vz = 0x00;
	tHR->v1.vw = 0x00;
	tHR->v1.d = 0x00;
	tHR->v1.e = 0x00;
	tHR->v1.pad1 = 0x00;
	tHR->v1.pad2 = 0x00;
	tHR->Print();


	memset(c, 0xAA, 128);
	Test_I *tI = new(c)Test_I[0];
	tI->set();
	tI->Print();

	memset(c, 0xAA, 128);
	Test_I_Rework *tIR = new(c)Test_I_Rework[0];
	tIR->set();
	tIR->Print();

	char *ptrJ = new char[200];
	memset(ptrJ, 0xAA, 200);
	Test_J *ovrJ = new (ptrJ) Test_J[0];
	ovrJ[0].set();
	ovrJ->Print();

	char *c1 = new char[300];
	memset(c1, 0xAA, 300);
	Test_J_Rework *tJR = new(c1)Test_J_Rework[0];
	memset(tJR->name, 0x00, 122);
	tJR->d = 0x00;
	tJR->y = 0x00;
	tJR->x = 0x00;
	tJR->z = 0x00;
	tJR->p = 0x00;
	tJR->c = 0x00;
	tJR->y = 0x00;
	tJR->Print();
}