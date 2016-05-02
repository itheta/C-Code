#include<stdio.h>
#include<math.h>

main ()
{

/* ENTERING THE MATRIX */

	int i,j,m,n;
	double a[10][10],b[10][10];
	printf("Enter the number of rows of the matrix: \n");
	scanf("%d",&m);
	printf("Enter the number of columns of the matrix: \n");
	scanf("%d",&n);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("Enter the (%d,%d) element of the matrix: \n",i,j);
			scanf("%lf",&a[i][j]);
		}
	}

	printf("\nThe given matrix is: \n\n");
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%lf \t",a[i][j]);
		}
		printf("\n");
	}

/* TRANSPOSING THE MATRIX */

	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			b[i][j]=a[j][i];
		}
	}
	printf("\nThe transpose of the given matrix is: \n\n");
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%lf \t",b[i][j]);
		}
		printf("\n");
	}
}

