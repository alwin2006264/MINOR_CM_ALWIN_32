#include <stdio.h>
#include <conio.h>
int main() {
    clrscr();
    int n = 5; 
    float x[] = {1, 2, 3, 4, 5};
    float y[] = {2.2, 2.8, 3.6, 4.5, 5.1};
    float sum_x=0, sum_x2=0, sum_x3=0, sum_x4=0;
    float sum_y=0, sum_xy=0, sum_x2y=0;
    int i;
    for(i=0; i<n; i++){
        sum_x += x[i];
        sum_x2 += x[i]*x[i];
        sum_x3 += x[i]*x[i]*x[i];
        sum_x4 += x[i]*x[i]*x[i]*x[i];
        sum_y += y[i];
        sum_xy += x[i]*y[i];
        sum_x2y += x[i]*x[i]*y[i];
    }
    float D = n*(sum_x2*sum_x4 - sum_x3*sum_x3) - sum_x*(sum_x*sum_x4 - sum_x2*sum_x3) + sum_x2*(sum_x*sum_x3 - sum_x2*sum_x2);
    float Da = sum_y*(sum_x2*sum_x4 - sum_x3*sum_x3) - sum_x*(sum_xy*sum_x4 - sum_x2y*sum_x3) + sum_x2*(sum_xy*sum_x3 - sum_x2y*sum_x2);
    float Db = n*(sum_xy*sum_x4 - sum_x2y*sum_x3) - sum_y*(sum_x*sum_x4 - sum_x2*sum_x3) + sum_x2*(sum_x*sum_x2y - sum_y*sum_x2);
    float Dc = n*(sum_x2*sum_x2y - sum_x3*sum_xy) - sum_x*(sum_x*sum_x2y - sum_x3*sum_y) + sum_y*(sum_x*sum_x3 - sum_x2*sum_x2);
    float a = Da / D;
    float b = Db / D;
    float c = Dc / D;
    printf("Quadratic curve fitting equation: y = %.4f + %.4fx + %.4fx^2\n", a, b, c);
    getch();
    return 0;
}
