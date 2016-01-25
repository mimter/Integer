#include<stdio.h>

int main(void)
{
	double a = 1.23456e10;
	double b = 7.89012e-3;
	double c = 7.89012e2;
	double d,e;

	d = a+b;
	e = a+c;

	printf("a   = %25.10f\n",a);
	printf("b   = %25.10f\n",b);
	printf("c   = %25.10f\n",c);
	printf("a+b = %25.10f\n",d);
	printf("a+c = %25.10f\n",e);

	return 0;
}