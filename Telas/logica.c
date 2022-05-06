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
int x, y, i, opcao, jogada, pontos, contagem = 0;
int matrizJogo[4][4];

int main(){

    for (x = 0; x < 4; x++){
        for (y = 0; y < 4; y++){
            matrizJogo[x][y] = 0;
        }
        matrizJogo[x][y] = 0;
    }

    valorAleatorio();
    system("cls");
    valorAleatorio();

    do{
        
	opcao = getch();
	
	/*
	ADICIONAR FUNCAO PARA VERIFICAR QUAIS MOVIMENTOS PODEM SER FEITOS
	E SE NAO PUDER SER FEITO, A TECLA DIGITADA NAO TEM VALOR
	*/

	if (opcao == 77){               // DIREITA

        for(y = 3; y >= 0; y--) {
                    
                for(x = 0; x < 4; x++) {

                if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] == 0) && (matrizJogo[x][y - 3] != 0) && (y > 2) ) {
                
                    matrizJogo[x][y] = matrizJogo[x][y - 3];
                    matrizJogo[x][y - 3] = 0;
                    
                } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] != 0) && (y > 1) ) {
                
                    matrizJogo[x][y] = matrizJogo[x][y - 2];
                    matrizJogo[x][y - 2] = 0;
                    
                } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] != 0) && (y > 0) ) {
                
                    matrizJogo[x][y] = matrizJogo[x][y - 1];
                    matrizJogo[x][y - 1] = 0;
                    
                } else if ( (matrizJogo[x][y]) != 0 ){

                    if ( (matrizJogo[x][y - 1] == matrizJogo[x][y]) && (y > 0) ) {

                        pontos = pontos + (matrizJogo[x][y]*2);
                        matrizJogo[x][y] = matrizJogo[x][y]*2;
                        matrizJogo[x][y - 1] = 0;

                    } else if ( (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] == matrizJogo[x][y]) && (y > 1) ) {

                        pontos = pontos + (matrizJogo[x][y]*2);
                        matrizJogo[x][y] = matrizJogo[x][y]*2;
                        matrizJogo[x][y - 2] = 0;

                    } else if ( (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] == 0) && (matrizJogo[x][y - 3] == matrizJogo[x][y]) && (y > 2) ) {

                        pontos = pontos + (matrizJogo[x][y]*2);
                        matrizJogo[x][y] = matrizJogo[x][y]*2;
                        matrizJogo[x][y - 3] = 0;

                    }

                }

            }

        }
        jogada++;
        valorAleatorio();

    } else if (opcao == 75) {			// ESQUERDA

        for(y = 0; y < 4; y++) {
            
            for(x = 3; x >= 0; x--) {

                if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == 0) && (matrizJogo[x][y + 3] != 0) && (y < 1) ) {
                
                    matrizJogo[x][y] = matrizJogo[x][y + 3];
                    matrizJogo[x][y + 3] = 0;
                    
                } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] != 0) && (y < 2) ) {
                
                    matrizJogo[x][y] = matrizJogo[x][y + 2];
                    matrizJogo[x][y + 2] = 0;
                    
                } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] != 0) && (y < 3) ) {
                
                    matrizJogo[x][y] = matrizJogo[x][y + 1];
                    matrizJogo[x][y + 1] = 0;
                    
                } else if ( (matrizJogo[x][y]) != 0 ){

                    if ( (matrizJogo[x][y + 1] == matrizJogo[x][y]) && (y < 3) ) {

                        pontos = pontos + (matrizJogo[x][y]*2);
                        matrizJogo[x][y] = matrizJogo[x][y]*2;
                        matrizJogo[x][y + 1] = 0;

                    } else if ( (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == matrizJogo[x][y]) && (y < 2) ) {

                        pontos = pontos + (matrizJogo[x][y]*2);
                        matrizJogo[x][y] = matrizJogo[x][y]*2;
                        matrizJogo[x][y + 2] = 0;

                    } else if ( (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == 0) && (matrizJogo[x][y + 3] == matrizJogo[x][y]) && (y < 1) ) {

                        pontos = pontos + (matrizJogo[x][y]*2);
                        matrizJogo[x][y] = matrizJogo[x][y]*2;
                        matrizJogo[x][y + 3] = 0;

                    }

                }

            }

        }
        jogada++;
        valorAleatorio();

    } else if (opcao == 80) {			// BAIXO

		for(x = 3; x >= 0; x--) {
			
        	for(y = 0; y < 4; y++) {

                if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] == 0) && (matrizJogo[x - 3][y] != 0) && (x > 2) ) {
                
                    matrizJogo[x][y] = matrizJogo[x - 3][y];
                    matrizJogo[x - 3][y] = 0;
                    
                } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] != 0) && (x > 1) ) {
                
                    matrizJogo[x][y] = matrizJogo[x - 2][y];
                    matrizJogo[x - 2][y] = 0;
                    
                } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] != 0) && (x > 0) ) {
                
                    matrizJogo[x][y] = matrizJogo[x - 1][y];
                    matrizJogo[x - 1][y] = 0;
                    
                } else if ( (matrizJogo[x][y]) != 0 ){

                    if ( (matrizJogo[x - 1][y] == matrizJogo[x][y]) && (x > 0) ) {

                        pontos = pontos + (matrizJogo[x][y]*2);
                        matrizJogo[x][y] = matrizJogo[x][y]*2;

                        matrizJogo[x - 1][y] = 0;

                    } else if ( (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] == matrizJogo[x][y]) && (x > 1) ) {

                        pontos = pontos + (matrizJogo[x][y]*2);
                        matrizJogo[x][y] = matrizJogo[x][y]*2;
                        matrizJogo[x - 2][y] = 0;

                    } else if ( (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] == 0) && (matrizJogo[x - 3][y] == matrizJogo[x][y]) && (x > 2) ) {

                        pontos = pontos + (matrizJogo[x][y]*2);
                        matrizJogo[x][y] = matrizJogo[x][y]*2;
                        matrizJogo[x - 3][y] = 0;

                    }

                }

            }

        }
        jogada++;
        valorAleatorio();

    } else if (opcao == 72) {			// CIMA

        for(x = 0; x < 4; x++) {   

            for(y = 3; y >= 0; y--) {
                
                if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == 0) && (matrizJogo[x + 3][y] != 0) && (x < 1) ) {
                
                    matrizJogo[x][y] = matrizJogo[x + 3][y];
                    matrizJogo[x + 3][y] = 0;
                    
                } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] != 0) && (x < 2) ) {
                
                    matrizJogo[x][y] = matrizJogo[x + 2][y];
                    matrizJogo[x + 2][y] = 0;
                    
                } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] != 0) && (x < 3) ) {
                
                    matrizJogo[x][y] = matrizJogo[x + 1][y];
                    matrizJogo[x + 1][y] = 0;
                    
                } else if ( (matrizJogo[x][y]) != 0 ){

                    if ( (matrizJogo[x + 1][y] == matrizJogo[x][y]) && (x < 3) ) {

                        pontos = pontos + (matrizJogo[x][y]*2);
                        matrizJogo[x][y] = matrizJogo[x][y]*2;
                        matrizJogo[x + 1][y] = 0;

                    } else if ( (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == matrizJogo[x][y]) && (x < 2) ) {

                        pontos = pontos + (matrizJogo[x][y]*2);
                        matrizJogo[x][y] = matrizJogo[x][y]*2;
                        matrizJogo[x + 2][y] = 0;

                    } else if ( (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == 0) && (matrizJogo[x + 3][y] == matrizJogo[x][y]) && (x < 1) ) {

                        pontos = pontos + (matrizJogo[x][y]*2);
                        matrizJogo[x][y] = matrizJogo[x][y]*2;
                        matrizJogo[x + 3][y] = 0;

                    }

                }

            }

        }
        jogada++;
        valorAleatorio();

    } else if (opcao == 27) {    // ESC
        return 1;
    }

    for(x = 3; x >= 0; x--) {
        for(y = 0; y < 4; y++) {
            if (matrizJogo[x][y] == 2048){
                system("cls");
                printf("VOCE GANHOU!");
            }
        }
    }
    } while ( opcao != 27 );


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
    for (x = 0; x < 4; x++) {
		for (y = 0; y < 4; y++){
	        printf("%i\t", matrizJogo[x][y]);
	    }
	    printf("\n");
	}
	
    printf("------------------------------------------------------\n");
    printf("                    JOGADAS:   %i                     \n", jogada);
    printf("                    PONTOS:    %i                     \n", pontos);
    printf("               ULTIMO MOVIMENTO:    %i                \n", opcao);
    printf("------------------------------------------------------\n");
}
