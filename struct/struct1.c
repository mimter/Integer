#include<stdio.h>

struct curry
{
	char name[50];
	int karasa;
	int ryou;
};

int main(void)
{
	struct curry a;
	struct curry b[3];

	sprintf(a.name,"jawwa curry");
	a.karasa = 3;
	a.ryou = 150;

	sprintf(b[0].name,"barmont curry");
	b[0].karasa = 2;
	b[0].ryou = 200;


	sprintf(b[1].name,"hapifami curry");
	b[1].karasa = 1;
	b[1].ryou = 100;

	sprintf(b[2].name,"boso curry");
	b[2].karasa = 5;
	b[2].ryou = 300;

	printf("a.name = %s\n",a.name);
	printf("a.karasa = %d\n",a.karasa);
	printf("a.ryou = %d\n",a.ryou);

	printf("b[0].name = %s\n",b[0].name);
	printf("b[0].karasa = %d\n",b[0].karasa);
	printf("b[0].ryou = %d\n",b[0].ryou);

	printf("b[1].name = %s\n",b[1].name);
	printf("b[1].karasa = %d\n",b[1].karasa);
	printf("b[1].ryou = %d\n",b[1].ryou);

	printf("b[2].name = %s\n",b[2].name);
	printf("b[2].karasa = %d\n",b[2].karasa);
	printf("b[2].ryou = %d\n",b[2].ryou);
	return 0;

}