#include <stdio.h>
#include <math.h>
#include <conio.h>
float f(float x) {
    return x*x; 
}
int main() {
    int n = 4;           
    float a = 0.0, b = 2.0;
    float h, area, sum = 0.0;
    int i;
clrscr();
    h = (b - a) / n;
    sum = f(a) + f(b); 
    for(i = 1; i < n; i++) {
        if(i % 2 == 0)
            sum += 2 * f(a + i*h); 
        else
            sum += 4 * f(a + i*h);
    }
    area = (h / 3) * sum;
    printf("Approximate value of the integral (Simpson 1/3): %.4f\n", area);
    getch();
    return 0;
}
