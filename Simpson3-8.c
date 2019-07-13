/*	
Que: Evaluate 1/(1+x^2) integration from x0 to xn
	by using Simppson three - eight rule with step size given 
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
    float x0,xn,h,y[20],so,se,s3,res,x[20];
    printf("Enter values of x0,xn:\n");
    scanf("%f%f",&x0,&xn);
    printf("Enter step size h:");
    scanf("%f",&h);
    n=(xn-x0)/h;
    printf("Value of n = %d\n",n);
    printf("X        Y\n");
    for(i=0; i<=n; i++)
    {
        x[i]=x0+i*h;
        y[i]=f(x[i]);
        printf("%.3f   %.4f\n",x[i],y[i]);
    }
    se=0;
    s3=0;
    for(i=1; i<n; i++)
    {
        if(i%3==0)
        {
            s3=so+y[i];
        }
        else
        {
            se=se+y[i];
        }
    }
    res=3*h/8*(y[0]+y[n]+2*s3+3*se);
    printf("Result: %f",res);
}

float f(float x)
{
    return(1/(1+pow(x,2)));
}

