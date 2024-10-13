#include<stdio.h>
#include<stdlib.h>

int main(void){
    int n, cont = 0;

    //recebe e armazena o tamanho da sequencia de numeros
    scanf("%d", &n);
    

    //Aloca a memória para o vetor de N inteiros
    int vetor[n];

    //alocando os valores no vetor 
    for (int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    //fazendo a comparação entre os valores.
    for(int i = 0; i < n; i++){
        if (vetor[i] != vetor[i + 1]){
            cont++;
        }
    }

    //imprimindo o numero de circulos
    printf("%d\n", cont);

    return 0;
}

