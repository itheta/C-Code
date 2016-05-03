#include<stdio.h>
#include<math.h>
double fact(double);
double truncbin(double,double,double);
double iteration(double,double);
double comb(double,double);
double func(double,double,double);


main()
{
	FILE *fp;
	fp=fopen("practical_16.dat","w");
	int i,n;
	double sum=0,sum1=0,mean,x[20],f[20],of[20],n_f=0,p;
	printf("Enter the number of non zero classes of frequencies(<20):\t");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the %d class value:\t",i);
		scanf("%lf",&x[i]);
		printf("Enter the frequency:\t");
		scanf("%lf",&f[i]);
	}
	for(i=1;i<=n;i++)
	{
		sum=sum+(x[i]*f[i]);
		n_f=n_f+f[i];
	}
	mean=sum/n_f;
	p=iteration(n,mean);
	printf("The parameter of the truncated binomaial is:\t%.4lf",p);
	fprintf(fp,"The parameter of the truncated binomaial is:\t%.4lf",p);
	for(i=1;i<=n-1;i++)
	{
		of[i]=n_f*truncbin(n,p,x[i]);
		sum1=sum1+truncbin(n,p,x[i]);
	}
	of[n]=n_f*(1-sum1);
	printf("\nClass\t\tObserved Frequency\t\tExpected frequency\t\n");
	fprintf(fp,"\nClass\t\tObserved Frequency\t\tExpected frequency\t\n");
	for(i=1;i<=n;i++)
	{
		printf("%.0lf\t\t%.0lf\t\t\t\t%.0lf\t\n",x[i],f[i],of[i]);
		fprintf(fp,"%.0lf\t\t%.0lf\t\t\t\t%.0lf\t\n",x[i],f[i],of[i]);
	}
   fclose(fp);
	return 0;
}
/*Iteration for fitting truncated binomial*/
double iteration(double n1, double m)
{
	double a1,a2,y=0.5;
	if((m*pow(y,6))<1)
	a1=func(y,n1,m);
	a2=func(a1,n1,m);
	int i=1;
	while(fabs(a1-a2)>0.0000001)
	{
		a1=func(a2,n1,m);
		a2=func(a1,n1,m);
		i=i+1;
	}
	printf("\nThe number of iterations for value of p:\t%d\n",i);
	return(a2);
}
double func(double y1,double n2,double m1)
{
	double func;
	func=m1*(1-pow((1-y1),n2))/n2;
	return(func);
}

/*Factorial Function*/

double fact(double y2)
{
	if(y2==0||y2==1)
	return 1;
	else
	return y2*fact(y2-1);
}

/*combinatorial function(n"choose" p)*/

double comb(double n2,double x1)
{
	double func1;
	func1=fact(n2)/(fact(x1)*fact(n2-x1));
	return(func1);
}

/*Truncated Binomial pdf*/

double truncbin(double n3,double p1,double x2)
{
	double func2,q1=(1-p1);
	func2=(comb(n3,x2)*pow(p1,x2)*pow(q1,(n3-x2)))/(1-pow(q1,n3));
	return(func2);
}







