/*sparse matrix*/
#include<stdio.h>
void main()
{
	int sp[100][100],a[100][3],b[100][3]; 	/*sp is the sparse matrix*/
	/*in matrix a sparse matrix is stored in such a way the storage space is not wasted very much */
/*b matrix is same as a but it stores the transposed elements of sp*/
	int i,j,n,m,c=0,t;	/*n is row number and m is the column number of sparse matrix,
i, and j are the index value,
c number of elememnts in sp matrix*/
	printf("\nsparse matrix\n");
	printf("\nenter n\n");
	scanf("%d",&n);
	printf("\nenter m\n");
	scanf("%d",&m);
	/*taking input to sp and creating a*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
		printf("\na[%d][%d]=",i,j);
		scanf("%d",&sp[i][j]);
			if(sp[i][j]!=0)
			{
			c++;
			a[c][0]=i+1;
			a[c][1]=j+1;
			a[c][2]=sp[i][j];
			}
		}
	}
	/*to form matrix a*/
	a[0][0]=n;
	a[0][1]=m;
	a[0][2]=c;
	/*printing matrix a*/
	printf("\ndisplaying matrix a\n");
	for(i=0;i<=c;i++)
	{
		for(j=0;j<3;j++)
		{
		printf("\t%d",a[i][j]);
		}
	printf("\n");
	}
	/*creating the matrix b swaping the column 1 and 2 of matrix a*/
	for(i=1;i<=c;i++)
	{
		for(j=0;j<3;j++)
		{
		 b[i][0]=a[i][1];
		 b[i][1]=a[i][0];
		 b[i][2]=a[i][2];
		}
	printf("\n");
	}
	b[0][0]=n;
	b[0][1]=n;
	b[0][2]=c;
	/*sorting the elements of matrix b*/
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
	/*showing the matrix b*/
	printf("\ndisplaying matrix b\n");
	for(i=0;i<=c;i++)
	{
		for(j=0;j<3;j++)
		{
		printf("\t%d",b[i][j]);
		}
	printf("\n");
	}
}

