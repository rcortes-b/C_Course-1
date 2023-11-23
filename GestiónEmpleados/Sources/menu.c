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