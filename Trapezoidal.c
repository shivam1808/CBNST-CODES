/*	
Que: Evaluate 1/(1+x^2) integration from x0 to xn
	by using Trapezoidal rule with step size given 
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
    float x0,xn,h,y[20],so,res,x[20];
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
    for(i=1; i<n; i++)
    {
        so=so+y[i];
    }
    printf("y[6] = %f\n",y[n]);
    res=h/2*(y[0]+y[n]+2*so);
    printf("Result: %f",res);
}

float f(float x)
{
    return(1/(1+pow(x,2)));
}

