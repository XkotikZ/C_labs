#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include <termios.h>
#include <unistd.h>

struct hotel{
    char name[25]; // наименование
    char address[25]; // адрес
    char phone[25]; // телефон
    int number_of_stars; // кол-во звёзд
    int number_of_rooms; // количество номеров
    int number_of_suites; // количество номеров люкс
    int available_rooms; // свободные номера
};


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

void my_gets(char *str, char *text) {
    printf("%s", text);
    int i = 0;
    // char* str = (char *)malloc(sizeof(char) * max_i);
    int c;
    while (true) {
        c = mygetch();
        if (c == 10) {
            break;
        }

        printf("%c", tolower(c));
        str[i] = (char)c;
        i += 1;

    }
    printf("\n");
}


void fill(int len_fill, int len_struct, struct hotel *database) {
    // char name[] = "Space";
    strncpy(database[0].name, "Space", 25);
    // char address[] = "somewhere in Moscow";
    strncpy(database[0].address, "somewhere in Moscow", 25);
    // char phone[] = "+79221999666";
    strncpy(database[0].phone, "+79221999666", 25);
    database[0].number_of_stars = 5;
    database[0].number_of_rooms = 512;
    database[0].number_of_suites = 256;
    database[0].available_rooms = 128;

    // char name2[] = "Elion";
    strncpy(database[1].name, "Elion", 25);
    // char address2[] = "somewhere not in Moscow";
    strncpy(database[1].address, "somewhere not in Moscow", 25);
    // char phone2[] = "+79228666999";
    strncpy(database[1].phone, "+79228666999", 25);
    database[1].number_of_stars = 4;
    database[1].number_of_rooms = 256;
    database[1].number_of_suites = 128;
    database[1].available_rooms = 64;

    // char name3[] = "Three cats";
    strncpy(database[2].name, "Three cats", 25);
    // char address3[] = "somewhere not in Moscow";
    strncpy(database[2].address, "somewhere not in Moscow", 25);
    // char phone3[] = "+79222800555";
    strncpy(database[2].phone, "+79222800555", 25);
    database[2].number_of_stars = 4;
    database[2].number_of_rooms = 128;
    database[2].number_of_suites = 64;
    database[2].available_rooms = 32;
}


int new_hotel(int num_hotels, struct hotel *database) {
    // char name[25]; // наименование
    // int number_of_stars; // кол-во звёзд
    // char address[25]; // адрес
    // char phone[12]; // телефон
    // int number_of_rooms; // количество номеров
    // int number_of_suites; // количество номеров люкс
    // int available_rooms; // свободные номера

    char* name = (char *)malloc(sizeof(char) * 25);
    my_gets(name, "Enter hotel name: ");
    strncpy(database[num_hotels].name, name, 25);

    char* address = (char *)malloc(sizeof(char) * 25);
    my_gets(address, "Enter hotel address: ");
    strncpy(database[num_hotels].address, address, 25);

    char* phone = (char *)malloc(sizeof(char) * 12);
    my_gets(phone, "Enter hotel phone: ");
    strncpy(database[num_hotels].phone, phone, 12);

    printf("Enter hotel number_of_stars: ");
    scanf("%i", &database[num_hotels].number_of_stars);

    printf("Enter hotel number_of_rooms: ");
    scanf("%i", &database[num_hotels].number_of_rooms);

    printf("Enter hotel number_of_suites: ");
    scanf("%i", &database[num_hotels].number_of_suites);

    printf("Enter hotel available_rooms: ");
    scanf("%i", &database[num_hotels].available_rooms);

    num_hotels += 1;
    return num_hotels;
}

int del_hotel(int num_del, int num_hotels, struct hotel *database) {
    // printf("%i-%i \n", num_del, num_hotels);
    if (num_del >= num_hotels) {
        return num_hotels;
    }

    for (int i = num_del; i < num_hotels; i += 1) {
        strncpy(database[i].name, database[i+1].name, 25);
        database[i].number_of_stars = database[i+1].number_of_stars;
        strncpy(database[i].address, database[i+1].address, 25);
        strncpy(database[i].phone, database[i+1].phone, 12);
        database[i].number_of_rooms = database[i+1].number_of_rooms;
        database[i].number_of_suites = database[i+1].number_of_suites;
        database[i].available_rooms = database[i+1].available_rooms;
    }

    // printf("end");
    int i = num_hotels;

    strncpy(database[i].name, "", 25);
    database[i].number_of_stars = 0;
    strncpy(database[i].address, "", 25);
    strncpy(database[i].phone, "", 12);
    database[i].number_of_rooms = 0;
    database[i].number_of_suites = 0;
    database[i].available_rooms = 0;

    num_hotels -= 1;
    return num_hotels;
}


void print_data(struct hotel data) {
    printf("name: %s \n", data.name);
    printf("address: %s \n", data.address);
    printf("phone: %s \n", data.phone);
    printf("number_of_stars: %i \n", data.number_of_stars);
    printf("number_of_rooms: %i \n", data.number_of_rooms);
    printf("number_of_suites: %i \n", data.number_of_suites);
    printf("available_rooms: %i \n", data.available_rooms);
}

void print_database(int len_struct, struct hotel *database) {
    for (int i = 0; i < len_struct; i += 1) {
        printf("-- отель №%i -- \n", i + 1);
        print_data(database[i]);
        printf("\n");
    }
}


void print_best_hotel(int len_struct, struct hotel *database) {
    int max_i = 0;
    int max_available_rooms = database[max_i].available_rooms;
    for (int i = 1; i < len_struct; i += 1) {
        if (max_available_rooms < database[i].available_rooms) {
            max_i = i;
            max_available_rooms = database[i].available_rooms;
        }
    }

    printf("Гостиница с самым большим количеством свободных номеров \n");
    print_data(database[max_i]);

    printf("\n");
}


int main()
{
    int num_hotels = 3, len_datebase = 100;
    struct hotel *database = (struct hotel *)malloc(len_datebase * sizeof(struct hotel));

    fill(num_hotels, len_datebase, database);

    char menu[] = "Выбор действий: \n 1) вывод всех отелей \n 2) добавить новый отель \n 3) удалить отель \n 4) данные о гостинице с самым большим количеством свободных номеров \n 0) выход \nвыбор: ";

    while (true) {
        printf("%s", menu);

        // int choise;
        // scanf("%i", &choise);
        // printf("\n");


        char* choise = (char *)malloc(sizeof(char) * 10);
        my_gets(choise, "");

        if (choise[0] == '0' || choise[0] == '1' || choise[0] == '2' || choise[0] == '3' || choise[0] == '4') {
            printf("\n");

            if (choise[0] == '0') {
                break;
            } else if (choise[0] == '1') {
                print_database(num_hotels, database);
            } else if (choise[0] == '2') {
                num_hotels = new_hotel(num_hotels, database);
                my_gets(choise, "");
            } else if (choise[0] == '3') {
                printf("%s", "Какой отель удалить (0-отмена): ");
                int num_del;
                scanf("%i", &num_del);
            my_gets(choise, "");
                num_hotels = del_hotel(num_del-1, num_hotels, database);
            } else if (choise[0] == '4') {
                print_best_hotel(num_hotels, database);
            }

        }
    }

    // printf("\n");
    return 0;
}