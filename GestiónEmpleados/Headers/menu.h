
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

struct empleado {
    char name[100];
    int id;
    float salary;
    float hour;
};

void display_menu();

#endif