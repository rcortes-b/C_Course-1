#include "operaciones.h"
#include "persistencia.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int opcion = -1;
    int players = 0;
    struct partidas partida;
    //get_fecha();
    //srand(time(NULL));
    //for (int i = 0; i < 5; i++) {printf("%d\n", rand() % 100);}

    while (opcion != 0) {
        opcion = display_menu();
        if (opcion == 1) {
            players = start_game(partida);
            game_logic(partida, players);
            //for (int i = 0; i < players; i++)
            //    printf("Nombre player: %s\n", partida.player[i]);
        }
        else if (opcion == 2) {
            printf("\nLoad Games\n\n");
    
        }
        else if (opcion != 0)
            printf("\nIntroduce una opción válida.\n\n");
    }
    printf("\nGracias por jugar al BlackJack,\n¡esperamos volver a verte pronto!\n");
}

//Formato de 'FILE'--->Fecha: %s--Name: %s - Points: %d;Name2: %s - Points2: %d\n