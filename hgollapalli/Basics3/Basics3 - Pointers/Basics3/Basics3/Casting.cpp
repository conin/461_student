#include <stdio.h>
#include "answerRegistry.h"
#include"Trace.h"
#define QuestionAnswer(x,y)  Answer::registerAnswer(1,x,(unsigned int)y)

struct Cat
{
	Cat()
	:c0( 0xC9 ), c1(0xCA), c2(0xCB)
	{}

	unsigned char c0;
	unsigned char c1;
	unsigned char c2;
};

struct Dog
{
	Dog()
	: d0(0xDDAA), d1(0xDDBB), d2(0xDDCC)
	{}

	unsigned short d0;
	unsigned short d1;
	unsigned short d2;
};

struct Bird
{
	Bird()
	: b0(0xBB001111), b1(0xBB002222), b2(0xBB003333)
	{}

	unsigned int b0;
	unsigned int b1;
	unsigned int b2;
};

struct petStore
{
	Cat		morris;
	char	pad0;
	Dog		fido;
	char    pad1;
	char    pad2;
	Bird	poly;
};


void Students_Casting()
{
	petStore		ps;
	unsigned int	*r;
	unsigned short	*s;
	unsigned char	*p;

	// Example:
	// Using only:  
	//             unsigned char *p
	//             initialize p with ps

	p = &ps.morris.c1;
	QuestionAnswer(0, *p);

	r = &ps.poly.b0;
	QuestionAnswer(1, *r);

	r += 1;
	QuestionAnswer(2, *r);

	r += 1;
	QuestionAnswer(3, *r);
	
	s = &ps.fido.d0;
	QuestionAnswer(4, *s);
	

	s = (unsigned short*)(s+ 1);
	QuestionAnswer(5, *s);
	
	s += 1;
	QuestionAnswer(6, *s);
	
	p = &ps.morris.c0;
	QuestionAnswer(7, *p);
	
	p += 1;
	QuestionAnswer(8, *p);
		
	p += 1;
	QuestionAnswer(9, *p);
	

	// Using only p, find the values: 
	//      question 0) morris.c1
	
	
	// Now repeat the pattern above { use the QuestionAnswer( index, val ) macro } 

	// Using only:  
	//             unsigned int *r
	//             initialize r with ps

	// REPLACE THIS LINE:
	
	// Using only r, find the values: 
	//      question 1)  b0 
	//      question 2)  b1
	//      question 3)  b2 


	// Using only:  
	//             unsigned short *s
	//             initialize s with ps

	// REPLACE THIS LINE:
	(void *)s;

	// Using only s, find the values: 
	//      question 4)  d0 
	//      question 5)  d1
	//      question 6)  d2 

	
	// Using only:  
	//             unsigned char *p
	//             initialize p with ps

	// REPLACE THIS LINE:
	(void *)p;

	// Using only p, find the values: 
	//      question 7)  c0 
	//      question 8)  c1
	//      question 9)  c2 
		

	// For the next set of questions
	//
	// You can cast and create temp variables to help you answer questions correctly.
	//          p <- the starting address of ps
	//          s <- the starting address of ps
	//          r <- the starting address of ps

	p = (unsigned char *)&ps;
	s = (unsigned short *)&ps;
	r = (unsigned int *)&ps;

	//      question 10)  addr of ps
	

	//      question 11)  number of unsigned chars to d0
	//      question 12)  number of unsigned chars to c1
	//      question 13)  number of unsigned chars to b2;
	
	p = (unsigned char *)((unsigned char *)&ps.fido.d0 - &ps.morris.c0);
	QuestionAnswer(11, p);

	p = (unsigned char *)(&ps.morris.c1 - &ps.morris.c0);
	QuestionAnswer(12, p);

	p = (unsigned char *)((unsigned char *)&ps.poly.b2 - &ps.morris.c0);
	QuestionAnswer(13, p);

	//      question 14)  number of unsigned shorts to the first d2
	//      question 15)  number of unsigned shorts to the first c2
	//      question 16)  number of unsigned shorts to b1;
	
	s = (unsigned short *)((unsigned short *)&ps.fido.d2 - (unsigned short *)&ps.morris.c0);
	QuestionAnswer(14, s);

	s = (unsigned short *)((unsigned short *)&ps.morris.c2 - (unsigned short *)&ps.morris.c0);
	QuestionAnswer(15, s);

	s = (unsigned short *)((unsigned short *)&ps.poly.b1 - (unsigned short *)&ps.morris.c0);
	QuestionAnswer(16, s);

	//      question 17)  number of unsigned ints to the first d0
	//      question 18)  number of unsigned ints to the first c0
	//      question 19)  number of unsigned ints to the first b0;

	
	r = (unsigned int *)((unsigned int *)&ps.fido.d0 - (unsigned int *)&ps.morris.c0);
	QuestionAnswer(17, r);

	r = (unsigned int *)((unsigned int *)&ps.morris.c0 - (unsigned int *)&ps.morris.c0);
	QuestionAnswer(18, r);

	r = (unsigned int *)((unsigned int *)&ps.poly.b0 - (unsigned int *)&ps.morris.c0);
	QuestionAnswer(19, r);


}