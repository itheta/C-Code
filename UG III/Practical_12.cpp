#include<stdio.h>
#include<math.h>

main ()
{

	/* INPUTTING THE DATA SET */

	int n,i,j,k;
	double x[5][10],y[10],r[5][5],m[20],s[5][5],sum[20],R[5][5],e[10],b12,b13;
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


	/* CALCULATION OF REGRESSION COEFFICIENTS, FITTED VALUES AND RESIDUALS */

	R[1][1]=1-r[2][3]*r[3][2];
	R[1][2]=r[2][3]*r[3][1]-r[2][1];
	R[1][3]=r[2][1]*r[3][2]-r[3][1];
	b12=-R[1][2]*pow(s[1][1],.5)/(R[1][1]*pow(s[2][2],.5));
	b13=-R[1][3]*pow(s[1][1],.5)/(R[1][1]*pow(s[3][3],.5));

	for(i=0;i<n;i++)
	{
		y[i]=m[1]+b12*(x[2][i]-m[2])+b13*(x[3][i]-m[3]);
	}

	for(i=0;i<n;i++)
	{
		e[i]=x[1][i]-y[i];
	}

	/* WRITING THE OUTPUT IN A FILE */

	FILE *fp;
	fp=fopen("practical_12.dat","w");
	fprintf(fp,"The multiple linear regression equation is:\n\nX1 = %lf + %lf(X2-%lf) + %lf(X3-%lf)",m[1],b12,m[2],b13,m[3]);
	fprintf(fp,"The observed values are:\n");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%lf \n",x[1][i]);
	}
	fprintf(fp,"The fitted values are:\n");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%lf \n",y[i]);
	}
	fprintf(fp,"The residuals are:\n");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%lf \n",e[i]);
	}
	fclose(fp);
}
