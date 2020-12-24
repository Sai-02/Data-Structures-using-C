// Create circular linked list having information
//  about the student and perform Insertion at front
// perform Deletion
// at end and display the elements of list.

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
    struct node *next;
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
                printf("Enter the roll number and name of student   ");
                char Name[20];
                int info;
                scanf("%d", &info);
                scanf("%[^\n]%*c", Name);
                head->next = head;

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
    printf("\nEnter the roll number and name of student  ");
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

    new->next = head;
    struct node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new;

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
    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    struct node *curr = head;
    struct node *prev = NULL;
    while (curr->next != head)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = head;
    free(curr);
    return head;
}
void print(struct node *head)
{
    printf("\n");
    if (head == NULL)
    {
        printf("List is empty!!!\n");
        return;
    }
    struct node *temp = head;
    while (temp->next != head)
    {
        printf("Roll number is %d\n", temp->Roll_no);
        printf("Name of student is %s\n\n\n", temp->name);
        temp = temp->next;
    }
    printf("Roll number is %d\n", temp->Roll_no);
    printf("Name of student is %s\n\n\n", temp->name);
}