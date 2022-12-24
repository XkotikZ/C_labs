#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


struct company_computers{
    char cpu[25]; // процессор
    char size_of_RAM[15]; // объём оперативной памяти
    char size_of_hard_drive[15]; // объём жёсткого диска
    char gpu[25]; // видеоадаптер
    int price; // стоимость
    int year; // год закупки
    char OS_version[15]; // версия обновления
}CCs;


void fill(int len_fill, int len_struct, struct company_computers *database) {
    char cpu[] = "AMD Ryzen 5600H";
    char RAM[] = "16Gb";
    char hard_drive[] = "2Tb";
    char gpu[] = "NVIDIA 3060";
    int price = 10000;
    int year = 2015;
    char OS_v[] = "3.2";

    for (int i = 0; i < len_fill; i += 1) {
        // char i1[3] = i + 1;
        // cpu[11] = (char)(i + 1);
        cpu[11] = i + 1;
        // cpu[11] = i1;
        RAM[1] = (char)(i + 1);
        hard_drive[0] = (char)(i + 1);
        gpu[7] = (char)(i + 1);

        strncpy(database[i].cpu, cpu, 25);
        strncpy(database[i].size_of_RAM, RAM, 15);
        strncpy(database[i].size_of_hard_drive, hard_drive, 15);
        strncpy(database[i].gpu, gpu, 25);
        database[i].price = price * (i + 1);
        database[i].year = year + i;
        strncpy(database[i].OS_version, OS_v, 15);

        // strncpy(database[i].cpu, "AMD Ryzen 5600H", 25);
        // strncpy(database[i].size_of_RAM, "16Gb", 15);
        // strncpy(database[i].size_of_hard_drive, "2Tb", 15);
        // strncpy(database[i].gpu, "NVIDIA 3060", 25);
        // database[i].price = 75000;
        // database[i].year = 2019;
    }
}

int new_computer(int num_computers, struct company_computers *database) {
    char* cpu = (char *)malloc(sizeof(char) * 25);
    printf("%s", "Enter cpu name: ");
    fgets(cpu, 25, stdin);
    strncpy(database[num_computers].cpu, cpu, 25);

    char* RAM = (char *)malloc(sizeof(char) * 15);
    printf("%s", "Enter size of RAM: ");
    fgets(RAM, 15, stdin);
    strncpy(database[num_computers].size_of_RAM, RAM, 15);

    char* hard_drive = (char *)malloc(sizeof(char) * 15);
    printf("%s", "Enter size of hard drive: ");
    fgets(hard_drive, 15, stdin);
    strncpy(database[num_computers].size_of_hard_drive, hard_drive, 15);

    char* gpu = (char *)malloc(sizeof(char) * 25);
    printf("%s", "Enter gpu name: ");
    fgets(gpu, 25, stdin);
    strncpy(database[num_computers].gpu, gpu, 25);

    printf("%s", "Enter price: ");
    int price;
    scanf("%i", &price);
    database[num_computers].price = price;

    printf("%s", "Enter year: ");
    int year;
    scanf("%i", &year);
    database[num_computers].year = year;

    char* OS_v = (char *)malloc(sizeof(char) * 15);
    printf("%s", "Enter OS version: ");
    fgets(OS_v, 15, stdin);
    strncpy(database[num_computers].OS_version, OS_v, 15);

    num_computers += 1;
    return num_computers;
}

