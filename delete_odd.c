#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *create(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	printf("enter data,enter -1 to stop\n");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=num;
		if(start==NULL)
		{
			new_node->next=NULL;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->next=NULL;
		}
		printf("\nenter data");
		scanf("%d",&num);
	}
return start;
}
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	if(start==NULL)
	{	
		printf("no data to display");
		return 0;
	}
	
	while(ptr!=NULL)
	{
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("null");
return start;
}
struct node *odd(struct node *start)
{
	struct node *ptr,*temp,*del;
	ptr=start;
	temp=ptr;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		del=ptr;
		temp->next=ptr->next;
		if(ptr->next==NULL)
		{
			return start;
		}
		ptr=ptr->next;
		temp=ptr;
		free(del);
	}
return start;
}
int main()
{
	int option;
	do
	{
		printf("\nenter 1 to create a list");
		printf("\nenter 2 to display");
		printf("\nenter 3 to delete odd nodes");
		printf("\nenter 4 to exit");
		scanf("%d",&option);
		switch(option)
		{
			case 1:start=create(start);break;
			case 2:start=display(start);break;
			case 3:start=odd(start);break;
		}	
	}while(option!=4);

return 0;
}
		