#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
#define KETA 20
#define CUL 3   //ループの回数 10^CUL回

struct NUMBER
{
	int n[KETA];
	int sign;
};


void clearByZero(); //0初期化
void dispNumber(); //表示
void dispNumberZeroSupress();
void setRand(); //ランダム初期化
void copyNumber(); //コピー
void getAbs();  //絶対値
int isZero(); //ゼロかどうか
int mulBy10(); //10かける
int divBy10(); //10で割る
void swap(); //入れ替え
void sort();
void setSign(); //符号を決める
int getSign(); //符号を読み取る
int numComp(); //大小比較
void setInt(); //多倍長配列に入れる
void getInt();
int add(); //足すc=a+b
int sub(); //引くc=a-b
int simpleMultiple(); //かける 
int multiple();
int divide();
int increment();
int power();
int isPrime();
double logy();
void naturallog();
void naturallog2();
int mulByN();
int gcd();

void A();


int main(void)
{
	srandom(time(NULL));

	struct NUMBER a,b,c,d,e,f,g;
	int r;
	int x=0,y=0,z=0;
	int i,flag;
	double ln =2;

	clearByZero(&a);
	clearByZero(&b);
	clearByZero(&c);
	clearByZero(&d);

	

	/*setInt(&a,678);
	setInt(&b,39);
	quickdiv(&a,&b,&c,&d);
	printf("divide = ");
	dispNumber(&c);
	printf("...");
	dispNumber(&d);
	putchar('\n');
	*/
	
	


	/*clearByZero(&a);
	clearByZero(&b);
	setInt(&a,1188);
	setInt(&b,8978);
	gcd(&a,&b,&c);
	printf("gcd = ");
	dispNumber(&c);
	putchar('\n'); 
	*/
	
	naturallog2(&a,&b);
	printf("ln2 = ");
	dispNumber(&b);
	putchar('\n');
	


/*
	while(1)
	{
		if(numComp(&b,&c) >=0)
			break;
		power(&e,&b,&f);
		divide(&c,&b,&d,&g);
		divide(&d,&f,&d,&g);
		add(&a,&d,&a);
		increment(&b);
	}

	printf("ln2 = ");
	dispNumber(&a);
	printf("\n");


	/*setInt(&a,83);
	printf("isPrime ");
	dispNumber(&a); 
	
	printf(" = %d\n",isPrime(&a));    */


	ln = logy(ln);
	printf("ln2 = %.10f",ln);
	putchar('\n');




	putchar('\n');

	
	return 0;
}

void clearByZero(struct NUMBER *a)
{
	int i;

	for(i=0;i<KETA;i++)
		a->n[i]=0;
	setSign(a,1);
}

void dispNumber(struct NUMBER *a)
{
	int i;
	if(getSign(a) == 1)
		printf(" + ");
	else if(getSign(a) == -1)
		printf(" - ");
	for(i=KETA-1;i>=0;i--)
		printf("%2d",a->n[i]);
}

void dispNumberZeroSupress(struct NUMBER *a)
{
	int i=KETA-1;
	if(getSign(a) == 1)
		printf(" + ");
	else if(getSign(a) == -1)
		printf(" - ");

	while(!a->n[i])
		i--;
	for(;i>=0;i--)
		printf("%2d",a->n[i]);
}

void setRand(struct NUMBER *a,int n)
{
	int i;
	
	if(n>KETA)
		printf("error\n");
	else
	{
		if(random()%2==1)
		{
			a->sign=1;
		}
		else if(random()%2==0)
		{
			a->sign=-1;
		}

		for(i=n-1;i>=0;i--)
		{
			a->n[i]=random()%10;
		}
	}
}

void copyNumber(struct NUMBER *a,struct NUMBER *b)
{
	int i;
	setSign(b,a->sign);
	for(i=KETA-1;i>=0;i--)
	{
		b->n[i]=a->n[i];
	}
}

void getAbs(struct NUMBER *a,struct NUMBER *b)
{
	copyNumber(a,b);
	setSign(b,1);
}

int isZero(struct NUMBER *a)
{
	int i,flag=0;
	for(i=0;i<KETA;i++)
	{
		if(a->n[i]!=0)
		{
			flag=-1;
			break;
		}
	}

	return flag;

}

int mulBy10(struct NUMBER *a,struct NUMBER*b)
{
	int i,flag=0;
	clearByZero(b);
	if(a->n[KETA-1]!=0)
		flag=-1;
	else
		for(i=KETA-1;i>0;i--)
		{
			b->n[i]=a->n[i-1];
		}

	return flag;
}



