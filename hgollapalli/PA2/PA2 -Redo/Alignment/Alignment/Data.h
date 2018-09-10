// Test structures and classes for Alignment Problem
// Enjoy
// - Ed Keenan

#include <string.h>

struct Test_A
{
	char r;		
	char g;		
	char b;
	char pad1;
	 

	Test_A()
	{
		r = 0x00;
		g = 0x00;
		b = 0x00;
	}

	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_A is %d	", sizeof(Test_A));
		for (int i = 0; i < sizeof(Test_A); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
	}
};

struct Test_A_Rework
{
	char r;
	char g;
	char b;
	char pad1;


	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_A_Rework is %d	", sizeof(Test_A_Rework));
		for (int i = 0; i < sizeof(Test_A_Rework); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
	}
};

struct Test_B
{
	int   x;
	int   y;
	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_B is %d	", sizeof(Test_B));
		for (int i = 0; i < sizeof(Test_B); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
	}

};

struct Test_B_Rework
{
	int   x;
	int   y;

	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_B_Rework is %d	", sizeof(Test_B_Rework));
		for (int i = 0; i < sizeof(Test_B_Rework); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
	}

};

class Test_C
{
public:
	void set()
	{
		x = 0x00;
		b = 0x00;
	}

	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_C is %d	", sizeof(Test_C));
		for (int i = 0; i < sizeof(Test_C); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
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
		x = 0x00;
		b = 0x00;
	}

	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_C_Rework is %d	", sizeof(Test_C_Rework));
		for (int i = 0; i < sizeof(Test_C_Rework); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
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
		c = 0x00;
		x = 0x00;
		b = 0x00;
	}

	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_D is %d	", sizeof(Test_D));
		for (int i = 0; i < sizeof(Test_D); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
	}

private:
	char  c;
	char p1, p2, p3;
	int   x;
	char  b;
	char pad1;
	char pad2, pad3;
};

class Test_D_Rework
{
public:
	void set()
	{
		c = 0x00;
		x = 0x00;
		b = 0x00;
	}

	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_D_Rework is %d	", sizeof(Test_D_Rework));
		for (int i = 0; i < sizeof(Test_D_Rework); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
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
	char pad1, pad2, pad3;
	float x;
	char  b, pad4, pad5, pad6;
	int   y;
	char  c;
	char pad7, pad8, pad9;

	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_E is %d	", sizeof(Test_E));
		for (int i = 0; i < sizeof(Test_E); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
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
	char pad;

	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_E_Rework is %d	", sizeof(Test_E_Rework));
		for (int i = 0; i < sizeof(Test_E_Rework); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
	}

};

struct Test_F
{
	char   a;
	char pad1;
	char pad2;
	char pad3;
	char pad4;
	char pad5;
	char pad6;
	char pad7;
	double t;
	float  s;
	int pad8;

	void set()
	{
		this->t = 0x00;
		this->a = 0x00;
		this->s = 0x00;
	}
	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_F is %d	", sizeof(Test_F));
		for (int i = 0; i < sizeof(Test_F); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
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
		this->t = 0x00;
		this->a = 0x00;
		this->s = 0x00;
	}
	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_F_Rework is %d	", sizeof(Test_F_Rework));
		for (int i = 0; i < sizeof(Test_F_Rework); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
	}

};

struct Vect
{

public:

	Vect()
	{
		vx = vy =  vz = vw = e = 0x00;
		d = 0x00;
	}
	void set()
	{
		vx= vy= vz= vw=e = 0x00;
		d = 0x00;
	}

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

	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Vect is %d	", sizeof(Vect));
		for (int i = 0; i < sizeof(Vect); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
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
	char pad1;
	char pad2;

	void set()
	{
		vx = vy = vz = vw = e = 0x00;
		d = 0x00;
	}

	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Vect_Rework is %d	", sizeof(Vect_Rework));
		for (int i = 0; i < sizeof(Vect_Rework); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
	}

};

struct Test_H
{
	int		a;
	int pad1;
	double pad2, pad3;
	Vect	v1;
	int		b;
	char	c;
	char pad4, pad5, pad6;
	double pad7, pad8;


	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_H is %d	", sizeof(Test_H));
		for (int i = 0; i < sizeof(Test_H); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
	}

};

struct Test_H_Rework
{
	Vect_Rework	v1;
	int			a;
	int			b;
	char		c;
	char pad1;
	char pad2;
	char pad3;
	double pad4;


	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_H_Rework is %d	", sizeof(Test_H_Rework));
		for (int i = 0; i < sizeof(Test_H_Rework); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
	}

};

class Test_I
{
public:
	void set()
	{
		memset(name, 0X00, 63);
		x = z = 0X00;
		p = 0x00;
	}

	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_I is %d	", sizeof(Test_I));
		for (int i = 0; i < sizeof(Test_I); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
	}

private:
	char	name[63];
	char pad1;
	int		x;
	char	z;
	char pad4, pad2, pad3;
	int		*p;

};

class Test_I_Rework
{
private:

	int		*p;
	int		x;
	char	name[63];
	char	z;

public:
	void set()
	{
		memset(name, 0X00, 63);
		x = z = 0X00;
		p = 0x00;
	}

	void Print()
	{
		int padding = 0;
		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_I_Rework is %d	", sizeof(Test_I_Rework));
		for (int i = 0; i < sizeof(Test_I_Rework); i = i + 4)
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
	}

};

struct Test_J
{
	char	name[122];
	char p1, p2, p3, p4, p5, p6;
	int		x;
	char	z;
	char p7, p8, p9;
	double	d;
	int		*p;
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
		Trace::out("\n--------------------------\n");
		Trace::out("\nSize of Test_J is %d	", sizeof(Test_J));
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
		Trace::out("\nPadding is %d\n", padding);
		Trace::out("\n--------------------------\n");
	}
};

struct Test_J_Rework
{
	double	d;
	int		*p;
	int		x;
	float	y;
	char	z;
	char	c;
	char	name[122];
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
		Trace::out("\n\n\nSize of Test_J_Rework %d ", sizeof(Test_J_Rework));
		Trace::out("\nTest_J_Rework");

		unsigned char *iterator = (unsigned char*)this;
		Trace::out("\n Address    Values");
		int ind = 0;
		for (int i = 0; i < sizeof(Test_A); i = i + 4)
		{
			Trace::out("\n0X%x:", iterator);
			for (int j = 0; j < 4; j++)
			{
				if (*iterator == '0xAA')
					ind++;

				Trace::out("%02x ", *iterator);
				iterator++;
			}
		}
		Trace::out("\n");

		Trace::out("padded bits %d", 1);
	}

};