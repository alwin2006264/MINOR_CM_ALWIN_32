#include <stdio.h>
#include <conio.h>
float fact(int num)
{
    float f = 1;
    int i;  // Declare loop variable at top
    for(i = 2; i <= num; i++)
        f = f * i;
    return f;
}
int main()
{
    int n = 5;
    float x[5] = {0, 1, 2, 3, 4};      
    float y[5][5] = {                  
        {1}, {8}, {27}, {64}, {125}
    };
    float value = 3.5, h, p, y_int, p_term;
    int i, j;  // Declare all loop variables at top
    clrscr();
    for(j = 1; j < n; j++)
        for(i = n-1; i >= j; i--)
            y[i][j] = y[i][j-1] - y[i-1][j-1];
    printf("\nNewton Backward Difference Table:\n");
    printf("x\tf(x)\tDeltay\tDelta2y\tDelta3y\tDelta4y\n");
    for(i = 0; i < n; i++)
    {
        printf("%.1f", x[i]);
        for(j = 0; j <= i; j++)
            printf("\t%.2f", y[i][j]);
        printf("\n");
    }
    h = x[1] - x[0];
    p = (value - x[n-1]) / h;
    y_int = y[n-1][0];
    p_term = 1;
    for(i = 1; i < n; i++)
    {
        p_term = p_term * (p + i - 1);
        y_int = y_int + (p_term * y[n-1][i]) / fact(i);
    }
    printf("\nValue at x = %.2f is %.4f\n", value, y_int);
    getch();
    return 0;
}
