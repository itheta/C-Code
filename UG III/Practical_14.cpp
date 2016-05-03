#include<stdio.h>
#include<math.h>

main()
{
  FILE *fp;
  int n,i,j;
  double a[15],b[15],c[15],ra[15],rb[15],rc[15],d1[15],d2[15],d3[15],sum1=0,sum2=0,sum3=0,rR1,rR2,rR3;

	fp=fopen("practical_14.dat","w");

	printf("Enter the number of observations :");
	scanf("%d",&n);

  printf("Enter the scores given by Judge A : \n");
  for(i=1;i<=n;i++)
  {
  scanf("%lf",&a[i]);
  }

  printf("Enter the scores given by Judge B : \n");
	for(i=1;i<=n;i++)
  {
  scanf("%lf",&b[i]);
  }

  printf("Enter the scores given by Judge C : \n");
  for(i=1;i<=n;i++)
  {
  scanf("%lf",&c[i]);
  }


		  /* ASSIGNING RANKS TO THE SCORES */

	for(i=1;i<=n;i++)
	  {
		 ra[i]=1;rb[i]=1;rc[i]=1;
		 for(j=1;j<=n;j++)
			{
				 if(a[i]<a[j])
				 ra[i]=ra[i]+1;

				 if(b[i]<b[j])
				 rb[i]=rb[i]+1;

				 if(c[i]<c[j])
				 rc[i]=rc[i]+1;
			}
	  }

		 /* SHOWING THE REQUIRED CALCULATIONS */

		for(i=1;i<=n;i++)
		  {
			 d1[i]=ra[i]-rb[i];
			 d2[i]=rb[i]-rc[i];
			 d3[i]=rc[i]-ra[i];

			 sum1=sum1+pow(d1[i],2);
			 sum2=sum2+pow(d2[i],2);
			 sum3=sum3+pow(d3[i],2);
		  }

		  /* CALCULATION OF SPEARMAN'S RANK CORRELATION COEFFICIENTS */

		  rR1=1-((6*sum1)/(n*(pow(n,2)-1)));
		  rR2=1-((6*sum2)/(n*(pow(n,2)-1)));
		  rR3=1-((6*sum3)/(n*(pow(n,2)-1)));

		  printf("%lf %lf %lf \n",rR1,rR2,rR3);

		  fprintf(fp,"The rank correlation coefficient between Judge A & B is %lf \n",rR1);
		  fprintf(fp,"The rank correlation coefficient between Judge B & C is %lf \n",rR2);
		  fprintf(fp,"The rank correlation coefficient between Judge C & A is %lf \n",rR3);


			 /* DETERMINING WHICH PAIR OF JUDGES HAS THE NEAREST APPROACH TO COMMON TASTE IN BEAUTY */

		if((rR1>rR2)&&(rR1>rR3))
		  {
		  printf(" Judges A and B has the nearest approach to the common taste in beauty \n");
		  fprintf(fp," Judges A and B has the nearest approach to the common taste in beauty \n");
		  }

		if((rR2>rR1)&&(rR2>rR3))
		  {
		  printf(" Judges B and C has the nearest approach to the common taste in beauty \n");
		  fprintf(fp," Judges B and C has the nearest approach to the common taste in beauty \n");
			}

		if((rR3>rR1)&&(rR3>rR2))
		  {
		  printf(" Judges C and A has the nearest approach to the common taste in beauty \n");
		  fprintf(fp," Judges C and A has the nearest approach to the common taste in beauty \n");
			}




}
