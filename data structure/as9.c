/*max heap generation*/
#include<stdio.h>
int *h_arr,k=0; /*h_arr,h_brr is the array of heap*/
void max_hp(int n,int i)
{

	int j,t;
	k++;
	j=(i+1)/2-1;
	if(h_arr[i]>h_arr[j])
	{
		
		t=h_arr[i];
		h_arr[i]=h_arr[j];
		h_arr[j]=t;
		if(j==0)
		return;
		else
		max_hp(n,j);
		
	}
	else
	return;
}
void main()
{
	int n,i,j;/*size of the array*/

	printf("\nenter the number of elements");
	scanf("%d",&n);
	h_arr=(int)malloc(n*sizeof(int));
	printf("\n");
	printf("\nenter the elements one by one");
	
	for(i=0;i<n;i++)
	{
	printf("\nenter the element");
	scanf("\t%d",&h_arr[i]);
	}
	for(i=1;i<n;i++)
		max_hp(n,i);
	printf("\n");
	
	for(i=0;i<n;i++)
	printf("\t%d",h_arr[i]);
}
