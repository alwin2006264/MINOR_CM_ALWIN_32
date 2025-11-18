#include <stdio.h>
#include <conio.h>

// Factorial function
float fact(int num)
{
    float f = 1;
    int i;
    for(i = 2; i <= num; i++)
        f = f * i;
    return f;
}

int main()
{
    int n = 5;
    float x[5] = {0, 1, 2, 3, 4};   // Hardcoded x values
    float y[5][5] = {                // Hardcoded y values
        {1}, {8}, {27}, {64}, {125}
    };
    float value = 2.5, h, p, y_int, p_term;
    int i, j;  // Declare all loop variables at the top

    clrscr();

    // Create Forward Difference Table
    for(j = 1; j < n; j++)
        for(i = 0; i < n-j; i++)
            y[i][j] = y[i+1][j-1] - y[i][j-1];

    printf("\nNewton Forward Difference Table:\n");
    printf("x\tf(x)\ty\tDeltay\tDelta2y\tDelta3y\n");
    for(i = 0; i < n; i++)
    {
        printf("%.1f", x[i]);
        for(j = 0; j < n-i; j++)
            printf("\t%.2f", y[i][j]);
        printf("\n");
    }

    // Interpolation
    h = x[1] - x[0];
    p = (value - x[0]) / h;
    y_int = y[0][0];
    p_term = 1;

    for(i = 1; i < n; i++)
    {
        p_term = p_term * (p - i + 1);
        y_int = y_int + (p_term * y[0][i]) / fact(i);
    }

    printf("\nValue at x = %.2f is %.4f\n", value, y_int);

    getch();
    return 0;
}