int divBy10(struct NUMBER *a,struct NUMBER *b)
{
	int i,flag=0;
	flag=a->n[0];
	clearByZero(b);

	for(i=0;i<KETA-1;i++)
		b->n[i]=a->n[i+1];
	return flag;

}

void swap(struct NUMBER *a,struct NUMBER *b)
{
	struct NUMBER temp;
	copyNumber(a,&temp);
	copyNumber(b,a);
	copyNumber(&temp,b);

}

/*void sort(struct NUMBER *a)
{
	int i,j;
	for(i=0;i<10;i++)
		for(j=i;j<10;j++)
			if(a->n[i]>a->n[i+1])
				swap

}*/


void setSign(struct NUMBER *p,int s)
{
	if(s==1)
		p->sign=1;
	if(s==-1)
		p->sign=-1;
}

int getSign(struct NUMBER *a)
{
	if(a->sign==1)
		return 1;
	else if(a->sign==-1)
		return -1;
}

int numComp(struct NUMBER *a,struct NUMBER *b)
{
	int i;
	if(getSign(a)>getSign(b))
		return 1;
	else if(getSign(a)<getSign(b))
		return -1;
	else
	{
		if(getSign(a)==1)
		{
			for(i=KETA-1;i>=0;i--)
			{
				if(a->n[i] > b->n[i])
				{
					return 1;
					break;
				}
				if(a->n[i] < b->n[i])
				{
					return -1;
					break;
				}
			}
			return 0;
		}
		else if(getSign(a)==-1)
		{
			for(i=KETA-1;i>=0;i--)
			{
				if(a->n[i] > b->n[i])
				{
					return -1;
					break;
				}
				if(a->n[i] < b->n[i])
				{
					return 1;
					break;
				}
			}
			return 0;
		}
		else
			return 0;
	}
}

void setInt(struct NUMBER *a,int x)
{
	int i;
	clearByZero(a);
	if(x<0)
	{
		setSign(a,-1);
		x=x*(-1);
	}
	else if(x>0)
		setSign(a,1);
	else
		setSign(a,0);

	for(i=0;i<KETA;i++)
	{
		a->n[i]=x%10;
		x=x/10;
		if(x<1)
			break;
	}
}

void getInt(struct NUMBER *a,int *x)
{
	int i;
	for(i=0;i<KETA;i++)
	{
		*x += a->n[i] * (int)pow(10,i);
	}

}

int add(struct NUMBER *a,struct NUMBER *b, struct NUMBER *c)
{
	int i,e=0,d=0;
	int flag=0;
	struct NUMBER temp,temp2;
	clearByZero(&temp);
	clearByZero(&temp2);
	clearByZero(c);

	if(getSign(a)==1)
	{
		if(getSign(b)==1)
		{
			for(i=0;i<KETA;i++)
			{
				d=a->n[i]+b->n[i]+e;
				if(i==KETA-1 && d>=10)
				{
					printf("OverFlow\n");
					clearByZero(c);
					flag=1;
					break;
				}
				c->n[i]=d%10;
				e=d/10;	
			}
		}
		else if(getSign(b)==-1)
		{
			getAbs(b,&temp);
			sub(a,&temp,c);
		}
	}
	else
	{
		if(getSign(b)==1){
			getAbs(a,&temp);
			sub(b,&temp,c);
		}
		else if(getSign(b)==-1)
		{
			getAbs(a,&temp);
			getAbs(b,&temp2);
			add(&temp,&temp2,c);
			setSign(c,-1);
		}
	}

	return flag;
}

int sub(struct NUMBER *a,struct NUMBER *b,struct NUMBER *c)
{
	int i,h=0,d=0;
	struct NUMBER temp;
	clearByZero(&temp);
	clearByZero(c);
	if(getSign(a)==1)
	{
		if(getSign(b)==1)
		{
			for(i=0;i<KETA;i++)
			{
				if(numComp(a,b)==1)
				{
					d=a->n[i]-b->n[i]-h;
					h=0;
					if(d<0)
					{
						d+=10;
						h=1;
					}
					c->n[i]=d;
				}
				else
				{
					getAbs(b,&temp);
					sub(&temp,a,c);
					setSign(c,-1);
				}

			}
		}
		else if(getSign(b)==-1)
		{
			getAbs(b,&temp);
			add(a,&temp,c);
		}
	}
	else if(getSign(a)==-1)
	{
		if(getSign(b)==1)
		{
			getAbs(a,&temp);
			add(b,&temp,c);
			setSign(c,-1);
		}
		else if(getSign(b)==-1)
		{
			getAbs(b,&temp);
			add(&temp,a,c);
		}
	}

	return 0;
}


