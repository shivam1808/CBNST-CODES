/*
	Que: Evaluate at a point given by user from 
	dy/dx = x^2y-1 by using Euler's Method.
	Name: Shivam Gupta
	Sec: A(60)
*/

#include<stdio.h>

float f(float, float);
int main()
{
	float n,h,itr, x[10], y[10], res;
	int x0,y0,i;
	printf("Equation: dy/dx = x^2*y-1\n");
	printf("Enter the value to be evaluate: ");
	scanf("%f",&n);
	printf("Enter x0 and y0: ");
	scanf("%d%d",&x0,&y0);
	printf("Enter Step Size: ");
	scanf("%f",&h);
	itr = n/h;
	//printf("itr = %f\n", itr);
	for(i=0;i<itr;i++)
	{
		x[i+1]=h*(i+1); 
		printf("x%d = %f\n",i+1,x[i+1]);
	}
	x[0] = x0;
	y[0] = y0;
	for(i=0;i<itr;i++)
	{
		y[i+1] = y[i] + h*f(x[i],y[i]);
		printf("%f\n",y[i+1]);
	}	
	printf("Result : %f",y[i]);
	
}

float f(float x, float y)
{
	return(x*x*y-1);
}
