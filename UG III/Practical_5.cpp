#include<stdio.h>
#include<math.h>

/* System of linear equation*/

main ()
{

/* ENTERING THE MATRIX */

	int i,j,k,n;
	double a[20][20],r,s,b[20],c[20],d;
	printf("Enter the order of the coefficient matrix: \n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("Enter the (%d,%d) element of the coefficient matrix: \n",i,j);
			scanf("%lf",&a[i][j]);
			if(i==j)
			a[i][j+n]=1;
			else
			a[i][j+n]=0;
		}
	}
	printf("Enter the constant vector:\n");
	for(i=1;i<=n;i++)
	{
		scanf("%lf",&b[i]);
	}

/* WRITING THE SYSTEM OF EQUATIONS IN AN OUTPUT FILE */

	FILE *fp;
	fp=fopen("Practical_5.dat","w");
	for(i=1;i<=n;i++)
	{
		fprintf(fp,"%lfx1 + %lfx2 + %lfx3 = %lf\n\n",a[i][1],a[i][2],a[i][3],b[i]);
	}



/* DIAGONALIZATION OF THE MATRIX */

	for(i=1;i<=n;i++)
	{
		r=a[i][i];
		for(k=1;k<=2*n;k++)
		{
			a[i][k]=a[i][k]/r;
		}
		for(j=1;j<=n;j++)
		{

			if(j!=i)
			{
				s=a[j][i];
				for(k=1;k<=2*n;k++)
				{
					a[j][k]=a[j][k]-s*(a[i][k]);
				}
			}
		}
	}



/* FINDING THE SOLUTION */

	for(i=1;i<=n;i++)
	{
		c[i]=0;
		for(j=1;j<=n;j++)
		{
			d=a[i][j+n]*b[j];
			c[i]=c[i]+d;
		}
	}
	printf("\nThe required solution is:\n\n");
	for(i=1;i<=n;i++)
	{
	printf("%lf ",c[i]);
	}

/* WRITING THE SOLUTION IN AN OUTPUT FILE */

	fprintf(fp,"\nThe required solution is:\n\n");
	for(i=1;i<=n;i++)
	{
	fprintf(fp,"x[%d] = %lf \n",i,c[i]);
	}
}
