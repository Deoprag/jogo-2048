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
#define TAM 5


void gotoxy(int x, int y);
void movEsquerda();
void movDireita();
void movCima();
void movBaixo();
int logo();
int tijolos();
int tijoloMenor();
int jogar5x5();
int checarMovimento();
int checarVazios();
int valorAleatorio();
int checarVitoria();

int x, y, opcao, jogada, pontos, contagem, mov, tijolo = 0;
int matrizJogo[TAM][TAM];
int matrizJogoChecar[TAM][TAM];

int main(){
    jogar5x5();
}


jogar5x5(){
    
    int ver = 0;

    valorAleatorio();
    system("cls");

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             DIFICULDADE: FACIL                             %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] VOLTAR                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c    PONTOS:  |      |%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c  MOVIMENTOS:|      |%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijoloMenor();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c [P] SALVAR JOGO     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c [R] REINICIAR JOGO  %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c [O] RANKING         %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijoloMenor();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    
    tijoloMenor();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijoloMenor();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c  UNIFACEAR - 2022   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    valorAleatorio();

    do{

        gotoxy(71,18);
        printf("%i", pontos);                   // PRINTA OS PONTOS NA TELA
        gotoxy(71,19);
        printf("%i", jogada);                   // PRINTA A QUANTIDADE DE MOVIMENTOS NA TELA
        gotoxy(80,40);

        opcao = getch();

        if ( (opcao == DIREITA) ) {               // DIREITA

            movDireita();    
            
        } else if ( (opcao == ESQUERDA) ) {			// ESQUERDA

            movEsquerda();
            
        } else if ( (opcao == BAIXO) ) {			// BAIXO

            movBaixo();

        } else if ( (opcao == CIMA) ) {			// CIMA

            movCima();

        } else if (opcao == 27) {    // ESC
            return 1;
        }

        if(checarVitoria(ver) == 0){
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

tijoloMenor(){
    for (tijolo = 0; tijolo != 57; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");
}

movDireita(){

    for(y = 4; y >= 0; y--) {
                    
        for(x = 0; x < TAM; x++) {
            
            matrizJogoChecar[x][y] = matrizJogo[x][y];
        
            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] == 0) && (matrizJogo[x][y - 3] != 0) && (y > 2) && (matrizJogo[x][y - 4] != 0) && (y > 3) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y - 3];
                matrizJogo[x][y - 3] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] == 0) && (matrizJogo[x][y - 3] != 0) && (y > 2) ) {
            
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

                } else if ( (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] == 0) && (matrizJogo[x][y - 3] == 0) && (matrizJogo[x][y - 4] == matrizJogo[x][y]) && (y > 3) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y - 3] = 0;

                }
            }
        }
    }
    if (checarMovimento(mov) == 0) {
        jogada++;
        valorAleatorio();
    }

}

movEsquerda(){
    for(y = 0; y < TAM; y++) {
            
        for(x = 4; x >= 0; x--) {

            matrizJogoChecar[x][y] = matrizJogo[x][y];

            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == 0) && (matrizJogo[x][y + 3] != 0) && (matrizJogo[x][y + 4] != 0) && (y < 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y + 3];
                matrizJogo[x][y + 3] = 0;
            
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == 0) && (matrizJogo[x][y + 3] != 0) && (y < 2) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y + 3];
                matrizJogo[x][y + 3] = 0;
            
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] != 0) && (y < 3) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y + 2];
                matrizJogo[x][y + 2] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] != 0) && (y < 4) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y + 1];
                matrizJogo[x][y + 1] = 0;
        
            }
            
            if ( (matrizJogo[x][y]) != 0 ) {
                
                if ( (matrizJogo[x][y + 1] == matrizJogo[x][y]) && (y < 4) ) {

                pontos = pontos + (matrizJogo[x][y]*2);
                matrizJogo[x][y] = matrizJogo[x][y]*2;
                matrizJogo[x][y + 1] = 0;

                } else if ( (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == matrizJogo[x][y]) && (y < 3) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y + 2] = 0;

                } else if ( (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == 0) && (matrizJogo[x][y + 3] == matrizJogo[x][y]) && (y < 2) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y + 3] = 0;

                } else if ( (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == 0) && (matrizJogo[x][y + 3] == 0) && (matrizJogo[x][y + 4] == matrizJogo[x][y]) && (y < 1) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y + 3] = 0;

                }
            }
        }
    }
    if (checarMovimento(mov) == 0) {
        jogada++;
        valorAleatorio();
    }
}

