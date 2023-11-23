#include <stdio.h>
#include "menu.h"

void display_menu()
{
        printf("\nEscoge la operación que deseas llevar a cabo:\n\n");
        printf("1 - Alta empleado\n");
        printf("2 - Baja empleado\n");
        printf("3 - Listar todos los empleados\n");
        printf("4 - Consultar los datos de un empleado\n");
        printf("5 - Modificar el salario de un empleado\n");
        printf("6 - Modificar horas de trabajo de un empleado\n");
        printf("7 - Salir del menú\n\n");
        printf("Introduce el número de la operación a realizar: ");
}

void list_empleados(struct empleado empleados[100], int emp_cant)
{
        for (int i = 0; i < emp_cant; i++) {
                if (emp_cant == 1 && empleados[i].id == 0) {
                    printf("\nNo hay empleados para listar.\n");
                    break;
                }
                else {
                    printf("\nNombre: %s\n", empleados[i].name);
                    printf("ID de Empleado: %d\n", empleados[i].id);
                    printf("Salario: %.2f\n", empleados[i].salary);
                    printf("Horas: %.1f\n", empleados[i].hour);
                }
        }
}

int comprobarID(struct empleado empleados[100], int emp_cant, int id)
{
    for (int i = 0; i < emp_cant; i++) {
        if (empleados[i].id == id)
            return (1);
    }
    return (0);
}

int alta_empleado(struct empleado empleados[100], int emp_cant)
{
    int created = 0;
    struct empleado emp;
    printf("\nIntroduzca el nombre del empleado: ");
    scanf("%s", emp.name);
    printf("Introduzca el ID que desea asignar al empleado: ");
    scanf("%d", &emp.id);
    printf("Introduzca el salario a recibir del empleado: ");
    scanf("%f", &emp.salary);
    printf("Introduzca las horas a realizas por el empleado: ");
    scanf("%f", &emp.hour);
    
    if (comprobarID(empleados, emp_cant, emp.id) == 0 && emp.id != 0) {
        empleados[emp_cant] = emp;
        created = 1;
    }
    else {
        printf("\nError al registrar el empleado. El ID ya está en uso o has introducido un ID no válido.\n");
        //alta_empleado(empleados, emp_cant);
    }
    return created;
}

int baja_empleado(struct empleado empleados[100], int emp_cant)
{
    int id, line = 0;
    struct empleado temp;
    printf("\nIntroduce el ID del empleado que quieres dar de baja: ");
    scanf("%d", &id);
    
    if (comprobarID(empleados, emp_cant, id) == 1) {
        for (int i = 0; i < emp_cant; i++) {
            if (id == empleados[i].id) {
                line = i;
            }
        }
        for (int j = line; j < (emp_cant - 1); j++) {
            empleados[j] = empleados[j + 1];
            empleados[j + 1] = temp;
        }
    }
    else {
        printf("\nEl empleado que estás buscando no existe.\n");
        return 0;
    }
    return 1;
}

void consulta_datos(struct empleado empleados[100], int emp_cant)
{
    int id;
    printf("\nIntroduce el ID del empleado cuyos datos quieres consultar: ");
    scanf("%d", &id);

        if (comprobarID(empleados, emp_cant, id) == 1) {
             for (int i = 0; i < emp_cant; i++) {
                if (id == empleados[i].id) {
                    printf("\nListando los datos del empleado con ID: %d\n", id);
                    printf("Nombre del empleado: %s\n", empleados[i].name);
                    printf("Sueldo del empleado: %.2f\n", empleados[i].salary);
                    printf("Horas semanales: %.1f\n", empleados[i].hour);
                }
            }
        }
        else
            printf("\nEl empleado cuyos datos quieres consultar no existe.\n");
}

void modificar_datos(struct empleado empleados[100], int emp_cant, int option)
{
    int id;
    float temp;
    if (option == 5) {
        printf("\nIntroduce el ID del empleado cuyo salario quieres modificar: ");
        scanf("%d", &id);

        if (comprobarID(empleados, emp_cant, id) == 1) {
             for (int i = 0; i < emp_cant; i++) {
                if (id == empleados[i].id) {
                    printf("Introduce el nuevo salario a percibir por el empleado: ");
                    scanf("%f", &temp);
                    if (empleados[i].salary == temp)
                        printf("\nEl empleado ya percibe el salario introducido.\n");
                    else {
                        empleados[i].salary = temp;
                        printf("\nSalario actualizado.\n");
                    }
                    break;
                }
            }
        }
        else
            printf("\nEl empleado cuyo salario quieres modificar no existe.\n");
    }
    else if (option == 6) {
        printf("\nIntroduce el ID del empleado cuyas horas quieres modificar: ");
        scanf("%d", &id);

        if (comprobarID(empleados, emp_cant, id) == 1) {
             for (int i = 0; i < emp_cant; i++) {
                if (id == empleados[i].id) {
                    printf("Introduce las nuevas horas a realizar por el empleado: ");
                    scanf("%f", &temp);
                    if (empleados[i].hour == temp)
                        printf("\nEl empleado ya trabaja las horas introducidas.\n");
                    else {
                        empleados[i].hour = temp;
                        printf("\nHoras actualizadas.\n");
                    }
                    break;
                }
            }
        }
        else
            printf("\nEl empleado cuyas horas quieres modificar no existe.\n");
    }
}