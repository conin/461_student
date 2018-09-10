// Test structures and classes for Alignment Problem
// Enjoy
// - Ed Keenan

#include <string.h>
#include<stdio.h>

// Refactor the "Rework" class/ data structures
// You can add constructors and methods to any class / data strudtor
// In the "Rework" class/data structures 
//         - you can also rearrange the order of variable declarations


struct Test_A
{
	char r;		
	char g;		
	char b;

	Test_A()
	{
		r = 0x00;
		g = 0x00;
		b = 0x00;
	}

	void print() 
	{
		Trace::out("\n\n\nSize of Test_A %d ", sizeof(Test_A));
		Trace::out("\nTest_A");

		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n Address    Values");
		int ind = 0;
		for (int i = 0; i < sizeof(Test_A); i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				if (*iterator == '0xaa')
					ind++;

				Trace::out("%02x ", *iterator);				
				iterator++;
			}
		}
		Trace::out("\n");

		Trace::out("padded bits %d",1);
	}
};



struct Test_A_Rework
{
	char r;
	char g;
	char b;

	Test_A_Rework()
	{
		r = 0x00;
		g = 0x00;
		b = 0x00;
	}
	void print() 
	{
		Trace::out("\n\n\nSize of Test_A_ReWork %d ", sizeof(Test_A_Rework));
		Trace::out("\n Test_A_ReWork");

		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n Address    Values");
		int ind = 0;
		for (int i = 0; i < sizeof(Test_A_Rework); i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				Trace::out("%02x ", *iterator);
				if (*iterator == '0xaa')
					ind++;

				iterator++;
			}
		}
		Trace::out("\n");
		Trace::out("padded bits %d", 1);
	}
};

struct Test_B
{
	int   x;		
	int   y;

	Test_B()
	{
		x = 0x00000000;
		y = 0x00000000;
	}

	void print() 
	{
		Trace::out("\n \n\nSize of Test_B %d ", sizeof(Test_B));
		Trace::out("\n Test_B");

		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n Address    Values");
		int ind = 0;
		for (int i = 0; i <= sizeof(Test_B); i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				Trace::out("%02x ", *iterator);
				if (*iterator == '0xaa')
					ind++;

				iterator++;
			}
		}
		Trace::out("\n");
		Trace::out("padded bits %d", 0);
	}
};

struct Test_B_Rework
{
	int   x;
	int   y;
	
	Test_B_Rework()
	{
		x = 0x00000000;
		y = 0x00000000;
	}

	void print()
	{
		Trace::out("\n \n\nSize of Test_B_Rework %d ", sizeof(Test_B_Rework));
		Trace::out("\n Test_B_Rework");
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n Address    Values");
		int ind = 0;
		for (int i = 0; i <= sizeof(Test_B_Rework); i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				Trace::out("%02x ", *iterator);
				iterator++;

				if (*iterator == '0xaa')
					ind++;
			}
		}
		Trace::out("\n");
		Trace::out("padded bits %d", 0);
	}
};

class Test_C
{
	public:

	Test_C()
	{
		x = 0x00000000;
		b = 0x00;
	}

	void set() 
	{
		x = 0x00000000;
		b = 0x00;
		pad1 = 0x00;
		pad2 = 0x00;
		pad3 = 0x00;
	}

	void print()
	{
		Trace::out("\n\n\nSize of TestC %d", sizeof(Test_C));
		Trace::out("\n Address       Values");

		unsigned char *iterator = (unsigned char*)this;
		int ind = 0;

		for (int i = 0; i <= sizeof(Test_C); i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				Trace::out("%02x ", *iterator);
				iterator++;

				if (*iterator == '0xaa')
					ind++;
			}
		}
		Trace::out("\n");

		Trace::out("padded bits %d", 3);
	}

private:
	int   x;	 
	char  b;
	char pad1;
	char pad2;
	char pad3;
};

class Test_C_Rework
{
	public:
	void set()
	{
		x = 0x31415161;
		b = 0x51;
		pad1 = 0x00;
		pad3 = 0x00;
		pad2 = 0x00;
	}

	void print()
	{
		Trace::out("\n\n\nSize of Test_C_Rework %d", sizeof(Test_C_Rework));
		Trace::out("\n Address       Values");		
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n Address    Values");
		int ind = 0;

		for (int i = 0; i <= sizeof(Test_C_Rework); i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				Trace::out("%02x ", *iterator);
				if (ind == '0xaa')
					ind++;
				iterator++;
			}
		}
		Trace::out("\n");
		Trace::out("padded bits %d", 3);
	}

