/*multiplication*/
#include<stdio.h>
void main()
{
	int arr[2][100],crr[2][100],brr[100];
	int af,al,bf,bl,cf,cl;
	int i,j,k,na,nb,nc;
	int p1,p2,p=0;
	//printf("\nenter af");
	//scanf("%d",&af);
	printf("\nenter al");
	scanf("%d",&al);
	//printf("\nenter bf");
	//scanf("%d",&bf);
	printf("\nenter bl");
	scanf("%d",&bl);
	printf("\nfor array A");
	for(i=0;i<=al;i++)
	{
		printf("\nenter the coeff");
		scanf("%d",&arr[0][i]);
		printf("\nenter the exp");
		scanf("%d",&arr[1][i]);
	}
	printf("\n\nfor array B");
	for(;i<=bl;i++)
	{
		printf("\nenter the coeff");
		scanf("%d",&arr[0][i]);
		printf("\nenter the exp");
		scanf("%d",&arr[1][i]);
	}
	printf("array arr\n");
	for(j=0;j<2;j++)
	{
		for(k=0;k<i;k++)
		{
			printf("\t%d",arr[j][k]);
		}
		printf("\n");
	}
	printf("\narray brr\n");
	cf=bl+1;
	cl=bl+1;
	for(j=0;j<=al;j++)
	{
	for(k=al+1;k<=bl;k++)
	  {
		arr[0][cl]=arr[0][j]*arr[0][k];
		arr[1][cl]=arr[1][k]+arr[1][j];
	   cl++;
       	  }
	}

	for(i=cf;i<cl;i++)
	{
	brr[i]=0;
	crr[0][i]=0;
	crr[1][i]=0;
	}
	printf("\nfinal array crr\n");
	for(j=0;j<2;j++)
	{
		for(k=cf;k<cl;k++)
		{
			printf("\t%d",arr[j][k]);
		}
		printf("\n");
	}
	for(i=cf;i<cl;i++)
	{
		for(j=i+1;j<cl;j++)
		{
			if(arr[1][i]==arr[1][j])
			{
				arr[0][i]+=arr[0][j];
				brr[j]++;
			}
		}
	}
	p=0;
	for(i=cf;i<cl;i++)
	{
		if(brr[i]==0)
		{
			crr[0][p]=arr[0][i];
			crr[1][p]=arr[1][i];
			p++;
		}
	}
	printf("\nnfinal array crr\n");
	for(j=0;j<2;j++)
	{
		for(k=0;k<p;k++)
		{
			printf("\t%d",crr[j][k]);
		}
		printf("\n");
	}
	
}

