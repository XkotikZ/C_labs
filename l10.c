#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fail() {
    printf("Memory allocation failure!\n");
    exit(EXIT_FAILURE);
}

void fill(int n, int m, float a[n][m]) {
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            a[i][j] = rand() % 101 - 50;
        }
    }
}

void fill_new(int n, int m, float** a) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = rand() % 101 - 50;
}

void zeros(int n, int m, int a[n][m]) {
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            a[i][j] = 0;
        }
    }
}

void print_array_int(int n, int m, int a[n][m]){
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            printf("%2d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_array_float(int n, int m, float a[n][m]){
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            printf("%8.3f", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_array_float_new(int n, int m, float** a) {
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

float max_nums_new(int n, int m, float** a) {
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

// void division_preparation(int n, int m, float M_num, float a[n][m], int pre_a[n][m]) {
void division_preparation_new(int n, int m, float M_num, float** a, int pre_a[n][m]) {
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            if (i == j) {
                pre_a[i][j] = 1;


                if (0 <= j - 1 && j - 1 <= m && abs(j + 1 - i) == 1) {
                    pre_a[i][j-1] = 1;
                }

                if (0 <= j + 1 && j + 1 <= m && abs(j - 1 - i) == 1) {
                    pre_a[i][j+1] = 1;
                }

            }
        }

        for (int j = m; j > 0; j -= 1) {
            if (i == m - j) {
                int m_j = m - j;
                int j1 = j - 1;
                // printf("%i-%i-%i \n", i, j1, m_j);
                pre_a[i][j1] = 1;

                if (0 <= j1 - 1 && j1 - 1 <= m && abs(m_j + 1 - i) == 1) {
                    pre_a[i][j1-1] = 1;
                }

                if (0 <= j1 + 1 && j1 + 1 <= m && abs(m_j - 1 - i) == 1) {
                    pre_a[i][j1+1] = 1;
                }
            }
        }
    }
}


void division(int n, int m, float M, float a[n][m], int pre_a[n][m]) {
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            if (pre_a[i][j]) {
                a[i][j] /= M;
            }
        }
    }
}

void division_new(int n, int m, float M, float** a, int pre_a[n][m]) {
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            if (pre_a[i][j]) {
                a[i][j] /= M;
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

    // float A[n][m];
    // fill(n, m, A);
    // printf("A := \n");
    // print_array_float(n, m, A);

    // new code
    float **a = (float **)malloc(n * sizeof(float *));
    if (!a)
        fail();
    // int i, j;
    for (int i = 0; i < n; i++) {
        a[i] = (float *)malloc(m * sizeof(float));
        if (!a[i])
            fail();
    }

    fill_new(n, m, a);

    printf("a := \n");
    print_array_float_new(n, m, a);


    // float M_num = max_nums(n, m, A);
    float M_num = max_nums_new(n, m, a);
    printf("M = %f \n", M_num);

    int pre_A[n][m];
    zeros(n, m, pre_A);
    // division_preparation(n, m, M_num, A, pre_A);
    division_preparation_new(n, m, M_num, a, pre_A);
    printf("pre A := \n");
    print_array_int(n, m, pre_A);

    // division(n, m, M_num, A, pre_A);
    division_new(n, m, M_num, a, pre_A);

    printf("del a := \n");
    // print_array_float(n, m, A);
    print_array_float_new(n, m, a);

    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);

    return 0;
}