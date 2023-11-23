#include <stdio.h>
#include "menu.h"
#include "registro.h"

int main() {
    
    int choose_menu;
    struct empleado empleados[100]; //Defino un array donde almaceno los datos de cada empleado
    
    int emp_cant = 0;
    emp_cant = cargarEmpleados(empleados);  //Le asigno a la variable la cantidad de empleados que habrán
    printf("El número de empleados es %d", emp_cant);

    printf("¡Bienvenido/a al gestor de empleados!\n"); //Bienvenida al Software
    display_menu(); //Se imprimen las opciones por pantalla
    scanf("%d", &choose_menu);
    while (choose_menu != 7) { //Elige una opción (Dentro del bucle siempre y cuando no pongas 7)
        if (choose_menu == 1) {
            if (alta_empleado(empleados, emp_cant) == 1)
                emp_cant++;
        }
        else if (choose_menu == 2) {
            if (baja_empleado(empleados, emp_cant) == 1)
                emp_cant--;
        }
        else if (choose_menu == 3) {
            list_empleados(empleados, emp_cant);
        }
        else if (choose_menu == 4) {
            consulta_datos(empleados, emp_cant);
        }
        else if (choose_menu == 5) {
            modificar_datos(empleados, emp_cant, choose_menu);
        }
        else if (choose_menu == 6) {
            modificar_datos(empleados, emp_cant, choose_menu);
        }
        else if (choose_menu != 7) {
            printf("\nLa opción elegida no es una opción válida\n");
        }
        if (choose_menu != 7) { //Para que no termine el software y siempre y cuando no sea 7 (para salir) va imprimiendo el menú
            display_menu();
            scanf("%d", &choose_menu);
        }
    }
    save_datos(empleados, emp_cant);
    printf("\nHas salido del menú. ¡Gracias por usar el gestor de empleados!\n"); //Cuando introduce 7 se termina el bucle y da las gracias por usar el software - FIN DE PROGRAMA
    return 0;
}