/*	
Que: Find the approximate roots of the equation in the given
 	 interval using Regula falsi.
Name: Shivam Gupta
Sec: A(60)
*/

#include<stdio.h>
#include<math.h>

int input(int, float[]);
float fun(float,float [],int);
int main()
{
	float fa,fb,z=0,temp=0,ab,a,b,c,x0,x1;
	float arr[20];
	int x,y,n,itr;
		printf("Enter Degree of Eq: ");
    	scanf("%d",&n);
		input(n,arr);
		do{
			printf("Enter the interval: ");
			scanf("%f%f",&a,&b);
			fa = fun(a,arr,n);
			fb = fun(b,arr,n);
			printf("f(a) = %f , f(b) = %f\n",fa,fb);
			if((fa*fb)<0)
				temp = 1;
		}while(temp!=1);
		//printf("Enter the absolut error: ");
		//scanf("%f",&ab);
		printf("Enter Max No. of Iteration: ");
		scanf("%d",&itr);
		x0 = a;
		x1 = b;
		do{
			c = x0 - (x1 - x0)/(fun(x1,arr,n)-fun(x0,arr,n))*fun(x0,arr,n);
			if(fun(x0,arr,n)*fun(c,arr,n)<0)
				x1=c;
			else
				x0=c;
			//printf("Value of x0 = %f  f(x0) = %f\n",x0,fun(x0,arr,n));
			//printf("Value of x1 = %f  f(x1) = %f\n\n",x1,fun(x1,arr,n));
			itr--;
		}while(itr!=0);
		printf("Result : %f",c);
}

float fun(float x,float arr[],int n)
{
	float z = 0;
	int i,j;
	for(i=0,j=n;i<=n;i++,j--)
	{
		z = z + arr[i]*pow(x,j);
	}
	return(z);
}

int input(int n,float a[])				//Polynomial Equation:
{
	int i;
    n=n+1;
    printf("Enter the equation in the form of ax^2+bx+c: ");
    for(i=0;i<n;i++)
    {
    	if(i == n-1)
    		scanf("%f",&a[i]);
    	else if (i == n-2)
    		scanf("%f%*c",&a[i]);
    	else
    		scanf("%f%*c%*c%*c",&a[i]);		//To store LHS Variables
	}           
    for(i=0;i<n;i++)
        printf("%.2f ",a[i]);
    return n;
}
