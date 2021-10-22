#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int linearSearch(int arr[], int n, int search)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
          return i+1;
        }
    }
    return -1;
}

int binarySearch(int arr[], int left , int right, int search)
{
    if (right >= left) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == search)
            return mid+1;
  
        if (arr[mid] > search)
            return binarySearch(arr, left, mid - 1, search);
  
        return binarySearch(arr, mid + 1, right, search);
    }
    return -1;
}

int main()
{
    clock_t begin = clock();
    int arr[100], search, n, userCase, result=-1;
    printf("___Program for Linear/Binary Search___\n\n");
    printf("Input the number of elements: ");
    scanf("%d",&n);
    printf("\nEnter %d elements: ",n);
    
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);

    printf("Enter a number to search:");
    scanf("%d", &search);
    
    printf("\nPress number according to your choice: \n");
    printf("1.For Linear Search\n2.For Binary Search\n");
    scanf("%d",&userCase);
    switch(userCase){
        case 1: printf("\nPerforming Linear Search...\n");
                result = linearSearch(arr,n,search);
                break;
        case 2: printf("\nPerforming Binary Search...\n");
                result = binarySearch(arr,0,n-1,search);
                break;
        default: printf("Invalid Input! No operation Performed.");
    }
    if(result==-1)
    {
        printf("\nThe number %d not found!",search);
    }
    else
    {
        printf("\nThe number %d is found at location: %d",search,result);
    }
    
    clock_t end = clock();
    printf("\nExecution time: %f", (double)(end - begin) / CLOCKS_PER_SEC);

  return 0;
}
