#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define Pi 3.1429
double Box_Muller1(double,double);
double Box_Muller2(double,double);
double Central_f(double,double,double,double);

main()
{
	FILE *fp;
	fp=fopen("practical_38.dat","w");
	randomize();
	rand();
	int i,j,k,n;
	int a11,a12,a21,a22;
	double b11,b12,b21,b22,r,r1;
	double x[20],y[20],chi1[20],chi2[20],sum1,sum2,n1,n2;
	printf("Enter the desired sample size:\t");
	scanf("%d",&n);
	printf("Enter the df n1:\t");
	scanf("%lf",&n1);
	printf("Enter the df n2:\t");
	scanf("%lf",&n2);
	for(i=1;i<=n;i++)
	{
		chi1[i]=0;chi2[i]=0;
		r=0;	r1=0;
		a11=(rand()%90+1);a12=(rand()%90+1);
		b11=a11/(double)(RAND_MAX%1000+10);
		b12=a12/(double)(RAND_MAX%1000+10);
		r=b11*b11+b12*b12;
		if(r!=0 && r<=1)
		{
			for(j=1;j<=n1;j++)
			{
				x[j]=Box_Muller1(b11,b12);
				chi1[i]=chi1[i]+(x[j]*x[j]);
			}
		}


		a21=(rand()%90+1);a22=(rand()%90+1);
		b21=a21/(double)(RAND_MAX%1000+10);
		b22=a22/(double)(RAND_MAX%1000+10);
		r1=b21*b21+b22*b22;
		if(r1!=0 && r1<=1)
		{
			for(k=1;k<=n2;k++)
			{

				y[k]=Box_Muller2(b21,b22);
				chi2[i]=chi2[i]+(y[k]*y[k]);
			}
		}
	}
	printf("The random sample from central F(%.0lf,%.0lf):\t\n",n1,n2);
	fprintf(fp,"The random sample from central F(%.0lf,%.0lf):\t\n",n1,n2);
	printf("The Size:\t%d\n",n);
	fprintf(fp,"The Size:\t%d\n",n);
	for(i=1;i<=n;i++)
	{
		printf("%d)\t%.5lf\n",i,Central_f(chi1[i],chi2[i],n1,n2));
		fprintf(fp,"%d)\t%.5lf\n",i,Central_f(chi1[i],chi2[i],n1,n2));
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
double Central_f(double x1,double x2,double m1,double m2)
{
	double func3=(m2/m1)*(x1/x2);
	return(func3);
}
