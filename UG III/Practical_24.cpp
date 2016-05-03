#include<stdio.h>
#include<math.h>

main()
{
	FILE *fp;
	fp=fopen("practical_24.dat","w");

	int i,j,n,position;
	float array[20],swap=0;
	printf("Enter the number of elements in the array:\t");
	scanf("%d",&n);
	printf ("Enter the elements of the array:\n");
	for (i=0;i<n;i++)
	{
		scanf("%f",&array[i]);
	}

	/*Selecton Sort*/
	for(i=0;i<n;i++)
	{
		position=i;
		for(j=i+1;j<n;j++)
		{
			if(array[position]<array[j])
			position=j;
		}
		if(position!=i)
		{
			swap=array[i];
			array[i]=array[position];
			array[position]=swap;
		}
	}
	printf("The array in the descending order is:\n");
	fprintf(fp,"The array sorted in descending order:\n");
	for(i=0;i<n;i++)
	{
		printf("%.3f\t",array[i]);
		fprintf(fp,"%.3f\t",array[i]);
	}
   fclose(fp);
}
