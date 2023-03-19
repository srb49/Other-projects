/*heap sort*/
#include<stdio.h>
#include<stdlib.h>
int *harr,*narr;
void create(int i)
{
	int j,t;
	j=i/2;
	if(j==0)
	return;
	else
	{
		if(harr[i-1]>harr[j-1])
		{
			t=harr[i-1];
			harr[i-1]=harr[j-1];
			harr[j-1]=t;
		if((j-1)!=0)
		create(j);
		}
	}
}
void swap(i,j)
{
	int t;
	t=harr[i];
	harr[i]=harr[j];
	harr[j]=t;
}
void adjst(int i,int n)
{
	int j1,j2,t;
	j1=2*i+1;
	j2=2*i+2;
	if(j1>n-1)
	return;
	else if(j1==n-1)
	{
		if(harr[i]<harr[j1])
		{
			swap(i,j1);
			return;
		}
	}
	else
	{
		if(harr[j1]>harr[j2])
		{
			swap(i,j1);
			adjst(j1,n);
		}
		else
		{
			swap(i,j2);
			adjst(j2,n);
		}
	}
}

void main()
{
	int op,n,i,j,k,e,m;
	
	printf("\nenter number of elements-->");
	scanf("%d",&n);
	harr=(int*)malloc(n*sizeof(int));
	printf("\nenter the elements-->");
	
	/*max heap generation*/
	for(i=0;i<n;i++)
	{
	printf("enter");
	scanf("%d",&harr[i]);
	}
	for(i=1;i<=n;i++)
	create(i);
	
	
	/*displaying heap*/
	printf("\nthe generated heap is--->");
		
	for(i=0;i<n;i++)
		{
		j=(i+1)*2-1;
		k=(i+1)*2;
		printf("\n%d -> %d,%d",harr[i],harr[j],harr[k]);
		if(j==(n-1)||k==(n-1))
		break;
		}

	/*heap sort*/
	m=n;
	narr=(int*)malloc(n*sizeof(int));
	for(i=n-1;i>=0;i--)
	{
		narr[i]=harr[0];
		harr[0]=harr[n-1];
		printf("\n%d   %d",narr[i],harr[0]);
		n=n-1;
		adjst(0,n);
	}
	
	printf("\nsorted array is--->\n");
	for(i=0;i<m;i++)
	printf("\t%d",narr[i]);
	
}
