#include "operaciones.h"
#include "auxiliares.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int display_menu() //Menú inicial
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


int start_game()
{
    int players;
    printf("Introduce la cantidad de jugadores (2-4) o '0' para salir al menú: ");
    scanf("%d", &players);
    
    while (players < 2 || players > 4) {
        if (players == 0)
            return 0;
        printf("Introduce un número de jugadores válido o '0' para salir al menú: ");
        scanf("%d", &players);
    }
    return players; //Calcula la cantidad de players que habrán en la partida
}

int genera_carta_a(int num1, int num_palo) //Genera una carta y si es un A da opción a valer 1 u 11 puntos
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

int reparte_cartas(int num1, int num_palo, int num2, int num_palo2) //Genera una carta, habiendo comprobado ya que no coincida con la anterior (Válido para la 2da)
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

void game_logic(struct partidas *partida, int players)
{
    int punt1 = 0, punt2 = 0, punt3 = 0;

    printf("¡Que empiece la partida! ¡Suerte!\n");
    for (int i = 0; i < players; i++) {
        srand(time(NULL));
        int num1 = rand() % 13, num_palo = rand() % 4; //Randomizado primera carta
        int num2 = rand() % 13, num_palo2 = rand() % 4; //Randomizado segunda carta
        int opcion = -1;
        printf("Turno de: %s\n", partida->player[i]);
        
        punt1 = reparte_cartas(num1, num_palo, num2, num_palo2); //Se genera la primera carta
        punt2 = reparte_cartas(num2, num_palo2, num1, num_palo); //Se genera la segunda carta
        if (punt1 == 0)
            punt1 = check_A(punt1);
        if (punt2 == 0)
            punt2 = check_A(punt2);
        
        partida->puntos[i] = punt1 + punt2;
        printf("Puntos totales: %d\n", punt1 + punt2);
        printf("[1] Obtener otra carta\n");
        printf("[2] Terminar el turno.\n");

        while (opcion != 2) {
            int num3 = rand() % 13, num_palo3 = rand() % 100;
            printf("¿Qué quieres hacer ahora? Elige una opción: ");
            scanf("%d", &opcion);
            if (opcion == 1) { //Comprueba que la carta no coincida con la primera y la segunda (si hay una cuarta no serviría para la tercera)
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
                partida->puntos[i] += punt3;
                printf("[1] Obtener otra carta\n");
                printf("[2] Terminar el turno.\n");
                if (partida->puntos[i] > 21) {
                    printf("Los puntos totales superan el máximo, ¡Has perdido!.\n");
                    partida->puntos[i] = 0;
                    break;
                }
                printf("Puntos totales: %d\n", partida->puntos[i]);
            }
            else if (opcion != 2)
                printf("La opción introducida no es una opción válida.\n");
        }
    } //Tengo que perfeccionar la condicion de que dos cartas no coincidan.
}

void ranking(struct partidas *partida, int players)
{
    game_logic(partida, players);
    char temp_name[30];
    int temp_points, last_player = 0;
    for (int i = 0; i < players - 1; i++) {
        for (int j = i + 1; j < players; j++) {
            if (partida->puntos[i] < partida->puntos[j]) { //Swap names y puntos. Orden descendente.
                temp_points = partida->puntos[j];
                partida->puntos[j] = partida->puntos[i];
                partida->puntos[i] = temp_points;
                strcpy(temp_name, partida->player[j]);
                strcpy(partida->player[j], partida->player[i]);
                strcpy(partida->player[i], temp_name);
            }
        }
        if (partida->puntos[i] == partida->puntos[i - 1]) { //Detecta si hay un empate a puntos durante toda la partida
            printf("El/la jugador/a %s con una puntuación de %d puntos ha empatado con %s. ¡NO ESTÁ NADA MAL!.\n", partida->player[i], partida->puntos[i], partida->player[i - 1]);
        }
        else if (i == 0)
            printf("El primer puesto se lo lleva %s con una puntuación total de %d puntos. ¡FELICIDADES!.\n", partida->player[i], partida->puntos[i]);
        else if (i == 1)
            printf("El segundo puesto se lo lleva %s con una puntuación total de %d puntos. ¡GOOD JOB!.\n", partida->player[i], partida->puntos[i]);
        else if (i == 2)
            printf("El tercer puesto se lo lleva %s con una puntuación total de %d puntos. ¡NICE JOB!.\n", partida->player[i], partida->puntos[i]);
        if (i + 1 == players - 1)
            last_player = i + 1; //Se obtiene el último player para comprobar empates
    }
    if (partida->puntos[last_player] != partida->puntos[last_player - 1]) //Ya que el loop de arriba no llega a coger el último player se da una condición aquí
        printf("En último lugar está %s con una puntuación total de %d puntos. ¡NICE TRY!.\n", partida->player[last_player], partida->puntos[last_player]);
    else
        printf("El/la jugador/a %s con una puntuación de %d puntos ha empatado con %s. ¡NO ESTÁ NADA MAL!.\n", partida->player[last_player], partida->puntos[last_player], partida->player[last_player - 1]);
}

void add_game(struct partidas *partida, int players)
{
    FILE *f;
    time_t t = time(NULL);
    struct tm timeLocal = *localtime(&t); //Estructura predefinida ISO, localtime sirve para coger el tiempo del dispositivo
    char fechaHora[30];
    char *formato = "%d/%m/%Y %H:%M:%S"; //Formato como se verá la fecha, se puede modificar al gusto
    int bytesEscritos = strftime(fechaHora, sizeof fechaHora, formato, &timeLocal); //Buffer, tamaño máximo del buffer, formato y la dirección a la variable de la fecha local
        
    f = fopen("games.txt","a");
    if (bytesEscritos != 0)
        fprintf(f, "Fecha: %s--", fechaHora);
    else
        printf("Error al formatear la fecha.");
    for(int l = 0; l < players; l++) {
        if (l != players - 1)
            fprintf(f,"Nombre: %s - Puntos: %d;", partida->player[l], partida->puntos[l]);
        else
            fprintf(f,"Nombre: %s - Puntos: %d\n", partida->player[l], partida->puntos[l]);
    }
    fclose(f);
}

void read_file()
{
    FILE *f;
    char linea[255];
    f = fopen("games.txt","r");
    while (fgets(linea, 255, f) != NULL) { //Lee cada línea hasta que no haya contenido en una de estas.
        printf("%s", linea);
    }
    fclose(f);
}