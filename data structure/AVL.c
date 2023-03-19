#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *lchild,*rchild;
	int bf;
}node;

node *rotate(node *parent,int type)
{
	node *child,*gchild;
	if(type) //right rotation
	{
		child=parent->rchild;
		if(child->bf==-1){ //right high, RR case
			parent->rchild=child->lchild;
			child->lchild=parent;
			parent->bf=child->bf=0;
			return child;
		}
		else if(child->bf==0){ //deletion only case
			parent->rchild=child->lchild;
			child->lchild=parent;
			child->bf=1;
			return child;
		}
		else{ //left high, RL case
			gchild=child->lchild;
			parent->rchild=gchild->lchild;
			child->lchild=gchild->rchild;
			gchild->lchild=parent;
			gchild->rchild=child;
			switch(gchild->bf){
				case 1: parent->bf=0;
						child->bf=-1;
						break;
				case 0:	parent->bf=child->bf=0;
						break;
				case -1:parent->bf=1;
						child->bf=0;
			}
			gchild->bf=0;
			return gchild;
		}
	}
	else //left rotation, mirrored case
	{
		child=parent->lchild;
		if(child->bf==1){ //right high, LL case
			parent->lchild=child->rchild;
			child->rchild=parent;
			parent->bf=child->bf=0;
			return child;
		}
		else if(child->bf==0){ //right high, LL case
			parent->lchild=child->rchild;
			child->rchild=parent;
			child->bf=-1;
			return child;
		}
		else{ //left high, LR case
			gchild=child->rchild;
			parent->lchild=gchild->rchild;
			child->rchild=gchild->lchild;
			gchild->rchild=parent;
			gchild->lchild=child;
			switch(gchild->bf){
				case 1: parent->bf=-1;
						child->bf=0;
						break;
				case 0:	parent->bf=child->bf=0;
						break;
				case -1:parent->bf=0;
						child->bf=-1;
			}
			gchild->bf=0;
			return gchild;
		}
	}
}

node *AVLinsert(node *parent,int x,int *hb)
{
	node *n;
	if(parent==NULL){ //inserting into an empty sub-tree
		n=(node*)malloc(sizeof(node));
		*hb=0;
		n->lchild=n->rchild=NULL;
		n->data=x;
		n->bf=0;
		parent=n;
	}
	else if(parent->data > x){ //inserting into left-sub-tree
		parent->lchild=AVLinsert(parent->lchild,x,hb);
		if(*hb==0)
			switch(parent->bf){ //updating balance factor
				case -1:parent->bf=0;
						*hb=1;
						break;
				case 0: parent->bf=1;
						break;
				case 1: parent=rotate(parent,0);
						*hb=1;
		 	}
	}
	else{ //inserting into right-sub-tree
		parent->rchild=AVLinsert(parent->rchild,x,hb);
		if(*hb==0)
			switch(parent->bf){ //updating balance factor
				case 1:  parent->bf=0;
						 *hb=1;
						 break;
				case 0:  parent->bf=-1;
						 break;
				case -1: parent=rotate(parent,1);
						 *hb=1;
			}
	}
	return parent; //returns modified sub-tree
}

node *inorderSUCC(node *p)
{
	p=p->rchild; //next inorder successor will be in right sub-tree
	if(p!=NULL)
		while(p->lchild!=NULL) //traverse to the left most end
			p=p->lchild;
	return p; //p is now the inorder successor
}

