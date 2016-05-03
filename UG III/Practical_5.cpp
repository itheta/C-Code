#include<stdio.h>
#include<math.h>
main()
{
   FILE *fp;
	fp=fopen("d:\\Programs\\practical_5.dat","w");
	int i,j,k;
	double a[10][10],b[10],n=3;
	printf("Enter the coefficient matrix A in A*x=B system of eqns.:\t\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("Enter element(%d,%d):\t",i,j);
			scanf("%lf",&a[i][j]);
		}
		for(k=i+n;k<=2*n;k++)
		{
			if(n+i==k)
			a[i][k]=1;
			else
			a[i][k]=0;
		}
	}
	printf("Enter B-matrix:\t\n");
	for(i=1;i<=n;i++)
	{
		printf("Enter y_%d:\t",i);
		scanf("%lf",&b[i]);
	}
	printf("The system of equations is:\n\n\n");
	fprintf(fp,"The system of equations is:\n\n\n");
	for(i=1;i<=n;i++)
	{
		printf("%.0lfx1+%.0lfx2+%.0lfx3=%.0lf\n",a[i][1],a[i][2],a[i][3],b[i]);
	fprintf(fp,"%.0lfx1+%.0lfx2+%.0lfx3=%.0lf\n",a[i][1],a[i][2],a[i][3],b[i]);
	}
	double r,s;
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
	double sum,c[10];
	printf("\n\nThe solution vector is:\n");
	fprintf(fp,"\n\nThe solution vector is:\n");
	for(i=1;i<=n;i++)
	{
		sum=0;
		for(k=1;k<=n;k++)
		{
			sum=sum+a[i][k+(int)n]*b[k];
		}
		c[i]=sum;
	}
	for(i=1;i<=n;i++)
	{
		printf("(x_%d)=%0.3lf\n",i,c[i]);
      fprintf(fp,"(x_%d)=%0.3lf\n",i,c[i]);
	}
   fclose(fp);
}







