#include <stdio.h>
#include <math.h>
#include <conio.h>

double f(double x, double y) {
    return x + y;
}

void modified_eulers_method_solve() {
    const double X_INITIAL = 0.0;
    const double Y_INITIAL = 1.0;
    const double H = 0.1;
    const int N_STEPS = 5;

    double x = X_INITIAL;
    double y = Y_INITIAL;
    double x_next;
    double y_predictor;
    double k1, k2;
    int i;
clrscr();
    printf("--- Modified Euler's Method (y' = x + y) ---\n");
    printf("Initial Condition: y(%.1f) = %.1f, Step Size h = %.1f\n", X_INITIAL, Y_INITIAL, H);
    printf("Step |      x      |      y      | Predictor y | Avg. Slope\n");
    printf("-------------------------------------------------------------\n");
    printf(" 0   | %10.6f | %10.6f |\n", x, y);

    for (i = 1; i <= N_STEPS; i++) {
        k1 = f(x, y);
        x_next = x + H;
        y_predictor = y + H * k1;

        k2 = f(x_next, y_predictor);

        y = y + (H / 2.0) * (k1 + k2);
        x = x_next;

        printf(" %d   | %10.6f | %10.6f | %10.6f | %10.6f\n",
               i, x, y, y_predictor, (k1 + k2) / 2.0);
    }

    printf("-------------------------------------------------------------\n");
    printf("Final Approximation at x=%.1f: y = %.6f\n", x, y);
}

int main() {
    modified_eulers_method_solve();
getch();
    return 0;
}
