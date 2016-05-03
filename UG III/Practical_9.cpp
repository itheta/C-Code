#include<stdio.h>
#include<math.h>

main ()
{
	/* INPUTTING THE DATA SET */

	int n,i,j;
	double x[30],y[30],z[30],e[30],a,b,sum1,ssq1,sum2,ssq2,avg1,var1,sd1,avg2,var2,sd2,cov,r;
	printf("Enter n:\n");
	scanf("%d",&n);
	printf("Enter the %d ordered pairs: \n",n);
	for(i=0;i<n;i++)
	{
		scanf("%lf %lf",&x[i],&y[i]);
	}

/* CALCULATION OF PREDICTED VALUES, RESIDUALS AND CORRELATION INDEX */

	sum1=0,ssq1=0,sum2=0,ssq2=0,cov=0;
	for(i=0;i<n;i++)
	{
		sum1=sum1+x[i];
		ssq1=ssq1+pow(x[i],2);
		sum2=sum2+y[i];
		ssq2=ssq2+pow(y[i],2);
		a=a+x[i]*y[i]/n;
	}
	avg1=sum1/n;
	var1=ssq1/n-pow(avg1,2);
	sd1=pow(var1,.5);
	avg2=sum2/n;
	var2=ssq2/n-pow(avg2,2);
	sd2=pow(var2,.5);
	r=(a-avg1*avg2)/(sd1*sd2);
	b=r*sd2/sd1;
	for(i=0;i<n;i++)
	{
		z[i]=avg2+b*(x[i]-avg1);
		e[i]=y[i]-z[i];
	}



/* WRITING THE OUTPUT IN A FILE */

	FILE *fp;
	fp=fopen("practical_9.dat","w");
	fprintf(fp,"\n\nThe regression equation of y on x is given by:\n Y = %lf + %lf*(x-%lf)",avg2,b,avg1);
	fprintf(fp,"\n\nThe observed values are:\n");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"(%lf,%lf) \n",x[i],y[i]);
	}
	fprintf(fp,"\n\nThe predicted values are:\n");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%lf \n",z[i]);
	}
	fprintf(fp,"\n\nThe residuals are:\n");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%lf \n",e[i]);
	}
	fprintf(fp,"\n\nThe correlation index of order 1 is %lf",r);
	fclose(fp);
}