private:

	int   x;
	char  b;
	char pad1;
	char pad2;
	char pad3;
};

class Test_D
{
public:
	void set()
	{
		x = 0x36465666;
		c = 0x35;
		b = 0x36;
		pad1 = 0x11;
		pad2 = 0x11;
		pad3 = 0x11;
		pad4 = 0x11;
		pad5 = 0x11;
		pad6 = 0x11;		
	}

	void print() 
	{
		Trace::out("\n size of Test_D %d ", sizeof(Test_D));
		Trace::out("\n Test_D ");
		Trace::out("\n Address       Values");
		unsigned char *iterator = (unsigned char*)this;
		int size = sizeof(Test_D);
		int ind = 0;
		for (int i = 0; i < size; i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				if (*iterator == '0xaa')
					ind++;

				Trace::out("%02x ", *iterator);
				iterator++;
			}
		}
		Trace::out("\n");

		Trace::out("padded bits %d", 6);
	}

private:
	char  c;
	char pad1;
	char pad2;
	char pad3;
	int   x;	 
	char  b;
	char pad4;
	char pad5;
	char pad6;

};

class Test_D_Rework
{
public:
	void set()
	{
		x = 0x36465666;
		c = 0x35;
		b = 0x35;
		pad1 = 0x35;
		pad2 = 0x35;
	}

	void print()
	{
		Trace::out("\n size of Test_D_Rework %d ", sizeof(Test_D_Rework));
		Trace::out("\n Address       Values");
		unsigned char *iterator = (unsigned char*)this;
		int size = sizeof(Test_D_Rework);
		int ind = 0;

		for (int i = 0; i < size ; i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				if (*iterator == '0xaa')
					ind++;

				Trace::out("%02x ", *iterator);
				iterator++;
			}
		}
		Trace::out("\n");

		Trace::out("padded bits %d", 2);
	}

private:
	int   x;
	char  c;	
	char  b;
	char pad1;
	char pad2;
};


struct Test_E
{
	void  *p;  
	char  a;
	char pad1;
	char pad2;
	char pad3;
	float x; 
	char  b;
	char pad7;
	char pad8;
	char pad9;
	int   y;       
	char  c;
	char pad4;
	char pad5;
	char pad6;

	void print()
	{
		Trace::out("\n size of Test_E %d ", sizeof(Test_E));
		Trace::out("\n Test_E");
		unsigned char *iterator = (unsigned char*)this;
		int size = sizeof(Test_E);
		int ind = 0;

		for (int i = 0; i < size; i = i + 4)
		{
			{
				Trace::out("\n0X%x:", iterator);
				for (int j = 0; j < 4; j++)
				{
					if (*iterator == '0xaa')
						ind++;

					Trace::out("%02x ", *iterator);
					iterator++;
				}
			}
			Trace::out("\n");

		}
		Trace::out("padded bits %d", 9);
	}
};

struct Test_E_Rework
{
	void  *p;
	float x;
	int   y;
	char  a;
	char  b;
	char  c;
	char pad1;

	void print()
	{
		Trace::out("\n size of Test_E_Rework %d ", sizeof(Test_E_Rework));
		Trace::out("\n Test_E_Rework");
		Trace::out("\n Address       Values");
		unsigned char *iterator = (unsigned char*)this;
		int size = sizeof(Test_E_Rework);
		int ind = 0;

		for (int i = 0; i < size ; i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				if (*iterator == '0xaa')
					ind++;

				Trace::out("%02x ", *iterator);
				iterator++;
			}
		}
		Trace::out("\n");

		Trace::out("padded bits %d", 1);
	}
};

struct Test_F
{
	char   a; 
	char pad1; char pad2; char pad3; char pad4; char pad6; char pad7; char pad8;
	double t; 
	float  s;
	char pad12; char pad11; char pad10; char pad9;
	
