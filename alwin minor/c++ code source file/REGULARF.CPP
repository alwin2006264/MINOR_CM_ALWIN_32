#include <stdio.h>
#include <conio.h>
#include <math.h>

float f(float x) {
    return (x * x * x - 4 * x - 9);
}

int main() {
    float a = 2, b = 3, xr, fx, fb, fxr;
    int i = 0;
    float eps = 0.001;
    float prev1 = 0.0, prev2 = 0.0;
    int same_count = 0;

    clrscr();

    fx = f(a);
    fb = f(b);

    if (fx * fb > 0) {
        printf("Root not found in the given interval.\n");
        getch();
        return 0;
    }

    printf("\nIter\t a\t\t b\t\t xr\t\t f(a)\t\t f(b)\t\t f(xr)\n");
    printf("-----------------------------------------------------------------------------\n");

    do {
        i++;
        xr = (a * fb - b * fx) / (fb - fx);
        fxr = f(xr);
        fx = f(a);
        fb = f(b);

        printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\t %.6f\t %.6f\n", i, a, b, xr, fx, fb, fxr);

        if (fx * fxr < 0)
            b = xr;
        else
            a = xr;

        float xr3 = floor(xr * 1000 + 0.5) / 1000;

        if (fabs(xr3 - prev1) < 0.0001 && fabs(prev1 - prev2) < 0.0001)
            same_count++;
        else
            same_count = 0;

        prev2 = prev1;
        prev1 = xr3;

        if (same_count >= 1)
            break;

    } while (fabs(fxr) > eps);

    printf("\nApproximate root (correct up to 3 decimal places) = %.3f\n", prev1);

    getch();
    return 0;
}
