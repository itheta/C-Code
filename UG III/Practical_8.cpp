#include<stdio.h>
#include<math.h>
double factorial(double);
main ()
{
	int i,n;
	double k,x[50],f[50],a[50],e[50],sum1=0,sum2=0,sum3=0,b;
	printf("Enter the number of observations: \n");
	scanf("%d",&n);
	printf("Enter the %d observations:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&x[i]);
	}
	printf("Enter the corresponding frequencies:\n");
	for(i=0;i<n;i++)
	{
		scanf("%lf",&f[i]);
	}

	/* CALCULATION OF POISSON PDF */

	for(i=0;i<n;i++)
	{
		sum1=sum1+x[i]*f[i];
		sum2=sum2+f[i];
	}
	k=sum1/sum2;
	for(i=0;i<n;i++)
		{
			a[i]=exp(-k)*pow(k,x[i])/factorial(x[i]);
			sum3=sum3+a[i];
			e[i]=a[i]*sum2;
		}
	b=1-sum3;
	e[n]=b*sum2;

	/* WRITING THE OUTPUT IN A FILE */

	FILE *fp;
	fp=fopen("Practical_8.dat","w");
	fprintf(fp,"The number of misprints per page are:\n");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%lf \t",x[i]);
	}
	fprintf(fp,">=%lf",x[n-1]+1);
   fprintf(fp,"\n\n");
	fprintf(fp,"\nThe corresponding observed frequencies are:\n");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%lf \t",f[i]);
	}
	fprintf(fp,"0\n\n");
	fprintf(fp,"\nThe corresponding expected frequencies are:\n");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%lf \t",e[i]);
	}
	fprintf(fp,"%lf",e[n]);
}

double factorial(double p)
{
	if(p==0)
	return 1;
	else
	return p*factorial(p-1);
}
