#include<stdio.h>
#include<math.h>
main()
{
	FILE *fp;
	fp=fopen("practical_13.dat","w");
	int    i,p;
	double  n,h,f_x,f1_x,f2_x,x;
	printf("Enter a positive real number:\t");
	scanf("%lf",&n);
	printf("Enter the value of the desired root:\t");
	scanf("%d",&p);
	printf("Enter the good initial approximation of the root:\t");
	scanf("%lf",&x);
	printf("\nThe approximation of the root entered=\t%lf\n",x);
	fprintf(fp,"The approximation of the root entered=\t%lf\n",x);
	f_x=pow(x,p)-n;
	f1_x=p*pow(x,p-1);
	f2_x=p*(p-1)*pow(x,p-2);
	/*printf("%lf\t%lf\t%lf\t",f_x,f1_x,f2_x);*/
	h=(f_x/f1_x);
	x=x-h;
	/*printf("%lf\t%lf\t",h,x);*/

 while(h>0.001)
 if(fabs((float)(f_x*f2_x)/pow(f1_x,2))<1)
	{
		h=0;
		{
			h=(f_x/f1_x);
			x=x-h;
			/*printf("%lf",x);*/
		}
		f_x=pow(x,p)-n;
		f1_x=p*pow(x,p-1);
		f2_x=p*(p-1)*pow(x,p-2);
	}

	printf("The desired value of the root correct upto 4 decimal places is:\t");
	fprintf(fp,"The desired value of the root correct upto 4 decimal places is:\t");
	printf("%.4f",x);
	fprintf(fp,"%.4f",x);
   fclose(fp);
}

