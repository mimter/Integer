#include<stdio.h>
#include<math.h>

int factrial(int num)
{
	if(num==0||num==1)
		return 1;
	else
		return factrial(num)*factrial(num-1);
}

int main(void)
{
	double t;
	double sum=0;
	int n;
	double a;
	double b;
	double x=1;
	t=0.017452406;
	int loop=1;

	printf("sin1=%25.10f\n",t);

	printf("%d\n",factrial(3));

	while(1)
	{
		a=factrial(loop*2+1);
		b=pow(x,loop*2+1);
		sum+=a*b*pow(-1,loop);

		if(loop==1||loop==2||loop==3)
		{
			printf("%d項 %25.10f,",loop,sum);
			printf("誤差　%25.10f\n",t-sum);
		}
		loop++;

		if(loop==1000)
			break;
	}
	return 0;
}