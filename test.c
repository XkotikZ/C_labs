#include <stdio.h>
#include <stdlib.h>

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

int find_odd(size_t length, const int array[length])
{
//   for (int i = 0; i < lenght; i+=1) {
//     printf("%d", array[i]);
//   }
  print("%d", length);
  return 0;
}

int main() {
    find_odd(5, ((const int[]){20, 1, -1, 2, -2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, -2, 5}));
    // dna_strand("ATTGC");
}