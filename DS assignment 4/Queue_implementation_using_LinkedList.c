//Data Structures

//Write a program to implement queue using linked list

//Name-Sai Prashant Saxena
//Roll no-022 20902719

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *insertValue(int);
void ask(void);
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *temp;

    printf("Hello there!!\n\n");

    printf("Enter the value to be added");
    int firstValue;
    scanf("%d", &firstValue);
    head->info = firstValue;
    head->link = NULL;
    temp = head;
    int userValue;
askAgain:
    ask();
    scanf("%d", &userValue);
    if (userValue == 1)
    {
        printf("Enter the value to be added\n");
        int value;
        scanf("%d", &value);
        if (head == NULL)
        {
            head = insertValue(value);

            temp = head;
        }
        else
        {

            temp->link = insertValue(value);
            temp = temp->link;
        }
        printf("\nQueue after this operation is");

        printQueue(head);
    }
    else if (userValue == 2)
    {
        if (head == NULL)
        {
            printf("Queue is already empty");
        }
        else
        {
            struct node *deleteNode = head;
            head = head->link;
            free(deleteNode);
        }
        // printf("\nQueue after this operation is  ");
        printQueue(head);
    }
    else
    {
        printf("Queue at last is..\n");
        printQueue(head);
        goto end;
    }
    goto askAgain;

end:
    return 0;
}
void ask()
{
    printf("Press 1 for enqueue     Press 2 for dequeue   Press 0 to exit...\n  ");
}
void printQueue(struct node *head)
{

    if (head == NULL)
    {
        printf(" Empty\n");
        return;
    }
    struct node *temp = head;
    printf("\n");
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

struct node *insertValue(int value)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = value;
    new->link = NULL;
    return new;
}