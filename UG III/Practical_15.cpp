#include<stdlib.h>
#include<stdio.h>
#include<math.h>

main()
{
  randomize();
  rand();
  int n,i,j,l;
  long a1,a2;
  double b1,b2,x[50],y[50],m,s,t[50],sum;
  FILE *fp;
  fp=fopen("practical_15.dat","w");

					/* DRAWING OF RANDOM SAMPLE FROM NORMAL DISTRIBUTION */

  printf("Enter the sample size n \n");
  scanf("%d",&n);

  printf("Enter the mean and standard deviations of the distribution m & s \n");
  scanf("%lf %lf",&m,&s);

  fprintf(fp,"A random sample from a normal with mean %lf and sd %lf is :\n\n",m,s);

  for(i=1;i<=2*n;i=i+2)
	 {
		a1=rand();a2=rand();
		b1=a1/(float)RAND_MAX;
		b2=a2/(float)RAND_MAX;
		x[i]=pow((-2*log(b1)),0.5)*cos(2*3.14*b2);
		x[i+1]=pow((-2*log(b1)),0.5)*sin(2*3.14*b2);
	 }
  for(i=1;i<=n;i=i+1)
	 {
		y[i]=m+s*x[i];
		printf("%lf \n",y[i]);
		fprintf(fp,"%lf  \n",y[i]);
	 }

				 /* DRAWING OF RANDOM SAMPLE FROM t-DISTRIBUTION */


	 fprintf(fp,"\n\nA random sample from a t distribution with 5 degrees of freedom  is :\n\n");

	 for(i=1;i<=2*n;i=i+6)
		{
			sum=0;l=1;
			for(j=i+1;j<=i+5;j++)
			{
				sum=sum+pow(x[j],2);
			}
			t[l]=x[i]/(pow(sum,0.5)/pow(5,0.5));
			printf("%lf \n",t[l]);
			fprintf(fp,"%lf \n",t[l]);
			l=l+1;
		}

		fclose(fp);
}
