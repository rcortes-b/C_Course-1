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

int main() {
    //No necesito pedir parametros en las funciones debido a que depende del usuario mediante 'scanf'
    area_rectangulo();
    printf("\n");
    tres_caracteres();
    printf("\n");
    convert_pes_en_eur();
    printf("\n");
    return 0;
}