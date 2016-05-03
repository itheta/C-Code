#include<stdio.h>
#include<math.h>

main()
{
	FILE *fp;
	fp=fopen("practical_22.dat","w");
	int i,j,k,m,n;
	double a[10][10],b[10][10];
	printf("Enter the order of the matrix(rowxcolumn):\t");
	scanf("%d %d",&m,&n);
	printf("Enter the elements of the matrix:\n");
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("Enter the value of a[%d][%d]:\t",i,j);
			scanf("%lf",&a[i][j]);
		}
	}
	double r=0;
	printf("\nThe transpose:\n");
	fprintf(fp,"\nThe transpose:\n");
	for(i=1;i<=m;i++)
	{
		r=r+a[i][i];
		for(j=1;j<=n;j++)
		{
				printf("%.0lf\t",a[j][i]);
				fprintf(fp,"%.0lf\t",a[j][i]);
		}
		printf("\n");
		fprintf(fp,"\n");
	}
	printf("The trace:\t%.0lf",r);
	fprintf(fp,"The trace:\t%.0lf",r);
   fclose(fp);
}