int simpleMultiple(int a,int b,int *c)
{
	int i;
	for(i=0;i<b;i++)
		c+=a;
}


int multiple(struct NUMBER *a,struct NUMBER *b,struct NUMBER *c)
{
	int i,j,h=0,tempb,tempa,e;
	struct NUMBER d,mai1,mai2,temp;
	clearByZero(&d);
	clearByZero(c);
	if(getSign(a)==1)
	{
		if(getSign(b)==1)
		{
			for(i=0;i<KETA-1;i++)
			{
				h=0;
				clearByZero(&d);
				
				tempb=b->n[i];
				for(j=0;j<KETA;j++)
				{
					tempa=a->n[j];
					e=tempa*tempb + h;
					if(j+i<KETA)
						d.n[j+i]=e%10;
					h=e/10;
				}
				copyNumber(c,&temp);
				add(&temp,&d,c);
			}
		}
		else if(getSign(b)==-1)
		{
			getAbs(b,&mai1);
			multiple(a,&mai1,c);
			setSign(c,-1);
		}
	}
	else if(getSign(a)==-1)
	{
		if(getSign(b)==1)
		{
			getAbs(a,&mai1);
			multiple(b,&mai1,c);
			setSign(c,-1);
		}
		else if(getSign(b)==-1)
		{
			getAbs(a,&mai1);
			getAbs(b,&mai2);
			multiple(&mai1,&mai2,c);
		}
	}
}

int increment(struct NUMBER *a,struct NUMBER *b)
{
	int i;
	struct NUMBER one;
	clearByZero(b);
	clearByZero(&one);
	setInt(&one,1);
	i=add(a,&one,b);

	return i;
	
}

int decrement(struct NUMBER *a,struct NUMBER *b)
{
	int i;
	struct NUMBER one;
	clearByZero(b);
	clearByZero(&one);
	setInt(&one,1);
	i=sub(a,&one,b);

	return i;
	
}

int divide(struct NUMBER *a,struct NUMBER *b,
			struct NUMBER *c,struct NUMBER *d)
{
	int i,flag=1;
	struct NUMBER n,k,v,one;
	clearByZero(c);
	clearByZero(d);
	clearByZero(&one);
	setInt(&one,1);
	if(numComp(&one,b) == 0)
	{
		copyNumber(a,c);
		clearByZero(d);
		return 0;
	}
	if(isZero(b)==0)
		return -1;
	getAbs(a,&n);
	getAbs(b,&v);



	if(getSign(a) == -1)
	{
		if(getSign(b)==1)
		{
			flag = -1;
		}
	}

	if(getSign(b) == -1)
	{
		if(getSign(a) == 1)
		{
			flag = -1;
		}
	}

	if(getSign(a) == -1)
	{
		if(getSign(b)== -1)
		{
			flag = 0;
		}
	}



	while(1)
	{
		if(numComp(&n,&v)<=0)
			break;
		copyNumber(&n,&k);
		sub(&k,&v,&n);
		increment(c,&k);
		copyNumber(&k,c);
	}
	copyNumber(&n,d);

	if(flag == 1)
	{
		setSign(c,1);
		setSign(d,1);	
	}
	else if(flag == -1)
	{
		setSign(c,-1);
		setSign(d,-1);	
	}
	else if(flag == 0)
	{
		setSign(c,1);
		setSign(d,-1);
	}
	return 0;
}


int power(struct NUMBER *a,struct NUMBER *b,struct NUMBER *c)
{
	int i=0,l=0;
	struct NUMBER j,k,flag,tmp;
	clearByZero(&k);
	clearByZero(&flag);
	clearByZero(c);
	clearByZero(&j);
	clearByZero(&tmp);

	copyNumber(b,&flag);
	setInt(&j,1);
	while(1)
	{
		if(numComp(&flag,&k) <= 0)  
			break;
		multiple(&j,a,c);
		copyNumber(c,&j);
		increment(&k,&tmp);
		copyNumber(&tmp,&k);
	}

	return 0;

}

