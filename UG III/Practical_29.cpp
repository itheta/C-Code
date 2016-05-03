#include<stdio.h>
#include<math.h>
/* FUNCTION PROTOTYPE DECLARATION*/
double func(double);
double iteration(double);

main()
{
	FILE *fp;
	fp=fopen("practical_29.dat","w");

	double x,y;
	printf("Enter the fair approximation of the root:\t");
	scanf("%lf",&x);
	if(fabs((0.5/log(10))*pow(x,-1))<1) 	/*CONVERGENCE CRITERIA*/
	{
		y=func(x);
		printf("\nThe approximated value of the root is:\t %0.4lf",iteration(y));
	fprintf(fp,"\nThe approximated value of the root is:\t %0.4lf",iteration(y));
	}
	else
	printf("\nThe root entered does not satisfy the convergence criteria");
	fprintf(fp,"\nThe root entered does not satisfy the convergence criteria");
   fclose(fp);
}
/*FUNCTION PROVIDED*/
double func(double n)
{
	double func=(0.5*((log(n)/log(10))+7));
	return(func);
}
/*ITERATION PROCEDURE WITH COUNT*/
double iteration(double y1)
{
	int i=1;
	double a1,a2;
	a1=func(y1);
	a2=func(a1);
	while(fabs(a1-a2)>0.0001)
	{
			a1=a2;
			a2=func(a1);
			i=i+1;

	}
	printf("\nThe number of iterations:\t%d",i);
	return(a2);
}
/*
CHECKING THE VALUE OF LOG IN C++
	double t;
	t=exp(1);
	printf("%lf",log(t));
}*/