/*
node *AVLdelete(node *root,int item)
{
	node *ptr=root,*parent,*temp;
	int flag=0;
	while(ptr!=NULL && !flag)
	{
		if(ptr->data==item)
			flag=1;
		else if(item < ptr->data){
			parent=ptr;
			ptr=ptr->lchild;
		}
		else{
			parent=ptr;
			ptr=ptr->rchild;
		}
	}
	if(!flag){
		printf("ITEM not found");
		return root;
	}
	if(ptr->lchild==NULL && ptr->rchild==NULL){ //CASE 1: target node has no child, i.e. leaf node
		if(root==ptr)
			root=NULL;
		else{
			if(parent->lchild==ptr)
				parent->lchild=NULL;
			else
				parent->rchild=NULL;
		}
		free(ptr);
		return root;
	}
	else if(ptr->lchild==NULL || ptr->rchild==NULL){ //CASE 2: target node has only one child
		if(ptr->lchild==NULL)
			temp=ptr->rchild;
		else
			temp=ptr->lchild;
		if(root==ptr)
			root=temp;
		else{
			if(parent->lchild==ptr)
				parent->lchild=temp;
			else
				parent->rchild=temp;
		}
		free(ptr);
		return root;
	}
	else{ //CASE 3: target node has both left and right child
		temp=inorderSUCC(ptr);
		ptr->data=temp->data;
		ptr->rchild=AVLdelete(ptr->rchild,temp->data);
		return root;
	}
}
*/
node *AVLdelete(node *ptr,node *parent,int x,int *hb)
{
	/*if(ptr)	printf("\nptr %d par %d hb %d",ptr->data,parent->data,*hb);
	else	printf("\nptr -- par %d hb %d",parent->data,*hb);
	*/
	node *temp;
	if(ptr==NULL){ //deleting from an empty sub-tree
		printf("ITEM not found");
	}
	else if(ptr->data > x){ //deleting from left-sub-tree
		ptr->lchild=AVLdelete(ptr->lchild,ptr,x,hb);
		if(*hb==0)
			switch(ptr->bf){ //updating balance factor
				case 1: ptr->bf=0;
						//*hb=1;
						break;
				case 0: ptr->bf=-1;
						*hb=1;
						break;
				case -1:ptr=rotate(ptr,1);
						if(ptr->bf)	*hb=1; //if ptr->bf==1 no further BF adjustment required
		 	}
	}
	else if(ptr->data < x){ //deleting from right-sub-tree
		ptr->rchild=AVLdelete(ptr->rchild,ptr,x,hb);
		if(*hb==0)
			switch(ptr->bf){ //updating balance factor
				case -1:ptr->bf=0;
						//*hb=1;
						break;
				case 0: ptr->bf=1;
						*hb=1;
						break;
				case 1: ptr=rotate(ptr,0);
						if(ptr->bf)	*hb=1; //if ptr->bf==1 no further BF adjustment required
			}
	}
	else{ //ptr->data == x
		*hb=0;
		if(ptr->lchild==NULL && ptr->rchild==NULL){ //CASE 1: target node has no child, i.e. leaf node
			if(parent==ptr)
				parent=NULL;
			else{
				if(parent->lchild==ptr)
					parent->lchild=NULL;
				else
					parent->rchild=NULL;
			}
			free(ptr);
			ptr=NULL;
			//return parent;
		}
		else if(ptr->lchild==NULL || ptr->rchild==NULL){ //CASE 2: target node has only one child
			if(ptr->lchild==NULL)
				temp=ptr->rchild;
			else
				temp=ptr->lchild;
			if(parent==ptr)
				parent=temp;
			else{
				if(parent->lchild==ptr)
					parent->lchild=temp;
				else
					parent->rchild=temp;
			}
			free(ptr);
			ptr=temp;
			//return parent;
		}
		else{ //CASE 3: target node has both left and right child
			temp=inorderSUCC(ptr);
			ptr->data=temp->data;
			*hb=1;
			ptr->rchild=AVLdelete(ptr->rchild,ptr,temp->data,hb);
			//return parent;
			if(*hb==0)
			switch(ptr->bf){ //updating balance factor
				case -1:ptr->bf=0;
						break;
				case 0: ptr->bf=1;
						*hb=1;
						break;
				case 1: ptr=rotate(ptr,0);
						*hb=1;
			}
			//parent=ptr;
		}
	}
	/*if(ptr)	printf("\nptr %d par %d hb %d",ptr->data,parent->data,*hb);
	else	printf("\nptr -- par %d hb %d",parent->data,*hb);
	*/
	return ptr;
}

void inorder(node *root) //Inorder Traversal, recursive
{
	if(root){
		inorder(root->lchild);
		printf(" %d(%d)",root->data,root->bf);
		inorder(root->rchild);
	}
}

void preorder(node *root) //Preorder Traversal, recursive
{
	if(root){
		printf(" %d(%d)",root->data,root->bf);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void main()
{
	int n,ch,flag;
	node *root=NULL;
	while(1)
	{
		flag=1;
		printf("\n\n1. Insert\n2. Delete\n3. Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter a no: ");
				scanf("%d",&n);
				root=AVLinsert(root,n,&flag);
				break;
			case 2:
				printf("\nEnter a no: ");
				scanf("%d",&n);
				root=AVLdelete(root,root,n,&flag);
				break;
			case 3: exit(1);
			default: printf("Wrong Entry!!");continue;
		}
		printf("\nSequences with balance factor");
		printf("\nInorder:");
		inorder(root);
		printf("\nPreorder:");
		preorder(root);
	}
	/*int ins[]={1,26,2,25,3,24,4,23,5,22,6},del[]={1,26,2,25,3,24,4,23,5,22,6},i;
	for(i=0;i<11;i++)
	{
		flag=1;
		root=AVLinsert(root,ins[i],&flag);
		printf("\nSequences with balance factor");
		printf("\nInorder:");
		inorder(root);
		printf("\nPreorder:");
		preorder(root);
		getch();
	}
	for(i=10;i>=0;i--)
	{
		flag=1;
		root=AVLdelete(root,root,del[i],&flag);
		printf("\nSequences with balance factor");
		printf("\nInorder:");
		inorder(root);
		printf("\nPreorder:");
		preorder(root);
		getch();
	}*/
}
