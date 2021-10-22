#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
void insertionSort(int arr[], int n)
{
    int temp,i,j;
    for (i = 1; i < n; i++) 
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
        printArr(arr, n);
        printf("\n");
    }
}
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)     
   {
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j+1], &arr[j]);
    printArr(arr, n);
        printf("\n");
   }
}
void selectionSort(int arr[], int n){
    int temp,i, j;
    for (i = 0; i < n-1; i++)
    {
        temp = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[temp])
            temp = j;
        swap(&arr[temp], &arr[i]);
    printArr(arr, n);
        printf("\n");
    }
}

int main()
{
    clock_t begin = clock();
    int n, arr[100], userCase;
    printf("___Program for Insertion/Bubble/Selection Sort___\n\n");
    printf("Input the size of arr: ");
    scanf("%d",&n);
    printf("\nEnter the contents of arr: ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);

    printf("\nInitial arr: ");
    printArr(arr, n);
    
    printf("\n\nPress number according to your choice: \n");
    printf("1.For Insertion Sort\n2.For Bubble Sort\n3.For Selection Sort\n");
    scanf("%d",&userCase);
    switch(userCase){
        case 1: printf("\nPerforming Insertion Sort...\n");
                insertionSort(arr, n);
                break;
        case 2: printf("\nPerforming Bubble Sort...\n");
                bubbleSort(arr, n);
                break;
        case 3: printf("\nPerforming Selection Sort...\n");
                selectionSort(arr, n);
                break;
        default: printf("Invalid Input! No operation Performed.");
    }   
    printf("\nSorted arr: ");
    printArr(arr, n);
    
    clock_t end = clock();
    printf("\nExecution time: %f", (double)(end - begin) / CLOCKS_PER_SEC);
    return 0;
}
