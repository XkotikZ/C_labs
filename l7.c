#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int m, float a[n][m]) {
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            a[i][j] = rand() % 101 - 50;
        }
    }
}

void print_array(int n, int m, float a[n][m]){
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            printf("%8.3f", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

float max_nums(int n, int m, float a[n][m]) {
    float M = 0;
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            if (M < abs(a[i][j])) {
                M = abs(a[i][j]);
            }
        }
    }

    return M;
}

void division(int n, int m, float M, float a[n][m]) {
    for (int i = 0; i < n; i += 1) {
        // a[i][i] /= M;
        for (int j = 0; j < m; j += 1) {
            if (i == j) {
                a[i][j] /= M;

                if (0 < j - 1 && j - 1 < m && abs(a[i][j-1]) > 1) {
                    a[i][j-1] /= M;
                }
                if (0 < j + 1 && j + 1 < m && abs(a[i][j+1]) > 1) {
                    a[i][j+1] /= M;
                }
            }
        }
    }

    for (int i = 0; i < n; i += 1) {
        // a[i][i] /= M;
        for (int j = m; j > 0; j -= 1) {
            if (i == m-j && i != j-1) {
                printf("i = %i   j = %i   m-j = %i    m-i = %i \n", i, j, m - j, m - i);
                a[i][j-1] /= M;

                if (0 < j - 2 && j - 2 < m && abs(a[i][j-2]) > 1) {
                    a[i][j-2] /= M;
                }
                if (0 < j && j < m && abs(a[i][j]) > 1) {
                    a[i][j] /= M;
                }
            }
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

    float A[n][m];
    fill(n, m, A);
    printf("A := \n");
    print_array(n, m, A);

    float M_num = max_nums(n, m, A);
    printf("M = %f \n", M_num);

    division(n, m, M_num, A);

    printf("del A := \n");
    print_array(n, m, A);

    return 0;
}