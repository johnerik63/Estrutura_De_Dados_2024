#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int n, i;
    float xc, yc, xr, yr, xb, yb;
    int pode_escapar;
    int cont;
    while(scanf("%d", &n) != EOF){
        pode_escapar = 0;
        scanf("%f %f %f %f", &xc, &yc, &xr, &yr);
        cont = 0;

        for(i = 0; i < n; i++){
            scanf("%f %f", &xb, &yb);
            //Calculo da distancia do coelho e da raposa respectivamente
            float distancia_coelho = sqrt(pow(xb - xc, 2) + pow(yb - yc, 2));
            float distancia_raposa = sqrt(pow(xb - xr, 2) + pow(yb - yr, 2));
            if(distancia_coelho < (distancia_raposa / 2) ){
                pode_escapar = 1;
                cont++;
            }

            if(pode_escapar == 1 && cont == 1){
                printf("O coelho pode escapar pelo buraco (%.3f,%.3f).\n", xb, yb);
                cont++;
                continue;
            }
        }
        if(pode_escapar != 1){
            printf("O coelho nao pode escapar.\n");
        }
    }
    return 0;
}