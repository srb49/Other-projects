//sparse matrix
#include<stdio.h>
#include<conio.h>
void main()
{
	int mat[100][100],a[100][3],b[100][3];
	int n,i,j,c=0,t;
	printf("enter matrix order");
	scanf("%d",&n);
	printf("\nenter matrix element\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("\nenter mat[%d][%d]=",i,j);
		scanf("%d",&mat[i][j]);
		//creating the A matrix
		if(mat[i][j]!=0)
			{
			c++;
			a[c][0]=i+1;
			a[c][1]=j+1;
			a[c][2]=mat[i][j];
			}
		}
	}
	//for the first row of A
	a[0][0]=n;
	a[0][1]=n;
	a[0][2]=c;
	printf("\narray A--->\n");
	for(i=0;i<=c;i++)
	{
		for(j=0;j<3;j++)
		printf("\t%d",a[i][j]);
		printf("\n");
	}
	//swap col 1 and 2 and store into B
	for(i=1;i<=c;i++)
	{
		for(j=0;j<3;j++)
		{
			b[i][0]=a[i][1];
			b[i][1]=a[i][0];
			b[i][2]=a[i][2];
		}
	}
	b[0][0]=n;
	b[0][1]=n;
	b[0][2]=c;
	printf("\narray B--->\n");
	for(i=0;i<=c;i++)
	{
		for(j=0;j<3;j++)
		printf("\t%d",b[i][j]);
		printf("\n");
	}
	for(i=1;i<c;i++)
	{
		for(j=1;j<c;j++)
		{
			if(b[j][0]>b[j+1][0])
			{
				t=b[j][0];
				b[j][0]=b[j+1][0];
				b[j+1][0]=t;
				
				t=b[j][1];
				b[j][1]=b[j+1][1];
				b[j+1][1]=t;
				
				t=b[j][2];
				b[j][2]=b[j+1][2];
				b[j+1][2]=t;
				
			}
			else if(b[j][0]==b[j+1][0])
			{
				if(b[j][1]>b[j+1][1])
				{
				t=b[j][1];
				b[j][1]=b[j+1][1];
				b[j+1][1]=t;
				
				t=b[j][2];
				b[j][2]=b[j+1][2];
				b[j+1][2]=t;	
				}
				
			}
		}
	}
	
	printf("\narray B--->\n");
	for(i=0;i<=c;i++)
	{
		for(j=0;j<3;j++)
		printf("\t%d",b[i][j]);
		printf("\n");
	}
}
