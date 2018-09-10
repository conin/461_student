#include "UnitTest.h"
#include <string.h>
#include <stdio.h>
#include"Trace.h"
#include "CopyingStrings.h"
#include "ComparingStrings.h"
#include "LengthOfStrings.h"
#include "CopyToBuffer.h"
#include "SortStrings.h"

TEST( compare_strings, StringTests)
{
	char *s1 = "asf;ldj2";
	char *s2 = "asf;ldk2";
	char *s3 = "asf;lde2";
	char *s4 = "asf;lde21";

	CHECK( StringCompare_1( s1, s1 ) == 0 );
	CHECK( StringCompare_2( s1, s1 ) == 0 );
	CHECK( StringCompare_3( s1, s1 ) == 0 );

	CHECK( StringCompare_1( s1, s2 ) == -1 );
	CHECK( StringCompare_2( s1, s2 ) == -1 );
	CHECK( StringCompare_3( s1, s2 ) == -1 );

	CHECK( StringCompare_1( s1, s3 ) == 1 );
	CHECK( StringCompare_2( s1, s3 ) == 1 );
	CHECK( StringCompare_3( s1, s3 ) == 1 );

	CHECK( StringCompare_1( s1, s4 ) == 1 );
	CHECK( StringCompare_2( s1, s4 ) == 1 );
	CHECK( StringCompare_3( s1, s4 ) == 1 );
}

TEST( copy_strings, StringTests)
{
	char *d1 = new char[10];
	char *d2 = new char[10];
	char *d3 = new char[10];
	char *s2 = "12480973";
	char *s;

	s = StringCopy_1( d1, s2 );
	CHECK( (int)s == (int) d1);
	CHECK( strcmp( d1, s2 ) == 0 );

	s = StringCopy_2( d2, s2 );
	CHECK( (int)s == (int) d2);
	CHECK( strcmp( d2, s2 ) == 0 );

	s = StringCopy_3( d3, s2 );
	CHECK( (int)s == (int) d3);
	CHECK( strcmp( d3, s2 ) == 0 );

	// I HATE string.h lack of protection for null
	// --> WOW
	// strcpy( s1, 0 );
	// strcpy( 0, s2 );

}


TEST( strings_len, StringTests)
{
	char *s1 = "12480973";
	char *s0 = "";
	char s4[] = {'\0'};
	char s3[20] = "2233";
	
	CHECK( LengthOfString_1(s1) == 8 );
	CHECK( LengthOfString_2(s1) == 8 );

	CHECK( LengthOfString_1(s3) == 4 );
	CHECK( LengthOfString_2(s3) == 4 );

	CHECK( LengthOfString_1(s0) == 0 );
	CHECK( LengthOfString_2(s0) == 0 );

	CHECK( LengthOfString_1(s4) == 0 );
	CHECK( LengthOfString_2(s4) == 0 );

	// I HATE string.h lack of protection for null
	// --> WOW
	// strlen( 0 );


}


TEST( Copy_to_Buffer, StringTests)
{
	dog fido;
	char *s1 = "MonkeyBra";
	char *s2 = "Mono";
	char *s3 = "";
	char *s4 = "MonkeyBrai";
	char *s;

	fido.setMessage( "MonkeyBrainsAreYummy");
	s = fido.getMessage();
	CHECK( strcmp(s,s1) == 0);
	CHECK(strcmp(s, s2) == -1);
	CHECK( strcmp(s,s4) == -1);
	CHECK( strcmp(s4,s) == 1);
	fido.print();

	fido.setMessage( "Mono");
	s = fido.getMessage();
	CHECK( strcmp(s,s2) == 0 );
	fido.print();

	fido.setMessage( 0);
	s = fido.getMessage();
	CHECK( strcmp(s,s3) == 0 );
	fido.print();

}

