#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float d1, d2, d3;
    printf("Enter d1 -> ");
    scanf("%f", &d1);
    printf("Enter d2 -> ");
    scanf("%f", &d2);
    printf("Enter d3 -> ");
    scanf("%f", &d3);

    float D[3] = {d1, d2, d3};

    int len = (int) sizeof(D) / sizeof(D[0]);
    int num_i;

    float d_max = D[0];
    float d_min = D[0];
    for (int i = 0; i < len; i += 1) {
        if (d_max < D[i]) {
            d_max = D[i];
            num_i = i + 1;
        };
        if (d_min > D[i]) {
            d_min = D[i];
        }
    }
    printf("d_max = %f \nd_min = %f \n", d_max, d_min);


    if (num_i % 2) {
        printf("%i", (int)(d_max - d_min));
    } else {
        printf("%f", d_min / d_max);
    }

    return 0;
}
