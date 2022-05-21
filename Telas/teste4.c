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
#define TAM4 4
#define TAM5 5

// PROCEDIMENTOS
void gotoxy();
void movEsquerda4x4();
void movDireita4x4();
void movCima4x4();
void movBaixo4x4();
void jogar4x4Media();
void logo();
void tijolos();

// FUNÇÕES
int checarMovimento();
int checarVazios();
int valorAleatorio();
int checarVitoriaMedia();
int checarVitoriaDificil();

// VARIAVEIS GLOBAIS
int opcao, jogada, pontos, mov = 0;
int **matrizJogo;
int **matrizJogoChecar;

// FUNÇÃO PRINCIPAL
int main(){
    jogar4x4Media();
}


jogar4x4Media(){
    int ver, x, y = 0;
    int tam = TAM4;

    pontos = jogada = 0;

    valorAleatorio(TAM4);
    system("cls");

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             DIFICULDADE: MEDIA                             %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] VOLTAR                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   PONTOS:  |     | %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c MOVIMENTOS:|     | %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c [P] SALVAR JOGO    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c [R] REINICIAR JOGO %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c [O] RANKING        %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c        DICA:       %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c  UTILIZE AS SETAS  %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c  DO TECLADO PARA   %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    MOVIMENTAR O    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c     TABULEIRO      %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  UNIFACEAR - 2022  %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);

    tijolos();

    valorAleatorio(TAM4);

    do{

        gotoxy(71,18);
        printf("%i", pontos);                   // PRINTA OS PONTOS NA TELA
        gotoxy(71,19);
        printf("%i", jogada);                   // PRINTA A QUANTIDADE DE MOVIMENTOS NA TELA
        gotoxy(80,40);

        opcao = getch();

        if ( (opcao == DIREITA) ) {                 // DIREITA

            movDireita4x4();
            
        } else if ( (opcao == ESQUERDA) ) {			// ESQUERDA

            movEsquerda4x4();
            
        } else if ( (opcao == BAIXO) ) {			// BAIXO

            movBaixo4x4();

        } else if ( (opcao == CIMA) ) {			    // CIMA

            movCima4x4();

        } else if (opcao == ESC) {                   // ESC
            return 1;
        }

        if(checarVitoriaMedia(ver) == 0){
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
    int tijolo = 0;
    for (tijolo = 0; tijolo != 80; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");
}

movDireita4x4(){
    int x, y = 0;

    for(y = 3; y >= 0; y--) {
                    
        for(x = 0; x < TAM4; x++) {
            
            matrizJogoChecar[x][y] = matrizJogo[x][y];
        
            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] == 0) && (matrizJogo[x][y - 3] != 0) && (y > 2) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y - 3];
                matrizJogo[x][y - 3] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] != 0) && (y > 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y - 2];
                matrizJogo[x][y - 2] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] != 0) && (y > 0) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y - 1];
                matrizJogo[x][y - 1] = 0;
                
            }

            if ( (matrizJogo[x][y]) != 0 ) {

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
    if (checarMovimento(TAM4) == 0) {
        jogada++;
        valorAleatorio(TAM4);
    }

}

movEsquerda4x4(){
    int x, y = 0;

    for(y = 0; y < TAM4; y++) {
            
        for(x = 3; x >= 0; x--) {

            matrizJogoChecar[x][y] = matrizJogo[x][y];

            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == 0) && (matrizJogo[x][y + 3] != 0) && (y < 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y + 3];
                matrizJogo[x][y + 3] = 0;
            
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] != 0) && (y < 2) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y + 2];
                matrizJogo[x][y + 2] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] != 0) && (y < 3) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y + 1];
                matrizJogo[x][y + 1] = 0;
        
            }
            
            if ( (matrizJogo[x][y]) != 0 ) {
                
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
    if (checarMovimento(TAM4) == 0) {
        jogada++;
        valorAleatorio(TAM4);
    }
}