int isPrime(struct NUMBER *a)
{
	struct NUMBER b,c,d,e;
	int i=1,flag = 0 ;
	clearByZero(&b);
	clearByZero(&c);
	clearByZero(&d);
	while(1)
	{
		i++;
		setInt(&b,i);
		//if()
		if(numComp(a,&b)==-1)
		{
			flag =1;
			break;
		}

		divide(a,&b,&c,&d);
		if(isZero(&d)==1)
			break;

	}

	return flag;
}


double logy(double y)
{
	int i;
	double b=0.0;
	int n = 5;
	double x=(y-1)/(y+1);
	printf("%.4f\n",x);
	for(i=0;i<n;i++)
	{
		b = b + ( 2*pow(x,2*i+1)/(2*i+1) );
	}
	return b;
}


/*
void naturallog(struct NUMBER *a,struct NUMBER *b)
{
	int i;
	struct NUMBER count,d,e,f,g,x,y1,y2,two,temp;
	clearByZero(&count);
	clearByZero(&d);
	clearByZero(&e);
	clearByZero(&f);
	clearByZero(&g);
	clearByZero(&x);
	clearByZero(&y1);
	clearByZero(&y2);
	clearByZero(&two);
	clearByZero(&x);
	clearByZero(&temp);

	setInt(&two,2);

	y1.n[CUL-2] = 1;
	printf("y1 = ");
	dispNumber(&y1);
	putchar('\n');

	increment(&two,&y2);
	printf("y2 = ");
	dispNumber(&y2);
	putchar('\n');

	divide(&y1,&y2,&x,&d);

	printf("x = ");
	dispNumber(&x);
	putchar('\n');

	while(1)
	{
		if(count.n[CUL-1]!=0) break;
		multiple(&count,&two,&d);

		increment(&d,&e);

		power(&x,&e,&d);

		multiple(&d,&two,&f);
		divide(&e,&f,&g,&d);

		add(b,&g,b);
		increment(&count,&temp);
		copyNumber(&temp,&count);


	} 

}
*/



void naturallog(struct NUMBER *a,struct NUMBER *b)
{
	int i,sec = 0;
	struct NUMBER count,d,e,f,g,x,y1,y2,one,temp,flag,two,ans;
	clearByZero(&count);
	clearByZero(&d);
	clearByZero(&e);
	clearByZero(&f);
	clearByZero(&g);
	clearByZero(&x);
	clearByZero(&y1);
	clearByZero(&y2);
	clearByZero(&one);
	clearByZero(&two);
	clearByZero(&x);
	clearByZero(&temp);
	clearByZero(&flag);
	clearByZero(&ans);

	setInt(&two,2);

	flag.n[KETA-1] = 1; 
	one.n[KETA-2] = 1;
	
	while(1)
	{
		increment(&count,&temp);
		copyNumber(&temp,&count);
		

		if(numComp(&flag,&count) < 0) 
		{
			printf("break\n");
			break;
		}

		divide(&one,&count,&d,&e);
		

		if(count.n[0] % 2 == 0)
			setSign(&d,-1);


		add(&ans,&d,&e);
		copyNumber(&e,&ans);

	}

	copyNumber(&ans,b);

}

void naturallog2(struct NUMBER *a,struct NUMBER *b)
{
	struct NUMBER d,e,f,g,flag,two,count,tmp,ans,one;
	clearByZero(b);
	clearByZero(&d);
	clearByZero(&e);
	clearByZero(&f);
	clearByZero(&g);
	clearByZero(&two);
	clearByZero(&flag);
	clearByZero(&count);
	clearByZero(&tmp);
	clearByZero(&ans);
	clearByZero(&one);
	flag.n[1] = 1;
	one.n[2] = 1;
	setInt(&two,2);



	while(1)
	{
		increment(&count,&tmp);
		copyNumber(&tmp,&count);

		if(numComp(&flag,&count)<=0)
			break;
		power(&two,&count,&d);

		multiple(&d,&count,&e);

		quickdiv(&one,&e,&f,&g);
		printf("1/(n * 2^n) = ");
		dispNumber(&f);
		putchar('\n');

		add(&ans,&f,&g);
		copyNumber(&g,&ans);
		printf("ln2 = ");
		dispNumber(&ans);
		putchar('\n');
		putchar('\n');
	}

	copyNumber(&ans,b);
}

int quickdiv(struct  NUMBER *a,struct NUMBER *b,
				struct NUMBER *c,struct NUMBER *d)
{
	int i,count=0,pos1=0,pos2=0;
	struct NUMBER temp,a2,b2;
	clearByZero(&temp);
	clearByZero(c);
	clearByZero(d);
	clearByZero(&a2);
	clearByZero(&b2);

