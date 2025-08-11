#include <stdio.h>

float soma(float num1, float num2){
    float soma = num1 + num2; 
    return soma;
}

float subtracao(float num1, float num2){
    float sub = num1 - num2;
    return sub;
}

float multiplicacao(float num1, float num2){
    float multi = num1 * num2;
    return multi;
}

float divisao(float num1, float num2){
    float div = num1 / num2;
    if(div == 0){
        div = 0;
    }

    return div;
}


float operacoes(char op, float num1, float num2){
    float result;
    
    switch (op){
        case '+':
            result = soma(num1, num2);
            break;
        case '-':
            result = subtracao(num1, num2);
            break;
        case '*':
            result = multiplicacao(num1, num2);
            break;
        case '/':
            result = divisao(num1, num2);
            break;
    }

    return result;
}

int main(){
    float num1, num2, result;
    char opc;

    printf("CALCULADORA BASICA:\n");
    printf("Informe o 1º valor: ");
    scanf("%f", &num1);

    printf("Informe o 2º valor: ");
    scanf("%f", &num2);

    do{
        printf("\nInforme a operação:\n");
        printf("[+] [-] [*] [/]\n");
        printf("Sua opção: ");
        scanf(" %c", &opc);

        if(opc != '+' && opc != '-' && opc != '*' && opc != '/'){
           printf("Entrada Invalida!!"); 
        }
    }while(opc != '+' && opc != '-' && opc != '*' && opc != '/');

    result = operacoes(opc, num1, num2);

    printf("\nResultado:\n");
    printf("%.2f %c %.2f = %.2f", num1, opc, num2, result);

    return 0;
}