int del_computer(int num_del, int num_computers, struct company_computers *database) {
    printf("del f");
    // for (int i = num_del; num_del < num_computers; i += 1) {
    //     database[0] = database[i+1];
    // }
    // int i;
    printf("%i-%i \n", num_del, num_computers);
    if (num_del > num_computers) {
        return num_computers;
    }
    for (int i = num_del; num_del <= num_computers; i += 1) {
        if (i < num_computers) {
            printf("%i \n", i);
        }
        strncpy(database[i].cpu, database[i+1].cpu, 25);
        strncpy(database[i].size_of_RAM, database[i+1].size_of_RAM, 15);
        strncpy(database[i].size_of_hard_drive, database[i+1].size_of_hard_drive, 15);
        strncpy(database[i].gpu, database[i+1].gpu, 25);
        database[i].price = database[i+1].price;
        database[i].year = database[i+1].year;
        strncpy(database[i].OS_version, database[i+1].OS_version, 15);
    }

    int i = num_computers;
    strncpy(database[i+1].cpu, "", 25);
    strncpy(database[i+1].size_of_RAM, "", 15);
    strncpy(database[i+1].size_of_hard_drive, "", 15);
    strncpy(database[i+1].gpu, "", 25);
    database[i+1].price = 0;
    database[i+1].year = 0;
    strncpy(database[i+1].OS_version, "", 15);

    num_computers -= 1;
    return num_computers;
}

void print_OS_version(int len_struct, struct company_computers *database) {
    for (int i = 0; i < len_struct; i += 1) {
        printf("-- pc №%i -- \n", i + 1);
        // print_data();
        printf("%s \n", database[i].OS_version);
    }
    printf("\n");
}

void print_data(struct company_computers data) {
    printf("CPU: %s \n", data.cpu);
    printf("RAM: %s \n", data.size_of_RAM);
    printf("HD: %s \n", data.size_of_hard_drive);
    printf("GPU: %s \n", data.gpu);
    printf("price: %i \n", data.price);
    printf("year: %i \n", data.year);
    printf("OS version: %s \n", data.OS_version);

    // printf("%s \n", data.cpu);
    // printf("%s \n", data.size_of_RAM);
    // printf("%s \n", data.size_of_hard_drive);
    // printf("%s \n", data.gpu);
    // printf("%i \n", data.price);
    // printf("%i \n", data.year);
    // printf("%s \n", data.OS_version);
}

void print_database(int len_struct, struct company_computers *database) {
    for (int i = 0; i < len_struct; i += 1) {
        printf("-- pc №%i -- \n", i + 1);
        print_data(database[i]);
        printf("\n");
    }
}

int main()
{
    // struct company_computers ff = CCs;
    int num_computers = 3, len_datebase = 100;
    struct company_computers *database = (struct company_computers *)malloc(len_datebase * sizeof(struct company_computers));

    fill(num_computers, len_datebase, database);

    // strncpy(database[0].cpu, "AMD Ryzen 5600H", 25);
    // strncpy(database[0].size_of_RAM, "16Gb", 15);
    // strncpy(database[0].size_of_hard_drive, "2Tb", 15);
    // strncpy(database[0].gpu, "NVIDIA 3060", 25);
    // database[0].price = 75000;
    // database[0].year = 2019;

    // print_data(database[0]);
    // print_database(num_computers, database);

    char menu[] = "Выбор действий: \n 1) вывод базы данных \n 2) добавить пк \n 3) удалить пк \n 4) посмотреть обновления для пк \n 0) выход \nвыбор: ";

    // char* choise = (char *)malloc(sizeof(char) * 2);
    // printf("%s", "Enter OS version: ");
    // fgets(choise, 15, stdin);

    while (true) {
        printf("%s", menu);

        int choise;
        scanf("%i", &choise);
        // fgets(choise, 2, stdin);
        printf("\n");

        printf("choise = %i \n", choise);

        if (choise == 0) {
            break;
        } else if (choise == 1) {
            print_database(num_computers, database);
        } else if (choise == 2) {
            num_computers = new_computer(num_computers, database);
        } else if (choise == 3) {
            printf("%s", "Какой пк удалить: ");
            int num_del;
            scanf("%i", &num_del);
            num_computers = del_computer(num_del-1, num_computers, database);
        } else if (choise == 4) {
            print_OS_version(num_computers, database);
            // check_update(num_computers, database);
        }

        // break;
    }

    // printf("\n");
    return 0;
}

// Конечно не так, ведь будь всё так, так бы не было!