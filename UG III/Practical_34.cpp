#include<stdio.h>
#include<math.h>
double comb(double,double);
double fact(double);
main()
{
	FILE *fp;
	fp=fopen("practical_34.dat","w");
	int i,j,k,l,pos;
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

	double temp,temp1,temp2;

	for(i=1;i<=n;i++)
	{
		pos=i;
		for(j=i+1;j<=n;j++)
		{
			if(r_a[pos]>r_a[j])
			pos=j;
		}
		if(r_a[pos]<r_a[i])
		{
				temp=r_a[pos];
				r_a[pos]=r_a[i];
				r_a[i]=temp;
				temp1=r_b[pos];
				r_b[pos]=r_b[i];
				r_b[i]=temp1;
				temp2=r_c[pos];
				r_c[pos]=r_c[i];
				r_c[i]=temp2;

		}
	}
	printf("\n\nThe respective ranks alloted are (Judge 1 ordered):\n");
	printf("Judge 1\tJudge 2\tJudge 3\n");
	for(i=1;i<=n;i++)
	{
		printf("%.0lf\t%.0lf\t%.0lf\n",r_a[i],r_b[i],r_c[i]);
	}
	double kt_2,kt_3,sum=0,sum1=0;
	for(i=1;i<=n;i++)
	{
		kt_2=0;
		for(j=1;j<=n;j++)
		{
			if(i!=j && r_b[i]<r_b[j])
			kt_2=kt_2+1;
		}
		sum=sum+kt_2;
	}
	for(i=1;i<=n;i++)
	{
		kt_3=0;
		for(j=1;j<=n;j++)
		{
			if(i!=j && r_c[i]<r_c[j])
			kt_3=kt_3+1;
		}
		sum1=sum1+kt_3;
	}
	double k_rank2,k_rank3;
	k_rank2=((2*sum)/comb(n,2.0))-1;
	k_rank3=((2*sum1)/comb(n,2.0))-1;
	printf("\nThe Kendall's Tao for Judge 1 and 2:\t %.5lf",k_rank2);
	fprintf(fp,"\nThe Kendall's Tao for Judge 1 and 2:\t %.5lf",k_rank2);
	printf("\nThe Kendall's Tao for Judge 1 and 3:\t %.5lf",k_rank3);
	fprintf(fp,"\nThe Kendall's Tao for Judge 1 and 3:\t %.5lf",k_rank3);
   fclose(fp);
	return 0;

}
 double fact(double n1)
 {
	if(n1==0||n1==1)
	return 1;
	else
	return n1*fact(n1-1);
 }
 double comb(double n2,double x)
 {
	double func=fact(n2)/(fact(x)*fact(n2-x));
	return func;
 }
