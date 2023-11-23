
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

struct empleado {
    char name[100];
    int id;
    float salary;
    float hour;
};

void display_menu();
void list_empleados(struct empleado empleados[100], int emp_cant);
int comprobarID(struct empleado empleados[100], int emp_cant, int id);
int alta_empleado(struct empleado empleados[100], int emp_cant);
int baja_empleado(struct empleado empleados[100], int emp_cant);
void consulta_datos(struct empleado empleados[100], int emp_cant);
void modificar_datos(struct empleado empleados[100], int emp_cant, int option);

#endif