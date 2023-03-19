/*heap create, insert , delete, show
this heap is generated on the basis of max heap */
#include<stdio.h>
#include<stdlib.h>
int *harr;
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
	int op,n,i,j,k,e;
	
	/**/
	for(;;)
	{
		printf("\nenter 1 to create 2 insert 3 to delete 4 show 5 to break");
		scanf("%d",&op);
		switch(op)
		{
		case 1:
			printf("\nenter number of elements-->");
			scanf("%d",&n);
			harr=(int*)malloc(n*sizeof(int));
			printf("\nenter the elements-->");
			for(i=0;i<n;i++)
			{
				printf("enter");
				scanf("%d",&harr[i]);
			}
			for(i=1;i<=n;i++)
			create(i);
			break;
		case 2: 
				printf("\ninsert the element");
				scanf("%d",&e);
				create(n+1);
				break;
		case 3: printf("\nenter the element");
				scanf("%d",&e);
				for(i=0;i<n;i++)
				{
					if(harr[i]==e)
					break;
				}
				if(i==n)
				printf("element not found");
				else
				{
					harr[i]=harr[n-1];
					n=n-1;
					adjst(i,n);
				}
				break;
		case 4: for(i=0;i<n;i++)
				{
					j=(i+1)*2-1;
					k=(i+1)*2;
					if(j==(n-1))
					{
						printf("\n%d -> %d",harr[i],harr[j]);
						break;
					}
					else if(k==(n-1))
					{
						printf("\n%d -> %d,%d",harr[i],harr[j],harr[k]);
						break;
					}
					else
					printf("\n%d -> %d,%d",harr[i],harr[j],harr[k]);
				}
				break;
		case 5: exit(1);	
		}
	}
}
