#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "menu.h"

int cargarEmpleados(struct empleado empleados[100]) //Se busca saber la cantidad de empleados que hay registrados
{
    int nEmp = 0, dato = 0;
    FILE *f;
    f = fopen("empleados.txt","r");
    struct empleado emp;
    char cadena[255];
    char sep[] = ";";
    char *token;
    while (feof(f) == 0) {
        fgets(cadena, 255, f); //Coge cada linea del file 'empleados.txt'
        token = strtok(cadena, sep); //Se le asigna a la primera posición del token la primera cadena HASTA que llega al separador, es decir, el nombre
        if (token != NULL) {
            dato = 1;
            while (token != NULL) { //Mientras token no encuentre una coincidencia con el separador, es decir, hasta que no sea NULL
                if (dato == 1)
                    strcpy(emp.name, token);
                else if (dato == 2)
                    emp.id = atoi(token);
                else if (dato == 3)
                    emp.salary = atof(token);
                else if (dato == 4)
                    emp.hour = atof(token);
                dato++;
                token = strtok(NULL, sep); //Se le asigna un NULL al final
            }
        }
        empleados[nEmp] = emp; //Almacena cada empleado en el array de empleados
        nEmp++;
    }
    fclose(f);
    return (nEmp); //Devuelve la cantidad de empleados
}