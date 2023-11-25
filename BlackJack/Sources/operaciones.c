#include "operaciones.h"
#include "auxiliares.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int display_menu()
{
    int opcion;
    printf("----------BIENVENIDO AL BLACK JACK----------\n");
    printf("============================================\n");
    printf("[1] New Game\n");
    printf("[2] Load Games\n");
    printf("[0] Exit\n");
    printf("============================================\n");
    printf("Introduce una opción entre las anteriores: ");
    scanf("%d", &opcion);
    printf("--------------------------------------------\n");
    return opcion;
}


int start_game(struct partidas partida)
{
    int players, not_correct = 0;
    printf("Introduce la cantidad de jugadores (2-4) o '0' para salir al menú: ");
    scanf("%d", &players);
    
    while (players < 2 || players > 4) {
        if (players == 0)
            return 1;
        printf("Introduce un número de jugadores válido o '0' para salir al menú: ");
        scanf("%d", &players);
    }
    return players;
}

int genera_carta_a(int num1, int num_palo)
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
    if (num1 == 0) {
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
    }
    free(num_carta);
    free(palo);
    return num1;
}

int reparte_cartas(int num1, int num_palo, int num2, int num_palo2)
{
    int punt1 = -1, punt2 = -1;
    if (check_carta(num1, num_palo, num2, num_palo2) == 0) {
        punt1 = genera_carta(num1, num_palo);
    }
    else {
        while (check_carta(num1, num_palo, num2, num_palo2) != 0) {
            num2 = rand() % 13;
            num_palo2 = rand() % 4;
            if (check_carta(num1, num_palo, num2, num_palo2) == 0) {
                punt1 = genera_carta(num1, num_palo);
            }
        }
    }
    return punt1;
}

void game_logic(struct partidas partida, int players)
{
    int punt1 = 0, punt2 = 0, opcion, punt3 = 0;
    for (int i = 0; i < players; i++) {
        partida.player[i] = malloc(sizeof(char) * 50);
        printf("Introduce el nombre del jugador %d: ", i + 1);
        scanf("%s", partida.player[i]);
    }

    printf("¡Que empiece la partida! ¡Suerte!\n");
    for (int i = 0; i < players; i++) {
        srand(time(NULL));
        int num1 = rand() % 13;
        int num_palo = rand() % 4;
        int num2 = rand() % 13;
        int num_palo2 = rand() % 4;
        opcion = -1;
        printf("Turno de: %s\n", partida.player[i]);
        
        punt1 = reparte_cartas(num1, num_palo, num2, num_palo2);
        punt2 = reparte_cartas(num2, num_palo2, num1, num_palo); 
        if (punt1 == 0)
            punt1 = check_A(punt1);
        if (punt2 == 0)
            punt2 = check_A(punt2);
        
            partida.puntos[i] = punt1 + punt2;
            printf("Puntos totales: %d\n", punt1 + punt2);
            printf("[1] Obtener otra carta\n");
            printf("[2] Terminar el turno.\n");

        while (opcion != 2) {
            int num3 = rand() % 13;
            int num_palo3 = rand() % 100;
            printf("¿Qué quieres hacer ahora? Elige una opción: ");
            scanf("%d", &opcion);
            if (opcion == 1) {
                if ((check_carta(num1, num_palo, num3, num_palo3) == 0) && (check_carta(num3, num_palo3, num2, num_palo2) == 0))
                    punt3 = genera_carta_a(num3, num_palo3);
                else {
                    while ((check_carta(num1, num_palo, num3, num_palo3) != 0) && (check_carta(num2, num_palo2, num3, num_palo3) != 0)) {
                        num3 = rand() % 13;
                        num_palo3 = rand() % 4;
                        if ((check_carta(num1, num_palo, num3, num_palo3) == 0) && (check_carta(num3, num_palo3, num2, num_palo2) == 0))
                            punt3 = genera_carta_a(num3, num_palo3);
                    }
                }

                partida.puntos[i] += punt3;
                printf("[1] Obtener otra carta\n");
                printf("[2] Terminar el turno.\n");
                if (partida.puntos[i] > 21) {
                    printf("Los puntos totales superan el máximo, ¡Has perdido!.\n");
                    partida.puntos[i] = 0;
                    break;
                }
                printf("Puntos totales: %d\n", partida.puntos[i]);
            }
            else if (opcion != 2)
                printf("La opción introducida no es una opción válida.\n");
        }
    } //Aqui tengo que decir quien ha ganado y los puntos (Ranking). Tengo que solucionar el randomizado. Tengo que dar la condicion que dos cartas no coincidan.
      //Tengo que cargar las partidas y luego hacer el append de cada partida
}
//Crear otra función de generar_carta pero sin la opcion de si sale A, y ponersela manual en la function.