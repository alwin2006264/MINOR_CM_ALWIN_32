#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    float a[10][11] = {
        {  5, -3,  2,  12 },
        { -4,  6,  1,  -7 },
        {  3,  2, -5,  10 }
    };
    float x[10], ratio, temp;
    int n = 3;
    int i, j, k, max_row;
    clrscr();
    printf("\nSolving the augmented matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= n; j++)
        {
            printf("%0.0f ", a[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < n; i++)
    {
        max_row = i;
        for(k = i + 1; k < n; k++)
        {
            if(fabs(a[k][i]) > fabs(a[max_row][i]))
                max_row = k;
        }
        for(k = 0; k <= n; k++)
        {
            temp = a[i][k];
            a[i][k] = a[max_row][k];
            a[max_row][k] = temp;
        }
        if(a[i][i] == 0.0)
        {
            printf("\nMathematical Error: No unique solution\n");
            getch();
            return 0;
        }
        for(j = 0; j < n; j++)
        {
            if(i != j)
            {
                ratio = a[j][i] / a[i][i];
                for(k = 0; k <= n; k++)
                {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        x[i] = a[i][n] / a[i][i];
    }
    printf("\nThe solution is:\n");
    for(i = 0; i < n; i++)
    {
        printf("x%d = %0.3f\n", i+1, x[i]);
    }

    getch();
    return 0;
}
