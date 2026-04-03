#include <stdio.h>

int main () {
    int random = 42;
    int *puntero = &random;

    printf("Hola Mundo!\n");

    printf("-Contenido del puntero: %d\n", *puntero);
    printf("-Direccion de memoria almacenada por el puntero: %p\n", puntero);
    printf("-Direccion de memoria de la variable: %p\n", &random);
    printf("-Direccion de memoria del puntero: %p\n", &puntero);
    printf("-Memoria utilizada por la variable puntero: %lu bytes\n", sizeof(puntero));

    return 0;
}