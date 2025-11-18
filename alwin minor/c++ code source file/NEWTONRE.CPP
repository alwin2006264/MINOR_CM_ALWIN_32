#include <stdio.h>
#include <conio.h>
#include <math.h>
float f(float x) {
    return (x * x * x - 4 * x - 9);
}
float f1(float x) {
    return (3 * x * x - 4);
}
int main() {
    float x0 = 2, x1, f0, f1x;
    int i = 0;
    float eps = 0.001;
    float prev1 = 0.0, prev2 = 0.0;
    int same_count = 0;
    clrscr();
    printf("\nIter\t x0\t\t f(x0)\t\t f'(x0)\t\t x1\n");
    printf("-------------------------------------------------------------\n");
    do {
        i++;
        f0 = f(x0);
        f1x = f1(x0);
        x1 = x0 - (f0 / f1x);
        printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\n", i, x0, f0, f1x, x1);
        float x13 = floor(x1 * 1000 + 0.5) / 1000;
        if (fabs(x13 - prev1) < 0.0001 && fabs(prev1 - prev2) < 0.0001)
            same_count++;
        else
            same_count = 0;
        prev2 = prev1;
        prev1 = x13;
        if (same_count >= 1)
            break;
        x0 = x1;
    } while (fabs(f0) > eps);
    printf("\nApproximate root (correct up to 3 decimal places) = %.3f\n", prev1);
    getch();
    return 0;
}
