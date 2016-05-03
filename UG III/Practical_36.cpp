#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define Pi 3.1429
double Box_Muller1(double,double);
double Box_Muller2(double,double);
double Central_T(double,double);


main()
{
	FILE *fp;
	fp=fopen("practical_36.dat","w");
	randomize();
	rand();
	int i,j,n;
	int a11,a12;
	double b11,b12,b21,b22;
	double m,s,x[20],y[20],chi[10],r=0,sum;
	printf("Enter the desired sample size:\t");
	scanf("%d",&n);
	printf("\nThe mean:\t");
	scanf("%lf",&m);
	printf("\nThe standard deviation:\t");
	scanf("%lf",&s);
	printf("\n\nThe desired random sample from N(%.2lf,%.2lf):\t\n",m,s);
	fprintf(fp,"\n\nThe desired random sample from N(%.2lf,%.2lf):\t\n",m,s);
	printf("The Size:\t%d\n",n);
	fprintf(fp,"The Size:\t%d\n",n);
	for(i=1;i<=n;i++)
	{

			sum=0;
			a11=(rand()%90+1);a12=(rand()%90+1);
			b11=a11/(double)(RAND_MAX%1000+1);
			b12=a12/(double)(RAND_MAX%1000+1);
			b21=a11/(double)(RAND_MAX%1000+1);
			b22=a12/(double)(RAND_MAX%1000+1);
			r=b11*b11+b12*b12;
			if(r!=0 && r<=1)
			{
				x[i]=Box_Muller1(b11,b12);
				for(j=1;j<=5;j++)
				{
					y[j]=Box_Muller2(b21,b22);
					sum=sum+(y[j]*y[j]);

				}
			}
			chi[i]=sum;
	}
	for(i=1;i<=n;i++)
	{
		printf("%d)\t%.5lf\n",i,(x[i]*s)+m);
		fprintf(fp,"%d)\t%.5lf\n",i,(x[i]*s)+m);
	}
	int n1;
	printf("\n\nEnter the desired sample size from t-dist with 5.df:\t");
	scanf("%d",&n1);
	printf("\n\nThe desired random sample from the central-t distribution:\t\n");
	fprintf(fp,"\n\nThe desired random sample from central-t distribution:\t\n");
	printf("The Size:\t%d\n",n1);
	fprintf(fp,"The Size:\t%d\n",n1);
	for(i=1;i<=n1;i++)
	{
		printf("%d)\t%.5lf\n",i,Central_T(x[i],chi[i]));
		fprintf(fp,"%d)\t%.5lf\n",i,Central_T(x[i],chi[i]));
	}
   fclose(fp);
	return 0;
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
double Central_T(double x1,double y1)
{
	double func3=x1/pow((y1/5.0),0.5);
	return(func3);
}


