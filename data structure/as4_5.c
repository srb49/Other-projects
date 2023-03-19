/* dfs 
different edges for directed graph*/
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
void pop()
{
	int p;
	if(top!=-1)
		top--;	
}

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
	
	int d_n[100],d_cn[100],dn=0,dcn=0;   /*d_n[] is an array for storing dfs number of each vertices 
	and d_cn[] is an array for storing dfs completion number of each vertices*/
	int te[2][100],fe[2][100],be[2][100],ce[2][100];/*te :tree edge, fe:forward edge, be:back edge, ce:cross edge*/
	int c1=0,c2=0,c3=0,c4=0,c=0; /*c,c1,c2,c3,c4 counter variables*/
	
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
	dn++;
	d_n[i]=dn;
	/*dfs*/
	while(flag==check(visit,nv))
	{
		flag2=1;
		for(j=0;j<nv;j++)
		{
			if(b[i][j]==1&&visit[j]==0)/*it checks if the node is connected and is non-visited */
			{
				b[i][j]=0;
				/*setting dfs number of an edge*/
			
				dn++;
				d_n[j]=dn;
			
				
				/*setting tree edges*/
				te[0][c]=i;
				te[1][c]=j;
				c++;
				
				
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
		{
			/*element is popped from the stack to  */
		/*dfs completion number of an edge*/
		dcn++;
		d_cn[i]=dcn;
	
		pop();	
		i=stk[top];
			
		}
	}
	
	/*popping rest of the element to calculate dfs completion number*/
	while(top>-1)
	{
		dcn++;
		d_cn[i]=dcn;	
		
		pop();	/*element is popped from the stack to  */
		i=stk[top];
		/*dfs completion number of an edge*/
		
	}
	/*setting different edges*/
		for(i=0;i<nv;i++)
		for(j=0;j<nv;j++)
		{
			if(a[i][j]==1)
			{
				//printf("%d %d\n",i,j);
				if(d_n[i]<d_n[j] && d_cn[i]>d_cn[j])
				{
					fe[0][c2]=i; /*setting*/
					fe[1][c2]=j; /*forward edges*/
					c2++;
				}
				else if(d_n[i]>d_n[j] && d_cn[i]<d_cn[j])
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
	
	printf("\nthe dfs is----->\n");
	for(i=0;i<k;i++)
	printf("\t%d",op[i]+1);	
	printf("\n\ndfs# of different vertices-->\n");
	for(i=0;i<nv;i++)
	printf("%d-->%d\n",i+1,d_n[i]);

	printf("\n\ndfs completion# of different vertices-->\n");
	for(i=0;i<nv;i++)
	printf("%d-->%d\n",i+1,d_cn[i]);


	printf("\nThe Tree edges are:\n");
	for(i=0;i<c;i++)
		printf("(%d,%d)\t",te[0][i]+1,te[1][i]+1);
	
	printf("\nThe Fordard edges are:\n");
	for(i=0;i<c2;i++)
		{
			for(j=0;j<c;j++)
			if(fe[0][i]==te[0][j] && fe[1][i]==te[1][j])
				break;
		if(j==c)
			printf("(%d,%d)\t",fe[0][i]+1,fe[1][i]+1);
		}
	
	printf("\nThe Back edges are:\n");
	for(i=0;i<c3;i++)
	printf("(%d,%d)\t",be[0][i]+1,be[1][i]+1);
	
	printf("\nThe Cross edges are:\n");
		for(i=0;i<c4;i++)
		printf("(%d,%d)\t",ce[0][i]+1,ce[1][i]+1);
	

}
