// Perform Linear Search and Binary Search on an array.
// Description of programs:
// a. Read an array of type integer.
// b. Input element from user for searching.
// c. Search the element by passing the array to a function and then
// returning the position of the element from the function else return -1 if
// the element is not found.
// d. Display the position where the element has been found.

// Name -Sai Prashant Saxena
// Branch-CSE
// Subject-Data Structures
// Roll No-02220902719

#include <stdio.h>

void func(int);
void linearSearch(int[], int);
void binarySearch(int[], int);

int main()
{
    printf("Enter the number of elements in array..\n\t");
    int n;
    scanf("%d", &n);
    func(n);

    return 0;
}
void func(int n)
{
    int a[n];
    printf("\nEnter the values of Array in sorted manner...\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\n  Press 1 for Linear Search and 2 for Binary Search\n ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        linearSearch(a, n);
    }
    else if (choice == 2)
    {
        binarySearch(a, n);
    }
    else
    {
        printf("\n\nYou have made inappropriate choice!!!");
        return;
    }
}

void linearSearch(int a[], int n)
{
    printf("Enter the key to be searched\n  ");
    int key;
    scanf("%d", &key);
    int found = 0;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            break;
        }
    }
    if (i < n)
    {
        printf("Key found at index %d", i);
    }
    else
    {

        printf("-1");
    }
}

void binarySearch(int a[], int n)
{
    printf("Enter the key to be searched\n  ");
    int key;
    scanf("%d", &key);
    int l = 0, r = n - 1;
    int found = 0, index = 0;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (a[m] == key)
        {
            found = 1;
            index = m;
            break;
        }
        if (a[m] < key)
            l = m + 1;

        else
            r = m - 1;
    }
    if (found == 1)
    {
        printf("\nKey is found at index %d", index);
    }
    else
    {
        printf("-1");
    }
}
