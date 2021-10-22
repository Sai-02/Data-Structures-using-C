#include<stdio.h>
#include<string.h>

int greater(int num1, int num2)
{
    return (num1 > num2)? num1 : num2;
}

int lcs( char *str1, char *str2, int m, int n )
{
    int Arr[m+1][n+1];
    int i, j;

    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
        if (i == 0 || j == 0)
            Arr[i][j] = 0;
        else if (str1[i-1] == str2[j-1])
            Arr[i][j] = Arr[i-1][j-1] + 1;
        else
            Arr[i][j] = greater(Arr[i-1][j], Arr[i][j-1]);
        }
    }
     
    return Arr[m][n];
}

int main()
{
    char str1[40],str2[40];
    printf("Enter string 1: ");
    scanf("%[^\n]%*c", str1);
    printf("Enter string 2: ");
    scanf("%[^\n]%*c", str2);

    printf("The length of LCS is %d", lcs( str1, str2, strlen(str1), strlen(str2)));
 
    return 0;
}
