#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#ifndef MPI
#define MPI 3.14159265358979323846
#endif

void area_rectangulo() {
    //Se inicializan las variables, el area es ancho * largo
    int area = 0;
    int ancho = 0;
    int largo = 0;

    printf("Introduce el ancho: ");
    scanf("%d", &ancho);
    printf("Introduce el largo: ");
    scanf("%d", &largo);
    area = largo * ancho;
    printf("\nEl área del rectángulo es: %d\n", area);
}

void tres_caracteres()
{
    //Se pide al usuario que introduzcan 3 carácteres y se imprimen por pantalla
    char c1, c2, c3;
    printf("Introduce un carácter: ");
    scanf(" %c", &c1);
    printf("Introduce un carácter: ");
    scanf(" %c", &c2);
    printf("Introduce un carácter: ");
    scanf(" %c", &c3);
    printf("\nLos carácteres introducidos son: %c-%c-%c\n", c1, c2, c3);
}

void convert_pes_en_eur() //Convierte Euros en Pesetas
{
    double euros = 0;
    double pesetas = 0;
    printf("Introduce la cantidad de Euros que quires convertir a Pesetas: ");
    scanf("%lf", &euros);
    pesetas = euros * 166.386; //Cada Euro son 166 pesetas
    printf("\nLa cantidad de Euros en Pesetas es de: %.2lf\n", pesetas);
}

void check_note() //El 'alumno' introduce una nota y comprueba cuál ha sido su calificación
{
    float nota;

    printf("Introduce tu nota para saber tu calificación: ");
    scanf("%f", &nota);
    if (nota < 5 && nota >= 0)
        printf("\nLo siento, has suspendido\n");
    else if (nota >= 5 && nota < 6)
        printf("\n¡Has obtenido un suficiente!\n");
    else if (nota >= 6 && nota < 7)
        printf("\n¡Has obtenido un bien!\n");
    else if (nota >= 7 && nota < 9)
        printf("\n¡Has obtenido un notable!\n");
    else if (nota >= 9 && nota <= 10)
        printf("\n¡Felicidades!, ¡tienes un sobresaliente!\n");
    else
        printf("\nLa nota que has introducido no es una calificación válida.\n");
}

void final_price() //Calcula el precio final de un coche basándose en los parámetros introducidos (Precio base, km totales y consumo)
{
    float base_price, avrg_cons, tot_price;
    int tot_km;

    printf("Introduce el precio base del vehículo: ");
    scanf("%f", &base_price);
    printf("Introduce el número de kilómetros del vehículo: ");
    scanf("%d", &tot_km);
    printf("Introduce el consumo medio del vehículo: ");
    scanf("%f", &avrg_cons);

    if (tot_km < 20000 && avrg_cons <= 5)
        tot_price = base_price * 1.20;
    else if (tot_km >= 20000 && avrg_cons <= 5)
        tot_price = base_price *1.10;
    else if (tot_km < 20000 && avrg_cons > 5)
        tot_price = base_price * 1.25;
    else {
        tot_price = base_price * 1.15;
    }
    printf("\nEl precio final del coche es de: %.2f\n", tot_price);
}

void week_day() //Consiste en introducir un número del 1 al 7 y cada número corresponde al día de la semana (1 es Lunes, ... y 7 es Domingo)
{               //Usando switch
    int n;
    printf("Introduce el número correspondiente al día de la semana para ver el día escrito: ");
    scanf("%d", &n);

    switch(n) {
        case(1):
            printf("\nLunes\n");
            break;
        case(2):
            printf("\nMartes\n");
            break;
        case(3):
            printf("\nMiércoles\n");
            break;
        case(4):
            printf("\nJueves\n");
            break;
        case(5):
            printf("\nViernes\n");
            break;
        case(6):
            printf("\nSábado\n");
            break;
        case(7):
            printf("\nDomingo\n");
            break;
        default:
            printf("\nError. El día que has introducido no existe.\n");
            break;
    }
}

void multi_three () //Imprime por pantalla todos los múltiplos de 3 hasta 100. Lo he realizado de dos formas distintas.
{
    for(int i = 3; i < 100; i += 3)
        printf("%d\n", i);
    //int i = 0;  //Esta es otra forma de hacerlo usando el módulo
    //while(i++ < 100)
    //{
    //    if (i % 3 == 0)
    //        printf("%d\n", i);
    //}
}

