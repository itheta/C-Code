#include<stdio.h>
#include<math.h>
main()
{
   FILE *fp;
	fp=fopen("practical_32.dat","w");
	int i,j;
	double n,x[20],y[20],y_p[20];
	printf("Enter the number of observation:\t");
	scanf("%lf",&n);
	printf("Enter the values:\n");
	for(i=1;i<=n;i++)
	{
		printf("Enter the values of x[%d]:\t",i);
		scanf("%lf",&x[i]);
		printf("Enter the values of y[%d]:\t",i);
		scanf("%lf",&y[i]);
	}
	double sum1=0,sum2=0,sum3=0,sum4=0;
	for(i=1;i<=n;i++)
	{
		sum1=sum1+x[i];
		sum2=sum2+log(y[i]);
	}
	double mean_x=sum1/n;
	double mean_y=sum2/n;
	double x_1[20],ssq1=0,ssp=0,a,b;
	for(i=1;i<=n;i++)
	{
		x_1[i]=(x[i]-mean_x);
		ssq1=ssq1+pow(x_1[i],2);
		ssp=ssp+(x_1[i]*log(y[i]));
	}
	b=(ssp/ssq1);
	a=mean_y;
printf("The fitted linear trend is:Y\t=%.4lf\t+(%.4lf)*(t-%.0lf)",a,b,mean_x);
fprintf(fp,"The fitted linear trend is:Y\t=%.4lf\t+(%.4lf)*(t-%.0lf)",a,b,mean_x);
	for(i=1;i<=n;i++)
	{
		y_p[i]=a+b*x_1[i];
	}
	printf("\nX\t\tY\t\tY_p\t\n");
	fprintf(fp,"\nX\t\tY\t\tY_p\t\n");
	for(i=1;i<=n;i++)
	{
		printf("%.4lf\t%.4lf \t%.4lf\t\n",x[i],y[i],exp(y_p[i])) ;
      fprintf(fp,"%.4lf\t%.4lf \t%.4lf\t\n",x[i],y[i],exp(y_p[i])) ;
	}
   fclose(fp);
}






