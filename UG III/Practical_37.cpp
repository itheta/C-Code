#include<stdlib.h>
#include<math.h>
#include<stdio.h>

#define Pi 3.1429

double Box_Muller1(double,double);
double Box_Muller2(double,double);

main()
{
	FILE *fp;
	fp=fopen("practical_37.dat","w");
	randomize();
	rand();
	int i,j,n,d;
	int a11,a12;
	double b11,b12,x[20],y[20],sum,chi[20],r=0;
	printf("Enter the desired sample size from central chi-sq. dist.:\t");
	scanf("%d",&n);
	printf("Enter the d.f of the central chi-sq. dist.:\t");
	scanf("%d",&d);
	for(i=1;i<=n;i++)
	{
			sum=0;
			a11=(rand()%90+1);a12=(rand()%90+1);
			b11=a11/(double)(RAND_MAX%1000+1);
			b12=a12/(double)(RAND_MAX%1000+1);
			r=b11*b11+b12*b12;
			if(r!=0 && r<=1)
			{
				x[i]=Box_Muller1(b11,b12);
				for(j=1;j<=d;j++)
				{
					y[j]=Box_Muller2(b11,b12);
					sum=sum+(y[j]*y[j]);

				}
			}
			chi[i]=sum;
	}
	printf("\n\nThe desired random sample from chi-square with %d df:\n",d);
	fprintf(fp,"\n\nThe desired random sample from chi-square with %d df:\n",d);
	printf("The Size:\t%d\n",n);
	fprintf(fp,"The Size:\t%d\n",n);
	for(i=1;i<=n;i++)
	{
		printf("%d)\t%0.5lf\n",i,chi[i]);
		fprintf(fp,"%d)\t%0.5lf\n",i,chi[i]);
	}
   fclose(fp);
}

double Box_Muller1(double u1,double u2)
{
	double func1=pow((-2*log(u1)),0.5)*cos(2*Pi*u2);
	return(func1);
}

double Box_Muller2(double u3,double u4)
{
	double func2=pow((-2*log(u3)),0.5)*sin(2*Pi*u4);
	return(func2);
}

