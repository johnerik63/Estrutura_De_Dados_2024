#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//definindo uma constante que vai me dar o limite máximo do tamanho do meu vetor
#define TAM_MAX 32768
int V[TAM_MAX]; //vetor original
int R[TAM_MAX]; //vetor com os máximos dos blocos 

int n, r; // tamanho do vetor V e do vetor R (sqrt(n))

//Função que coloca os máximos de cada bloco no vetor R
void Cria_R(){
    r = (int) sqrt(n); //tamanho dos blocos
    for (int i = 0; i < n; i++){
        if (i % r == 0){
            R[i/r] = V[i];
        }else {
            if(R[i/r] > V[i]){
                R[i/r] = R[i/r];
            }else{
                R[i/r] = V[i];
            }
        }
    }
}
int calculo_max(int i, int j){
    //definindo o valor máximo como o primeiro valor do intervalo pedido.
    int maximo_valor = V[i];

    //percorrendo o vetor e comparando o máximo quando i % r for diferente de zero.
    while (i <= j && i % r != 0) {
        if (maximo_valor > V[i]) {
            maximo_valor = maximo_valor;
        } else {
            maximo_valor = V[i];
        }
        i++;
    }
    //Aqui verificamos se o bloco de R, na posição i,  está inteiramente contido no intervalor e daí ja usamos o valor de R pertencente áquele intervalo ao inves de percorrer o bloco.
    while (i <= j) {
        if (i + r - 1 <= j) {
            if (maximo_valor > R[i / r]) {
                maximo_valor = maximo_valor;
            } else {
                maximo_valor = R[i / r];
            }
            i += r;
        } else {
            break; // Sai do loop se o próximo bloco não tiver completamente dentro do intervalo [i, j]
        }
    }
    // Aqui maximizamos os elementos à esquerda de j até o início do último bloco
    while (i <= j) {
        maximo_valor = (maximo_valor > V[i]) ? maximo_valor : V[i];
        i++;
    }

    return maximo_valor;
}
void atualiza(int i, int x){
    V[i] = x;
    //determina o bloco que eu quero atualizar
    int bloco = i / r;
    
    // Recalcula o máximo do bloco com o valor atualizado
    R[bloco] = V[bloco * r];
    //faz a contagem do valor máximo no bloco o qual o valor foi atualizado na posição i.
    for (int j = bloco * r + 1; j < (bloco + 1) * r && j < n; j++) {
        R[bloco] = (R[bloco] > V[j]) ? R[bloco] : V[j];    }
}
//função principal que recebe os valores e aciona as outras funções.
int main(void){
    //definindo os inteiros i, j, x;
    int i, j, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &V[i]);
    }

    //chamada da função que Cria o Vetor R com os máximos de cada bloco
    Cria_R();

    //variável que recebe o comando da função que querp, se é pra calcular o máximo ou atualizar o valor no bloco.
    char comando;

    //enquanto houver comando temos o processamento do algoritimo.
    while (scanf(" %c", &comando) != EOF) {
        if (comando == 'm') {
            scanf("%d %d", &i, &j);
            printf("%d\n", calculo_max(i, j));
        } else if (comando == 'a') {
            scanf("%d %d", &i, &x);
            atualiza(i, x);
        }
    }
    return 0;
}
