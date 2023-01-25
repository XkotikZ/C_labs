#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int mygetch()
{
    struct termios oldt, newt;
    int c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

void wheel(int n, int c, int last_num_print[n]) {
    for (int i = 0; i < n - 1; i += 1) {
        last_num_print[i] = last_num_print[i + 1];
    }
    last_num_print[n] = c;
}

int main()
{
    int c;
    int i, n = 5, end_c, print = 1;
    // int last_27 = 0;
    int last_num[n], last_num_print[n];
    for (i = 0; i < n; i += 1) {
        last_num[i] = 0;
        last_num_print[i] = 0;
    }

    int end_num[] = {27, 91, 49, 57, 126};

    while (true) {
        c = mygetch();

        //  27 0033 0x1b
        //  91 0133 0x5b
        //  49 0061 0x31
        //  57 0071 0x39
        //  126 0176 0x7e

        for (i = 0; i < n - 1; i += 1) {
            last_num[i] = last_num[i + 1];
            last_num_print[i] = last_num_print[i + 1];
        }

        last_num[n-1] = c;
        last_num_print[n-1] = c;
        // last_num[i+1] = c;
        // last_num[0] = c;

        end_c = 0;
        for (i = 0; i < n; i += 1) {
            if (last_num[i] == end_num[i]) {
                end_c += 1;
                // printf("%i -", c[i]);
            }
        }
        if (n == end_c) {
            break;
        }

        print = 1;
        for (i = 0; i < n; i += 1) {
            if (last_num_print[i] == 27) {
                if (last_num_print[i] == 27 && last_num_print[i+1] == 79) {
                    print = 0;
                    // printf("(%d)", c);
                    wheel(n, c, last_num_print);
                    wheel(n, c, last_num_print);
                    break;
                }
                print = 0;
             }
        }

        if (print == 1) {
            printf("%c", toupper(c));
            // printf("d = %d \n", c);
            // for (i = 0; i < n; i += 1) {
            //     // printf("%i ", last_num[i]);
            //     printf("%i ", last_num_print[i]);
            // }
            // printf("\n");
        }
    }
    printf("\n");
    return 0;
}