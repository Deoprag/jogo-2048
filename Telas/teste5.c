#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define CIMA 72
#define BAIXO 80
#define ESQUERDA 75
#define DIREITA 77
#define ESC 27
#define ENTER 13
#define TAM5 5


void gotoxy(int x, int y);
void movEsquerda5x5();
void movDireita5x5();
void movCima5x5();
void movBaixo5x5();
int logo();
int tijolos();
int jogar5x5();
int checarMovimento5x5();
int checarVazios5x5();
int valorAleatorio5x5();
int checarVitoriaFacil();

int x, y, opcao, jogada, pontos, mov, tijolo = 0;
int matrizJogo5x5[TAM5][TAM5];
int matrizJogoChecar5x5[TAM5][TAM5];

int main(){
    jogar5x5();
}


jogar5x5(){
    
    int ver = 0;

    valorAleatorio5x5();
    system("cls");

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             DIFICULDADE: FACIL                             %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] VOLTAR                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c   PONTOS:  |      | %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c MOVIMENTOS:|      | %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c [P] SALVAR JOGO     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c [R] REINICIAR JOGO  %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c [O] RANKING         %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c        DICA:        %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   UTILIZE AS SETAS  %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c   DO TECLADO PARA   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c    MOVIMENTAR O     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c     TABULEIRO       %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c  UNIFACEAR - 2022   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    valorAleatorio5x5();

    do{

        gotoxy(70,18);
        printf("%i", pontos);                   // PRINTA OS PONTOS NA TELA
        gotoxy(70,19);
        printf("%i", jogada);                   // PRINTA A QUANTIDADE DE MOVIMENTOS NA TELA
        gotoxy(80,40);

        opcao = getch();

        if ( (opcao == DIREITA) ) {               // DIREITA

            movDireita5x5();    
            
        } else if ( (opcao == ESQUERDA) ) {			// ESQUERDA

            movEsquerda5x5();
            
        } else if ( (opcao == BAIXO) ) {			// BAIXO

            movBaixo5x5();

        } else if ( (opcao == CIMA) ) {			// CIMA

            movCima5x5();

        } else if (opcao == 27) {    // ESC
            return 1;
        }

        if(checarVitoriaFacil(ver) == 0){
            gotoxy(40,40);
			printf("VITORIA");
        }
        
    } while ( opcao != 27 );
}

