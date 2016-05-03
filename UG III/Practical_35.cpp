#include<stdlib.h>
#include<stdio.h>
#include<math.h>
double F_exp(double,double);
main()
{
   FILE *fp;
	fp=fopen("practical_35.dat","w");
	randomize();
	rand();
	int i,n;
	int a11;
	double m,x[20];
	printf("Enter the desired sample size:\t");
	scanf("%d",&n);
	printf("\nEnter the mean of the exponential distribution:\t");
	scanf("%lf",&m);
	printf("\n\nThe desired random sample from the Exp(%.3lf) distribution:\n",m);
	fprintf(fp,"\n\nThe desired random sample from the Exp(%.3lf) distribution:\n",m);
	printf("The Size:\t%d\n",n);
	fprintf(fp,"The Size:\t%d\n",n);
	for(i=1;i<=n;i++)
	{
			a11=(rand()%9+1);/*a12=(rand()%9+1);*/
			x[i]=a11/(double)(RAND_MAX%100+1);
			/*y[i]=a12/(double)(RAND_MAX%100+1);*/
	}
	for(i=1;i<=n;i++)
	{
		printf("%d)\t%.5lf\n",i,(F_exp(m,x[i])*100));
		fprintf(fp,"%d)\t%.5lf\n",i,(F_exp(m,x[i])*100));
	}
   fclose(fp);
	return 0;
}
double F_exp(double m1,double x1)
{
	double func=(-1*m1*log(1-x1));
	return(func);
}


