//Write a program to implement queue using array

//Name-Sai Prashant Saxena
//Roll no-022 20902719

#include <stdio.h>
void ask();
int main()
{
    int queue[100];
    int front = 0, rear = -1;
    printf("Hello there!!\n");

    int userValue;
askAgain:
    ask();
    scanf("%d", &userValue);
    if (userValue == 1)
    {
        int value;
        printf("\nEnter value to be added\n");
        scanf("%d", &value);
        if (rear == 99)
        {
            printf("\nQueue Overflow");
        }
        else
        {
            rear++;
            queue[rear] = value;
        }
        printf("\nQueue after this operation is..");
        printValue(queue, front, rear);
    }
    else if (userValue == 2)
    {
        if (front > rear)
        {
            printf("\nQueue is already empty!!");
        }
        else
        {
            front++;
            printf("\nQueue after this operation is..");
            printValue(queue, front, rear);
        }
    }
    else if (userValue == 3)
    {
        if (front == -1 || front > rear)
        {
            printf("\nQueue is already empty!!");
        }
        else
        {

            printf("\nThe front of queue is %d", queue[front]);
        }
    }
    else
    {
        goto end;
    }
    goto askAgain;

end:
    return 0;
}

void ask()
{
    printf("\nPress 1 for enqueue     Press 2 for dequeue   Press 3 for front    Press 0 to exit...\n  ");
}

void printValue(int queue[], int front, int rear)
{
    if (front == -1 || front > rear)
    {
        printf(" empty");
    }
    else
    {
        printf("\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}