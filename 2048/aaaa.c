#include <stdio.h>
#include <stdlib.h>
#define TAM5 5

typedef struct{
    char nomeSalvo[17];
	int matrizSalva[5][5];
	int dificuldade;
    int pontos;
    int jogada;
} JogosSalvos;

int main(){
    int x, y = 0;
    FILE *salvos;
    JogosSalvos salvaJogo;

    salvos = fopen("JogosSalvos.txt", "rb");
    while ( fread(&salvaJogo, sizeof(JogosSalvos), 1, salvos) == 1 ){
        printf("Nome: %s\n", salvaJogo.nomeSalvo);
        printf("Matriz: \n");
        for (x = 0; x < TAM5; x++){
            for (y = 0; y < TAM5; y++){
                printf(" %i\t|", salvaJogo.matrizSalva[x][y]);
            }
            printf("\n");
        }
        printf("Dificuldade:    %i\n", salvaJogo.dificuldade);
        printf("Pontos:         %i\n", salvaJogo.pontos);
        printf("Jogadas:        %i\n", salvaJogo.jogada);
        printf("----------------------------------------------\n");
    }
    fclose(salvos);
    getch();
}