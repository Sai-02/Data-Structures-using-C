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

int partition(int arr[], int left, int right) {
  
  int pivot = arr[right];
  int i = (left - 1);

  for (int j = left; j < right; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[right]);
  
  return (i + 1);
}

void quickSort(int arr[], int left, int right) {
  if (left < right) {
    int pivot = partition(arr, left, right);
    
    quickSort(arr, left, pivot - 1);
    quickSort(arr, pivot + 1, right);
  }
}



void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int Lt[n1], Rt[n2];

    for (i = 0; i < n1; i++)
        Lt[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        Rt[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) 
    {
        if(Lt[i] > Rt[j]) {
            arr[k] = Rt[j];
            j++;
        }
        
        else {
            arr[k] = Lt[i];
            i++;
        }
        
        k++;
    }

    while (i < n1) {
        arr[k] = Lt[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = Rt[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    //Starting Timer for execution time
    clock_t begin = clock();
    int n,arr[100],userCase;
    printf("___Program for Merge/QuickSort___\n\n");
    printf("Input the size of arr: ");
    scanf("%d",&n);
    printf("\nEnter the contents of arr: ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);

    printf("\nInitial arr: ");
    printArr(arr, n);
    
    printf("\n\nPress number according to your choice: \n");
    printf("1.For Merge Sort\n2.For Quick Sort\n");
    scanf("%d",&userCase);
    switch(userCase){
        case 1: printf("\nPerforming Merge Sort...\n");
                mergeSort(arr, 0, n - 1);
                break;
        case 2: printf("\nPerforming Quick Sort...\n");
                quickSort(arr, 0, n-1);
                break;
        default: printf("Invalid Input! No operation Performed.");
    }
    
    printf("\nSorted arr: ");
    printArr(arr, n);
    
    clock_t end = clock();
    //Printing execution time
    printf("\nExecution time: %f", (double)(end - begin) / CLOCKS_PER_SEC);
    return 0;
}
