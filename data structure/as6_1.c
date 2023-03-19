/*addition of plynomial*/
#include<stdio.h>
void main()
{
	int arr[2][100],brr[100];/*arr is the polynomial array where A B and resultant C is stored,brr is a temporary array*/
	int af,al,bf,bl,cf,cl;/*af,bf,cf are staring index of A,B,C respectively,af=0,al,bl,cl are the last index of A,B,C*/
	int i,j,k;/*i,j,k are index variable*/
	printf("\nenter al");
	scanf("%d",&al);
	bf=al+1;
	scanf("%d",&bl);
	printf("\nfor array A");
	/*entering the elements of array A*/
	for(i=0;i<=al;i++)
	{
		printf("\nenter the coeff");
		scanf("%d",&arr[0][i]);
		printf("\nenter the exp");
		scanf("%d",&arr[1][i]);
	}
	printf("\n\nfor array B");
	/*entering array B*/
	for(;i<=bl;i++)
	{
		printf("\nenter the coeff");
		scanf("%d",&arr[0][i]);
		printf("\nenter the exp");
		scanf("%d",&arr[1][i]);
	}
	printf("array A and B\n");
	/*printing array A and B*/
	for(j=0;j<2;j++)
	{
		for(k=0;k<i;k++)
		{
			printf("\t%d",arr[j][k]);
		}
		printf("\n");
	}
	printf("\narray brr\n");
	/*brr is tacken for an index matrix-those index of array A and B which did not have similar exponent were marked 0 by array brr*/
	for(i=0;i<=bl;i++)
	{
	brr[i]=0;
	}
	cf=bl+1;
	cl=bl+1;
	/*computing the addition operation*/
	for(j=0;j<=al;j++)/*it checks if the exponant of A matches with that of B*/
	{
		for(k=al+1;k<=bl;k++)
		{
		if(arr[1][j]==arr[1][k])/*if the exponant of A matches with that of B the coefficients of them are added and stored in C*/
		{
		arr[0][cl]=arr[0][j]+arr[0][k];
		arr[1][cl]=arr[1][j];
		brr[j]++;/*accordingly those indices of brr is increased*/
		brr[k]++;
		cl++;
		}
		}
	}
/*addition for unmatched exponants*/
	for(i=0;i<=bl;i++)
	{
		if(brr[i]==0)
		{
		arr[0][cl]=arr[0][i];
		arr[1][cl]=arr[1][i];
		cl++;
		}
	}
/*printing all the array -the final polynomial arr*/
	printf("\nfinal array arr\n");
	for(j=0;j<2;j++)
	{
		for(k=0;k<cl;k++)
		{
			printf("  %d",arr[j][k]);
		}
		printf("\n");
	}
}