void apto_no_apto() //Función la cual según el número de alumnos y sus notas te dice la cantidad de aprobados/suspensos. 
{
    int alumnos, apto = 0, no_apto = 0, num_alumno = 0;
    float *notas; //Array de float, para almacenar todas las notas de los alumnos
    printf("Introduce la cantidad de alumnos: ");
    scanf("%d", &alumnos);
    printf("\n");
    notas = malloc(sizeof(*notas) * (alumnos + 1)); //Almaceno suficiente memoria al array dependiendo del número de alumnos
    for (int i = 0; i < alumnos; i++)
    {
        printf("Introduce la nota del alumno %d: ", (num_alumno + 1));
        scanf("%f", &notas[i]);
        if (notas[i] < 5)
            no_apto++;
        else
            apto++;
        num_alumno++;
    }
    printf("\nEl número de alumnos aprobados es de: %d\n", apto);
    printf("El número de alumnos suspensos es de: %d\n", no_apto);
}

void suma_and_average() //Suma todos los números introducidos hasta que se encuentra un 0 y saca el promedio de éstos
{
    int value_counter = 0;
    float tot_suma = 0, tot_value = 0, value;
    while (value != 0)
    {
        printf("Introduce un valor: ");
        scanf("%f", &value);
        tot_suma += value;
        value_counter++;
    }
    value_counter -= 1;
    tot_value = tot_suma / value_counter;
    printf("\nLa suma y el promedio total es de: %.2f\n", tot_value);
}

void avrg_pesos() //Coge 5 pesos, da el promedio de estos y dice qué persona está por encima o está por debajo de este promedio
{
    float peso[5], tot_peso = 0, avrg_peso = 0;
    for (int i = 0; i < 5; i++) {
        printf("Introduce el peso de la %d persona: ", (i + 1));
        scanf("%f", &peso[i]);
        tot_peso += peso[i];
    }
    avrg_peso = tot_peso / 5;
    printf("\nEl peso promedio es de: %.2f\n", avrg_peso);
    for (int i = 0; i < 5; i++) {
        if (peso[i] > avrg_peso)
            printf("El peso de la %d persona es mayor al promedio.\n", (i + 1));
        else if (peso[i] < avrg_peso)
            printf("El peso de la %d persona es menor al promedio.\n", (i + 1));
        else
            printf("El peso de la %d persona es igual al promedio.\n", (i + 1));
    }
}

void min_and_max() //De un array de enteros coge el valor mínimo y el valor máximo
{
    int tab[10] = {100, 33, 25, 12, 4, 79, 55, 76, 77, 37};
    int min = tab[0], max = tab[0];
    for (int i = 0; i < 10; i++) {
        if (tab[i] > max)
            max = tab[i];
        if (tab[i] < min)
            min = tab[i];
        
    }
    printf("El valor máximo del array es: %d\n", max);
    printf("El valor mínimo del array es: %d\n", min);
}

void hotel_rooms() //Introduce 'x' cantidad de habitaciones y le da un precio a cada una según la temporada l/m/h. No importa el número de habitación que introduzcas.
{
    int num_room;
    float low_temp = 0, mid_temp = 0, high_temp = 0;
    float low_avrg = 0, mid_avrg = 0, high_avrg = 0;
    printf("Introduce el número de habitaciones que hay: ");
    scanf("%d", &num_room);
    float room_price[num_room][4];
    for (int i = 0; i < num_room; i++) {
        printf("\nIntroduce el número de habitación: ");
        scanf("%f", &room_price[i][0]);
        printf("Introduce el precio de la habitación en temporada baja: ");
        scanf("%f", &room_price[i][1]);
        printf("Introduce el precio de la habitación en temporada media: ");
        scanf("%f", &room_price[i][2]);
        printf("Introduce el precio de la habitación en temporada alta: ");
        scanf("%f", &room_price[i][3]);
        low_temp += room_price[i][1];
        mid_temp += room_price[i][2];
        high_temp += room_price[i][3];
    }
        low_avrg = low_temp / num_room;
        mid_avrg = mid_temp / num_room;
        high_avrg = high_temp / num_room;
        printf("\nEl precio medio de las habitaciones en temporada baja es de: %.2f", low_avrg);
        printf("\nEl precio medio de las habitaciones en temporada media es de: %.2f", mid_avrg);
        printf("\nEl precio medio de las habitaciones en temporada alta es de: %.2f", high_avrg);
}

