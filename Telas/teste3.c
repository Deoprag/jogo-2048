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
#define TAM3 3


void gotoxy(int x, int y);
void movEsquerda3x3();
void movDireita3x3();
void movCima3x3();
void movBaixo3x3();
int logo();
int tijolos();
int jogar3x3();
int checarMovimento3x3();
int checarVazios3x3();
int valorAleatorio3x3();
int checarVitoriaHardcore();

int x, y, opcao, jogada, pontos, mov, tijolo = 0;
int matrizJogo3x3[TAM3][TAM3];
int matrizJogoChecar3x3[TAM3][TAM3];

int main(){
    jogar3x3();
}


jogar3x3(){
    
    int ver = 0;

    valorAleatorio3x3();
    system("cls");

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                            DIFICULDADE: HARDCORE                           %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] VOLTAR                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    PONTOS:  |     | %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  MOVIMENTOS:|     | %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c [P] SALVAR JOGO     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c [R] REINICIAR JOGO  %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c [O] RANKING         %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c        DICA:        %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  UTILIZE AS TECLAS  %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c   DO TECLADO PARA   %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c     MOVIMENTAR O    %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c      TABULEIRO      %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  UNIFACEAR - 2022   %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);

    tijolos();

    valorAleatorio3x3();

    do{

        gotoxy(71,18);
        printf("%i", pontos);                   // PRINTA OS PONTOS NA TELA
        gotoxy(71,19);
        printf("%i", jogada);                   // PRINTA A QUANTIDADE DE MOVIMENTOS NA TELA
        gotoxy(80,40);

        opcao = getch();

        if ( (opcao == DIREITA) ) {               // DIREITA

            movDireita3x3();    
            
        } else if ( (opcao == ESQUERDA) ) {			// ESQUERDA

            movEsquerda3x3();
            
        } else if ( (opcao == BAIXO) ) {			// BAIXO

            movBaixo3x3();

        } else if ( (opcao == CIMA) ) {			// CIMA

            movCima3x3();

        } else if (opcao == 27) {    // ESC
            return 1;
        }

        if(checarVitoriaHardcore(ver) == 0){
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

movDireita3x3(){

    for(y = 2; y >= 0; y--) {
                    
        for(x = 0; x < TAM3; x++) {
            
            matrizJogoChecar3x3[x][y] = matrizJogo3x3[x][y];
        
            if ( (matrizJogo3x3[x][y] == 0) && (matrizJogo3x3[x][y - 1] == 0) && (matrizJogo3x3[x][y - 2] != 0) && (y > 1) ) {
            
                matrizJogo3x3[x][y] = matrizJogo3x3[x][y - 2];
                matrizJogo3x3[x][y - 2] = 0;
                
            } else if ( (matrizJogo3x3[x][y] == 0) && (matrizJogo3x3[x][y - 1] != 0) && (y > 0) ) {
            
                matrizJogo3x3[x][y] = matrizJogo3x3[x][y - 1];
                matrizJogo3x3[x][y - 1] = 0;
                
            }

            if ( (matrizJogo3x3[x][y]) != 0 ) {

                if ( (matrizJogo3x3[x][y - 1] == matrizJogo3x3[x][y]) && (y > 0) ) {

                    pontos = pontos + (matrizJogo3x3[x][y]*2);
                    matrizJogo3x3[x][y] = matrizJogo3x3[x][y]*2;
                    matrizJogo3x3[x][y - 1] = 0;

                } else if ( (matrizJogo3x3[x][y - 1] == 0) && (matrizJogo3x3[x][y - 2] == matrizJogo3x3[x][y]) && (y > 1) ) {

                    pontos = pontos + (matrizJogo3x3[x][y]*2);
                    matrizJogo3x3[x][y] = matrizJogo3x3[x][y]*2;
                    matrizJogo3x3[x][y - 2] = 0;

                }
            }
        }
    }
    if (checarMovimento3x3(mov) == 0) {
        jogada++;
        valorAleatorio3x3();
    }

}

movEsquerda3x3(){
    for(y = 0; y < TAM3; y++) {
            
        for(x = 2; x >= 0; x--) {

            matrizJogoChecar3x3[x][y] = matrizJogo3x3[x][y];

            if ( (matrizJogo3x3[x][y] == 0) && (matrizJogo3x3[x][y + 1] == 0) && (matrizJogo3x3[x][y + 2] != 0) && (y < 1) ) {
            
                matrizJogo3x3[x][y] = matrizJogo3x3[x][y + 2];
                matrizJogo3x3[x][y + 2] = 0;
                
            } else if ( (matrizJogo3x3[x][y] == 0) && (matrizJogo3x3[x][y + 1] != 0) && (y < 2) ) {
            
                matrizJogo3x3[x][y] = matrizJogo3x3[x][y + 1];
                matrizJogo3x3[x][y + 1] = 0;
        
            }
            
            if ( (matrizJogo3x3[x][y]) != 0 ) {
                
                if ( (matrizJogo3x3[x][y + 1] == matrizJogo3x3[x][y]) && (y < 2) ) {

                pontos = pontos + (matrizJogo3x3[x][y]*2);
                matrizJogo3x3[x][y] = matrizJogo3x3[x][y]*2;
                matrizJogo3x3[x][y + 1] = 0;

                } else if ( (matrizJogo3x3[x][y + 1] == 0) && (matrizJogo3x3[x][y + 2] == matrizJogo3x3[x][y]) && (y < 1) ) {

                    pontos = pontos + (matrizJogo3x3[x][y]*2);
                    matrizJogo3x3[x][y] = matrizJogo3x3[x][y]*2;
                    matrizJogo3x3[x][y + 2] = 0;

                }
            }
        }
    }
    if (checarMovimento3x3(mov) == 0) {
        jogada++;
        valorAleatorio3x3();
    }
}

movBaixo3x3(){
    for(x = 2; x >= 0; x--) {
            
        for(y = 0; y < TAM3; y++) {

            matrizJogoChecar3x3[x][y] = matrizJogo3x3[x][y];
            
            if ( (matrizJogo3x3[x][y] == 0) && (matrizJogo3x3[x - 1][y] == 0) && (matrizJogo3x3[x - 2][y] != 0) && (x > 1) ) {
            
                matrizJogo3x3[x][y] = matrizJogo3x3[x - 2][y];
                matrizJogo3x3[x - 2][y] = 0;
                
            } else if ( (matrizJogo3x3[x][y] == 0) && (matrizJogo3x3[x - 1][y] != 0) && (x > 0) ) {
            
                matrizJogo3x3[x][y] = matrizJogo3x3[x - 1][y];
                matrizJogo3x3[x - 1][y] = 0;
                
            }
            
            if ( (matrizJogo3x3[x][y]) != 0 ) {

                if ( (matrizJogo3x3[x - 1][y] == matrizJogo3x3[x][y]) && (x > 0) ) {

                    pontos = pontos + (matrizJogo3x3[x][y]*2);
                    matrizJogo3x3[x][y] = matrizJogo3x3[x][y]*2;

                    matrizJogo3x3[x - 1][y] = 0;

                } else if ( (matrizJogo3x3[x - 1][y] == 0) && (matrizJogo3x3[x - 2][y] == matrizJogo3x3[x][y]) && (x > 1) ) {

                    pontos = pontos + (matrizJogo3x3[x][y]*2);
                    matrizJogo3x3[x][y] = matrizJogo3x3[x][y]*2;
                    matrizJogo3x3[x - 2][y] = 0;

                }
            }
        }
    }
    if (checarMovimento3x3(mov) == 0) {
        jogada++;
        valorAleatorio3x3();
    }
}

movCima3x3(){
    for(x = 0; x < TAM3; x++) {   

        for(y = 2; y >= 0; y--) {

            matrizJogoChecar3x3[x][y] = matrizJogo3x3[x][y];
            
            if ( (matrizJogo3x3[x][y] == 0) && (matrizJogo3x3[x + 1][y] == 0) && (matrizJogo3x3[x + 2][y] != 0) && (x < 1) ) {
            
                matrizJogo3x3[x][y] = matrizJogo3x3[x + 2][y];
                matrizJogo3x3[x + 2][y] = 0;
                
            } else if ( (matrizJogo3x3[x][y] == 0) && (matrizJogo3x3[x + 1][y] != 0) && (x < 2) ) {
            
                matrizJogo3x3[x][y] = matrizJogo3x3[x + 1][y];
                matrizJogo3x3[x + 1][y] = 0;
                
            }
            
            if ( (matrizJogo3x3[x][y]) != 0 ) {

                if ( (matrizJogo3x3[x + 1][y] == matrizJogo3x3[x][y]) && (x < 2) ) {

                    pontos = pontos + (matrizJogo3x3[x][y]*2);
                    matrizJogo3x3[x][y] = matrizJogo3x3[x][y]*2;
                    matrizJogo3x3[x + 1][y] = 0;

                } else if ( (matrizJogo3x3[x + 1][y] == 0) && (matrizJogo3x3[x + 2][y] == matrizJogo3x3[x][y]) && (x < 1) ) {

                    pontos = pontos + (matrizJogo3x3[x][y]*2);
                    matrizJogo3x3[x][y] = matrizJogo3x3[x][y]*2;
                    matrizJogo3x3[x + 2][y] = 0;

                }
            }
        }
    }
    if (checarMovimento3x3(mov) == 0) {
        jogada++;
        valorAleatorio3x3();
    }
}

gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

checarMovimento3x3(){
    
	if (jogada > 0){
		for(x = 0; x < TAM3; x++){
			for(y = 0; y < TAM3; y++){
				if (matrizJogo3x3[x][y] != matrizJogoChecar3x3[x][y]){
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

checarVazios3x3(){
    int vazios = TAM3 * TAM3;
    for (x = 0; x < TAM3; x++){
        for (y = 0; y < TAM3; y++){
            if (matrizJogo3x3[x][y] != 0){
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

checarVitoriaHardcore(){
	for ((x = 0); (x < TAM3); x++) {
		for ((y = 0); (y < TAM3); y++) {
			if (matrizJogo3x3[x][y] == 1024) {
				return 0;
				break;
			}
		}
	}
	return 1;
}

valorAleatorio3x3(){
    
    int ver, i, posx, posy = 0;

    if(checarVazios3x3(ver) == 0){

        srand(time(NULL));

        do{
            x = (rand() % TAM3);     // GERAR VALOR ALEATORIO PRA POSICAO HORIZONTAL
            y = (rand() % TAM3);     // GERAR VALOR ALEATORIO PRA POSICAO VERTICAL

            if (matrizJogo3x3[x][y] == 0) {
                matrizJogo3x3[x][y] = 2;
                i = 1;
            } else {
                i = 0;
            }
        }while(i != 1);
    }
}
