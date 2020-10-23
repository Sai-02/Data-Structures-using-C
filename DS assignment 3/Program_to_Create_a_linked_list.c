// Program to create a linked list.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

void insertion(struct node *);
void print(struct node *);

int main()
{
	int value,n;
	struct node *temp=NULL;
	struct node *start=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value of first node: ");
	scanf("%d",&value);
	start->info=value;
	start->link=NULL;
	temp=start;
	
	printf("\nIf you want to add new node press 1 else press 0 : ");
	scanf("%d",&n);
	while(n==1)
	{
		insertion(temp);
		temp=temp->link;
		printf("\nIf you want to add new node press 1 else press 0 : ");
		scanf("%d",&n);
	}
	printf("\nThe linked list is : ");
	print(start);
	return 0;
}

void insertion(struct node *temp)
{
	int value;
	struct node *next=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value : ");
	scanf("%d",&value);
	next->info=value;
	next->link=NULL;
	temp->link=next;
}

void print(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr=ptr->link;
	}
}
