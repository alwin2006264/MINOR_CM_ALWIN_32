#include <stdio.h>
#include <conio.h>
#include <math.h>
float f(float x) {
    return x*x; 
}
int main() {
    clrscr(); 
    int n = 6;           
    float a = 0.0, b = 2.0;
    float h, area, sum = 0.0;
    int i;
    if(n % 3 != 0) {
        printf("Error: Number of sub-intervals must be a multiple of 3\n");
        getch();
        return 1;
    }
    h = (b - a) / n;        
    sum = f(a) + f(b);   
    for(i = 1; i < n; i++) {
        if(i % 3 == 0)
            sum += 2 * f(a + i*h); 
        else
            sum += 3 * f(a + i*h); 
    }
    area = (3*h / 8) * sum; 
    printf("Approximate value of the integral (Simpson 3/8): %.4f\n", area);
    getch(); 
    return 0;
}
