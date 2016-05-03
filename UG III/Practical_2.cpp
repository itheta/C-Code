#include<stdio.h>
#include<math.h>
main ()
{
/* INPUTTING THE DATA SET */

	int i,j,n;
	double a[10],b[10],c,sum1,ssq1,sum2,ssq2,avg1,avg2,var1,sd1,var2,sd2,r;
	printf("Enter n:\n");
	scanf("%d",&n);
	printf("Enter the %d ordered pairs of numbers \n",n);
	for(i=0;i<n;i++)
	{
	scanf("%lf",&a[i]);
	scanf("%lf",&b[i]);
	}

/* CALCULATION OF COEFFICIENT OF CORRELATION */

	sum1=0,ssq1=0,sum2=0,ssq2=0,c=0;
	for(i=0;i<n;i++)
	{
		sum1=sum1+a[i];
		ssq1=ssq1+pow(a[i],2);
		sum2=sum2+b[i];
		ssq2=ssq2+pow(b[i],2);
		c=c+a[i]*b[i]/n;
	}
	avg1=sum1/n;
	var1=ssq1/n-pow(avg1,2);
	sd1=pow(var1,.5);
	avg2=sum2/n;
	var2=ssq2/n-pow(avg2,2);
	sd2=pow(var2,.5);
	r=(c-avg1*avg2)/(sd1*sd2);
	printf("The coefficient of correlation for the given data set is %lf",r);

/* WRITING THE OUTPUT IN A FILE */

	FILE *fp;
	fp=fopen("practical_2","w");
	fprintf(fp,"The coefficient of correlation for the given data set is %lf",r);
	fclose(fp);
}
