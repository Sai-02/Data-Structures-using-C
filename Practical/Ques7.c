// Create a Linear Queue using Linked List and
// implement different operations such as Insert,
// Delete, and Display
// the queue elements.

// Name -Sai Prashant Saxena
// Branch-CSE
// Subject-Data Structures
// Roll No-02220902719

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *enqueue(struct node *);
struct node *dequeue(struct node *);
void display(struct node *);
void peek(struct node *);
int main()
{
    struct node *head = NULL;
    int choice;
    while (1)
    {

        printf("\n\nPress 1 for enqueue\nPress 2 for Dequeue\nPress 3 for display\nPress 4 for Peek\nPress any other key to exit..   ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            head = enqueue(head);
        }
        else if (choice == 2)
        {
            head = dequeue(head);
        }
        else if (choice == 3)
        {
            display(head);
        }
        else if (choice == 4)
        {
            peek(head);
        }
        else
        {
            break;
        }
    }

    return 0;
}

struct node *enqueue(struct node *head)
{
    int data;
    printf("\nEnter the data ");
    scanf("%d", &data);
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->link = NULL;
        head->data = data;
        return head;
    }
    struct node *temp = head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->link = NULL;
    newNode->data = data;
    temp->link = newNode;
    return head;
}

struct node *dequeue(struct node *head)
{
    if (head == NULL)
    {
        printf("\nQueue is already empty!!!\n\n");
        return NULL;
    }
    if(head->link==NULL){
        free(head);
        return NULL;
    }
    struct node *prev = NULL;
    struct node *curr = head;
    while (curr->link != NULL)
    {
        prev = curr;
        curr = curr->link;
    }
    free(curr);
    prev->link = NULL;
    return head;
}
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("\n\nQueue is empty!!!\n\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n\n");
}
void peek(struct node *head)
{
    if (head == NULL)
    {
        printf("\nQueue is empty!!\n");
        return;
    }
    printf("\nThe top of the key is %d \n", head->data);
}