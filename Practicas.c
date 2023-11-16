#include <stdio.h>

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
    return 0;
}