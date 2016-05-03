#include<stdio.h>
#include<math.h>

main()
{
   FILE *fp;
	fp=fopen("practical_31.dat","w");
	int i;
	double n,sum1=0,sum2=0,sum3=0,sum4=0,sum_1=0,mean_x,mean_y;
	double x[20],y[20],x_1[20];
	double a,b;
	printf("Enter the number of paired values provided(<20):\t");
	scanf("%lf",&n);
	printf("Enter the values:\t");
	for(i=1;i<=n;i++)
	{
		printf("\nEnter x[%d]:\t",i);
		scanf("%lf",&x[i]);
		printf("\nEnter y[%d]:\t",i);
		scanf("%lf",&y[i]);
	}
	for(i=1;i<=n;i++)
	{
		sum1=sum1+x[i];
		sum3=sum3+y[i];
	}
	mean_x=sum1/n;
	for(i=1;i<=n;i++)
	{
		x_1[i]=(x[i]-mean_x);
	}
	for(i=1;i<=n;i++)
	{
		sum2=sum2+pow(x_1[i],2);
		sum4=sum4+(x_1[i]*y[i]);
	}
	mean_y=sum3/n;
	b=sum4/sum2;
	a=(mean_y)-b*mean_x;
	printf("The fitted staright line is:\tY\t=\t%.4lf\t+\t%.4lf*X\t\n",a,b);
	fprintf(fp,"The fitted staright line is:\tY\t=\t%.4lf\t+\t%.4lf*X\t\n",a,b);
	double e[20],y_p[20],sum5=0;
	for(i=1;i<=n;i++)
	{
		y_p[i]=a+(b*x[i]);
		e[i]=y[i]-y_p[i];
		sum5=sum5+y_p[i];
	}
	double mean_y_p=sum5/n;
	double ssq1=0,ssq2=0;
	for(i=1;i<=n;i++)
	{
		ssq1=ssq1+pow(y_p[i],2);
		ssq2=ssq2+pow(y[i],2);
	}
	double var1=ssq1/n-pow(mean_y_p,2);
	double var2=ssq2/n-pow(mean_y,2);
	double t,ci_1;
	t=var1/var2;
	ci_1=pow(t,0.5);
	printf("X\t\tY\t\tY_p\t\tResiduals\t\n");
	fprintf(fp,"X\t\tY\t\tY_p\t\tResiduals\t\n");
	for(i=1;i<=n;i++)
	{
		printf("%.2lf\t\t%.2lf\t\t%.4lf\t\t%.4lf\t\n",x[i],y[i],y_p[i],e[i]);
		fprintf(fp,"%.2lf\t\t%.2lf\t\t%.4lf\t\t%.4lf\t\n",x[i],y[i],y_p[i],e[i]);
	}
	printf("The correlation index is:\t%.4lf",ci_1);
	fprintf(fp,"The correlation index is:\t%.4lf",ci_1);
   fclose(fp);
}







