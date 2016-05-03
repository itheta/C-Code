#include<stdio.h>
#include<math.h>
double factorial(double);
double poisson(double,int);

main()
{
	FILE *fp;
	fp=fopen("practical_19.dat","w");
	int i,n;
	double sum=0,mean,n1=0,sum1=0,of[10],f[10],x[10];
	printf("Enter the number of classes with non zero frequencies(<20):\t");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the %d class:\t",i);
		scanf("%lf",&x[i]);
		printf("Enter the frequency of %d class:\t",i);
		scanf("%lf",&f[i]);
	}
	for(i=1;i<=n;i++)
	{
		sum=sum+(x[i]*f[i]);
		n1=n1+f[i];
	}
	mean=(sum/n1);
	printf("The parameter of the Poisson Distribution is:\t%.4lf\n",mean);
	fprintf(fp,"The parameter of the Poisson Distribution is:\t%.4lf\n",mean);
	for(i=1;i<=n-1;i++)
	{
		of[i]=n1*poisson(mean,x[i]);
		sum1=sum1+poisson(mean,x[i]);
	}
	of[n]=n1*(1-sum1);
	printf("\nClass\t\tObserved Frequency\t\tExpected Frequency\n");
	fprintf(fp,"\nClass\t\tObserved Frequency\t\tExpected Frequency\n");
	for(i=1;i<=n;i++)
	{
		printf("%.0lf\t\t\t%.0lf\t\t\t%.0lf\t\n",x[i],f[i],of[i]);
		fprintf(fp,"%.0lf\t\t\t%.0lf\t\t\t%.0lf\t\n",x[i],f[i],of[i]);
	}
   fclose(fp);
}
double factorial(double n)
{
	if(n==1||n==0)
	return 1;
	else
	return n*factorial(n-1);

}
double poisson(double p,int x)
{
	double func;
	func=(exp(-p)*pow(p,x))/factorial(x);
	return func;
}





