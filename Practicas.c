#include <stdio.h>
#include <stdlib.h>

/*void area_rectangulo() {
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
}*/

int main() {
    //No necesito pedir parametros en las funciones debido a que depende del usuario mediante 'scanf'
    /*area_rectangulo();
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
    printf("\n");*/
    return 0;
}