#include<stdio.h>
#include<math.h>
main()
{
	int i,r;
	double a[7],sum,avg,ssq,var,sd,b,mom;
	printf("Enter the 7 integers \n");
	i=0,sum=0,ssq=0,b=0;
	for(i=0;i<7;i++)
	{
		scanf("%lf",&a[i]);
		sum=sum+a[i];
		ssq=ssq+pow(a[i],2);
	}
	printf("Enter the order of the moment \n");
	scanf("%d",&r);
	avg=sum/7;
	var=ssq/7-pow(avg,2);
	sd=pow(var,.5);
	for(i=0;i<7;i++)
	{
	b=b+pow((a[i]-avg),r);
	}
	mom=b/7;
	printf("The average of the numbers is %lf \n",avg);
	printf("The variance of the numbers is %lf \n",var);
	printf("The standard deviation of the numbers is %lf \n",sd);
	printf("The %dth order central moment of the numbers is %lf \n",r,mom);
}
