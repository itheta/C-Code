#include<stdio.h>
#include<math.h>

main()
{
	FILE *fp;
	fp=fopen("practical_28.dat","w");

	int i,j,n;
	float y[10],f_y[10],y1,l,sum=0;
	printf("Enter the number of oservations:\t");
	scanf("%d",&n);
	printf("Enter the values of the arguments:\t\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&y[i]);
	}
	printf("Enter the values of the function corresponding to the arguments:\t\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&f_y[i]);
	}
	printf("Enter the value for which the functional argument is desired:\t");
	scanf("%f",&y1);
	for(i=0;i<n;i++)
	{
		l=1;
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				l=l*(y1-y[j])/(y[i]-y[j]);
			}
		}
		sum=sum+l*f_y[i];
	}
	printf("The required functional argument is %0.4f",sum);
	fprintf(fp,"The arguments provided are:\n");
	fprintf(fp,"y(i)\t\t\tf_y(i)\n");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%0.4f\t\t\t%0.4f\n",y[i],f_y[i]);
	}
	fprintf(fp,"\n\nThe argument entered is %f",y1);
	fprintf(fp,"\nThe corresponding functional argument is %0.4f",sum);
	fclose(fp);
}