movBaixo4x4(){
    int x, y = 0;

    for(x = 3; x >= 0; x--) {
            
        for(y = 0; y < TAM4; y++) {

            matrizJogoChecar[x][y] = matrizJogo[x][y];
            
            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] == 0) && (matrizJogo[x - 3][y] != 0) && (x > 2) ) {
            
                matrizJogo[x][y] = matrizJogo[x - 3][y];
                matrizJogo[x - 3][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] != 0) && (x > 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x - 2][y];
                matrizJogo[x - 2][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] != 0) && (x > 0) ) {
            
                matrizJogo[x][y] = matrizJogo[x - 1][y];
                matrizJogo[x - 1][y] = 0;
                
            }
            
            if ( (matrizJogo[x][y]) != 0 ) {

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
    if (checarMovimento(TAM4) == 0) {
        jogada++;
        valorAleatorio(TAM4);
    }
}

movCima4x4(){
    int x, y = 0;
    for(x = 0; x < TAM4; x++) {   

        for(y = 3; y >= 0; y--) {

            matrizJogoChecar[x][y] = matrizJogo[x][y];
            
            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == 0) && (matrizJogo[x + 3][y] != 0) && (x < 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x + 3][y];
                matrizJogo[x + 3][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] != 0) && (x < 2) ) {
            
                matrizJogo[x][y] = matrizJogo[x + 2][y];
                matrizJogo[x + 2][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] != 0) && (x < 3) ) {
            
                matrizJogo[x][y] = matrizJogo[x + 1][y];
                matrizJogo[x + 1][y] = 0;
                
            }
            
            if ( (matrizJogo[x][y]) != 0 ) {

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
    if (checarMovimento(TAM4) == 0) {
        jogada++;
        valorAleatorio(TAM4);
    }
}

gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

checarMovimento(int tam){
    int x, y = 0;

	if (jogada > 0){
		for(x = 0; x < tam; x++){
			for(y = 0; y < tam; y++){
				if (matrizJogo[x][y] != matrizJogoChecar[x][y]){
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

checarVazios(int tam){
    int x, y = 0;
    int vazios = tam * tam;
    for (x = 0; x < tam; x++){
        for (y = 0; y < tam; y++){
            if (matrizJogo[x][y] != 0){
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

checarVitoriaMedia(){
    int x, y = 0;
	for ((x = 0); (x < TAM4); x++) {
		for ((y = 0); (y < TAM4); y++) {
			if (matrizJogo[x][y] == 2048) {
				return 0;
			}
		}
	}
	return 1;
}

checarVitoriaDificil(){
    int x, y = 0;
	for ((x = 0); (x < TAM4); x++) {
		for ((y = 0); (y < TAM4); y++) {
			if (matrizJogo[x][y] == 4096) {
				return 0;
			}
		}
	}
	return 1;
}

valorAleatorio(int tam){
    
    int i, posx, posy, x, y = 0;

    if(checarVazios(tam) == 0){

        srand(time(NULL));

        do{
            x = (rand() % tam);     // GERAR VALOR ALEATORIO PRA POSICAO HORIZONTAL
            y = (rand() % tam);     // GERAR VALOR ALEATORIO PRA POSICAO VERTICAL

            if (matrizJogo[x][y] == 0) {
                matrizJogo[x][y] = 2;
                i = 1;
            } else {
                i = 0;
            }
        }while(i != 1);

        posy = 20;
        for (x = 0; x < tam; x++){                   // PRINTA OS VALORES DA MATRIZ NAS POSICOES CORRESPONDENTES
            posx = 11;
            for (y = 0; y < tam; y++){
                gotoxy(posx,posy);                 // COLUNA / LINHA
                    if (matrizJogo[x][y] != 0){
                    	printf("      ");
                    	gotoxy(posx,posy);
                        printf("%i  ", matrizJogo[x][y]);
                    } else {
                        printf("      ");
                    }
                posx += 11;
            }
            posy += 5;
        }
    }
}
