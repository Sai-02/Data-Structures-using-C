#include <stdio.h>
#include <limits.h>

int sum(int freq[], int i, int j)
{
    int sum = 0;
    for (int x = i; x <=j; x++)
       sum += freq[x];

    return sum;
}
 
int OST(int keys[], int freq[], int n)
{
    int cost[n][n];
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for (int L=2; L<=n; L++)
    {
        for (int i=0; i<=n-L+1; i++)
        {
            int j = i+L-1;
            cost[i][j] = INT_MAX;
            for (int r=i; r<=j; r++)
            {
               int c = ((r > i)? cost[i][r-1]:0) + ((r < j)? cost[r+1][j]:0) + sum(freq, i, j);
               if (c < cost[i][j])
                cost[i][j] = c;
            }
        }
    }
    return cost[0][n-1];
}

int main()
{
    int keys[15],freq[15],x;
    printf("Enter the size of Array: ");
    scanf("%d",&x);
    printf("\nEnter keys Array: ");
    for(int i=0;i<x;i++)
    scanf("%d",&keys[i]);
    printf("\nEnter freq Array: ");
    for(int i=0;i<x;i++)
    scanf("%d",&freq[i]);

    printf("\nOptimal BST cost = %d ", OST(keys, freq, x));
    return 0;
}
