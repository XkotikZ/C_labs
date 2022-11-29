#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// char dna_strand(const char *dna)
// {
//     int I = 0;
//     while (dna[I] != 0) {
//         I += 1;
//     }

//     char new_dna[I + 1];
//     // T - 84
//     // A - 65
//     // G - 71
//     // C - 67
//     for (int i = 0; i < I; i += 1) {
//         printf("%i ", dna[i]);
//         if (dna[i] == 84) {
//             new_dna[i] = 'A';
//         } else if (dna[i] == 65) {
//             new_dna[i] = 'T';
//         }

//         if (dna[i] == 71) {
//             new_dna[i] = 'C';
//         } else if (dna[i] == 67) {
//             new_dna[i] = 'G';
//         }
//     }

//     printf("%s", new_dna);
//     return new_dna;
// }

// int find_odd(size_t length, const int array[length])
// {
// //   for (int i = 0; i < lenght; i+=1) {
// //     printf("%d", array[i]);
// //   }
//   print("%d", length);
//   return 0;
// }

int is_armstrong_number(int x) {
    int x_c = x;
    int c = 0;
    while (x_c > 0) {
        x_c /= 10;
        c += 1;
    }
    printf("c = %i \n", c);
    x_c = x;
    int a = 0;
    while (x_c > 0) {
        printf("a += %i \n", (int)pow(x_c % 10, c));
        a += (int)pow(x_c % 10, c);
        x_c /= 10;
    }

    printf("x = %i \n", x);
    printf("a = %i \n", a);

    if (x == a) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    printf("Enter n -> ");
    scanf("%i", &n);
    printf("%i", is_armstrong_number(n));
}