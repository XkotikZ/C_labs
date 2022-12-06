#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define END 27

int mygetch()
{
    struct termios oldt, newt;
    int c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    // printf("c = %i \n", newt.c_cflag);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    // c = getegid
    // printf("c = %i \n", newt.c_cflag);
    // printf("c = %hhn \n", newt.c_oflag);
    // printf("c = %c \n", toupper(c));
    // printf("c2 = %i \n", getegid());
    // printf("c = %i \n", iscntrl(c));
    // printf("c = %i \n", isxdigit(c));
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    // printf("c3 = %i \n", iscntrl(c));
    // printf("c4 = %i \n", isxdigit(c));
    return c;
}

int main()
{
    // int a;
    // while (mygetch() != END) {
    //     int res = scanf("%d", &a);
    //     printf("%i", res);
    // }
    int c;
    // int res;
    while (true) {
        c = mygetch();
        // res = scanf("%i", c);
        printf("%c", toupper(c));
        // printf("%i \n", c);
        // if (mygetch() == 27) {
        if (c == 27) {
            // printf("1c = %i \n", c);
            break;
        }
    }
    printf("\n");
    return 0;
}
