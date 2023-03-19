//ditected unweighted
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct list
{
	int data;
	struct list *next;
};
struct list *head=NULL;
struct list *curr=NULL;
void main()
{
	struct list *new_n;
	int ch=1,dt,i,j,nv,ne,v1,v2;
	int a[100][100];
	
	struct list *al[100];
	printf("\nenter number of vertices\n");
	scanf("%d",&nv);	
	printf("\nenter the number of edges");
	scanf("%d",&ne);
	for(i=0;i<nv;i++)
	{
		for(j=0;j<=i;j++)
		{
				a[i][j]=0;
				a[j][i]=0;
		}
	}
	for(i=1;i<=ne;i++)
	{
		printf("\nfor edge number %d",i);
		printf("\nenter tail vertex");
		scanf("%d",&v1);
		printf("\nenter head vertex");
		scanf("%d",&v2);
		a[v1-1][v2-1]=1;
	}	
	printf("\nthe adjacency matrix of undirected unweighted graph\n");
	for(i=0;i<nv;i++)
	{
		for(j=0;j<nv;j++)
		{
			printf("\t%d",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<nv;i++)
	{
		al[i]=(struct list*)malloc(sizeof(struct list));
		al[i]->data=i+1;
		al[i]->next=NULL;
		for(j=0;j<nv;j++)
		{
			if(a[i][j]==1)
			{
				new_n=(struct list*)malloc(sizeof(struct list));
				new_n->data=j+1;
				new_n->next=NULL;
				if(al[i]->next==NULL)
				{
				al[i]->next=new_n;	
				curr=new_n;
				}
				else
				{
				curr->next=new_n;
				curr=new_n;
				}
				curr->next=NULL;		
			}
		}
	}
	printf("\nadjacency list---->\n");
	for(i=0;i<nv;i++)
	{
		printf("\t%d",al[i]->data);
		curr=al[i]->next;
		while(curr!=NULL)
		{
		printf("\t\t%d",curr->data);
		curr=curr->next;
		}
		printf("\n");
	}
}

