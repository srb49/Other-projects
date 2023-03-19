/* component of graph using dfs */
#include<stdio.h>
#include<stdlib.h>
int top=-1;
int stk[100];
int visit[100];
	/*visit is an array to check all vertices are visited or not*/
void push(int e,int n)
{
	if(top<n-1)
	{
		top++;
		stk[top]=e;
	}
	/*printf("\npushed element is %d",e);*/
}
pop()
{
	int p;
	if(top!=-1)
	{
		p=stk[top];
		top--;
	}
	else
	p=-1;
	/*printf("\npopped element is %d ",p);*/
	return p;
	
}
/*void display()
{
	int i;
	printf("\nthe stack is displayed below\n");
	for(i=0;i<=top;i++)
	{
		printf("\t%d",stk[i]);
	}
}*/
int check(int v[],int n)
{
	int i,f=1;
	for(i=0;i<n;i++)
	{
		if(v[i]==0)
		{
			f=0;
			break;
		}
	}
	if(f==0)
	return 1; /*we return 1 to continue the loop...f=0 indicates all vertices are not yet visited*/
	else
	return 0; /*return 0 if we want to terminate the loop*/
}
dfs(int b[100][100],int ip,int nv)
{
	int flag=1,flag2;
	int i,k=0,j;
	int op[100];/*op is for output*/
	visit[ip]=1;
	i=ip;
	push(i,nv);
	op[k]=i;
	k++;
	
	while(flag==check(visit,nv))
	{
		flag2=1;
		for(j=0;j<nv;j++)
		{
			if(b[i][j]==1&&visit[j]==0)/*it checks if the node is connected and is non-visited */
			{
				b[i][j]=0;
				b[j][i]=0;
				visit[j]=1;
				i=j;
				push(j,nv);
				op[k]=j;
				k++;
				flag2=0;
				break;
			}
		}
		if(flag2==1)
		i=pop();	/*element is popped from the stack to  */
		if(top==-1)
		break;
	}
	printf("\nthe dfs is----->\n");
	for(i=0;i<k;i++)
	printf("\t%d",op[i]+1);	
}
void main()
{
	
	/*a is main adjacency matrix */
	
	int a[100][100];
/*v1,v2 are the pair of vertices(temporary) */
/*ne number of edge, nv number of vertices*/
/*i,j,k,m are index values*/
	int v1,v2,i,j,m,ne,nv,k=0;

	int ip,flag;
	/*ip is the input vertex*/

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
		}
	}
	
	for(i=0;i<ne;i++)
	{
		printf("\nvertices for edge number %d",i+1);
		printf("\nenter v1");
		scanf("%d",&v1);
		printf("\nenter v2");
		scanf("%d",&v2);
		a[v1-1][v2-1]=1;
		a[v2-1][v1-1]=1;
	
	}
	
	/*initially visit[i]=0 */
	for(i=0;i<nv;i++)
	visit[i]=0;
	
	printf("\nenter the input vertex");
	scanf("%d",&ip);
	while(flag==check(visit,nv))
	{
	
		for(i=0;i<nv;i++)
		{
			if(visit[i]==0)
			break;
		}	
		ip=i;
		k++;
		dfs(a,ip,nv);
	}
	printf("\nthe number of components of the graph is %d",k);
	

}
