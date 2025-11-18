

#include <stdio.h>
#include <math.h>
#include <conio.h>
double f(double x, double y) {
    return x + y;
}
double f_prime(double x, double y) {
    return 1.0 + x + y;
}
void taylor_series_solve() {
    const double X_INITIAL = 0.0;
    const double Y_INITIAL = 1.0;
    const double H = 0.1;
    const int N_STEPS = 5;
    double x = X_INITIAL;
    double y = Y_INITIAL;
    double y_prime;
    double y_double_prime;
    int i;
clrscr();
    printf("--- Taylor Series Method (y' = x + y) ---\n");
    printf("Initial Condition: y(%.1f) = %.1f, Step Size h = %.1f\n", X_INITIAL, Y_INITIAL, H);
    printf("Step |      x      |      y      |    y' (f)   |    y'' (f') \n");
    printf("----------------------------------------------------------------\n");
    printf(" 0   | %10.6f | %10.6f | \n", x, y);
    for (i = 1; i <= N_STEPS; i++) {
        y_prime = f(x, y);
        y_double_prime = f_prime(x, y);
        y = y + H * y_prime + (H * H / 2.0) * y_double_prime;
        x = x + H;
        printf(" %d   | %10.6f | %10.6f | %10.6f | %10.6f\n", i, x, y, y_prime, y_double_prime);
    }
    printf("----------------------------------------------------------------\n");
    printf("Final Approximation at x=%.1f: y = %.6f\n", x, y);
}
int main() {
    taylor_series_solve();
    getch();
    return 0;
}