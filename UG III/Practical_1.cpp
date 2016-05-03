#include<stdio.h>
#include<math.h>

/*Calculating descriptive statistics of the univariate data*/

main()
{
/* INPUTTING THE DATA SET */

	int i,n,k,min;
	double a[50],temp,sum,avg,ssq,var,sd;
	printf("Enter the number of observations:\n");
	scanf("%d",&n);
	printf("Enter the %d numbers \n",n);
	for(i=0;i<n;i++)
	{
	scanf("%lf",&a[i]);
	}

/* SORTING THE DATA */

	for(i=0;i<n;i++)
		{
			min=i;
			for(k=i+1;k<n;k++)
			{
				if(a[min]>a[k])
				min=k;
			}
			if(a[min]<a[i])
			{
				temp=a[min];
				a[min]=a[i];
				a[i]=temp;
			}
		}

/* CALCULATION OF MEAN, VARIANCE, STANDARD DEVIATION */

	sum=0,ssq=0;
	for(i=0;i<n;i++)
	{
		sum=sum+a[i];
		ssq=ssq+pow(a[i],2);
	}
	avg=sum/n;
	var=ssq/n-pow(avg,2);
	sd=pow(var,.5);
	printf("The mean of the data set is %lf \n",avg);
	printf("The standard deviation of the data set is %lf \n",sd);


/* CALCULATION OF MEDIAN, AND INTERQUARTILE RANGE */

	double Med,Q1,Q3,Q;
	if((int)(n/2.0)==(n/2.0))
		Med=((a[(n/2)-1]+a[(n/2)])/2);
	else
		Med=a[(n-1)/2];
	printf("\nThe Median is %lf \n",Med);

	Q1=a[(int)(n/4)-1];
	Q3=a[(int)(3*n/4)-1];
	Q=(Q3-Q1)*0.5;
	printf("The Semi-Interquartile Range is %lf\n",Q);


/* CALCULATION OF MOMENTS AND MEASURES OF SKEWNESS AND KURTOSIS */

	double s3=0,s4=0,m3,m4,b1,b2;
	for(i=0;i<n;i++)
	{
		s3=s3+pow((a[i]-avg),3);
		s4=s4+pow((a[i]-avg),4);
	}

	m3=s3/n;
	m4=s4/n;
	b1=(pow(m3,2))/(pow(var,3));
	b2=m4/pow(var,2);
	printf("b1 = %lf\n",b1);
	printf("b2 = %lf\n",b2);

/* WRITING THE OUTPUT IN A FILE */

	FILE *fp;
	fp=fopen("practical_1.dat","w");
	fprintf(fp,"The given raw data is:\n\n");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%lf \n",a[i]);
	}
	fprintf(fp,"\n(a) The mean of the data set is %lf \n",avg);
	fprintf(fp,"\n(b) The median of the data set is %lf \n",Med);
	fprintf(fp,"\n(c) The standard deviation of the data set is %lf \n",sd);
	fprintf(fp,"\n(d) The semi-interquartile range of the data set is %lf \n",Q);
	fprintf(fp,"\n(e) The value of b1 of the data set is %lf \n",b1);
	fprintf(fp,"\n(f) The value of b2 of the data set is %lf \n",b2);
   fclose(fp);
}