logo(){
    tijolos();
    
    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c****_****%c      .d8888b.    .d8888b.       d8888    .d8888b.      %c****_****%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c***/ \\***%c     d88P  Y88b  d88P  Y88b     d8P888   d88P  Y88b     %c***/ \\***%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c**( 2 )**%c            888  888    888    d8P 888   Y88b. d88P     %c**( 4 )**%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c***\\_/***%c          .d88P  888    888   d8P  888    'Y88888'      %c***\\_/***%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c****_****%c      .od888P'   888    888  d88   888   .d8P''Y8b.     %c****_****%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c***/ \\***%c     d88P'       888    888  8888888888  888    888     %c***/ \\***%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c**( 0 )**%c     888'        Y88b  d88P        888   Y88b  d88P     %c**( 8 )**%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c***\\_/***%c     888888888    'Y8888P'         888    'Y8888P'      %c***\\_/***%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);

    tijolos();
}

tijolos(){
    for (tijolo = 0; tijolo != 80; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");
}

movDireita5x5(){

    for(y = 4; y >= 0; y--) {
                    
        for(x = 0; x <= TAM5; x++) {
            
            matrizJogoChecar5x5[x][y] = matrizJogo5x5[x][y];
        
            if ( (matrizJogo5x5[x][y] == 0) && (matrizJogo5x5[x][y - 1] == 0) && (matrizJogo5x5[x][y - 2] == 0) && (matrizJogo5x5[x][y - 3] == 0) && (matrizJogo5x5[x][y - 4] != 0) && (y > 3) ) {
            
                matrizJogo5x5[x][y] = matrizJogo5x5[x][y - 4];
                matrizJogo5x5[x][y - 4] = 0;
                
            } else if ( (matrizJogo5x5[x][y] == 0) && (matrizJogo5x5[x][y - 1] == 0) && (matrizJogo5x5[x][y - 2] == 0) && (matrizJogo5x5[x][y - 3] != 0) && (y > 2) ) {
            
                matrizJogo5x5[x][y] = matrizJogo5x5[x][y - 3];
                matrizJogo5x5[x][y - 3] = 0;
                
            } else if ( (matrizJogo5x5[x][y] == 0) && (matrizJogo5x5[x][y - 1] == 0) && (matrizJogo5x5[x][y - 2] != 0) && (y > 1) ) {
            
                matrizJogo5x5[x][y] = matrizJogo5x5[x][y - 2];
                matrizJogo5x5[x][y - 2] = 0;
                
            } else if ( (matrizJogo5x5[x][y] == 0) && (matrizJogo5x5[x][y - 1] != 0) && (y > 0) ) {
            
                matrizJogo5x5[x][y] = matrizJogo5x5[x][y - 1];
                matrizJogo5x5[x][y - 1] = 0;
                
            }

            if ( (matrizJogo5x5[x][y]) != 0 ) {

                if ( (matrizJogo5x5[x][y - 1] == matrizJogo5x5[x][y]) && (y > 0) ) {

                    pontos = pontos + (matrizJogo5x5[x][y]*2);
                    matrizJogo5x5[x][y] = matrizJogo5x5[x][y]*2;
                    matrizJogo5x5[x][y - 1] = 0;

                } else if ( (matrizJogo5x5[x][y - 1] == 0) && (matrizJogo5x5[x][y - 2] == matrizJogo5x5[x][y]) && (y > 1) ) {

                    pontos = pontos + (matrizJogo5x5[x][y]*2);
                    matrizJogo5x5[x][y] = matrizJogo5x5[x][y]*2;
                    matrizJogo5x5[x][y - 2] = 0;

                } else if ( (matrizJogo5x5[x][y - 1] == 0) && (matrizJogo5x5[x][y - 2] == 0) && (matrizJogo5x5[x][y - 3] == matrizJogo5x5[x][y]) && (y > 2) ) {

                    pontos = pontos + (matrizJogo5x5[x][y]*2);
                    matrizJogo5x5[x][y] = matrizJogo5x5[x][y]*2;
                    matrizJogo5x5[x][y - 3] = 0;

                } else if ( (matrizJogo5x5[x][y - 1] == 0) && (matrizJogo5x5[x][y - 2] == 0) && (matrizJogo5x5[x][y - 3] == 0) && (matrizJogo5x5[x][y - 4] == matrizJogo5x5[x][y]) && (y > 3) ) {

                    pontos = pontos + (matrizJogo5x5[x][y]*2);
                    matrizJogo5x5[x][y] = matrizJogo5x5[x][y]*2;
                    matrizJogo5x5[x][y - 4] = 0;

                }
            }
        }
    }
    if (checarMovimento5x5(mov) == 0) {
        jogada++;
        valorAleatorio5x5();
    }

}

movEsquerda5x5(){
    for(y = 0; y < TAM5; y++) {
            
        for(x = 4; x >= 0; x--) {

            matrizJogoChecar5x5[x][y] = matrizJogo5x5[x][y];

            if ( (matrizJogo5x5[x][y] == 0) && (matrizJogo5x5[x][y + 1] == 0) && (matrizJogo5x5[x][y + 2] == 0) && (matrizJogo5x5[x][y + 3] == 0) && (matrizJogo5x5[x][y + 4] != 0) && (y < 1) ) {
            
                matrizJogo5x5[x][y] = matrizJogo5x5[x][y + 3];
                matrizJogo5x5[x][y + 4] = 0;
            
            } else if ( (matrizJogo5x5[x][y] == 0) && (matrizJogo5x5[x][y + 1] == 0) && (matrizJogo5x5[x][y + 2] == 0) && (matrizJogo5x5[x][y + 3] != 0) && (y < 2) ) {
            
                matrizJogo5x5[x][y] = matrizJogo5x5[x][y + 3];
                matrizJogo5x5[x][y + 3] = 0;
            
            } else if ( (matrizJogo5x5[x][y] == 0) && (matrizJogo5x5[x][y + 1] == 0) && (matrizJogo5x5[x][y + 2] != 0) && (y < 3) ) {
            
                matrizJogo5x5[x][y] = matrizJogo5x5[x][y + 2];
                matrizJogo5x5[x][y + 2] = 0;
                
            } else if ( (matrizJogo5x5[x][y] == 0) && (matrizJogo5x5[x][y + 1] != 0) && (y < 4) ) {
            
                matrizJogo5x5[x][y] = matrizJogo5x5[x][y + 1];
                matrizJogo5x5[x][y + 1] = 0;
        
            }
            
            if ( (matrizJogo5x5[x][y]) != 0 ) {
                
                if ( (matrizJogo5x5[x][y + 1] == matrizJogo5x5[x][y]) && (y < 4) ) {

                pontos = pontos + (matrizJogo5x5[x][y]*2);
                matrizJogo5x5[x][y] = matrizJogo5x5[x][y]*2;
                matrizJogo5x5[x][y + 1] = 0;

                } else if ( (matrizJogo5x5[x][y + 1] == 0) && (matrizJogo5x5[x][y + 2] == matrizJogo5x5[x][y]) && (y < 3) ) {

                    pontos = pontos + (matrizJogo5x5[x][y]*2);
                    matrizJogo5x5[x][y] = matrizJogo5x5[x][y]*2;
                    matrizJogo5x5[x][y + 2] = 0;

                } else if ( (matrizJogo5x5[x][y + 1] == 0) && (matrizJogo5x5[x][y + 2] == 0) && (matrizJogo5x5[x][y + 3] == matrizJogo5x5[x][y]) && (y < 2) ) {

                    pontos = pontos + (matrizJogo5x5[x][y]*2);
                    matrizJogo5x5[x][y] = matrizJogo5x5[x][y]*2;
                    matrizJogo5x5[x][y + 3] = 0;

                } else if ( (matrizJogo5x5[x][y + 1] == 0) && (matrizJogo5x5[x][y + 2] == 0) && (matrizJogo5x5[x][y + 3] == 0) && (matrizJogo5x5[x][y + 4] == matrizJogo5x5[x][y]) && (y < 1) ) {

                    pontos = pontos + (matrizJogo5x5[x][y]*2);
                    matrizJogo5x5[x][y] = matrizJogo5x5[x][y]*2;
                    matrizJogo5x5[x][y + 4] = 0;

                }
            }
        }
    }
    if (checarMovimento5x5(mov) == 0) {
        jogada++;
        valorAleatorio5x5();
    }
}

movBaixo5x5(){
    for(x = 4; x >= 0; x--) {
            
        for(y = 0; y < TAM5; y++) {

            matrizJogoChecar5x5[x][y] = matrizJogo5x5[x][y];
            
            if ( (matrizJogo5x5[x][y] == 0) && (matrizJogo5x5[x - 1][y] == 0) && (matrizJogo5x5[x - 2][y] == 0) && (matrizJogo5x5[x - 3][y] == 0) && (matrizJogo5x5[x - 4][y] != 0) && (x > 3) ) {
            
                matrizJogo5x5[x][y] = matrizJogo5x5[x - 3][y];
                matrizJogo5x5[x - 4][y] = 0;
                
            } else if ( (matrizJogo5x5[x][y] == 0) && (matrizJogo5x5[x - 1][y] == 0) && (matrizJogo5x5[x - 2][y] == 0) && (matrizJogo5x5[x - 3][y] != 0) && (x > 2) ) {
            
                matrizJogo5x5[x][y] = matrizJogo5x5[x - 3][y];
                matrizJogo5x5[x - 3][y] = 0;
                
            } else if ( (matrizJogo5x5[x][y] == 0) && (matrizJogo5x5[x - 1][y] == 0) && (matrizJogo5x5[x - 2][y] != 0) && (x > 1) ) {
            
                matrizJogo5x5[x][y] = matrizJogo5x5[x - 2][y];
                matrizJogo5x5[x - 2][y] = 0;
                
            } else if ( (matrizJogo5x5[x][y] == 0) && (matrizJogo5x5[x - 1][y] != 0) && (x > 0) ) {
            
                matrizJogo5x5[x][y] = matrizJogo5x5[x - 1][y];
                matrizJogo5x5[x - 1][y] = 0;
                
            }
            
            if ( (matrizJogo5x5[x][y]) != 0 ) {

                if ( (matrizJogo5x5[x - 1][y] == matrizJogo5x5[x][y]) && (x > 0) ) {

                    pontos = pontos + (matrizJogo5x5[x][y]*2);
                    matrizJogo5x5[x][y] = matrizJogo5x5[x][y]*2;

                    matrizJogo5x5[x - 1][y] = 0;

                } else if ( (matrizJogo5x5[x - 1][y] == 0) && (matrizJogo5x5[x - 2][y] == matrizJogo5x5[x][y]) && (x > 1) ) {

                    pontos = pontos + (matrizJogo5x5[x][y]*2);
                    matrizJogo5x5[x][y] = matrizJogo5x5[x][y]*2;
                    matrizJogo5x5[x - 2][y] = 0;

                } else if ( (matrizJogo5x5[x - 1][y] == 0) && (matrizJogo5x5[x - 2][y] == 0) && (matrizJogo5x5[x - 3][y] == matrizJogo5x5[x][y]) && (x > 2) ) {

                    pontos = pontos + (matrizJogo5x5[x][y]*2);
                    matrizJogo5x5[x][y] = matrizJogo5x5[x][y]*2;
                    matrizJogo5x5[x - 3][y] = 0;

                } else if ( (matrizJogo5x5[x - 1][y] == 0) && (matrizJogo5x5[x - 2][y] == 0) && (matrizJogo5x5[x - 3][y] == 0) && (matrizJogo5x5[x - 4][y] == matrizJogo5x5[x][y]) && (x > 3) ) {

                    pontos = pontos + (matrizJogo5x5[x][y]*2);
                    matrizJogo5x5[x][y] = matrizJogo5x5[x][y]*2;
                    matrizJogo5x5[x - 4][y] = 0;

                }
            }
        }
    }
    if (checarMovimento5x5(mov) == 0) {
        jogada++;
        valorAleatorio5x5();
    }
}

movCima5x5(){
    for(x = 0; x < TAM5; x++) {   

        for(y = 4; y >= 0; y--) {

            matrizJogoChecar5x5[x][y] = matrizJogo5x5[x][y];
            
            if ( (matrizJogo5x5[x][y] == 0) && (matrizJogo5x5[x + 1][y] == 0) && (matrizJogo5x5[x + 2][y] == 0) && (matrizJogo5x5[x + 3][y] == 0) && (matrizJogo5x5[x + 4][y] != 0) && (x < 1) ) {
            
                matrizJogo5x5[x][y] = matrizJogo5x5[x + 3][y];
                matrizJogo5x5[x + 4][y] = 0;
                
            } else if ( (matrizJogo5x5[x][y] == 0) && (matrizJogo5x5[x + 1][y] == 0) && (matrizJogo5x5[x + 2][y] == 0) && (matrizJogo5x5[x + 3][y] != 0) && (x < 2) ) {
            
                matrizJogo5x5[x][y] = matrizJogo5x5[x + 3][y];
                matrizJogo5x5[x + 3][y] = 0;
                
            } else if ( (matrizJogo5x5[x][y] == 0) && (matrizJogo5x5[x + 1][y] == 0) && (matrizJogo5x5[x + 2][y] != 0) && (x < 3) ) {
            
                matrizJogo5x5[x][y] = matrizJogo5x5[x + 2][y];
                matrizJogo5x5[x + 2][y] = 0;
                
            } else if ( (matrizJogo5x5[x][y] == 0) && (matrizJogo5x5[x + 1][y] != 0) && (x < 4) ) {
            
                matrizJogo5x5[x][y] = matrizJogo5x5[x + 1][y];
                matrizJogo5x5[x + 1][y] = 0;
                
            }
            
            if ( (matrizJogo5x5[x][y]) != 0 ) {

                if ( (matrizJogo5x5[x + 1][y] == matrizJogo5x5[x][y]) && (x < 4) ) {

                    pontos = pontos + (matrizJogo5x5[x][y]*2);
                    matrizJogo5x5[x][y] = matrizJogo5x5[x][y]*2;
                    matrizJogo5x5[x + 1][y] = 0;

                } else if ( (matrizJogo5x5[x + 1][y] == 0) && (matrizJogo5x5[x + 2][y] == matrizJogo5x5[x][y]) && (x < 3) ) {

                    pontos = pontos + (matrizJogo5x5[x][y]*2);
                    matrizJogo5x5[x][y] = matrizJogo5x5[x][y]*2;
                    matrizJogo5x5[x + 2][y] = 0;

                } else if ( (matrizJogo5x5[x + 1][y] == 0) && (matrizJogo5x5[x + 2][y] == 0) && (matrizJogo5x5[x + 3][y] == matrizJogo5x5[x][y]) && (x < 2) ) {

                    pontos = pontos + (matrizJogo5x5[x][y]*2);
                    matrizJogo5x5[x][y] = matrizJogo5x5[x][y]*2;
                    matrizJogo5x5[x + 3][y] = 0;

                } else if ( (matrizJogo5x5[x + 1][y] == 0) && (matrizJogo5x5[x + 2][y] == 0) && (matrizJogo5x5[x + 3][y] == 0) && (matrizJogo5x5[x + 4][y] == matrizJogo5x5[x][y]) && (x < 1) ) {

                    pontos = pontos + (matrizJogo5x5[x][y]*2);
                    matrizJogo5x5[x][y] = matrizJogo5x5[x][y]*2;
                    matrizJogo5x5[x + 4][y] = 0;

                }
            }
        }
    }
    if (checarMovimento5x5(mov) == 0) {
        jogada++;
        valorAleatorio5x5();
    }
}

gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

checarMovimento5x5(){
    
	if (jogada > 0){
		for(x = 0; x < TAM5; x++){
			for(y = 0; y < TAM5; y++){
				if (matrizJogo5x5[x][y] != matrizJogoChecar5x5[x][y]){
					return 0;
					break;
				}
			}
		}
		return 1;
	} else {
		return 0;
	}

}

checarVazios5x5(){
    int vazios = TAM5 * TAM5;
    for (x = 0; x < TAM5; x++){
        for (y = 0; y < TAM5; y++){
            if (matrizJogo5x5[x][y] != 0){
                vazios--;
            }
        }
    }
    if (vazios == 0){
        return 1;
    } else {
        return 0;
    }
}

checarVitoriaFacil(){
	for ((x = 0); (x < TAM5); x++) {
		for ((y = 0); (y < TAM5); y++) {
			if (matrizJogo5x5[x][y] == 2048) {
				return 0;
				break;
			}
		}
	}
	return 1;
}

valorAleatorio5x5(){
    
    int ver, confirmar, posx, posy = 0;

    if(checarVazios5x5(ver) == 0){

        srand(time(NULL));

        do{
            x = (rand() % TAM5);     // GERAR VALOR ALEATORIO PRA LINHA
            y = (rand() % TAM5);     // GERAR VALOR ALEATORIO PRA COLUNA

            if (matrizJogo5x5[x][y] == 0) {
                matrizJogo5x5[x][y] = 2;
                confirmar = 1;
            } else {
                confirmar = 0;
            }
        }while(confirmar != 1);

        posy = 18;
        for (x = 0; x < TAM5; x++){                   // PRINTA OS VALORES DA MATRIZ NAS POSICOES CORRESPONDENTES
            posx = 5;
            for (y = 0; y < TAM5; y++){
                gotoxy(posx,posy);                 // COLUNA / LINHA
                    if (matrizJogo5x5[x][y] != 0){
                    	printf("      ");
                    	gotoxy(posx,posy);
                        printf("%i  ", matrizJogo5x5[x][y]);
                    } else {
                        printf("      ");
                    }
                posx += 11;
            }
            posy += 5;
        }
    }
}
