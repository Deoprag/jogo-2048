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
#define TAM 4


// FUNCOES
int checarMovimento();
int checarVazios();
int valorAleatorio();
int checarVitoria();

// VAR GLOBAIS
int x, y, opcao, jogada, pontos, contagem, mov = 0;
int matrizJogo[TAM][TAM];
int matrizJogoChecar[TAM][TAM];

// PRINCIPAL
int main(){
	
	int ver = 0;
	
    for (x = 0; x < TAM; x++){
        for (y = 0; y < TAM; y++){
            matrizJogo[x][y] = 0;
			matrizJogoChecar[x][y] = 0;
        }
    }

    valorAleatorio();
    system("cls");
    valorAleatorio();

    do{
        
    system("cls");
    printf("------------------------------------------------------\n");
    for (x = 0; x < TAM; x++) {
		printf("\t");
		for (y = 0; y < TAM; y++){
	        printf("%i\t", matrizJogo[x][y]);
	    }
	    printf("\n");
	}
	
    printf("------------------------------------------------------\n");
    printf("                    JOGADAS:   %i                     \n", jogada);
    printf("                    PONTOS:    %i                     \n", pontos);
    printf("               ULTIMO MOVIMENTO:    %i                \n", opcao);
    printf("------------------------------------------------------\n");

	opcao = getch();

	if ( (opcao == DIREITA) ) {               // DIREITA

		for(y = 3; y >= 0; y--) {
				
			for(x = 0; x < TAM; x++) {
				
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
		if (checarMovimento(mov) == 0) {
			jogada++;
			valorAleatorio();
    	}    
        
    } else if ( (opcao == ESQUERDA) ) {			// ESQUERDA

		for(y = 0; y < TAM; y++) {
		
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
		if (checarMovimento(mov) == 0) {
			jogada++;
			valorAleatorio();
    	}
        
    } else if ( (opcao == BAIXO) ) {			// BAIXO

		for(x = 3; x >= 0; x--) {
		
			for(y = 0; y < TAM; y++) {

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
		if (checarMovimento(mov) == 0) {
        	jogada++;
        	valorAleatorio();
        }

    } else if ( (opcao == CIMA) ) {			// CIMA

		for(x = 0; x < TAM; x++) {   

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
		if (checarMovimento(mov) == 0) {
			jogada++;
			valorAleatorio();
        }

    } else if (opcao == 27) {    // ESC
        return 1;
    }

    if(checarVitoria(ver) == 0){
    	system("cls");
    	printf("VITORIA");
    	opcao = 27;
	}
	
    } while ( opcao != 27 );


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
    int vazios = 16;
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

    int ver, i = 0;

    if(checarVazios(ver) == 0){

        srand(time(0));

        do{
            x = (rand() % TAM);     // GERAR VALOR ALEATORIO PRA POSICAO HORIZONTAL
            y = (rand() % TAM);     // GERAR VALOR ALEATORIO PRA POSICAO VERTICAL

            if (matrizJogo[x][y] == 0) {
                matrizJogo[x][y] = 2;
                i = 1;
            } else {
                i = 0;
            }
        }while(i != 1);
    }
}