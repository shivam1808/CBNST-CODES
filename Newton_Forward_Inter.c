/*	
Que: Find the poynomial and value of the function
at given point using Newton Forward Interpolation
Method.
Name: Shivam Gupta
Sec: A(60)
*/

#include<stdio.h>
#include<math.h>


int fact(int n);
int main()
{
	float a[10][10] = {0},res;
	int i,j,n;
	float h,y,p,t,x;	
	printf("Enter no. of points: ");
	scanf("%d",&n);
	printf("Enter value of X and Y:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%f",&a[i][j]);
		}
	}
	printf("Enter value of x to find: ");
	scanf("%f",&x);
	for(j=2;j<n+1;j++)
	{
		for(i=0;i<=n-j;i++)
		{
			a[i][j]= a[i+1][j-1]-a[i][j-1];
		}
	}
	
	printf("Table:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1-i;j++)
		{
			printf("%f\t",a[i][j]);
		}
		printf("\n");
	}
	
	h = a[1][0] - a[0][0];
	printf("Value of h = %f\n",h);
	p = (x - a[0][0])/h;
	printf("Value of p = %f\n",p);
	t = p;
	y=a[0][1];
	for(i=0;i<n-1;i++)
	{
		y+=t*a[0][i+2]/fact(i+1);
		t = t*(t-i-1);
	}
	printf("Result: %f",y);
}

int fact(int n)
{
	int x = 1,i;
	for(i=2;i<=n;i++)
		x = x*i;
	//printf("Factorial of %d = %d\n",n,x);
	return x;
}

