#include<stdio.h>
#include<math.h>

/* Function prototype */

double factorial(double);
main()

/* DECLARATION */

{
	int i,n;
	double a[100],f[100],e[100],p[100],sum,sum1,c;
	printf("Enter number of non-empty classes (<100): \n");
	scanf("%d",&n);
	printf("\nEnter the %d classes: \n",n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&a[i]);
	}
	printf("\nEnter the %d non-zero frequencies: \n",n);

/* COMPUTATION OF PMF AND CHI-SQUARE */

	for(i=0;i<n;i++)
	{
		scanf("%lf",&f[i]);
		if(f[i]<0)
		printf("Invalid frequency.");
	}
	i=0,sum=0,sum1=0;
	for(i=0;i<n;i++)
	{
		sum=sum+a[i]*f[i];
		sum1=sum1+f[i];
	}
	c=sum/sum1;
	printf("\n\n\nThe parameter of the poisson distribution is %lf \n \n \n",c);

	double k,sum2=0,b,d,z=0;
		for(i=0;i<n;i++)
		{
			p[i]=exp(-c)*pow(c,a[i])/factorial(a[i]);
			e[i]=p[i]*sum1;
			sum2=sum2+p[i];
			z=z+(pow((e[i]-f[i]),2)/e[i]);
		}
		b=1-sum2;
		d=b*sum1;
		z=z+d;

/* DISPLAY OF RESULT */

		printf("Class\tFrequency\tProbability\tExpected Frequency \n");
		for(i=0;i<n;i++)
		{
			printf("%.0lf\t%.0lf\t\t%lf\t%lf\n",a[i],f[i],p[i],e[i]);
		}
		printf("=>%d\t0\t\t%lf\t%lf\n",n,b,d);
		printf("\n Pearsonian Frequency Chi-square = %lf",z);

}

/*DEFINING THE FUNCTION */

double factorial(double p)
{
	if(p==0)
	return 1;
	else
	return p*factorial(p-1);
}

