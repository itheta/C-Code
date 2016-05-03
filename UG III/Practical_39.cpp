#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Pi 3.1429
double Box_Muller1(double,double);
double Box_Muller2(double,double);
double Cauchy(double,double,double,double);

main()
{
   FILE *fp;
	fp=fopen("practical_39.dat","w");
	randomize();
	rand();
	int i,n,a11,a12,a21,a22;
	double b11,b12,b21,b22,x[20],y[20],c[20],m,s,r,r1;
	printf("Enter the sample size desired:\t");
	scanf("%d",&n);
	printf("Enter the location parameter of the Cauchy distribution:\t");
	scanf("%lf",&m);
	printf("Enter the scale parameter of the Cauchy distribution:\t");
	scanf("%lf",&s);
	printf("\n\nThe desired random sample from the C(%.1lf,%.1lf)-Dist:\t\n",m,s);
	fprintf(fp,"\n\nThe desired random sample from the C(%.1lf,%.1lf)-Dist:\t\n",m,s);
	printf("The Size:\t%d\n",n);
	fprintf(fp,"The Size:\t%d\n",n);
	for(i=1;i<=n;i++)
	{
		r=0;r1=0;
		a11=(rand()%90+1);a12=(rand()%90+1);
		a21=(rand()%90+1);a22=(rand()%90+1);
		b11=a11/(double)(RAND_MAX%1000+10);
		b12=a12/(double)(RAND_MAX%1000+10);
		b21=a21/(double)(RAND_MAX%1000+10);
		b22=a22/(double)(RAND_MAX%1000+10);
		r=b11*b11+b12*b12;
		if(r!=0 && r<=1)
		{
			x[i]=Box_Muller1(b11,b12);
		}
		r1=b21*b21+b22*b22;
		if(r1!=0 && r<=1)
		{
			y[i]=Box_Muller2(b21,b22);
		}
		c[i]=Cauchy(x[i],y[i],m,s);
		printf("%d)\t%.5lf\n",i,c[i]);
      fprintf(fp,"%d)\t%.5lf\n",i,c[i]);
	}
   fclose(fp);
	return 0;
}
double Box_Muller1(double u1,double u2)
{
	double func1=pow((-2*log(u1)),0.5)*cos(2*Pi*(u2));
	return (func1);
}
double Box_Muller2(double u3,double u4)
{
	double func2=pow((-2*log(u3)),0.5)*sin(2*Pi*(u4));
	return (func2);
}
double Cauchy(double x1,double y1, double m,double s)
{
	double func3=((x1/y1)*s)+m;
   return(func3);
}





