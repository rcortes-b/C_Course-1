#include "auxiliares.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int genera_carta(int num1, int num_palo)
{
    char *palo;
    char *num_carta;

    palo = malloc(sizeof(char) * 9);
    num_carta = malloc(sizeof(char) * 3);
    
    if (num_palo == 0)
        strcpy(palo, "Corazón");
    else if (num_palo == 1)
        strcpy(palo, "Diamante");
    else if (num_palo == 2)
        strcpy(palo, "Trébol");
    else
        strcpy(palo, "Pica");

    if (num1 == 11) {
        strcpy(num_carta, "J");
        num1 = 10;
    }
    else if (num1 == 12) {
        strcpy(num_carta, "Q");
        num1 = 10;
    }
    else if (num1 == 1) {
        strcpy(num_carta, "K");
        num1 = 10;
    }
    else if (num1 == 0)
        strcpy(num_carta, "A");
    else if (num1 == 10)
        strcpy(num_carta, "10");
    else {
        num_carta[0] = num1 + '0';
        num_carta[1] = '\0';
    }
    
    printf("--------------------------------\n");
    printf("%s\n\n", num_carta);
    printf("             %s\n\n", palo);
    printf("                               %s\n", num_carta);
    printf("--------------------------------\n");

    free(num_carta);
    free(palo);
    return num1;
}

void get_fecha()
{
    time_t t = time(NULL);
    struct tm timeLocal = *localtime(&t);
    char fechaHora[30];
    char *formato = "%d-%m-%Y %H:%M:%S";
    int bytesEscritos = strftime(fechaHora, sizeof fechaHora, formato, &timeLocal);
    if (bytesEscritos != 0) {
        printf("Fecha: %s", fechaHora);
    }
    else
        printf("Error formatenado la fecha");
}

int check_carta(int num1, int num_palo, int num2, int num_palo2)
{
    if (num1 == num2 && num_palo == num_palo2) {
        return 1;
    }
    return 0;
}

int check_A(int num1)
{
    while (num1 != 11 && num1 != 1) {
        if (num1 == 0) {
            printf("La 'A' actúa como comodín. Puedes establecer su valor como 1 o como 11: ");
            scanf("%d", &num1);
        }
        else {
            printf("El valor introducido no es un valor válido.\nInténtalo  de nuevo: ");
            scanf("%d", &num1);
        }
    }
    return num1;
}