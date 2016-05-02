#include<stdio.h>
#include<math.h>
//simpsons 1/3 rule
main()
{
	int i;
	double x[20],f[20],sum=0,h=0.05,s;
	for(i=0;i<=20;i++)
	{
		x[i]=i*h;
		f[i]=exp(x[i]*tan(x[i]));
	}
	sum=sum+f[0]+f[20];
	for(i=1;i<20;i=i+2)
	{
		sum=sum+4*f[i];
	}
	for(i=2;i<=18;i=i+2)
	{
		sum=sum+2*f[i];
	}
	s=sum*h/3;
	printf("The value of the integral of exp(x*tan(x)) over the range (0,1) is %lf",s);
}

