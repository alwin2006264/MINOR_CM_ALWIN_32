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
        sum += 2 * f(a + i*h); 
    }
    area = (h / 2) * sum; 
    printf("Approximate value of the integral: %.4f\n", area);
getch()
    return 0;
}
