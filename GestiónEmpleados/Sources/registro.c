#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "menu.h"

int cargarEmpleados(struct empleado empleados[100])
{
    int nEmp = 0, dato = 0;
    FILE *f;
    f = fopen("empleados.txt","r");
    struct empleado emp;
    char cadena[255];
    char sep[] = ";";
    char *token;
    while (feof(f) == 0) {
        fgets(cadena, 255, f);
        token = strtok(cadena, sep);
        if (token != NULL) {
            dato = 1;
            while (token != NULL) {
                if (dato == 1)
                    strcpy(emp.name, token);
                else if (dato == 2)
                    emp.id = atoi(token);
                else if (dato == 3)
                    emp.salary = atof(token);
                else if (dato == 4)
                    emp.hour = atof(token);
                dato++;
                token = strtok(NULL, sep);
            }
        }
        empleados[nEmp] = emp;
        nEmp++;
    }
    fclose(f);
    return (nEmp);
}