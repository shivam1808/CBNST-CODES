/*	
Que: Evaluate 1/(1+x^2) integration from x0 to xn
	by using Simppson one-third rule with step size given 
	by the user. 
Name: Shivam Gupta
Sec: A(60)
*/


#include<stdio.h>
#include<math.h>
float f(float );
void main()
{
    int i,n;
    float x0,xn,h,y[20],so,se,res,x[20];
    printf("Enter values of x0,xn:\n");
    scanf("%f%f",&x0,&xn);
    printf("Enter step size h:");
    scanf("%f",&h);
    n=(xn-x0)/h;
    printf("X        Y\n");
    for(i=0; i<=n; i++)
    {
        x[i]=x0+i*h;
        y[i]=f(x[i]);
        printf("%.3f   %.4f\n",x[i],y[i]);
    }
    so=0;
    se=0;
    for(i=1; i<n; i++)
    {
        if(i%2==1)
        {
            so=so+y[i];
        }
        else
        {
            se=se+y[i];
        }
    }
    res=h/3*(y[0]+y[n]+4*so+2*se);
    printf("Result: %f",res);
}

float f(float x)
{
    return(1/(4*x+5));
}

