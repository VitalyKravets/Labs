#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include "menu.h"
#include "streets.h"

int menu(void)
{
    setlocale(0, "rus");
    FILE *streets = fopen("streets.tab", "rb+");
    if (!streets)
        streets = fopen("streets.tab", "wb+");
    char ch;

    do
    {
        while (getchar() != '\n');
        print_menu();
        ch = getchar();
        switch (ch)
        {
        case '1':
            add(streets);
            break;
        case '2':
            del(streets);
            break;
        case '3':
            edit(streets);
            break;
        case '4':
            print(streets);
            break;
        }
    } while (ch != '0');

    return 0;
}

void print_menu()
{
    printf("\n1: Вставить строку");
    printf("\n2: Удалить строку");
    printf("\n3: Изменить строку");
    printf("\n4: Напечатать таблицу");
    printf("\n0: Выход\n");
}


