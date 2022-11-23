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

    int I = 2 / h + h / 2;
    printf("I = %i \n", I);

    printf("\ndo while \nx        f(x) \n------------------\n");
    int i = 0;
    do {
        float f = func(i*h);
        printf("%.5f  %.5f \n", i*h, f);
        i += 1;
    } while(i <= I);

    // printf("\nfor \nx        f(x) \n------------------\n");
    // for (int i = 0; i <= I; i += 1) {
    //     float f = func(i*h);
    //     printf("%.5f  %.5f \n", i*h, f);
    // }

    // printf("I = %f \n", I);
    return 0;
}