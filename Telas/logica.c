#include <stdio.h>
#include <stdlib.h>
#include <windows.h>    // SetConsoleCursorPosition
#include <string.h>     // funçoes str
#include <conio.h>      // getch()
#include <ctype.h>      // isdigit, isalpha, etc.
#define CIMA 72
#define BAIXO 80
#define ESQUERDA 75
#define DIREITA 77
#define ESC 27
#define ENTER 13

int valorAleatorio();
int x, y, i, tecla = 0;
int matrizJogo[4][4];

int main(){

    for (x = 0; x < 4; x++){
        for (y = 0; y < 4; y++){
            matrizJogo[x][y] = 0;
        }
        matrizJogo[x][y] = 0;
    }

    valorAleatorio();

    do{
        tecla = getch();
        if (tecla == 13){
            valorAleatorio();
        } else if (tecla == 27){
            tecla = 0;
        }

    } while (tecla != 0);
}

valorAleatorio(){
    
    srand(time(0));

    do{
        x = (rand() % 4);     // GERAR VALOR ALEATORIO PRA POSICAO HORIZONTAL
        y = (rand() % 4);     // GERAR VALOR ALEATORIO PRA POSICAO VERTICAL

        if (matrizJogo[x][y] == 0) {
            matrizJogo[x][y] = 2;
            i = 1;
        } else {
            i = 0;
        }
    }while(i != 1);

    printf("---------------------------------------------------\n");
    for (x = 0; x < 4; x++){
        for (y = 0; y < 4; y++){
            printf("%i\t", matrizJogo[x][y]);
        }
        printf("\n");
    }
}
