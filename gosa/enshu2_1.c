#include<stdio.h>

int main(void)
{
	int a=2147483647;
	unsigned int b=4294967295;

	printf("%d\n",a);
	a++;
	printf("%d\n",a);
	a--;
	printf("%d\n",a);

	printf("%u\n",b);
	b++;
	printf("%u\n",b);
	b--;
	printf("%u\n",b);

	return 0;
}