//Fichero donde voy a empezar haciendo el menu

#include <stdio.h>

struct employees {
    char name[30];
    int id;
    float salary, hours;
};
struct employees empleado[100];


int alta_empleado()
{
    FILE *f;
    char name[30];
  
    printf("\nIntroduce el nombre del empleado: ");
    scanf("%s", empleado.name);
    printf("Introduce el ID del empleado: ");
    scanf("%d", &id);
    printf("Introduce el salario del empleado: ");
    scanf("%f", &salary);
    printf("Introduce las horas semanales a realizar: ");
    scanf("%f", &hours);
    existant_id = id;
    f = fopen("empleados.txt","r");
    while (feof(f) == 0) {
        if (id == existant_id) { 
            printf("error");
            break;
        }
        else {
            fprintf(f, "%s;%d;%.2f;%.1f\n", name, id, salary, hours);
        }
        fclose(f);
    }
    return 1;
}

void display_menu()
{
    int choose_menu;
    printf("¡Bienvenido/a al gestor de empleados!\n");
    while (choose_menu != 7) {
        printf("\nEscoge la operación que deseas llevar a cabo:\n\n");
        printf("1 - Alta empleado\n");
        printf("2 - Baja empleado\n");
        printf("3 - Listar todos los empleados\n");
        printf("4 - Consultar los datos de un empleado\n");
        printf("5 - Modificar el salario de un empleado\n");
        printf("6 - Modificar horas de trabajo de un empleado\n");
        printf("7 - Salir del menú\n\n");
        printf("Introduce el número de la operación a realizar: ");
        scanf("%d", &choose_menu);

        if (choose_menu == 1) {
          
        }
    }
    printf("¡Gracias por usar el gestor de empleados!\n");
}
int main () {
    display_menu();
}