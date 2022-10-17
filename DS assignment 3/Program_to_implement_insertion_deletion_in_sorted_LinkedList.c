#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *insertion(struct node *);
struct node *deletion(struct node *);
void print(struct node *);

int main()
{
	int n,ch=1,choice;
	struct node *temp;
	struct node *start=(struct node *)malloc(sizeof(struct node));
	start->link=NULL;
	temp=start;
	
	printf("\nIf you want to create Linked list press 1 : ");
	scanf("%d",&n);
	if(n==1)
	{
		int value;
		printf("\nEnter the value of first node : ");
		scanf("%d",&value);
		start->info=value;
		temp=start;
	}
	else
	{
		return 0;
	}
	
	while(ch==1)
	{
		printf("\nPress 1 to add a new node");
		printf("\nPress 2 to delete a node");
		printf("\nPress 3 to print Linked list");
		printf("\n\nYour choice is : ");
		scanf("%d",&choice);
		
		switch(choice)
		{case 1 : start = insertion(start);
		          break;
		 case 2 : start = deletion(start);
		          break;
		 case 3 : print(start);
		          break;
		 default: printf("\nWrong choice entered");
		          break;		
		}
		printf("\nTf you want to perform more operations on Linked list press 1 else 0 : ");
		scanf("%d",&ch);
	}
	
}

struct node *insertion(struct node *start)
{
	int value;
	printf("\nEnter the value to be added : ");
    	scanf("%d", &value);
		          
	struct node *temp = start;
    	struct node *next = (struct node *)malloc(sizeof(struct node));
    	next->info = value;
    	next->link = NULL;
    	if (start == NULL)
    	{
        	return next;
    	}
    	if (start->info > value)
    	{
        	next->link = start;
        	start = next;
        	return start;
    	}
    	while (temp->link != NULL)
    	{
        	if (temp->link->info > value)
        	{
        	    next->link = temp->link;
         	   temp->link = next;
         	   return start;
        	}
        	temp = temp->link;
    	}
    	temp->link = next;
    	return start;    
}

struct node *deletion(struct node *start)
{
    int value;
    printf("\nEnter the value to be deleted : ");
    scanf("%d", &value);
		          
    if (start == NULL)
    {
     	printf("\nThe linked list is empty\n");
        return start;
    }
    struct node *current = start, *previous;
    if (start->info > value)
    {
        current = NULL;
    }
    if (start->info == value)
    {
        start = start->link;
        free(current);
        return start;
    }
    while (current != NULL)
    {
        if (current->info > value)
        {
            break;
        }
        if (current->info == value)
        {
            previous->link = current->link;
            free(current);
            return start;
        }
        previous = current;
        current = current->link;
    }

    printf("\nItem is not found in Linked list\n");

    return start;
}

void print(struct node *start)
{
    if (start == NULL)
    {
        printf("\nThe linked list is empty\n");
        return;
    }
    struct node *temp = start;
    while (temp != NULL)
    {
        printf("%d  ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}
