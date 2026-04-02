#include <stdio.h>

void invertir_num(int *p_num) {
    int num = *p_num;
    int num_invertido = 0;
    while (num > 0) {
        num_invertido = (num_invertido * 10) + (num % 10);
        num = num / 10;
    }
    *p_num = num_invertido;
}

void div_en_2(int *p_num) {
    *p_num = *p_num / 2;
}

void sumar_suma_de_digitos(int *p_num) {
    int num = *p_num;
    int sumaDigitos = 0;
    while (num > 0) {
        sumaDigitos = sumaDigitos + (num % 10);
        num = num / 10;
    }
    *p_num = *p_num + sumaDigitos;
}

void procesar_enigma(int *codigo) {
    invertir_num(codigo);
    div_en_2(codigo);
    sumar_suma_de_digitos(codigo);
}

int main() {
    int dato_secreto = 452;
    
    printf("Iniciando depuracion con el valor: %d\n", dato_secreto);
    
    // Instrucción para el alumno: 
    // Pon un breakpoint aquí (F9) y usa F11 (Step Into) para entrar a cada función.
    procesar_enigma(&dato_secreto);
    
    printf("Resultado final del enigma: %d\n", dato_secreto);
    
    return 0;
}