void intro_cadena()
{
    int cant_cad = 0, cant_pal = 0;
    printf("¿Cuántas cadenas quieres introducir? ");
    scanf("%d", &cant_cad);    
    char *cadena[cant_cad];
    char *cadenasrc;
    for (int i = 0; i < cant_cad; i++) {
      printf("¿Cuántas palabras tiene la cadena? ");
      scanf("%d", &cant_pal);
      cadena[i] = malloc(sizeof(char) * 100 * (cant_pal + 1));
      for (int j = 0; j < cant_pal; j++) {
        if (j == 0){ 
            printf("Introduce la primera palabra: ");
            scanf("%s", cadena[i]); }
        else {
        cadenasrc = malloc(sizeof(char) * 100);
        printf("Introduce la siguiente palabra: ");
        scanf("%s", cadenasrc);
        strcat(cadena[i], cadenasrc);
        }
        if (j != cant_pal - 1)
            strcat(cadena[i], " ");
      }
    }
    for (int i = 0; i < cant_cad; i++) {
        if (i == cant_cad - 1)
            printf("%s", cadena[i]);
        else
            printf("%s-", cadena[i]);
        free(cadena[i]);
    }
    free(cadenasrc);
}

void look_for_char()
{
    int cant_pal = 0;
    printf("¿Cuántas palabras tiene la cadena que vas a introducir? ");
    scanf("%d", &cant_pal);
    char *str, *strsrc;
    char c;
    str = malloc(sizeof(char) * 100 * (cant_pal + 1));
    for (int i = 0; i < cant_pal; i++) {
        if (i == 0) {
            printf("Introduce la primera palabra del string donde quieres buscar coincidencias: ");
            scanf("%s", str); }
        else {
            strsrc = malloc(sizeof(char) * 100);
            printf("Introduce la siguiente palabra de la cadena donde quuieres buscar coincidencias: ");
            scanf("%s", strsrc);
            strcat(str, strsrc);
        }
        if (i != cant_pal - 1)
            strcat(str, " ");
    }
    printf("Introduce el carácter a buscar en la cadena: ");
    scanf(" %c", &c);
    for(int j = 0; str[j] != '\0'; j++) {
        if (str[j] == c) {
            printf("Hay una coincidencia en la posición número: %d", j);
            break;
        }
        else if (str[j + 1] == '\0')
            printf("No se ha encontrado ninguna coincidencia.");
    }
}

void basket_team()
{
    int cant_players, choose_menu;
    float high_height;
    char temp_name[100];
    struct datage {
        char name[100];
        int age;
        float height;
    };
    struct datage team_datage[5];
    printf("¿Cuántos jugadores hay en el equipo? "); //Se supone que hay 5 pero, cuanto más variable mejor :)
    scanf("%d", &cant_players);
    printf("\n");
    for (int i = 0; i < cant_players; i++) { //Esto almacena los datos de los jugadores del equipo :)
        printf("Introduce el nombre del jugador número %d: ", (i + 1)); //Sólo puede mostrar nombre, no apellidos. Y el nombre debe ser simple.
        scanf("%s", team_datage[i].name);
        printf("Introduce la edad del jugador número %d: ", (i + 1));
        scanf("%d", &team_datage[i].age);
        printf("Introduce la altura del jugador número %d: ", (i + 1));
        scanf("%f", &team_datage[i].height);
        printf("\n");
    }
    while (choose_menu != 9) { //Hace un bucle del menú hasta que se introduce un número que no sea 1, 2 o 3 ya que entra en 'else' junto a un 'break'
        high_height = team_datage[0]. height;
        printf("\n-----Elige una opción-----\n"); //Presenta un menú con las 3 opciones disponibles
        printf("--Introduce 1 para listar los nombres y la altura de los jugadores--\n");
        printf("--Introduce 2 para buscar un jugador por su nombre y presentar su altura y su edad--\n");
        printf("--Introduce 3 para ver cual es el nombre y la edad del jugador más alto del equipo--\n");
        printf("--Introduce cualquier otro número para salir del menú :)");
        printf("\nTu elección: ");
        scanf("%d", &choose_menu);
    
        if (choose_menu == 1) {
            for (int i = 0; i < cant_players; i++)
                printf("El jugador %d se llama %s y mide %.2f metros.\n", i + 1, team_datage[i].name, team_datage[i].height);
        }
        else if (choose_menu == 2) {
            printf("Introduce el nombre del jugador: ");
            scanf("%s", temp_name);
          for(int j = 0; j < cant_players; j++) {
                if (strcmp(temp_name, team_datage[j].name) == 0) {
                    printf("El jugador %s mide %.2f metros y tiene %d años.\n", team_datage[j].name, team_datage[j].height, team_datage[j].age);
                    break;
                }
            }
        }
        else if (choose_menu == 3) {
            for (int k = 0; k < cant_players - 1; k++) {
                if ((team_datage[k].height < team_datage[k + 1].height) && (high_height <= team_datage[k + 1].height))
                    high_height = team_datage[k + 1].height;
                }
            for (int l = 0; l < cant_players; l++) {
                if (high_height == team_datage[l].height)
                    printf("El/los jugador/es más alto/s del equipo se llama/n %s y tiene/n %d años.\n", team_datage[l].name, team_datage[l].age);
            }
        }
        else {
            printf("No has elegido un número válido y has sido expulsado del menú.\n");
            break;
        }
    }
}

