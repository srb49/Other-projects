/*differentiation*/
#include<stdio.h>
void main()
{
	int arr[2][100],a[2][100];/*array A is arr and array A after differentiation*/
	int af,al;/*af is starting index of A,af is considered 0,al is the last index of A*/
	int i,j,k;/*i,j,k are index value*/
	printf("\nenter al");
	scanf("%d",&al);
	printf("\nenter array A");
	/*entering the values A*/
	for(i=0;i<=al;i++)
	{
		printf("\nenter the coeff");
		scanf("%d",&arr[0][i]);
		printf("\nenter the exp");
		scanf("%d",&arr[1][i]);
	}
	printf("\n array A");
	/*printing the elements of A*/
	for(j=0;j<2;j++)
	{
		for(k=0;k<=al;k++)
		{
			printf("\t%d",arr[j][k]);
		}
		printf("\n");
	}
	/*differentiation of A*/
	for(i=0;i<=al;i++)
	{
		if(arr[1][i]!=0)/*for variable terms*/
		{
		a[0][i]=arr[0][i]*arr[1][i];
		a[1][i]=arr[1][i]-1;
		}
		else /*for constant terms*/
		{
		a[0][i]=0;
		}
	}
	printf("\narray A after differentiation\n");
	/*printg the differentiated values*/
	for(j=0;j<2;j++)
	{
		for(k=0;k<=al;k++)
		{
			printf("\t%d",a[j][k]);
		}
		printf("\n");
	}
	
}

