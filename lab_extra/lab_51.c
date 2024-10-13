#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define TAM 10
//verificando se todos os algarismos do número são unicos
bool digitos_unicos(int num){
    bool digitos_vistos[TAM] = { false };

    //verificando cada digito do número
    while(num > 0){
        int digito = num % 10;
        if(digitos_vistos[digito]){
            return false; //Aqui o digito se repetiu
        }
        digitos_vistos[digito] = true;
        num /= 10;
    }
    return true; //Aqui temos todos os digitos unicos
}
//Função para contar números com digitos unicos no intervalo [N, M]
int contando_os_numeros(int N, int M){
    int cont = 0;
    for(int i = N; i <= M; i++){
        if(digitos_unicos(i)){
            cont++;
        }
    }
    return cont;
}
int main(void){
    int M, N;
    //lendo as entradas
    scanf("%d", &N);
    scanf("%d", &M);
    //contagem e impressão do resultado
    printf("%d\n", contando_os_numeros(N, M));
    return 0;
}