void motor_power()
{
    struct stcilindro {
        float diametro;
        float carrera;
    };
    struct info_motor {
        int motor_id;
        struct stcilindro info_cilindro;
        int cant_cil;
        float cilindrada;
        };
    struct info_motor motor;
    float carr_cm = 0, diam_cm = 0;

    //Este bloque empieza aquí y almacena toda la información necesaría
    printf("Introduce el número del identificador del motor: "); //Aquí tengo mis dudas de si es valor solo númerico, si es un string y cuánto ocupa (int o long int)
    scanf("%d", &motor.motor_id);
    printf("Introduce el número de cilindros del motor: ");
    scanf("%d", &motor.cant_cil);
    printf("Introduce la carrera del cilíndro (en milímetros): ");
    scanf("%f", &motor.info_cilindro.carrera);
    printf("Introduce el diámetro del cilíndro (en milímetros): ");
    scanf("%f", &motor.info_cilindro.diametro);
    //El bloque termina aquí
    carr_cm = motor.info_cilindro.carrera / 10;
    diam_cm = motor.info_cilindro.diametro / 10;
    //Pasamos la carrera y el diámetro del cilíndro a centímetros
    motor.cilindrada = (motor.cant_cil * carr_cm * MPI * (diam_cm * diam_cm)) / 4;
    //Calculamos la cilíndrada
    printf("\n-----Aquí están los datos introducidos y la cilindrada correspondiente-----\n");
    printf("--Número del identificador del motor: %d\n", motor.motor_id);
    printf("--Número de cilíndros del motor: %d\n", motor.cant_cil);
    printf("--La carrera del cilíndro (en mm) es %.2f y el diámetro (en mm) es %.2f\n", motor.info_cilindro.carrera, motor.info_cilindro.diametro);
    printf("\n--La cilindrada del motor es: %.2f--\n", motor.cilindrada);
    //Mostramos todos los datos y la cilíndrada obtenida a raíz de los datos introducidos
}

void museum_entry()
{
    struct entry_hour {
        int hour;
        int minute;
    };
    struct info_entry {
        struct entry_hour entry_time;
        int ppl_cuant;
        float tot_price;        
    };

    struct info_entry info_museum[100]; //Almaceno los datos de los grupos
    int *edad; //Defino esto y lo inicializo con un malloc
    char continue_or_not = 'S';
    int group_number = 0, five_eur_counter = 0, eight_eur_counter = 0, ten_eur_counter = 0;
    
    while (continue_or_not != 'N') 
    {
        if (continue_or_not == 'S') { //Al inicializar con S entra esta condición
            printf("--Introduce los datos del grupo %d--\n", group_number + 1);
            printf("\nHora de entrada: ");
            scanf("%d", &info_museum[group_number].entry_time.hour);
            printf("Minutos de entrada: ");
            scanf("%d", &info_museum[group_number].entry_time.minute);
            printf("¿Cuántas personas formarn el grupo? ");
            scanf("%d", &info_museum[group_number].ppl_cuant);
            edad = malloc(sizeof(int) * (info_museum[group_number].ppl_cuant + 1)); //Almaceno suficiente espacio para almacenar todas las edades
            for(int i = 0; i < info_museum[group_number].ppl_cuant; i++) {
                printf("Introduce la edad del asistente Nº%d del grupo: ", i + 1);
                scanf("%d", &edad[i]);
                if (edad[i] >= 6 && edad[i] < 16)
                    five_eur_counter++;
                else if (edad[i] < 6)
                    continue;
                else if ((edad[i] > 15 && edad[i] < 27) || edad[i] >= 65)
                    eight_eur_counter++;
                else
                    ten_eur_counter++;
            }
            info_museum[group_number].tot_price = (five_eur_counter * 5) + (eight_eur_counter * 8) + (ten_eur_counter * 10);
            if (info_museum[group_number].ppl_cuant < 5)
                printf("\nEl precio total de las entradas es de %.2f€\n", info_museum[group_number].tot_price);
            else {
                info_museum[group_number].tot_price = info_museum[group_number].tot_price - ((info_museum[group_number].tot_price * 1.1) - info_museum[group_number].tot_price);
                printf("\nEl precio total de las entradas con un descuento del 10%% es de %.2f€\n", info_museum[group_number].tot_price);
            }
        }
        else { //Si no se introduce S o N pide de vuelta un carácter válido
            printf("Introduce un carácter válido 'S' o 'N': ");
            scanf(" %c", &continue_or_not);
        }
        group_number++;
        printf("\nIntroduce 'S' para almacenar los datos de otro grupo o 'N' para salir del menú: ");
        scanf(" %c", &continue_or_not);
    }
    printf("Gracias por usar el programa, ¡nos vemos con el siguiente grupo :D!\n");
}