	void set()
	{
	
		this->t = 0x00118922;
		this->a = 0x00;
		this->pad1 = 0x11;
		this->pad2 = 0x11;
		this->pad3 = 0x11;
		this->pad4 = 0x11;
		this->pad7 = 0x11;
		this->pad6 = 0x11;
		this->pad8 = 0x11;
		this->pad9 = 0x11;
		this->pad11 = 0x11;
		this->pad10 = 0x11;
		this->pad12 = 0x11;

	}
	void print() 
	{
		Trace::out("\n size of Test_F %d ", sizeof(Test_F));
		Trace::out("\n Test_F ");
		Trace::out("\n Address       Values");
		unsigned char *iterator = (unsigned char*)this;
		int size = sizeof(Test_F);
		int ind = 0;

		for (int i = 0; i < size; i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				if (*iterator == '0xaa')
					ind++;

				Trace::out("%02x ", *iterator);
				iterator++;
			}
		}
		Trace::out("\n");

		Trace::out("padded bits %d", 11);		Trace::out("\n");
	}
};

struct Test_F_Rework
{
	double t;
	float  s;
	char   a;
	char pad1;
	char pad2;
	char pad3;

	void set()
	{
	}

	void print()
	{
		Trace::out("\n size of Test_F_Rework %d ", sizeof(Test_F_Rework));
		Trace::out("\n Test_F_Rework ");
		Trace::out("\n Address       Values");

		unsigned char *iterator = (unsigned char*)this;
		int size = sizeof(Test_F_Rework);
		int ind = 0;
		for (int i = 0; i < size; i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				if (*iterator == '0xaa')
					ind++;

				Trace::out("%02x ", *iterator);
				iterator++;
			}
		}
		Trace::out("\n");

		Trace::out("padded bits %d", 3);
	}
};

struct Vect
{
	float vx;
	float vy;
	char  d;
	char pad1;
	char pad2;
	char pad3;
	float vz;
	float vw;
	char  e;
	char pad4;
	char pad5;
	char pad6;

	void set()
	{
		
	}

	void print()
	{
	    Trace::out("\n size of Vect %d ", sizeof(Vect));
		Trace::out("\n Vect");
		Trace::out("\n Address       Values");
		unsigned char *iterator = (unsigned char*)this;
		int size = sizeof(Vect);
		int ind = 0;

		for (int i = 0; i < size; i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				if (*iterator == '0xaa')
					ind++;

				Trace::out("%02x ", *iterator);
				iterator++;
			}
		}
		Trace::out("\n");

		Trace::out("padded bits %d", 6);

	}
};

struct Vect_Rework
{
	float vx;
	float vy;
	float vz;
	float vw;
	char  d;
	char  e;
	char  pad1;
	char  pad2;

	void set()
	{
		this->vx = 0x000000000;
		this->vy = 0x000000000;
		this->vz = 0x000000000;
		this->vw = 0x000000000;
		this->d = 0x00;
		this->e = 0x00;
		this->pad1 = 0x00;
		this->pad2 = 0x00;
	}

	void print()
	{
		Trace::out("\n size of Vect_Rework %d", sizeof(Vect_Rework));
		Trace::out("\n Vect_Rework");
		Trace::out("\n Address       Values");
		unsigned char *iterator = (unsigned char*)this;
		int size = sizeof(Vect_Rework);
		int ind = 0;
		for (int i = 0; i < size; i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				if (*iterator == '0xaa')
					ind++;

				Trace::out("%02x ", *iterator);
				iterator++;
			}
		}
		Trace::out("\n");

		Trace::out("padded bits %d", 2);
	}

};

struct Test_H
{
	int		a;
	Vect	v1;
	int		b;
	char	c;
	char pad8; 
	char pad9;
	char pad10;

	void set()
	{
		this->a = 0x00;
		this->b = 0x00;
		this->c = 0x00;
		this->pad8 = 0x01;
		this->pad9 = 0x01;
		this->pad10 = 0x01;
	}

	void print()
	{
		Trace::out("\n size of Test_H %d", sizeof(Test_H));
		Trace::out("\n Test_H");
		Trace::out("\n Address       Values");
		unsigned char *iterator = (unsigned char*)this;
		int size = sizeof(Test_H);
		int ind = 0;
		for (int i = 0; i < size; i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				if (*iterator == '0xaa')
					ind++;

				Trace::out("%02x ", *iterator);
				iterator++;
			}
		}
		Trace::out("\n");

		Trace::out("padded bits %d", 3);
	}
};

