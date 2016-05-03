#include<stdio.h>
#include<math.h>

main()
{
	FILE *fp;
	fp=fopen("practical_18.dat","w");

	int i,j,n,l;
	float array[20],swap=0,p,p1,quant_p,quant_p1;
	printf("Enter the number of elements in the array:\t");
	scanf("%d",&n);
	printf ("Enter the elements of the array:\n");
	for (i=0;i<n;i++)
	{
		scanf("%f",&array[i]);
	}
/*Bubble sort*/

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(array[j]>array[j+1])
			{
				swap=array[j];
				array[j]=array[j+1];
				array[j+1]=swap;
			}
		}
	}

	printf("The array in the ascending order is:\n");
	fprintf(fp,"The array sorted in ascending order:\n");
   for(i=0;i<n;i++)
	{
		printf("%.3f\t",array[i]);
		fprintf(fp,"%.3f\t",array[i]);
	}
	printf("\nEnter the quantile required:\t");
	scanf("%f",&p);
	l=(int)(n*p)-1;
	quant_p=array[l];
	printf("The required %f quantile is=:\t %.3f\n",p,quant_p);
	fprintf(fp,"The required %f quantile is=:\t %.3f\n",p,quant_p);
   printf("\nEnter the quantile required:\t");
	scanf("%f",&p1);
	l=(int)(n*p1)-1;
	quant_p1=array[l];
	printf("The required %f quantile is=:\t %.3f\n",p1,quant_p1);
	fprintf(fp,"The required %f quantile is=:\t %.3f\n",p1,quant_p1);
	fclose(fp);

}
