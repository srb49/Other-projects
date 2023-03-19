/*bfs for undirected graph*/
#include<stdio.h>
int qu[100],f=-1,r=-1;
int q_i(int e)
{
	int i,flag=0;
	if(f==-1 && r==-1)
	{
	f++;
	r++;
	qu[r]=e;
	}
	else
	{
	for(i=f;i<=r;i++)
		if(e==qu[i])
		{
		flag=1;
		break;
		}
	if(flag ==0)
	  {
	  r++;
	  qu[r]=e;
	  }
	}	
}
int q_d()
{
	int i=qu[f];
	f++;

	return(i);
}
void main()
{
	/*a is main adjacency matrix, b is replica of a but we modify this matrix later
	c is an array and matrix d are used to create the bfs tree*/
	int a[100][100],b[100][100],op[100],c[100],d[100][100];
/*v1,v2 are the pair of vertices(temporary) */
/*ne number of edge, nv number of vertices*/
	int v1,v2,i,j,ne,nv,k,m=0;
/*i,j are index values*/
	printf("\nenter the number of vertices");
	scanf("%d",&nv);
	printf("\nenter the number of edge");
	scanf("%d",&ne);
/*initialising the adjacency matrix as 0 initially*/
	for(i=0;i<nv;i++)
	{
		for(j=0;j<=i;j++)
		{
			a[i][j]=0;
			a[j][i]=0;
			
			b[i][j]=0;
			b[j][i]=0;
			
			d[i][j]=0;
			d[j][i]=0;
		}
	}
	/*c is intialised 0 at first,later gets modified for each visited vertex*/
	for(i=0;i<nv;i++)
	c[i]=0;
	for(i=0;i<ne;i++)
	{
		printf("\nenter v1");
		scanf("%d",&v1);
		printf("\nenter v2");
		scanf("%d",&v2);
		a[v1-1][v2-1]=1;
		a[v2-1][v1-1]=1;
		b[v1-1][v2-1]=1;
		b[v2-1][v1-1]=1;
	}
	printf("\nenter the starting vertex");
	scanf("%d",&k);
	k--;
	q_i(k);
	c[k]=1;
	while(f<=r)
	{
		for(j=0;j<nv;j++)
		{
			if(b[k][j]==1)
			{
			b[j][k]=0;
			q_i(j);
			
			
				if(c[j]==0)
				{
					d[k][j]=1;
					c[j]=1;
				}

			}
		}
	op[m]=q_d();
	m++;
	k=qu[f];	
	}
	
	printf("\nthe output of bfs-->\n");
	for(i=0;i<m;i++)
	printf("\t%d",op[i]+1);
	printf("\nthe bfs tree is shown");
	for(i=0;i<nv;i++)
	{
		for(j=0;j<nv;j++)
		{
			if(d[i][j]==1)
			printf("\n%d  ->  %d",i+1,j+1);
		}
		printf("\n");
	}
}