struct Test_H_Rework
{
	int			a;
	int			b;
	Vect_Rework	v1;
	char		c;
	char		pad11;
	char		pad12;
	char		pad13;

	void print()
	{
		Trace::out("\n size of Test_H_Rework %d", sizeof(Test_H_Rework));
		Trace::out("\n Test_H_Rework");
		Trace::out("\n Address       Values");
		unsigned char *iterator = (unsigned char*)this;
		int size = sizeof(Test_H_Rework);
		int ind = 0;
		for (int i = 0; i < size; i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				if (*iterator == '0xaa')
					ind++;

				Trace::out("%02x ", *iterator);
				iterator++;
			}
		}
		Trace::out("\n");

		Trace::out("padded bits %d", 5);
	}

};

class Test_I
{
public:
	void print()
	{
		Trace::out("\n size of Test_I %d", sizeof(Test_I));
		Trace::out("\n Test_I");
		Trace::out("\n Address       Values");
		unsigned char *iterator = (unsigned char*)this;
		int size = sizeof(Test_I);
		int ind = 0;

		for (int i = 0; i < size; i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				if (*iterator == '0xaa')
					ind++;

				Trace::out("%02x ", *iterator);
				iterator++;
			}
		}
		Trace::out("\n");

		Trace::out("padded bits %d", 4);
	}

	void set()
	{
		this->pad = 0x00;
		this->pad1 = 0x00;
		this->pad2 = 0x00;
		this->pad3 = 0x00;
		this->x = 0x66666666;
		this->z = 0x000000000;
	}
private:
	char	name[63];
	char pad3;
	int		x;
	char	z;
	char pad; char pad1; char pad2;
	int		*p;
};

class Test_I_Rework
{
public:
	void set()
	{
		this->x=0x00112200;
		this->z=0x00;
	}

	void print()
	{
		Trace::out("\n size of Test_I_Rework %d",sizeof(Test_I_Rework));
		Trace::out("\n Test_I_Rework");
		Trace::out("\n Address       Values");
		
		unsigned char *iterator = (unsigned char*)this;
		int size = sizeof(Test_I_Rework);
		int ind = 0;
		for (int i = 0; i < size; i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				if (*iterator == '0xaa')
					ind++;

				Trace::out("%02x ", *iterator);
				iterator++;
			}
		}
		Trace::out("\n");

		Trace::out("padded bits %d", 0);
	}

private:
	int		x;
	int		*p;
	char	name[63];
	char	z;
};

struct Test_J
{
	char	name[122];
	char p1, p2, p3, p4, p5, p6;
	int	x;
	char	z;
	char p7, p8, p9;
	double	d;
	int	*p;
	char	c;
	char pad6, pad7, pad8;
	float	y;
	char pad9, pad10, pad11, pad12;

public:
	void set()
	{
		memset(name, 0X00, 122);
		x = 0x00;
		z = 0x00;
		d = 0x00;
		p = 0x00;
		c = 0x00;
		y = 0x00;

	}

	void Print()
	{

		int padding = 0;

		unsigned char *iterator = (unsigned char*)this;

		for (int i = 0; i < sizeof(Test_J); i = i + 4)
		{

			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				Trace::out("%02x ", *iterator);
				if (*iterator == 0xAA)
				{
					padding = padding + 1;
				}
				iterator++;

			}
		}
		Trace::out("Size of Test_J is %d  ", sizeof(Test_J));
		Trace::out("Padding is %d\n", padding);
	}
};



struct Test_J_Rework
{
	double	d;
	int	*p;
	int	x;
	//char pad1, pad2;
	float	y;
	char	z;
	char	c;
	char	name[122];
	//char pad3, pad4;
public:
	void set()
	{
		memset(name, 0X00, 122);
		x = 0x00;
		z = 0x00;
		d = 0x00;
		p = 0x00;
		c = 0x00;
		y = 0x00;

	}

	void Print()
	{

		int padding = 0;

		unsigned char *iterator = (unsigned char*)this;

		for (int i = 0; i < sizeof(Test_J_Rework); i = i + 4)
		{

			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				Trace::out("%02x ", *iterator);
				if (*iterator == 0xAA)
				{
					padding = padding + 1;
				}
				iterator++;

			}
		}
		Trace::out("Size of Test_J_Rework is %d  ", sizeof(Test_J_Rework));
		Trace::out("Padding is %d\n", padding);
	}
};