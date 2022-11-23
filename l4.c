#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float func(float x) {
    float f;

    if (0 <= x && x <= 1) {
        f = -1 * cos(exp(x));
    } else if (1 < x && x <= 2) {
        f = log(2 * x + sin(x * x));
    }

    return f;
}

float integrate(float n, float h) {
    float integral = 0;
    // printf("n = %f    h = %f \n", n, h);
    for (int i = 0; i <= n; i += 1) {
        float f = func(i * h + h / 2);
        integral += f * h;
    }
    // printf("f_i = %f \n", integral);
    return integral;

}

int main() {
    float ep;
    printf("Enter ep -> ");
    scanf("%f", &ep);

    int a = 0, b = 2;
    // int b = 2;
    int n = 2;
    // float h;
    float h = (float)(b - a) / (float)n;
 
    float f_integral_1, f_integral_2;

    f_integral_1 = integrate(n, h);

    n *= 2;
    h = (float)(b - a) / (float)n;
    f_integral_2 = integrate(n, h);

    // printf("%f \n", abs(f_integral_1 - f_integral_2));

    while ((f_integral_1 - f_integral_2) / 3 > ep) {
        // n *= 2;
        h = (float)(b - a) / (float)n;
        // printf("h = %f \n", h);
        // f_integral_1 = integrate(n, h);
        f_integral_1 = f_integral_2;

        n *= 2;
        h = (float)(b - a) / (float)n;
        f_integral_2 = integrate(n, h);
    }

    printf("integral = %.5f \n", f_integral_2);
    return 0;
}