TEST( sort_strings, StringTests)
{
	char *s1 = "everclear cider beer daiquiri bacardi";
	char *s2 = "pug beagle chihuahua akita doberman";
	char *s3 = "blue azul rojo red green verde blanco white negro black";

	char *a1 = "bacardi beer cider daiquiri everclear";
	char *a2 = "akita beagle chihuahua doberman pug";
	char *a3 = "azul black blanco blue green negro red rojo verde white";

	char *r1 = new char[ strlen(s1) + 1 ];
	char *r2 = new char[ strlen(s2) + 1 ];
	char *r3 = new char[ strlen(s3) + 1 ];
	
	char *t1 = new char[strlen(s1) + 2];
	t1[strlen(s1) + 1] = 0xE;
	char *t2 = new char[strlen(s2) + 2];
	t2[strlen(s2) + 1] = 0xE;
	char *t3 = new char[strlen(s3) + 2];
	t3[strlen(s3) + 1] = 0xE;
	
	ReorderAlphabetical( s1, r1 );
	CHECK( strcmp( r1, a1 ) == 0 );

	// concatenation overrun check
	ReorderAlphabetical(s1, t1);
	CHECK(strcmp(t1, a1) == 0);
	CHECK(t1[strlen(s1) + 1] == 0xE);

	//printf("\n");
	//printf("orig: %s  len:%d \n",s1);
   // printf(" new: %s  len:%d \n",r1);

	ReorderAlphabetical( s2, r2 );
	CHECK( strcmp( r2, a2 ) == 0 );

	// concatenation overrun check
	ReorderAlphabetical(s2, t2);
	CHECK(strcmp(t2, a2) == 0);
	CHECK(t2[strlen(s2) + 1] == 0xE);

	//printf("\n");
	//printf("orig: %s\n",s2);
	//printf(" new: %s\n",r2);

	ReorderAlphabetical( s3, r3 );
	CHECK( strcmp( r3, a3 ) == 0 );

	// concatenation overrun check
	ReorderAlphabetical(s3, t3);
	CHECK(strcmp(t3, a3) == 0);
	CHECK(t3[strlen(s3) + 1] == 0xE);

	//printf("\n");
	//printf("orig: %s\n",s3);
	//printf(" new: %s\n",r3);

}

TEST( sort_strings_wordlength, StringTests)
{
	char *s1 = "everclear cider beer daiquiri bacardi";
	char *s2 = "pug beagle chihuahua akita doberman";
	char *s3 = "blue azul rojo red green verde blanco white negro black";

	char *a1 = "beer cider bacardi daiquiri everclear";
	char *a2 = "pug akita beagle doberman chihuahua";
	char *a3 = "red azul blue rojo black green negro verde white blanco";

	char *r1 = new char[ strlen(s1) + 1 ];
	char *r2 = new char[ strlen(s2) + 1 ];
	char *r3 = new char[ strlen(s3) + 1 ];
	
	char *t1 = new char[strlen(s1) + 2];
	t1[strlen(s1) + 1] = 0xE;
	char *t2 = new char[strlen(s2) + 2];
	t2[strlen(s2) + 1] = 0xE;
	char *t3 = new char[strlen(s3) + 2];
	t3[strlen(s3) + 1] = 0xE;

	ReorderWordLength( s1, r1 );
	
	CHECK( strcmp( r1, a1 ) == 0 );

	// concatenation overrun check
	ReorderWordLength(s1, t1);
	CHECK(strcmp(t1, a1) == 0);
	CHECK(t1[strlen(s1) + 1] == 0xE);

	//printf("\n");
	//printf("orig: %s  len:%d \n",s1);
    //printf(" new: %s  len:%d \n",r1);
	
	ReorderWordLength( s2, r2 );
	CHECK( strcmp( r2, a2 ) == 0 );

	// concatenation overrun check
	ReorderWordLength(s2, t2);
	CHECK(strcmp(t2, a2) == 0);
	CHECK(t2[strlen(s2) + 1] == 0xE);

	//printf("\n");
	//printf("orig: %s\n",s2);
	//printf(" new: %s\n",r2);

	ReorderWordLength( s3, r3 );
	CHECK( strcmp( r3, a3 ) == 0 );

	// concatenation overrun check
	ReorderWordLength(s3, t3);
	CHECK(strcmp(t3, a3) == 0);
	CHECK(t3[strlen(s3) + 1] == 0xE);

	//printf("\n");
	//printf("orig: %s\n",s3);
	//printf(" new: %s\n",r3);

}