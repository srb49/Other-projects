//assignment 2-incidence matrix
//directed and weighted
#include<stdio.h>
void main()
{
	int a[100][100],nv,ne,v1,v2; /*a is adjacency matrix,nv number of vertices,ne numberpf edges,v1 & v2 pair of vertices connected through an edge*/ 
	int i,j,w; /* i,j are index variable*/ 
	printf("\nenter the number of vertices");
	scanf("%d",&nv);
	printf("\nenter the number of edges");
	scanf("%d",&ne);
	/*accepting the vertices connected via edges and creating the adjacency matrix*/
	for(i=0;i<nv;i++)
	{
		for(j=0;j<ne;j++)
		{
			a[i][j]=0;
		}
	}
	for(i=0;i<ne;i++)
	{
		printf("\nfor edge number %d",i+1);
		printf("\nenter tail vertex");
		scanf("%d",&v1);
		printf("\nenter head vertex");
		scanf("%d",&v2);
		printf("\nenter weight");
		scanf("%d",&w);
		a[v1-1][i]=-w;
		a[v2-1][i]=w;
	}
	printf("\nthe incidence matrix of undirected unweighted graph\n");
	for(i=0;i<nv;i++)
	{
		for(j=0;j<ne;j++)
		{
			printf("\t%d",a[i][j]);
		}
		printf("\n");
	}
}
