#include <stdio.h>
#include <stdlib.h>
#define TAM5 5

typedef struct{
    char apelido[17];
    int dificuldade;
    int pontos;
} Pontuacoes;

int main(){
    int x, y = 0;
    FILE *salvos;
    Pontuacoes ranking;

    salvos = fopen("Ranking.txt", "rb");
    while ( fread(&ranking, sizeof(Pontuacoes), 1, salvos) == 1 ){
        printf("Dificuldade:    %i\n", ranking.dificuldade);
        printf("Pontos:         %i\n", ranking.pontos);
        printf("Apelido:        %s\n", ranking.apelido);
        printf("----------------------------------------------\n");
    }
    fclose(salvos);
    getch();
}