#include<stdio.h>
#include<math.h>
/*Prototype Declaration*/
float simp(float a, float b,int n);
float func(float y);

/*Iteration*/
main()
{
	FILE *fp;
	fp=fopen("d:\\Programs\\practical_7.dat","w");
	int n=2;
	float a=0,b=1,intg1=1,intg2=2;
	while(fabs(intg1-intg2)>0.001)
	{
		intg1=simp(a,b,n);
		intg2=simp(a,b,n+2);
		n=n+2;
	}
	printf("The number of iterations= %d\n",(n/2)-1);
	fprintf(fp,"The number of iterations= %d\n",(n/2)-1);
	printf("The integral is=\t%.4f\n",intg2);
	fprintf(fp,"The integral is=\t%.4f\n",intg2);
   fclose(fp);
}
/*Simpson's rule*/
float simp(float a,float b, int n)
{
	int i;
	float h,x[20],sum=0;
	h=(b-a)/n;
	for(i=1;i<=n-1;i++)
	{
		x[i]=a+i*h;
	}
	sum=sum+func(a)+func(b);
	for(i=1;i<=n-1;i=i+2)
	{
		sum=sum+4*func(x[i]);
	}
	for(i=2;i<=n-2;i=i+2)
	{
		sum=sum+2*func(x[i]);
	}
	sum=(h/3.0)*sum;
	return sum;
}
/*Function Declaration*/
float func(float y)
{
	float c;
	c=exp(y*tan(y));
	return c;
}





