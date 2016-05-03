#include<stdio.h>
#include<math.h>

float func(float y);
float trap(float a,float b,int n);

main()
{

  FILE *fp;
  fp=fopen("practical_17.dat","w");
  int n=2;
  float a=0,b=1,intg1=1,intg2=2;
  while(fabs(intg1-intg2)>0.001)
  {
		intg1=trap(a,b,n);
		intg2=trap(a,b,n+1);
		n=n+1;
  }
  printf("No of iterations is %d\n",n/2-1);
  fprintf(fp,"No. of iterations is %d\n",n/2-1);
  printf("The integral =\t%.4f\n",intg2);
  fprintf(fp,"The integral =\t%.4f\n",intg2);
  fclose(fp);
}
float trap(float a,float b,int n)
{
	int i;
	float h,x[10],sum=0;
	h=(b-a)/n;
	for(i=1;i<=n-1;i++)
	{
		x[i]=a+i*h;
	}
	sum=(func(a)+func(b));
	for(i=1;i<=n-1;i++)
	{
		sum=sum+2*func(x[i]);
	}
	sum=(h/2.0)*sum;
	return sum;
}
float func(float y)
{
	float c;
	c=exp(y)*sin(y);
	return c;
}



