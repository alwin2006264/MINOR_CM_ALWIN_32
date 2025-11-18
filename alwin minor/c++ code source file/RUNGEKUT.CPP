#include <stdio.h>
#include <math.h>
#include <conio.h>

double f(double x, double y) {
    return x + y;
}

void runge_kutta_4th_order_solve() {
    const double X0 = 0.0;
    const double Y0 = 1.0;
    const double H = 0.1;
    const int N = 5;

    double x = X0, y = Y0;
    double k1, k2, k3, k4;
    int i;

    clrscr();

    printf("---- RK4 Method ----\n");
    printf("y' = x + y , h=%.1f\n", H);
    printf("Step |    x    |    y    |   k1   |   k2   |   k3   |   k4   |  kavg\n");
    printf("-----------------------------------------------------------------------\n");
    printf("0    | %7.4f | %7.4f |\n", x, y);

    for (i = 1; i <= N; i++) {
        k1 = H * f(x, y);
        k2 = H * f(x + H/2, y + k1/2);
        k3 = H * f(x + H/2, y + k2/2);
        k4 = H * f(x + H, y + k3);

        double kavg = (k1 + 2*k2 + 2*k3 + k4) / 6.0;

        y = y + kavg;
        x = x + H;

        printf("%-4d | %7.4f | %7.4f | %7.4f | %7.4f | %7.4f | %7.4f | %7.4f\n",
               i, x, y, k1, k2, k3, k4, kavg);
    }

    printf("-----------------------------------------------------------------------\n");
    printf("Final y(%.1f) = %.6f", x, y);
}

int main() {
    runge_kutta_4th_order_solve();
    getch();
    return 0;
}
