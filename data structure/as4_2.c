/* dfs for directed graph*/
#include<stdio.h>
#include<stdlib.h>
int top=-1;
int stk[100];
void push(int e,int n)
{
	if(top<n-1)
	{
		top++;
		stk[top]=e;
	}
}
pop()
{
	int p;
	if(top!=-1)
	{
		p=stk[top];
		top--;
	}
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
void main()
{
	
	/*a is main adjacency matrix, b is replica of a but we modify this matrix later*/
	
	int a[100][100],b[100][100],op[100];/*op is for output*/
/*v1,v2 are the pair of vertices(temporary) */
/*ne number of edge, nv number of vertices*/
/*i,j,k,m are index values*/
	int v1,v2,i,j,m,ne,nv,k=0;

	int ip,visit[100],flag=1,flag2;
	/*ip is the input vertex*/
	/*visit is an array to check all vertices are visited or not*/
	/*flag is set to 0 if all vertices are visited  */
	
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
		}
	}
	
	for(i=0;i<ne;i++)
	{
		printf("\nvertices for edge number %d",i+1);
		printf("\nenter tail vertex");
		scanf("%d",&v1);
		printf("\nenter head vertex");
		scanf("%d",&v2);
		a[v1-1][v2-1]=1;
		b[v1-1][v2-1]=1;
	}
	for(i=0;i<nv;i++)
	{
		for(j=0;j<nv;j++)
		{
			printf("\t%d",a[i][j]);
		}
		printf("\n");
	}
	/*initially visit[i]=0 */
	for(i=0;i<nv;i++)
	visit[i]=0;
	
	printf("\nenter the input vertex");
	scanf("%d",&ip);
	visit[ip-1]=1;
	i=ip-1;
	push(i,nv);
	op[k]=i;
	k++;
	/*dfs*/
	while(flag==check(visit,nv))
	{
		flag2=1;
		for(j=0;j<nv;j++)
		{
			if(b[i][j]==1&&visit[j]==0)/*it checks if the node is connected and is non-visited */
			{
				b[i][j]=0;
	
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
		i=pop();	/*element is popped from the stack IF the current node is not connected to a non visited node  */
	
	}
	printf("\nthe dfs is----->\n");
	for(i=0;i<k;i++)
	printf("\t%d",op[i]+1);	
}
