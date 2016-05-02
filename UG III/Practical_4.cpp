#include<stdio.h>
#include<math.h>

main ()
{
//Inverse of a matrix by Gauss-Jordan elimination
/* ENTERING THE MATRIX */

	int i,j,k,n;
	double a[20][20],r,s,det=1;
	printf("Enter the order of the matrix: \n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("Enter the (%d,%d) element of the matrix: \n",i,j);
			scanf("%lf",&a[i][j]);
			if(i==j)
			a[i][j+n]=1;
			else
			a[i][j+n]=0;
		}
	}


/* DIAGONALIZATION OF THE MATRIX */

	for(i=1;i<=n;i++)
	{
		r=a[i][i];
		det=det*r;
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


/* PRINTING THE OUTPUT */

	printf("\nThe determinant of the matrix is: %lf\n\n",det);
	printf("\nThe inverse matrix is: \n\n");
	for(i=1;i<=n;i++)
	{
		for(j=n+1;j<=2*n;j++)
		{
			printf("%lf \t",a[i][j]);
		}
		printf("\n");
	}
}
