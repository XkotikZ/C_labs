#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include <termios.h>
#include <unistd.h>


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

int max_len(char *p, char *delim) {
    int max_l = 0, m;

    max_l = strlen(p);
    while ((p = strtok(NULL, delim))){
        m = strlen(p);
        if (max_l < m) {
            max_l = m;
        }
    }

    return max_l;
}

int max_counter(int max_l, char *p, char *delim) {
    int array_len_counter[max_l];
    for (int i = 0; i < max_l; i += 1)
        array_len_counter[i] = 0;

    int l;
    l = strlen(p);
    // printf(" l = %i, %s \n", l, p);
    array_len_counter[l] += 1;
    while ((p = strtok(NULL, delim))) {
        l = strlen(p);
        // printf(" l = %i, %s \n", l, p);
        array_len_counter[l] += 1;
    }

    // for (int i = 0; i < max_l; i += 1) {
    //     printf("%i-%i \n", i, array_len_counter[i]);
    // }

    int max_count = 0;
    int max_count_num = 0;
    for (int i = 0; i < max_l; i += 1) {
        if (max_count < array_len_counter[i]) {
            max_count = array_len_counter[i];
            max_count_num = i + 1;
        }
    }
    return max_count_num-1;
}

void print_str(int max_count, char *p, char *delim) {
    printf("\nout:\n");

    if (strlen(p) != max_count) {
        printf("%s ", p);
    }

    while ((p = strtok(NULL, delim))) {
        if (strlen(p) != max_count) {
            printf("%s ", p);
        }
    }
}

int main()
{
    // char* str = (char *)malloc(sizeof(char) * 100);
    // printf("%s", "Enter string: ");
    // fgets(str, 100, stdin);

    printf("in:\n");
    int i = 0, max_i = 100;
    char* str = (char *)malloc(sizeof(char) * max_i);
    int c;
    while (true) {
        c = mygetch();
        if (c == 10) {
            break;
        }
        // printf("", c);
        printf("%c", tolower(c));
        str[i] = (char)c;
        i += 1;

        if (max_i - i == 5) {
            char* str_swap = (char *)malloc(sizeof(char) * max_i);
            for (int j = 0; j < i; j += 1) {
                str_swap[j] = str[j];
            }
        max_i += 10;
        str = (char *)malloc(sizeof(char) * max_i);
        }
        // printf("%i | ", c);
    }

    str = strtok(str, ",\n");

    int str_len = i;
    // int str_len = strlen(str);
    // printf("%s, %i  \n", str, str_len);
    // char str1[str_len], str2[str_len], str3[str_len];
    char* str1 = (char *)malloc(sizeof(char) * str_len);
    char* str2 = (char *)malloc(sizeof(char) * str_len);
    char* str3 = (char *)malloc(sizeof(char) * str_len);
    for (int i = 0; i < str_len; i += 1) {
        str1[i] = str[i];
        str2[i] = str[i];
        str3[i] = str[i];
    }

    // printf("%s, %li \n", str1, strlen(str1));

    // char str1[] = "Vicariously I live while the whole world"; // Vicariously I live the
    // char str2[] = "Vicariously I live while the whole world";
    // char str3[] = "Vicariously I live while the whole world";

    char delim[] = ", ";

    char *p = strtok(str1, delim);
    int max_l = max_len(p, delim);
    // printf("max_l = %i \n", max_l);

    p = strtok(str2, delim);
    int max_count = max_counter(max_l, p, delim);
    // printf("max_count = %i \n", max_count);

    p = strtok(str3, delim);
    print_str(max_count, p, delim);

    printf("\n");
    return 0;
}
