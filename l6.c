#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int a[]) {
    for (int i = 0; i < n; i += 1) {
        a[i] = rand() % 40 - 19;
    }
}

void print_array(int n, int a[]){
    for (int i = 0; i < n; i += 1) {
        printf("%4i", a[i]);
    }
    printf("\n");
}

int get_array(int n, char *s) {
    int a[n];
    fill(n, a);
    printf("%s =", s);
    print_array(n, a);
    return *a;
}

int c_nums(int n, int i, int a[], int b[]) {
    int not_a = 0, not_b = 0;
    for (int j = 0; j < n; j += 1) {
        if (i - 19 == a[j]) {
            not_a = 1;
        }

        if (i - 19 == b[j]) {
            not_b = 1;
        }
    }

    if (not_a != not_b) {
        return 1;
    } else {
        return 0;
    }
}

int k_notin(int n, int a[], int b[]) {
    int k, c, i;
    k = 0;
    for (i = 0; i < 40; i += 1) {
        c = c_nums(n, i, a, b);
        
        if (c == 1) {
            k += 1;
        }
    }

    return k;
}

void notin(int n, int a[], int b[], int noab[]) {
    int k, c, i;
    k = 0;
    for (i = 0; i < 40; i += 1) {
        c = c_nums(n, i, a, b);
        
        if (c == 1) {
            noab[k] = i - 19;
            k += 1;
        }
    }
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter n -> ");
    scanf("%i", &n);

    int A[n];
    fill(n, A);
    printf("A =");
    print_array(n, A);


    int B[n];
    fill(n, B);
    printf("B =");
    print_array(n, B);


    int k = k_notin(n, A, B);
    int no_AB[k];
    notin(n, A, B, no_AB);


    printf("no AB = ");
    for (int i = 0; i < k; i += 1) {
        printf("%4i", no_AB[i]);
    }
    printf("\n");


    return 0;
}