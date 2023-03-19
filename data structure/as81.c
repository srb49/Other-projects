#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int key,bf;
	struct node *lc,*rc;
};
node* rorate(node p,int t)
{
	
}
node* insert(node p,int n,int *hb)
{
	int root;
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
		root->key=n;
		root->bf=0;
		root->lc=NULL;
		root->rc=NULL;
		*hb=0;
		p=root;
	}
	else if(p->key>n)
	{
		p->lc=insert(p->lc,n,&hb);
		if(*hb==0)
		{
			switch(p->bf)
			{
				case 1:p=rotate(p,0);
						hb=1;
						break;
				case 0: p->bf=1;
						hb=0;
						break;
				case -1:p->bf=0;
						hb=0;
						break;
			}
		}
	}
	else if(p->key<n)
	{
		p->rc=insert(p->rc,n,&hb);
		if(*hb==0)
		{
			switch(p->bf==0)
			{
				case 1: p->bf=0;
						hb=0;
						break;
				case 0: p->bf=-1;
						hb=0;
						break;
				case -1:p=rorate(p,1);
						hb=0;
						break;
			}
		}
	}
	return p;
}
void main()
{
	int op,i,j,k,e;
	int flag=1;
	struct node root=NULL;
	for(;;)
	{
		printf("1 insert 2 delete 3 break");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
					printf("\nenter the element to be inserted");
					scanf("%d",&e);
					root=insert(root,e,&flag);
					break;
			case 2:
				break;
			case 3:exit(1);				
		}
		
	}
	inorder(root);
}
