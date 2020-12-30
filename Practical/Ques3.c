// Create a linked list with nodes having information about a student and perform:
// I. Insert a new node at specified position.
// II. Delete of a node with the roll number of students specified.
// III. Reversal of that linked list

// Name -Sai Prashant Saxena
// Branch-CSE
// Subject-Data Structures
// Roll No-02220902719

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int Roll_no;
    char name[20];
    struct node *link;
};
void delete ();
void insert();
void print();
void reverse();

struct node *head = NULL, *temp = NULL;

int main()
{
    while (1)
    {

        printf("Press 1 for new student's data\n Press 2 for deleting a student's data\n Press 3 for printing list \n Press 4 for reversing the list\n Press any other key to exit....\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            insert();
        }
        else if (choice == 2)
        {
            delete ();
        }
        else if (choice == 3)
        {
            print();
        }
        else if (choice == 4)
        {
            reverse();
        }
        else
        {
            break;
        }
    }

    return 0;
}

void insert()
{
    printf("Enter the Roll no of student\t");
    int roll_no;
    printf("\nEnter the name of student\n");
    scanf("%d ", &roll_no);
    char Name[20];

    scanf("%[^\n]%*c", Name);

    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));

        head->Roll_no = roll_no;
        for (int i = 0; i < 20; i++)
        {
            head->name[i] = Name[i];
        }
        head->link = NULL;
        temp = head;
    }
    else
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->link = NULL;
        new->Roll_no = roll_no;
        for (int i = 0; i < 20; i++)
        {
            new->name[i] = Name[i];
        }
        temp->link = new;
        temp = temp->link;
    }
}
void print()
{
    if (head == NULL)
    {
        printf("\nList is empty!!!\n");
        return;
    }
    printf("\n\n");
    temp = head;
    while (temp != NULL)
    {
        printf("Roll no-%d\n", temp->Roll_no);
        printf("Name of student is %s\n\n\n", temp->name);
        temp = temp->link;
    }
    temp = head;
}
void delete ()
{
    if (head == NULL)
    {
        printf("\nList is already empty!!\n");
        return;
    }
    printf("Enter the roll number to be deleted\n");
    int delete;
    scanf("%d", &delete);

    if (head->Roll_no == delete)
    {
        temp = head;
        head = head->link;
        free(temp);
        temp = head;
        printf("\nData deleted successfully\n\n");
        return;
    }
    struct node *curr = head;
    struct node *prev = NULL;
    while (curr != NULL)
    {
        if (curr->Roll_no == delete)
        {
            prev->link = curr->link;
            free(curr);
            printf("Data deleted successfully!!\n\n");
            return;
        }
        prev = curr;
        curr = curr->link;
    }
    printf("\nRoll numbered entered does not exist!!!\n\n");
}

void reverse()
{
    if (head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    struct node *curr = head;
    struct node *next = head->link;
    head->link = NULL;
    while (next != NULL)
    {
        curr = next;
        next = next->link;
        curr->link = head;
        head = curr;
    }
}