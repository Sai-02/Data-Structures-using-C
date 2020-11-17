#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *removeValue(struct node *, int);

int main()
{
    int n,i;
    char ch;
    printf("Enter the Size of linked list:");
    scanf("%d", &n);
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->link = NULL;
    struct node *temp;
    for ( i = 0; i < n; i++)
    {    
        int value;
        printf("Enter the node value:\n");
        scanf("%d", &value);
        if (i == 0)
        {
            head->info = value;
            temp = head;
        }
        else
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            new->info = value;
            new->link = NULL;
            temp->link = new;
            temp = temp->link;
        }
    }
    int k;
    do
    {
	
    printf("\nEnter the value to be deleted:");
    scanf("%d", &k);
    head = removeValue(head, k);
    temp = head;
    printf("\nNew Linked list:");
    while (temp != NULL)
    {  
        printf("%d ", temp->info);
        temp = temp->link;
    }
 printf("\nWant to delete more(y/n):");
    scanf("%s",&ch);
}while(ch=='y'||ch=='Y');
    return 0;
}
struct node *removeValue(struct node *head, int k)
{
    struct node *temp = head;
    if (head == NULL)
    {   printf("\nUndeflow ...Linked list is empty");
    }

if (k == temp->info)
    {
        head = head->link;
      
        return head;
    }
    struct node *prev = head;
    temp = head->link;
    while (temp != NULL)
    {
        if (temp->info == k)
        {
            prev->link = temp->link;
           
            return head;
        }
        prev = temp;
        temp = temp->link;
    }
      free(temp);
    return head;
}
