#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int Arr[], int n)
{
    int temp[n][n],i, j, k, L, x;
    for (i = 1; i < n; i++)
    {
        temp[i][i] = 0;
    }
 
    for (L = 2; L < n; L++) 
    {

        for (i = 1; i < n - L + 1; i++) 
        {
            j = i + L - 1;
            temp[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) 
            {
                x = temp[i][k] + temp[k + 1][j] + Arr[i - 1] * Arr[k]* Arr[j];
                if (x < temp[i][j])
                    temp[i][j] = x;
            }
        }
    }
    return temp[1][n - 1];
}
 
int main()
{
    int arr[15],x;
    printf("Enter the size of Array: ");
    scanf("%d",&x);
    printf("\nEnter the Array: ");
    for(int i=0;i<x;i++)
    scanf("%d",&arr[i]);
    printf("\nThe minimum no. of multiplications: %d ", matrixChainOrder(arr, x));

    return 0;
}
