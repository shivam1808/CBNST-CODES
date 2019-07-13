/*
Que: Find the roots of the given polynomial equation

Name: Shivam Gupta
Section: A(60)	
*/

#include<stdio.h>
#include<math.h>

int main()
{
	int i, n; float d;
	float a[50];
	printf("Enter Degree of Eq: ");
    scanf("%d",&n);
    n=n+1;
    printf("Enter the equation in the form of ax^2+bx+c: ");
    for(i=0;i<n;i++)
    {
    	if(i == n-1)
    		scanf("%f",&a[i]);
    	else if (i == n-2)
    		scanf("%f%*c",&a[i]);
    	else
    		scanf("%f%*c%*c%*c",&a[i]);
	}           
    printf("\n");
    d = a[1]*a[1] - 4*a[0]*a[2];
    
    if(d<0)
    {
    	printf("Roots are imaginary\n");
    	printf("Roots : %f",-a[1]/(2*a[0]));
    	printf(" + %f i\n",sqrt(d*-1)/(2*a[0]));
    	
    	printf("Roots : %f",-a[1]/(2*a[0]));
    	printf(" - %f i",sqrt(d*-1)/(2*a[0]));
	}
	else if(d == 0)
	{
		printf("Roots are Equal\n");
    	printf("Roots : %f",-a[1]/(2*a[0]));
	}
	else
	{
		printf("Roots : %f\n",-a[1]/(2*a[0])+sqrt(d)/(2*a[0]));
		printf("Roots : %f",-a[1]/(2*a[0])-sqrt(d)/(2*a[0]));
	}
}
