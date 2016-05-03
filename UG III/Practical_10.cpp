#include<stdio.h>
#include<math.h>

main ()
{
	/* INPUTTING THE DATA SET */

	int n,i,j;
	double x[30],y[30],z[30],t[30],e[30],a,b,A,B,c,sum,avg,sum1,ssq1,sum2,ssq2,avg1,var1,sd1,avg2,var2,sd2,r;
	printf("Enter n:\n");
	scanf("%d",&n);
	printf("Enter the %d ordered pairs: \n",n);
	for(i=0;i<n;i++)
	{
		scanf("%lf %lf",&t[i],&y[i]);
	}

/* FITTING OF EXPONENTIAL TREND & CALCULATION OF PREDICTED VALUES */

	sum=0;
	for(i=0;i<n;i++)
	{
		z[i]=log(y[i]);
		sum=sum+t[i];
	}
	avg=sum/n;
   for(i=0;i<n;i++)
	{
		x[i]=t[i]-avg;
	}
	sum1=0,ssq1=0,sum2=0,ssq2=0,c=0;
	for(i=0;i<n;i++)
	{
		sum1=sum1+x[i];
		ssq1=ssq1+pow(x[i],2);
		sum2=sum2+z[i];
		ssq2=ssq2+pow(z[i],2);
		c=c+x[i]*z[i]/n;
	}
	avg1=sum1/n;
	var1=ssq1/n-pow(avg1,2);
	sd1=pow(var1,.5);
	avg2=sum2/n;
	var2=ssq2/n-pow(avg2,2);
	sd2=pow(var2,.5);
	r=(c-avg1*avg2)/(sd1*sd2);
	B=r*sd2/sd1;
	A=avg2-avg1*B;
	a=exp(A);
	b=exp(B);
	for(i=0;i<n;i++)
	{
		e[i]=a*pow(b,x[i]);
	}
	printf("%lf %lf",a,b);



/* WRITING THE OUTPUT IN A FILE */

	FILE *fp;
	fp=fopen("Practical_10.dat","w");
	fprintf(fp,"The exponential trend equation is given by:\n T = %lf*(%lf^t)",a,b);
	fprintf(fp,"\n\nCensus Year(t) \t Obeserved Population (in crores) \t Fitted Population (in crores):\n");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%lf \t \t %lf \t \t \t %lf\n",t[i],y[i],e[i]);
	}
	fclose(fp);
}
