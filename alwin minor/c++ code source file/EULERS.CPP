#include <stdio.h>
#include <math.h>

double f(double x, double y) {
    return x + y;
}

void eulers_method_solve() {
    const double X_INITIAL = 0.0;
    const double Y_INITIAL = 1.0;
    const double STEP_SIZE = 0.1;
    const int N_STEPS = 5;

    double x = X_INITIAL;
    double y = Y_INITIAL;
    double slope;
    int i;

    printf("--- Standard Euler's Method (y' = x + y) ---\n");
    printf("Initial Condition: y(%.1f) = %.1f, Step Size h = %.1f\n", X_INITIAL, Y_INITIAL, STEP_SIZE);
    printf("Step |      x      |      y      |    f(x, y)\n");
    printf("--------------------------------------------------\n");
    printf(" 0   | %10.6f | %10.6f |\n", x, y);

    for (i = 1; i <= N_STEPS; i++) {
        slope = f(x, y);

        y = y + STEP_SIZE * slope;
        x = x + STEP_SIZE;

        printf(" %d   | %10.6f | %10.6f | %10.6f\n", i, x, y, slope);
    }

    printf("--------------------------------------------------\n");
    printf("Final Approximation at x=%.1f: y = %.6f\n", x, y);
}

int main() {
    eulers_method_solve();
    return 0;
}
