//assignment 1
//directed and unweighted
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
	
	/*initially assigning all the elements of adjacency maatrix 0*/
	
	for(i=0;i<nv;i++)
	{
		for(j=0;j<nv;j++)
		{
				a[i][j]=0;			
		}
	}
	
	/*assigning 1 to the cell of adjacency matrix where there is a edge between a pair of vertices*/
	for(i=1;i<=ne;i++)
	{
		printf("\nfor edge number %d",i);
		printf("\nenter tail vertex");
		scanf("%d",&v1);
		printf("\nenter head vertex");
		scanf("%d",&v2);
		a[v1-1][v2-1]=1;
	}
	/*printing the adjacency matrix*/
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
