#include<stdio.h>
#include<math.h>

main ()
{

	/* INPUTTING THE DATA SET */

	int n,i,j,k;
	double x[5][10],r[5][5],m[20],s[5][5],sum[20],R[5][5],r12_3;
	printf("Enter the number of observations:");
	scanf("%d",&n);
	for(i=1;i<=3;i++)
	{
		printf("Enter the values of X%d:",i);
		for(j=0;j<n;j++)
		{
			scanf("%lf",&x[i][j]);
		}
	}

	/* CALCULATION OF CORRELATION MATRIX */

	for(i=1;i<=3;i++)
	{
		sum[i]=0;
		for(j=0;j<n;j++)
		{
			sum[i]=sum[i]+x[i][j];
		}
		m[i]=sum[i]/n;
	}


	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			s[i][j]=0;
			for(k=0;k<n;k++)
			{
				s[i][j]=s[i][j]+(x[i][k]-m[i])*(x[j][k]-m[j]);
			}
		}
	}
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			r[i][j]=s[i][j]/pow((s[i][i]*s[j][j]),.5);
		}
	}


	/* CALCULATION OF PARTIAL CORRELATION */

	R[1][1]=1-r[2][3]*r[3][2];
	R[2][2]=1-r[1][3]*r[3][1];
	R[1][2]=r[2][3]*r[3][1]-r[2][1];
	r12_3=-R[1][2]/pow((R[1][1]*R[2][2]),.5);


	/* WRITING THE OUTPUT IN A FILE */

	FILE *fp;
	fp=fopen("practical_11.dat","w");
	fprintf(fp,"\n\nThe Correlation Matrix is:\n");
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			fprintf(fp,"%lf \t",r[i][j]);
		}
		fprintf(fp,"\n");
	}
	fprintf(fp,"The partial correlation coefficient of X1 and X2 eliminating the effects of X3 is %lf",r12_3);
	fclose(fp);
}
