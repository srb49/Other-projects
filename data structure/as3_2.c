//unditected weighted
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct list
{
	int data;
	int eg;
	struct list *next;
};

struct list *head=NULL;
struct list *curr=NULL;
void main()
{
	struct list *new_n;
	int ch=1,dt,i,j;
	int nv,a[100][100];
	int ne,v1,v2,w;
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
		printf("\nenter vertex 1");
		scanf("%d",&v1);
		printf("\nenter vertex 2");
		scanf("%d",&v2);
		printf("\nenter the weight");
		scanf("%d",&w);
		a[v1-1][v2-1]=w;
		a[v2-1][v1-1]=w;
		
	}
	
	for(i=0;i<nv;i++)
	{
		al[i]=(struct list*)malloc(sizeof(struct list));
		al[i]->data=i+1;
		al[i]->next=NULL;
		for(j=0;j<nv;j++)
		{
			if(a[i][j]!=0)
			{
				new_n=(struct list*)malloc(sizeof(struct list));
				new_n->data=j+1;
				new_n->eg=a[i][j];
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
				curr->next=NULL;	
				}	
			}
			
		}
	}
	for(i=0;i<nv;i++)
	{
		printf("\t%d",al[i]->data);
		curr=al[i]->next;
		while(curr!=NULL)
		{
		printf("\t\t%d",curr->data);
		printf("|%d",curr->eg);
		curr=curr->next;
		}
		printf("\n");
	}
	
}

