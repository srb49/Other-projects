#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct list
{
	int data;
	struct list *next;
};

struct list *head=NULL;
struct list *curr=NULL;
void display()
{
	curr=head;
	printf("\ndisplay \n");
	while(curr!=NULL)
	{
		printf("\t%d",curr->data);
		curr=curr->next;
	}
}
void main()
{
	struct list *new_n;
	int ch=1,dt;
	while(ch==1)
	{
		new_n=(struct list*)malloc(sizeof(struct list));
		printf("\nenter data for node");
		scanf("%d",&dt);
		new_n->data=dt;
		new_n->next=NULL;
		if(head==NULL)
		{
			head=new_n;
			curr=new_n;
		}
		else
		{
			curr->next=new_n;
			curr=new_n;
		}
	printf("\npress 1 to continue 0 to stop");
	scanf("%d",&ch);
	}
display();
	
}

