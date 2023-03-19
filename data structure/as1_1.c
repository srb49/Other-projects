//assignment 1
//undirected and unweighted
#include<stdio.h>
void main()
{
	int a[100][100],nv,ne,v1,v2; /*a is adjacency matrix,nv number of vertices,ne numberpf edges,v1 & v2 pair of vertices connected through an edge*/ 
	int i,j; /* i,j are index variable*/ 
	printf("\nenter the number of vertices");
	scanf("%d",&nv);
	printf("\nenter the number of edges");
	scanf("%d",&ne);
	/*accepting the vertices connected via edges and creating the adjacency matrix*/
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
		a[v1-1][v2-1]=1;
		a[v2-1][v1-1]=1;
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
}
