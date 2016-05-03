#include<stdio.h>
#include<math.h>
double func1(double);
double func2(double,double);
double iteration(double,double);


main()
{
   FILE *fp;
	fp=fopen("practical_30.dat","w");
	double x_0,y_0,x_sol,y_sol;
	printf("Enter the initial approximation of x:\t");
	scanf("%lf",&x_0);
	printf("Enter the initial approximation of y:\t");
	scanf("%lf",&y_0);
	x_sol=iteration(y_0,x_0);
	y_sol=func1(x_sol);
printf("\nThe desired solution of the system is:\t%.4lf\t%.4lf",x_sol,y_sol);
fprintf(fp,"\nThe desired solution of the system is:\t%.4lf\t%.4lf",x_sol,y_sol);
   fclose(fp);
	return 0;
}
double func1(double x1)
{
	double func1=1.32+sin(x1);     /*y=func1*/
	return(func1);
}
double func2(double y1,double x1)
{
 double func2=2.17+sin(x1)+cos(y1)-y1;     /*x=func2*/
 return(func2);
}

double iteration(double x2,double y2)
{
	int n=1;
	double a1,a2,t;
	a1=func2(y2,x2);         /*x_app=a1*/
	a2=func1(a1);		 		/*y_app=a2*/
	t=func2(a2,a1);
	while(fabs(t-a1)>0.0001)
	{
		a1=func2(a2,a1);
		a2=func1(a1);
		t=func2(a2,a1);
		n=n+1;
	}
	printf("The number of iterations:\t%d",n);
	return(a1);
}


