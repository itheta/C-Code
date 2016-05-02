#include<stdio.h>
#include<math.h>
main ()
{
	/* INPUTTING THE DATA */

	int n,i,j;
	double x,y[20],f[20],p,q,r=0;
	printf("Enter the number of arguments:\n");
	scanf("%d",&n);
	printf("\nEnter the values of the %d arguments:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&y[i]);
	}
	printf("\nEnter the corresponding values of the response variable:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&f[i]);
	}
	printf("\nEnter the value of the argument corresponding to the required response variable:\n");
	scanf("%lf",&x);

	/* COMPUTATION USING LAGRANGE'S INTERPOLATION FORMULA */

	for(i=0;i<n;i++)
	{
		p=1.0,q=1.0;
		for(j=0;j<n;j++)
		{
			if(j!=i)
			{
				p=p*(x-y[j]);
				q=q*(y[i]-y[j]);
			}
		}
		r=r+(p/q)*f[i];
	}
	printf("The value of the e^%lf is %lf.",x,r);
}
