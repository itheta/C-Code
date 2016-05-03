#include<stdio.h>
#include<math.h>
#include<conio.h>
double spearman(double, double);
main()
{
	FILE *fp;
	fp=fopen("practical_33.dat","w");
	int i,j,k,l;
	double n,a[20],r_a[20],b[2],r_b[20],c[20],r_c[20];
	printf("Enter the number of individuals:\t");
	scanf("%lf",&n);
	printf("Enter the scores given by Judges 1,2,3:\t\n");
	for(i=1;i<=n;i++)
	{
		printf("\nEnter score given by Judge 1 to individual %d:\t",i);
		scanf("%lf",&a[i]);
      printf("\nEnter score given by Judge 2 to individual %d:\t",i);
		scanf("%lf",&b[i]);
      printf("\nEnter score given by Judge 3 to individual %d:\t",i);
		scanf("%lf",&c[i]);
	}
	clrscr();
	for(i=1;i<=n;i++)
	{
		r_a[i]=10;
		for(j=1;j<=n;j++)
		{
			if(i!=j && a[i]>a[j])
			r_a[i]=r_a[i]-1;
		}
	}
	for(i=1;i<=n;i++)
	{
		r_b[i]=10;
		for(k=1;k<=n;k++)
		{
			if(i!=k && b[i]>b[k])
			r_b[i]=r_b[i]-1;
		}
	}
	for(i=1;i<=n;i++)
	{
		r_c[i]=10;
		for(l=1;l<=n;l++)
		{
			if(i!=l && c[i]>c[l])
			r_c[i]=r_c[i]-1;
		}
	}
	printf("\n\nThe respective ranks alloted are:\n");
	fprintf(fp,"\n\nThe respective ranks alloted are:\n");
	printf("Judge 1\tJudge 2\tJudge 3\n");
	fprintf(fp,"Judge 1\tJudge 2\tJudge 3\n");
   for(i=1;i<=n;i++)
	{
		printf("%.0lf\t%.0lf\t%.0lf\n",r_a[i],r_b[i],r_c[i]);
		fprintf(fp,"%.0lf\t%.0lf\t%.0lf\n",r_a[i],r_b[i],r_c[i]);
	}

	double sum_12=0,sum_13=0,sum_23=0,r_12,r_13,r_23;
	for(i=1;i<=n;i++)
	{
		sum_12=sum_12+spearman(n,(r_a[i]-r_b[i]));
		sum_13=sum_13+spearman(n,(r_a[i]-r_c[i]));
		sum_23=sum_23+spearman(n,(r_b[i]-r_c[i]));
	}
	r_12=1-sum_12;r_13=1-sum_13;r_23=1-sum_23;
	if(r_12 > r_13 && r_12 > r_23)
	{
	printf("\n\nThe judges 1 and 2 agree the most");
	printf("\nThe Spearman rank correlation coefficient being:\t%.5lf",r_12);
	fprintf(fp,"\n\nThe judges 1 and 2 agree the most");
	fprintf(fp,"\nThe Spearman rank correlation coefficient being:\t%.5lf",r_12);
	}
	else if(r_13 > r_12  && r_13 > r_23)
	{
	printf("\n\nThe judges 1 and 3 agree the most");
	printf("\nThe Spearman rank correlation coefficient being:\t%.5lf",r_13);
	fprintf(fp,"\n\nThe judges 1 and 3 agree the most");
	fprintf(fp,"\nThe Spearman rank correlation coefficient being:\t%.5lf",r_13);
	}
	else if(r_23 > r_12  && r_23 > r_13)
	{
	printf("\n\nThe judges 2 and 3 agree the most");
	printf("\nThe Spearman rank correlation coefficient being:\t%.5lf",r_23);
	fprintf(fp,"\n\nThe judges 2 and 3 agree the most");
	fprintf(fp,"\nThe Spearman rank correlation coefficient being:\t%.5lf",r_23);
	}
	else
	printf("\n\nBased on the data provided no valid inference can be drawn.");
fprintf(fp,"\n\nBased on the data provided no valid inference can be drawn.");
   fclose(fp)
	getch();
}


double spearman(double n1,double d)
{
	double func;
	func=(6*pow(d,2))/(n1*(pow(n1,2)-1));
	return(func);
}