movBaixo(){
    for(x = 4; x >= 0; x--) {
            
        for(y = 0; y < TAM; y++) {

            matrizJogoChecar[x][y] = matrizJogo[x][y];
            
            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] == 0) && (matrizJogo[x - 3][y] != 0) && (matrizJogo[x - 4][y] != 0) && (x > 3) ) {
            
                matrizJogo[x][y] = matrizJogo[x - 3][y];
                matrizJogo[x - 3][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] == 0) && (matrizJogo[x - 3][y] != 0) && (x > 2) ) {
            
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

                } else if ( (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] == 0) && (matrizJogo[x - 3][y] == 0) && (matrizJogo[x - 4][y] == matrizJogo[x][y]) && (x > 3) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x - 3][y] = 0;

                }
            }
        }
    }
    if (checarMovimento(mov) == 0) {
        jogada++;
        valorAleatorio();
    }
}

movCima(){
    for(x = 0; x < TAM; x++) {   

        for(y = 4; y >= 0; y--) {

            matrizJogoChecar[x][y] = matrizJogo[x][y];
            
            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == 0) && (matrizJogo[x + 3][y] != 0) && (matrizJogo[x + 4][y] != 0) && (x < 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x + 3][y];
                matrizJogo[x + 3][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == 0) && (matrizJogo[x + 3][y] != 0) && (x < 2) ) {
            
                matrizJogo[x][y] = matrizJogo[x + 3][y];
                matrizJogo[x + 3][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] != 0) && (x < 3) ) {
            
                matrizJogo[x][y] = matrizJogo[x + 2][y];
                matrizJogo[x + 2][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] != 0) && (x < 4) ) {
            
                matrizJogo[x][y] = matrizJogo[x + 1][y];
                matrizJogo[x + 1][y] = 0;
                
            }
            
            if ( (matrizJogo[x][y]) != 0 ) {

                if ( (matrizJogo[x + 1][y] == matrizJogo[x][y]) && (x < 4) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x + 1][y] = 0;

                } else if ( (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == matrizJogo[x][y]) && (x < 3) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x + 2][y] = 0;

                } else if ( (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == 0) && (matrizJogo[x + 3][y] == matrizJogo[x][y]) && (x < 2) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x + 3][y] = 0;

                } else if ( (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == 0) && (matrizJogo[x + 3][y] == 0) && (matrizJogo[x + 4][y] == matrizJogo[x][y]) && (x < 1) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x + 3][y] = 0;

                }
            }
        }
    }
    if (checarMovimento(mov) == 0) {
        jogada++;
        valorAleatorio();
    }
}

gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

checarMovimento(){
    
	if (jogada > 0){
		for(x = 0; x < TAM; x++){
			for(y = 0; y < TAM; y++){
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

checarVazios(){
    int vazios = TAM * TAM;
    for (x = 0; x < TAM; x++){
        for (y = 0; y < TAM; y++){
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

checarVitoria(){
	for ((x = 0); (x < TAM); x++) {
		for ((y = 0); (y < TAM); y++) {
			if (matrizJogo[x][y] == 2048) {
				return 0;
				break;
			}
		}
	}
	return 1;
}

valorAleatorio(){
    
    int ver, confirmar, posx, posy = 0;

    if(checarVazios(ver) == 0){

        srand(time(NULL));

        do{
            x = (rand() % TAM);     // GERAR VALOR ALEATORIO PRA LINHA
            y = (rand() % TAM);     // GERAR VALOR ALEATORIO PRA COLUNA

            if (matrizJogo[x][y] == 0) {
                matrizJogo[x][y] = 2;
                confirmar = 1;
            } else {
                confirmar = 0;
            }
        }while(confirmar != 1);

        posy = 18;
        for (x = 0; x < TAM; x++){                   // PRINTA OS VALORES DA MATRIZ NAS POSICOES CORRESPONDENTES
            posx = 5;
            for (y = 0; y < TAM; y++){
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
