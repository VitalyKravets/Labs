#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "streets.h"

void add(FILE* f)
{
    struct Street *p = malloc(sizeof(struct Street));
    char buf[100];

    if ((fread(p, sizeof(struct Street), 1, f) == 1))
    {
        fseek(f, -sizeof(struct Street), SEEK_END);
        do
        {
            if (fread(p, sizeof(struct Street), 1, f) != 1)
                break;
            fseek(f, -2*sizeof(struct Street), SEEK_CUR);
        } while (p->ID == -1);
        fseek(f, 2*sizeof(struct Street), SEEK_CUR);
        (p->ID)++;
    }
    else
        p->ID = 0;
    fseek(f, 0, SEEK_END);
    while(getchar() != '\n');
    printf("\nНазвание улицы: ");
    gets(p->Name);
    printf("\nКоличество домов: ");
    gets(buf);
    p->Buildings = atoi(buf);
    printf("\nПротяженность улицы (км): ");
    gets(buf);
    p->Length = atoi(buf);
    fwrite(p, sizeof(struct Street), 1, f);
    free(p);
    fseek(f, 0, SEEK_SET);
}

void del(FILE* f)
{
    int id;
    long pos;

    printf("\nВведите ID строки: ");
    scanf("%d", &id);
    fseek(f, sizeof(struct Street) * id, SEEK_SET);

    struct Street *p = malloc(sizeof(struct Street));
    while ((fread(p, sizeof(struct Street), 1, f) == 1) && (p->ID != id));
    if (p->ID == id)
    {
        p->ID = -1;
        pos = ftell(f);
        fseek(f, pos - sizeof(struct Street), SEEK_SET);
        fwrite(p, sizeof(struct Street), 1, f);
    }
    else
    {
        printf("\nЗапись с данным ID не найдена.");
    }
    free(p);
}

void edit(FILE* f)
{
    int id;
    char buf[100];
    printf("\nВведите ID строки: ");
    scanf("%d", &id);
    fseek(f, id * sizeof(struct Street), SEEK_SET);
    struct Street *p = malloc(sizeof(struct Street));
    while ((fread(p, sizeof(struct Street), 1, f) == 1) && (p->ID != id));
    while (getchar() != '\n');
    if (p->ID == id)
    {
        printf("\nНазвание улицы: ");
        gets(p->Name);
        printf("\nКоличество домов: ");
        gets(buf);
        p->Buildings = atoi(buf);
        printf("\nПротяженность улицы (км): ");
        gets(buf);
        p->Length = atoi(buf);
        fseek(f, - sizeof(struct Street), SEEK_CUR);
        fwrite(p, sizeof(struct Street), 1, f);
    }
    else
    {
        printf("\nЗапись с данным ID не найдена.");
    }

    free(p);
}

void print(FILE* f)
{
    fseek(f, 0, SEEK_SET);
    struct Street *p = malloc(sizeof(struct Street));
    printf("\n   ID   Название  \t\t\t\tКол-во домов\tПротяженность");
    while (fread(p, sizeof(struct Street), 1, f) == 1)
    {
        OemToChar(p->Name, p->Name);
        if (p->ID != -1)
        {
            printf("\n%4d\t%-35s %7d\t\t %7d", p->ID, p->Name, p->Buildings, p->Length);

        }
    }
    printf("\n\n");
    fseek(f, 0, SEEK_SET);
}
