#include <stdio.h>

// Função para calcular o dobro de um numero
int duplica (int x){
    return 2 * x;
}

int main(){
    int a = 5;
    int resultado;
    resultado = duplica(a);
    printf("Resultado: %d", resultado);
    return 0;
}
