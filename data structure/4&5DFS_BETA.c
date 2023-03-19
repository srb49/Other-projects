/*Depth First Search for a[n] [un]directed and unweighted graph*/

#include<stdio.h>
#define size 10

int vn,gtype,adj[size][size],dfs_num[size][2],count1=1,count2=1;
int te[2][size],c1=0,fe[2][size],c2=0,be[2][size],c3=0,ce[2][size],c4=0;
int comp;

void input() /*read the graph*/
{
	int max_en,i,j,v1,v2;
	printf("Enter the number of vertices: ");
	scanf("%d",&vn);
	printf("Enter the type of the graph (0 for Undirected, 1 for Directed): ");
	scanf("%d",&gtype);
	
	/*setting maximum no. of edges*/
	max_en=vn*(vn-1);
	if(gtype==0)
		max_en/=2;
	
	printf("Enter the edges in the form\nsource_vertex_no destination_vertex_no\nand put a vertex as -1 to stop\n");
	for(i=0;i<vn;i++)
		for(j=0;j<vn;j++)
			adj[i][j]=0; /*clearing the matrix*/
	
	for(i=0;i<max_en;i++)
	{	
		printf("Enter vertices for edge %d: ",i);
		scanf("%d%d",&v1,&v2);
		if(v1<0||v2<0)
			break;
		if(v1>=vn||v2>=vn)
		{
			printf("Invalid input\n");
			i--;
			continue;
		}
		if(!adj[v1][v2])
		{
			adj[v1][v2]=1;
			if(gtype==0)
				adj[v2][v1]=adj[v1][v2];
		}
		else
		{
			printf("Redundant input, cannot create parallel edge, try again\n");
			i--;
		}
	}
}

void DFS_visit(int v) /*recursive DFS function*/
{
	int i;
	dfs_num[v][0]=count1++; /*setting DFS visit no.*/
	for(i=0;i<vn;i++)
		if(dfs_num[i][0]==0 && adj[v][i]==1)
		{
			te[0][c1]=v; /*setting*/
			te[1][c1]=i; /*tree edges*/
			c1++; /*increment counter for tree egde array*/
			DFS_visit(i);
		}
	dfs_num[v][1]=count2++; /*setting DFS completion no.*/
}
void DFS()
{
	int i,v;
	for(i=0;i<vn;i++)
		dfs_num[i][0]=dfs_num[i][1]=0;
	printf("Enter a vertex to start DFS: ");
	scanf("%d",&v);
	comp=1; /*setting component = 1*/
	DFS_visit(v);
	for(i=0;i<vn;i++)
		if(dfs_num[i][0]==0)
		{
			comp++; /*counting components*/
			DFS_visit(i);
		}
}

void main()
{
	int i,j;
	system("clear");
	
	/*get the graph*/
	input();
	
	/*do DFS*/
	DFS();
	
	/*setting other edges*/
	for(i=0;i<vn;i++)
		for(j=0;j<vn;j++)
		{
			if(adj[i][j]==1)
			{
				//printf("%d %d\n",i,j);
				if(dfs_num[i][0]<dfs_num[j][0] && dfs_num[i][1]>dfs_num[j][1])
				{
					fe[0][c2]=i; /*setting*/
					fe[1][c2]=j; /*forward edges*/
					c2++;
				}
				else if(dfs_num[i][0]>dfs_num[j][0] && dfs_num[i][1]<dfs_num[j][1])
				{
					be[0][c3]=i; /*setting*/
					be[1][c3]=j; /*backward edges*/
					c3++;
				}
				else
				{
					ce[0][c4]=i; /*setting*/
					ce[1][c4]=j; /*cross edges*/
					c4++;
				}
			}
		}
	
	/*diplay aquired information*/
	for(i=0;i<vn;i++)
		printf("For vertex %d DFS# = %d and DFScompletion# = %d\n",i,dfs_num[i][0],dfs_num[i][1]);
	printf("The number of component(s) is: %d\n",comp);
	
	printf("\nThe Tree edges are:\n");
	for(i=0;i<c1;i++)
		printf("(%d,%d)\t",te[0][i],te[1][i]);
	printf("\nThe Fordard edges are:\n");
	for(i=0;i<c2;i++)
		{
			if(fe[0][i]==te[0][i] && fe[1][i]==te[1][i])
				continue;
			printf("(%d,%d)\t",fe[0][i],fe[1][i]);
		}
	printf("\nThe Back edges are:\n");
	for(i=0;i<c3;i++)
		printf("(%d,%d)\t",be[0][i],be[1][i]);
	if(gtype==1) /*for directed*/
	{
		printf("\nThe Cross edges are:\n");
		for(i=0;i<c4;i++)
			printf("(%d,%d)\t",ce[0][i],ce[1][i]);
	}
}
