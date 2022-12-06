#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int m, int a[n][m]) {
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            // a[i][j] = rand() % 101 - 50;
            a[i][j] = rand() % 11;
        }
    }
}

void print_array(int n, int m, int a[n][m]){
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            printf("%4i", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void transpose(int n, int m, int a[n][m], int at[m][n]) {
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            at[j][i] = a[i][j];
        }
    }
}

// void multiply(int n, int m, int n_min, int a[n][m], int at[m][n], int aat[n_min][n_min]) {
void multiply(int n, int m, int a[n][m], int at[m][n], int aat[n][m]) {
    int i, j;
    for (i = 0; i < n; i += 1) {
        for (j = 0; j < m; j += 1) {
            aat[i][j] = a[i][j] * at[j][i];
        }
    }
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter n -> ");
    scanf("%i", &n);

    int m;
    printf("Enter m -> ");
    scanf("%i", &m);

    int A[n][m];
    fill(n, m, A);
    printf("At := \n");
    print_array(n, m, A);

    int At[m][n];
    // fill(m, n, At);
    transpose(n, m, A, At);
    printf("A := \n");
    print_array(m, n, At);

    // int n_min;
    // if (n < m) {
    //     n_min = n;
    // } else {
    //     n_min = m;
    // }
    // int AAt[n_min][n_min];
    int AAt[n][m];

    // multiply(n, m, n_min, A, At, AAt);
    multiply(n, m, A, At, AAt);

    // print_array(n_min, n_min, AAt);
    print_array(n, m, AAt);

    return 0;
}