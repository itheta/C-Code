#include<stdio.h>
#include<math.h>
main()
{
   FILE *fp;
	fp=fopen("practical_27.dat","w");
	int i,j,k,n;
	double a[20][20];
	printf("Enter the order of the square matrix:\t");
	scanf("%d",&n);
	printf("Enter the elements of the matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("Enter a[%d][%d]:\t",i,j);
			scanf("%lf",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+n;j<=2*n;j++)
		{
			if((i+n)==j)
			a[i][j]=1;
			else
			a[i][j]=0;
		}
	}
	double det=1;
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
		det=det*r;
	}
	printf("The inverse if the matrix is:\t\n");
	fprintf(fp,"The inverse if the matrix is:\t\n");
	for(i=1;i<=n;i++)
	{
		for(k=n+1;k<=2*n;k++)
		{
			printf("%0.2lf\t",a[i][k]);
			fprintf(fp,"%0.2lf\t",a[i][k]);
		}
		printf("\n");
		fprintf(fp,"\n");
	}
	printf("The determinant:\t %.4lf",det);
	fprintf(fp,"The determinant:\t %.4lf",det);
   fclose(fp);
}


