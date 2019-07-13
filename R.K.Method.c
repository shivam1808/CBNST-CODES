/*
	Que: Evaluate at a point given by user from 
	dy/dx = 1-2xy by using fourth order Runge-Kutta
	Method.
Name: Shivam Gupta
Sec: A(60)
*/
#include<stdio.h>

float f(float, float);
int main()
{
	float n,h,itr, x[10], y[10], res,k[4];
	int x0,y0,i;
	printf("Equation: dy/dx = 1-2xy\n");
	printf("Enter the value to be evaluate: ");
	scanf("%f",&n);
	printf("Enter x0 and y0: ");
	scanf("%d%d",&x[0],&y[0]);
	printf("Enter Step Size: ");
	scanf("%f",&h);
	itr = n/h;
	//printf("itr = %f\n", itr);
	for(i=0;i<itr;i++)
	{
		x[i+1]=h*(i+1); 
		printf("x%d = %f\n",i+1,x[i+1]);
	}
	
	for(i=0;i<itr;i++)
	{
		k[0] = h * f(x[i],y[i]);
		k[1] = h * f(x[i]+h/2.0, y[i]+k[0]/2.0);
		k[2] = h * f(x[i]+h/2.0, y[i]+k[1]/2.0);
		k[3] = h * f(x[i]+h, y[i]+k[2]);
		y[i+1] = y[i] + 1/6.0 * (k[0]+2*k[1]+2*k[2]+k[3]);
		printf("y%d = %f\n",i+1,y[i+1]);
	}	
	printf("Result : %f",y[i-1]);
}

float f(float x, float y)
{
	return(1-2*x*y);
}
