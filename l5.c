#include <stdio.h>

int f1(int a, int b) {
    int s = 0;
    for (int i = 0; i < b; i += 1) {
        s += a;
    }
    return s;
}

int f2(int a, int b) {
    if (b == 1) {
        return a;
    }
    if (b == 0) {
        return 0;
    }

    return f2(a , b - 1) + a;
}

int main() {
    int a, b;
    printf("Enter a -> ");
    scanf("%i", &a);

    printf("Enter b -> ");
    scanf("%i", &b);

    printf("s1 = %i \n", f1(a, b));
    printf("s2 = %i \n", f2(a, b));

   return 0;
}