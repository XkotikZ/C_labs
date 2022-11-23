#include <stdio.h>
#include <math.h>

int sgn(double y) {
    if (y > 0) {
        return 1;
    }

    if (y == 0) {
        return 0;
    }

    if (y < 0) {
        return -1;
    }
    return 0;
}

int main() {
    double x;
    printf("Enter x { x >= 0 and x not a whole } -> ");
    scanf("%lf", &x);
    // printf("e = %.5f", M_PI);
    if (0 < x) {
        // double y = sqrt(x) / sin(x);
        double y = sqrt(x) / sin(M_PI * x);
        double z = sgn(y);
        printf("\n y(x) = %.5f \n z(y) = %.5f \n", y, z);
        // printf(" sin(x) = %f \n sin(pi * x) = %f \n", sin(x), sin(M_PI * x));
    } else {
        printf("x value is incorrect!\n");
    }
    return 0;
}