#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#define pi 22/7
main()
    {
    int i,j,k,m,n,size,df1,df2,df,a[10],max;
    double chisq1[100],chisq2[100],sum1=0,sum2=0,z1[100],z2[100],z3[100],z4[100],f[100],u1[100],u2[100],u3[100],u4[100],t[100],sum3=0,chisq3[100];
    printf("Enter the size of samples to be generated from t and f distributions: \n");
    scanf("%d",&size);
    printf("Enter the degrees of freedom of t : \n");
    scanf("%d",&df);
    printf("Enter the d1 degrees of freedom of f : \n");
    scanf("%d",&df1);
    printf("Enter the d2 degrees of freedom of f : \n");
    scanf("%d",&df2);
    for(i=0;i<size;i++)
    {
        if(df1<df2)
        max=df2;
        else
        max=df1;

    for(j=0;j<max;j++)
    {
    u1[j]=rand()/(double)RAND_MAX;
    u2[j]=rand()/(double)RAND_MAX;
    }
    max=0;
    if(df<size)
    max=size;
    else
    max=df;
    for(j=0;j<max;j++)
    {
    u3[j]=rand()/(double)RAND_MAX;
    u4[j]=rand()/(double)RAND_MAX;
    }
        if(df1<df2)
        max=df2;
        else
        max=df1;
    for(j=0;j<max;j++)
    {
    z1[j]=pow(((-2)*log(u1[j])),.5)*cos(2*pi*u2[j]);
    z2[j]=pow(((-2)*log(u1[j])),.5)*sin(2*pi*u2[j]);
    }
    max=0;
    if(df<size)
    max=size;
    else
    max=df;
    for(j=0;j<max;j++)
    {
    z3[j]=pow(((-2)*log(u3[j])),.5)*cos(2*pi*u4[j]);
    z4[j]=pow(((-2)*log(u3[j])),.5)*sin(2*pi*u4[j]);
    }
    for(j=0;j<df1;j++)
    {
        sum1=sum1+pow(z1[j],2);
    }
    for(j=0;j<df2;j++)
    {
        sum2=sum2+pow(z2[j],2);
    }
    for(j=0;j<df;j++)
    {
        sum3=sum3+pow(z3[j],2);
    }
    chisq1[i]=sum1;chisq2[i]=sum2;chisq3[i]=sum3;sum1=0;sum2=0;sum3=0;
    }
    for(i=0;i<size;i++)
    {
    f[i]=(double)(chisq1[i]/df1)/(chisq2[i]/df2);
    t[i]=(double)(z4[i]*pow(df,.5))/pow(chisq3[i],.5);
    }
    for(i=0;i<size;i++)
    {
    printf("t[%d]\t%lf\n",i+1,t[i]);
    }
    printf("\n\n\n");
    for(i=0;i<size;i++)
    {
    printf("f[%d]\t%lf\n",i+1,f[i]);
    }
    return 0;
    }
