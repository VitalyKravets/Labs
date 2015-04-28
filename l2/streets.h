#ifndef HOLIDAYS_H
#define HOLIDAYS_H

struct Street
{
    int ID;
    char Name[100];
    int Buildings;
    int Length;
};

void print(FILE* f);
void edit(FILE* f);
void del(FILE* f);
void add(FILE* f);

#endif // HOLIDAYS_H
