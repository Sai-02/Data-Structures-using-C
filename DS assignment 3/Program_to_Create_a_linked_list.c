
//Write a program to create a linkedList

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
void printList(struct node *);

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    printf("Hello there!!");
    printf("\nWant to create a linked list press 1.....\n\t\t");
    char c;
    scanf("%c", &c);
    if (c == 1)
    {
        printf("Enter the value of head\n  ");
        int value;
        scanf("%d", &value);
        head->info = value;
        head->link = NULL;
        temp = head;
    }
    else
    {
        printf("Sorry!!!...Invalid Input\n");
        printf("Program exited");
        goto end;
    }

    int ch;
    addNode:
    printf("Want to add more values to linked list press 1...\n  ");
    scanf("%d", &ch);
    if (ch == 1)
    {
    
        printf("Enter the next value\n  ");
        int value;
        scanf("%d", &value);
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->info = value;
        new->link = NULL;
        temp->link = new;
        temp = temp->link;
        printf("\nThe new List is:");
        printList(head);
    }
    else
    {
        printf("At last the linked list is..");
        printList(head);
        goto end;
    }
    
    goto addNode;
    
end:
    return 0;
}
void printList(struct node *head)
{
    struct node *temp = head;
    printf("\n");
    while (temp != NULL)
    {
       	printf("-->%d ",temp->info);
  	    printf("\t Next:%d\n",temp->link); 
  	    temp = temp->link;
    }
    printf("\n");
}
