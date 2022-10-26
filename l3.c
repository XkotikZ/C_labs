#include <stdio.h>
#include <math.h>

float func(float x) {
    float f;

    if (0 <= x && x <= 1) {
        f = -1 * cos(exp(x));
    } else {
        f = log(2 * x + sin(x * x));
    }

    return f;
}

int main() {
    float h;
    printf("Enter h (h > 0) -> ");
    scanf("%f", &h);

    printf("\ndo while \nx        f(x) \n------------------\n");
    float x = 0;
    do {
        float f = func(x);
        printf("%.5f  %.5f \n", x, f);
        x += h;
    } while(x <= 2 + h / 2);

    printf("\nfor \nx        f(x) \n------------------\n");
    for (float x = 0; x <= 2 + h / 2; x += h) {
        float f = func(x);
        printf("%.5f  %.5f \n", x, f);
    }
    return 0;
}