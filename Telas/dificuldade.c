#include <stdlib.h>
#include <stdio.h>

char nomeJogador[20];
int dificuldadeJogo = 2;

int main(){
printf ("Ola, %s, escolha sua dificuldade:\n", nomeJogador);
    printf ("----------------------------------------------------------------------------\n");
    printf ("| Digite [1] para FACIL | Digite [2] para NORMAL | Digite [3] para DIFICIL |\n");
    printf ("|                      Se voce digitar alguma letra                        |\n");
    printf ("|              sua dificuldade sera definida como [2] NORMAL               |\n");
    printf ("----------------------------------------------------------------------------\n");
    dificuldade:
    printf ("Digite um valor: ");
    scanf ("%i", &dificuldadeJogo);
    if (dificuldadeJogo == 1) {
        printf("A dificuldade foi definida como FACIL\n");
        } else if (dificuldadeJogo == 2){
            printf ("A dificuldade foi definida como NORMAL\n");
        } else if (dificuldadeJogo == 3){
            printf ("A dificuldade foi definida como DIFICIL\n");
        } else {
            printf ("Digite um valor valido entre 1 - 3\n");
            int getchar(void);
            goto dificuldade;
        }

    return 0;
}
