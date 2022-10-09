#include <stdio.h>

int greater(int num1, int num2)
{
    return (num1 > num2)? num1 : num2;
}

int knapSack(int W, int weight[], int val[], int n)
{
    int i, wt;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++) 
    {
        for (wt = 0; wt <= W; wt++) 
        {
            if (i == 0 || wt == 0){
                K[i][wt] = 0;
                continue;
            }

            else if (weight[i - 1] <= wt){
                K[i][wt] = greater(val[i - 1] + K[i - 1][wt - weight[i - 1]], K[i - 1][wt]);
                continue;
            }
            
            K[i][wt] = K[i - 1][wt];
        }

    }
 

    return K[n][W];
}
 

int main()
{

    int val[15],weight[15],x,W;
    printf("Enter the size of Array: ");
    scanf("%d",&x);
    printf("\nEnter weight Array: ");
    for(int i=0;i<x;i++)
    scanf("%d",&weight[i]);
    printf("\nEnter value Array: ");
    for(int i=0;i<x;i++)
    scanf("%d",&val[i]);
    printf("\nEnter W: ");
    scanf("%d",&W);

    printf("\nSolution is %d", knapSack(W, weight, val, x));

    return 0;
}