	copyNumber(a,&a2);
	copyNumber(b,&b2);

	printf("a =");
	dispNumber(a);
	putchar('\n');
	printf("b =");
	dispNumber(b);
	putchar('\n');

	if(isZero(b) == 0)
		return -1;

	for(count=0;numComp(&a2,&b2) == 1;count++) //それぞれの最上位桁を見つける
	{
		mulBy10(&b2,&temp);
		copyNumber(&temp,&b2);
	}


	printf("b2 = ");
	dispNumber(&b2);
	putchar('\n');

	for(i=0;i <= count ;i++)
	{
		mulBy10(c,&temp);
		copyNumber(&temp,c);

		printf("1\n");
		while(1)
		{
			if(numComp(&a2,&b2) ==-1 )
			{
				printf("break\n");
				printf("c = ");
				dispNumber(c);
				putchar('\n');

				printf("a2 = ");
				dispNumber(&a2);
				putchar('\n');
				break;

			}
			increment(c,&temp);
			copyNumber(&temp,c);
			sub(&a2,&b2,&temp);
			copyNumber(&temp,&a2);

			printf("c = ");
			dispNumber(c);
			putchar('\n');

			printf("a2 = ");
			dispNumber(&a2);
			putchar('\n');
		}
		divBy10(&b2,&temp);
		copyNumber(&temp,&b2);
		printf("3\n");
	}

	copyNumber(&a2,d);
	return 0;

/*	setInt(&one,1);
	copyNumber(a,&a2);

	if(isZero(a) == 0) //分子が0の時、商は0
		return 0;
	if(isZero(b) == 0) //分母が0エラー
		return -1;
	if(numComp(&one,b) == 0) //割る数が1のとき、商はa
	{
		copyNumber(a,c);
		return 0;
	}

	for(i=KETA-1;i>=0;i--) //それぞれの最上位桁を見つける
	{
		if(a->n[i]!=0)
			if(pos1!=0)
				pos1 =i;
		if(b->n[i]!=0)
			if(pos2!=0)
				pos2 =i;
		if(pos1 !=0 &&pos2 !=0)
			break;
	}

	if(pos1<pos2)   //割られる数<割る数 のとき商0,あまりa
	{
		copyNumber(a,d);
		return 0;
	}

	mulByN(b,&b2,pos1-pos2);		//桁をそろえる
	
	for(i=pos1-pos2;i<=0;i--)
	{
		if(numComp(&a2,&b2)>0)
		{
			copyNumber(&a2,&n);

			while(1)
			{
				copyNumber(&n,&a2);
				if(numComp(&a2,&b2)<0)
					break;
				sub(&a2,&b2,&n);
				increment(&e,&g);
				copyNumber(&g,&e);
			}
			copyNumber(&f,&a2);
			if(numComp(&a2,b) == -1)
				break;
			mulByN(&e,&tmp,i);
			add(&sum,&tmp,&e);
			copyNumber(&e,&sum);
		}
		divBy10(&b2,&f);
		copyNumber(&f,&b2);
	}

	copyNumber(&sum,c);
	copyNumber(&a2,d);
	return 0;

	*/
}

int mulByN(struct NUMBER *a,struct NUMBER*b,int n)
{
	int i,flag=0;
	clearByZero(b);
	if(a->n[KETA-n]!=0)
		flag=-1;
	else
		for(i=KETA-1;i>0;i--)
		{
			if(i-n >=0)
				b->n[i]=a->n[i-n];
			else
				b->n[i] = 0;
		}

	return flag;
}





/*
int gcd(struct NUMBER *a,struct NUMBER *b,struct NUMBER *c)
{
	struct NUMBER d,e,f,g;
	clearByZero(&d);
	clearByZero(&e);
	clearByZero(&f);
	copyNumber(a,&g);
	copyNumber(b,&d);
	while(1)
	{
		divide(&g,&d,&e,&f);
		printf(",g = ");
		dispNumber(&g);

		printf(",d = ");
		dispNumber(&d);

		printf(",e = ");
		dispNumber(&e);
		printf("    ,   f = ");
		dispNumber(&f);
		putchar('\n');
		copyNumber(&d,&g);
		copyNumber(&f,&d);
		if(isZero(&f) == 0)
		{
			printf("break\n");
			break;
		}
	}

	copyNumber(&d,c);

	return 0;

}

*/
