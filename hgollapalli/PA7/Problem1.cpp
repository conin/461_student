#include<stdio.h>

void ComputeEquation(float x,float &y, float a0, float a1, float a2, float a3, float a4, float a5)
{
	y = a0 + a1*x + a2*x*x + a3*x*x*x + a4*x*x*x*x + a5*x*x*x*x*x;
}

int main()
{
	float x, y;
	x = 2;

	ComputeEquation(x, y,1,1,1,1,1,1);
	printf(" \n y = %f",y);
}