void real_vector_pointer()
{
    float vector[5];
    float alma_num = 0;
    for (int i = 0; i < 5; i++) {
        printf("Introduce la posición Nº%d del vector de números reales: ", i);
        scanf("%f", &vector[i]);
    }
    float *punteroAVector = &vector[0]; //El puntero apunta siempre a la primera posición del vector / primer catácter de un string. Si le pasamos la dirección de la primera posición del vector lo estamos igualando y haciendo el vector 'todo suyo'.
    for (int j = 0; j < 5; j++) {
        alma_num += *(punteroAVector + j); //Esta sintaxis itera en las posiciones del vector, pasando desde la 0 hasta la 4 (5 = NULL)
    }
    alma_num /= 5;
    printf("La media de los valores almacenados es %.2f\n", alma_num);
}

void vector_por_valor(int *vector, int size, int num)
{
    for(int i = 0; i < size; i++)
        *(vector + i) *= num; //Con esta sintaxis no se acumula el valor, itera y multiplica cada valor del vector por el numero SIN ACUMULAR, interesante!!!.
}       //También sirve *(vector++)

void save_table()
{
    int num;
    FILE *f;
    int *res;

    printf("Introduce un número a partir del cual se generará su tabla de multiplicar: ");
    scanf("%d", &num);
    f = fopen("tabla.txt","w"); //Abro el archivo en modo escritura de modo que se elimina todo el contenido y se escribe el que yo le indico
    for (int i = 0; i <= 10; i++) {
        res[i] = num * i; //Almaceno el resultado de cada multiplicación en un array de int
        fprintf(f, "%d ", res[i]); //Para escribir en el fichero
    }
    fclose(f); //Para cerrar el fichero
}

void suma_file()
{
    FILE *f;
    float read_num;
    float res_suma = 0;

    f = fopen("números.txt", "r");
    while (feof(f) == 0) {
        fscanf(f, "%f", &read_num);
        res_suma += read_num;
    }
    fclose(f);
    printf("La suma de los números del fichero es: %.2f", res_suma);
}

void registro_producto()
{
    struct registro {
        int code;
        char describe[100];
        float price;
    };
    struct registro *producto;
    
    producto = malloc(sizeof(*producto));
    if (!producto) {
        producto = NULL;
    }

    printf("Introduce el código de producto: ");
    scanf("%d", &producto->code);
    printf("Introduce el nombre del producto: ");
    scanf("%s", producto->describe);
    printf("Introduce el precio del producto: ");
    scanf("%f", &producto->price);
    
    printf("\nCódigo de producto: %d\n", producto->code);
    printf("Producto: %s\n", producto->describe);
    printf("Precio: %.2f\n", producto->price);

    free (producto);
    producto = NULL;
}

void f()
{
    
}

int main() {
    //No necesito pedir parametros en las funciones debido a que depende del usuario mediante 'scanf'
    area_rectangulo();
    printf("\n");
    tres_caracteres();
    printf("\n");
    convert_pes_en_eur();
    printf("\n");
    check_note();
    printf("\n");
    final_price();
    printf("\n");
    week_day();
    printf("\n");
    multi_three();
    printf("\n");
    apto_no_apto();
    printf("\n");
    suma_and_average();
    printf("\n");
    avrg_pesos();
    printf("\n");
    min_and_max();
    printf("\n");
    hotel_rooms();
    printf("\n");
    intro_cadena();
    printf("\n");
    look_for_char();
    printf("\n");
    basket_team();
    printf("\n");
    motor_power();
    printf("\n");
    museum_entry();
    printf("\n");
    real_vector_pointer();
    printf("\n");
    
    int vector[4] = {10, 12, 23, 25};
    vector_por_valor(&vector[0], 4, 10); //Le pasa la dirección de la primera posición como parámetro, interesante!!!
    for (int i = 0; i < 4; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    save_table();
    printf("\n");
    suma_file();
    printf("\n");
    registro_producto();
    printf("\n");
    
    return 0;
}