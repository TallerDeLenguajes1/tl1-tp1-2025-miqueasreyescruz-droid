#include <stdio.h>

void infoVariable (int *p_num);
void alCuadrado (int *p_num);
void invertirValores (int *p_num1, int *p_num2);
void ordenarVariables (int *p_num1, int *p_num2);


int main () {
    int num1;
    int num2;

    printf("-->Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("-->Ingrese el segundo numero: ");
    scanf("%d", &num2); 

    printf("-->Informacion del primer numero:\n");
    infoVariable(&num1);

    printf("-->Informacion del segundo numero:\n");
    infoVariable(&num2);

    return 0;
}

void alCuadrado (int *p_num) {
    *p_num = (*p_num) * (*p_num);
}

void infoVariable (int *p_num) {
    printf("-Direccion de memoria: %p\n", p_num);
    printf("-Contenido: %d\n", *p_num);
}

void invertirValores (int *p_num1, int *p_num2) {
    int aux = *p_num1;
    *p_num1 = *p_num2;
    *p_num2 = aux;
}

void ordenarVariables (int *p_num1, int *p_num2) {
    int aux1;
    if (*p_num1 > *p_num2) {
        aux1 = *p_num1;
        *p_num1 = *p_num2;
        *p_num2 = aux1;
    }
}