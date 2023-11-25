#ifndef OPERACIONES_H_INCLUDE
#define OPERACIONES_h_INCLUDE

struct partidas {
    char *player[4];
    int puntos[4];
};

int display_menu();
int start_game(struct partidas partida);
int genera_carta_a(int num1, int num_palo);
int reparte_cartas(int num1, int num_palo, int num2, int num_palo2);
void game_logic(struct partidas partida, int players);

#endif