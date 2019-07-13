/*	
Que: Solve the system of Equations by using Gauss
     Jordan Method.
Name: Shivam Gupta
Sec: A(60)
*/

#include<stdio.h>

int main()
{
	int i,j,k,n,m;
	int s,z,p;
	float c,a[10],b[10][10],x1,y1,z1;
	printf("Enter number of linear equation: ");
	scanf("%d",&n);
	m = 3;
	printf("Enter the equation in the form of ax+by+cz=d:\n");
	for(j=0;j<n;j++)
	{
		printf("Equation %d : ",j+1);
		for(i=0;i<m;i++)
	    {
	    	scanf("%f%*c",&a[i]);
		}            
	    scanf("%*c%f",&a[i]);
	    p = 0;
	    for(z=0;z<m+1;z++)
	    {
	    	b[j][z] = a[p];
	    	p++;
		}
		p=0;
	}
	printf("Augumented Matrix :\n");
	for(s=0;s<n;s++)
	{
	   	for(z=0;z<m+1;z++)
	   	{
	   		printf("%f  ",b[s][z]);
		}
		printf("\n");
	}
	printf("Final Matrix: \n");
	for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(i!=j)
            {
                c=b[i][j]/b[j][j];
                for(k=0; k<n+1; k++)
                {
                    b[i][k]=b[i][k]-(c*b[j][k]);
                }
            }
        }
    }
    
	for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        {
            printf("%f\t",b[i][j]);
        }
        printf("\n");
    }
    z1 = b[2][3]/b[2][2];
    y1 = (b[1][3] - b[1][2]*z1)/b[1][1];
    x1 = (b[0][3]-b[0][2]*z1-b[0][1]*y1)/b[0][0];
    printf("Result:\n");
    printf("x = %f\n",x1);
    printf("y = %f\n",y1);
    printf("z = %f\n",z1);
}
