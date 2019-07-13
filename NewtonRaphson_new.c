/*	
	Que: Find the approximate roots of the equation
		 in the interval using Newton Raphson 
		 method.		 
*/

#include<stdio.h>
#include<math.h>

void input(int, float[], float[]);
float fun(float,float [],int);
void deri(int ,float [],float []);
float fun2(float,float [],int);

int main()
{
	float fa,x0,fb,z=0,temp=0,ab,a,b,c;
	float arr[20], brr[20];
	int x,y,n,itr,p=1,m=1;
		printf("Enter Degree of Eq: ");
    	scanf("%d",&n);
		input(n,arr,brr);
		do{
			printf("Enter the interval: ");
			scanf("%f%f",&a,&b);
			fa = fun(a,arr,n);
			fb = fun(b,arr,n);
			printf("f(a) = %f , f(b) = %f\n",fa,fb);
			if((fa*fb)<=0)
				temp = 1;
		}while(temp!=1);
		printf("Enter Max No. of Iteration: ");
		scanf("%d",&itr);
		x0 = (a+b)/2.0;
		do{
			c = x0 - (fun(x0,arr,n)/fun2(x0,brr,n));
			x0 = c;
			printf("Value of x%d = %f\n",m++,x0);
			itr--;
		}while(itr!=0);
		printf("Result : %f",x0);
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

float fun2(float x,float brr[],int n)
{
	float z = 0;
	int i,j;
	for(i=0,j=n-1;i<n;i++,j--)
	{
		z = z + brr[i]*pow(x,j);
	}
	return(z);
}



void input(int n,float arr[], float brr[])				//Polynomial Equation:
{
	int i;
    n=n+1;
    printf("Enter the equation in the form of ax^2+bx+c: ");
    for(i=0;i<n;i++)
    {
    	if(i == n-1)
    		scanf("%f",&arr[i]);
    	else if (i == n-2)
    		scanf("%f%*c",&arr[i]);
    	else
    		scanf("%f%*c%*c%*c",&arr[i]);		//To store LHS Variables
	}           
    for(i=0;i<n;i++)
        printf("%f ",arr[i]);
    
    deri(n,arr,brr);
}

void deri(int n, float a[], float b[])
{
	int i,p;
	p = n-1;
	printf("\nDerivative:\n");
    n=n-1;
    for(i=0;i<p;i++)
    {
    	if(i == p-1)
    	{
    		printf("%.2f",a[i]);
    		b[i] = a[i];
		}		
    	else if (i == p-2)
    	{
    		printf("%.2fx + ",a[i]*n);
    		b[i] = a[i]*n;
		}	
    	else
    	{
    		printf("%.2fx^%d + ",a[i]*n,(n-1));
    		b[i] = a[i]*n;
    		n--;
		}    		
	}
	printf("\n");
}


