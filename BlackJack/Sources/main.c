#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int opcion = -1, players = 0;
    FILE *f;
    struct partidas partida;

    while (opcion != 0) {
        opcion = display_menu();
        if (opcion == 1) {
            players = start_game();
            if (players != 0) {
                for (int i = 0; i < players; i++) {
                    partida.player[i] = malloc(sizeof(char) * 50);
                    printf("Introduce el nombre del jugador %d: ", i + 1);
                    scanf("%s", partida.player[i]);
                }
                ranking(&partida, players);
                add_game(&partida, players);
            }
        }
        else if (opcion == 2) {
            printf("\n");
            read_file();
            printf("\n");
        }
        else if (opcion != 0)
            printf("\nIntroduce una opción válida.\n\n");
    }
    for (int j = 0; j < players; j++)
        free (partida.player[j]);
    printf("\nGracias por jugar al BlackJack,\n¡esperamos volver a verte pronto!\n");
}