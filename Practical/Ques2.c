//  Create a stack and perform Pop, Push,
//  Traverse operations on the stack using Linear Linked list.

// Name -Sai Prashant Saxena
// Branch-CSE
// Subject-Data Structures
// Roll No-02220902719

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
void peek();
void pop();
void push();
struct node *head, *temp;
int i = 0;
int main()
{
    int choice;

    while (1)
    {
        printf("Press 1 for Push, 2 for Pop, 3 for peek and any other key to exit\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            push();
        }
        else if (choice == 2)
        {
            pop();
        }
        else if (choice == 3)
        {
            peek();
        }
        else
        {
            printf("\nProgram Ended....");
            break;
        }
    }
    return 0;
}
void push()
{
    i++;
    printf("Enter the value to be entered..\n");
    int value;
    scanf("%d", &value);
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->info = value;
    }
    else
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->link = head;
        new->info = value;
        head = new;
    }
}

void pop()
{

    if (i == 0)
    {
        printf("\nStack is already empty!!\n");
        return;
    }
    struct node *remove = head;
    printf("%d is removed!!\n", remove->info);
    head = head->link;
    free(remove);
    i--;
}
void peek()
{
    if (i == 0)
    {
        printf("\nStack is empty!!\n");
    }
    printf("Top value is %d\n", head->info);
}