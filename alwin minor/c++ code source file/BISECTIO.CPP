#include <stdio.h>
#include <math.h>
#include <conio.h>
float f(float x) {
    return (x * x * x - 4 * x - 9);
}
int main() {
    float a = 2, b = 3, xr, fx, fb, fxr;
    int intr = 0;
    float eps = 0.001;
    float prev1 = 0.0, prev2 = 0.0;
    int same_count = 0;
    clrscr();
    fx = f(a);
    fb = f(b);
    if (fx * fb > 0) {
	printf("Root not found in the given interval.\n");
	return 0;
    }
    printf("\nItr\t a\t  b\t  xr\t f(a)\t f(b)\t f(xr)\n");
    printf("-------------------------------------------------------\n");
    do {
	intr++;
	xr = (a + b) / 2;
	fxr = f(xr);
	fx = f(a);
	fb = f(b);
printf("%2d\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n",
	       intr, a, b, xr, fx, fb, fxr);
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
