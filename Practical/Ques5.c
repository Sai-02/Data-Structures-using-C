//  Create doubly linked list with nodes having information about an employee and
//   perform Insertion at front of
// doubly linked list and perform deletion at end of that doubly linked list.

// Name -Sai Prashant Saxena
// Branch-CSE
// Subject-Data Structures
// Roll No-02220902719

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int Roll_no;
    char name[20];
    struct node *next, *prev;
};

struct node *addNode(struct node *);
struct node *deleteNode(struct node *);
void print(struct node *);
int main()
{
    struct node *head = NULL;
    struct node *temp = NULL;

    while (1)
    {

        printf(" \nPress 1 to add a new node\nPress 2 to delete a node\nPress 3 to print the list\nPress any other key to exit..    ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            if (head == NULL)
            {
                head = (struct node *)malloc(sizeof(struct node));
                printf("Enter the serial number and name of employee   ");
                char Name[20];
                int info;
                scanf("%d", &info);
                scanf("%[^\n]%*c", Name);
                head->next = NULL;
                head->prev = NULL;
                head->Roll_no = info;
                for (int i = 0; i < 20; i++)
                {
                    head->name[i] = Name[i];
                }
            }
            else
            {
                head = addNode(head);
            }
        }
        else if (choice == 2)
        {
            head = deleteNode(head);
        }
        else if (choice == 3)
        {
            print(head);
        }
        else
        {
            break;
        }
    }

    return 0;
}

struct node *addNode(struct node *head)
{
    printf("\nEnter the serial number and name of employee  ");
    struct node *new = (struct node *)malloc(sizeof(struct node));

    char Name[20];
    int info;
    scanf("%d ", &info);
    scanf("%[^\n]%*c", Name);
    new->Roll_no = info;
    for (int i = 0; i < 20; i++)
    {
        new->name[i] = Name[i];
    }

    head->prev = new;
    new->next = head;
    head = new;
    return head;
}

struct node *deleteNode(struct node *head)
{
    if (head == NULL)
    {
        printf("\nList is already empty!!!\n");
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct node *curr = head;
    struct node *prev = NULL;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    curr->prev = NULL;
    prev->next = NULL;
    free(curr);
    return head;
}
void print(struct node *head)
{
    printf("\n");
    if (head == NULL)
    {
        printf("List is empty!!!\n");
    }
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("Serial number is %d\n", temp->Roll_no);
        printf("Name of employee is %s\n\n\n", temp->name);
        temp = temp->next;
    }
}