#include<stdio.h>
#include<stdlib.h>

int main(void){
    //definindo as variáveis de coordenadas da fazenda
    int x1, y1, x2, y2;
    //definindo as variáveis de coordenadas do meteorito
    int n, x, y;
    //definindo um contador para o for e para os meteoros que caem na fazenda 
    int i, cont, j = 0;
    //while para fazer o ciclo
    while(1){
        cont = 0;
        //recebendo os pontos que determinam os vértices da fazenda
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if((x1 == 0) && (x2 == 0) && (y1 == 0) && (y2 == 0)){
            break;
        }
        j++;
        //recebendo o inteiro n que indica o numero de meteoritos
        scanf("%d", &n);
        //recebendo a posição dos meteoros 
        for(i = 0; i < n; i++){
            //recebendo as posições dos meteoros
            scanf("%d %d", &x, &y);
            if((x >= x1) && (x <= x2) && (y <= y1) && (y >= y2)){
                cont++;
            }
        }
        //print dos testes 
        printf("Teste %d\n", j);
        printf("%d\n\n", cont);
    }  
}