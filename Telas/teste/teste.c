#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastro();

int main(){

    int tijolo;

    tijolo = 0;
    for (tijolo = 0; tijolo < 63; tijolo ++){
        printf("%c", 178);
    }

    printf("\n");
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c    222222   \t 0000000000 \t    4444   \t 888888888   %c%c\n", 178, 178, 178, 178);
    printf("%c%c  2222222222 \t0000    0000\t   44444   \t88888888888  %c%c\n", 178, 178, 178, 178);
    printf("%c%c          222\t000      000\t  44 444   \t888     888  %c%c\n", 178, 178, 178, 178);
    printf("%c%c        22222\t00        00\t 44  444   \t 888888888   %c%c\n", 178, 178, 178, 178);
    printf("%c%c     22222   \t00        00\t44444444444\t 888888888   %c%c\n", 178, 178, 178, 178);
    printf("%c%c   22222     \t000      000\t     444   \t888     888  %c%c\n", 178, 178, 178, 178);
    printf("%c%c  2222       \t0000    0000\t     444   \t88888888888  %c%c\n", 178, 178, 178, 178);
    printf("%c%c  22222222222\t 0000000000 \t     444   \t 888888888   %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);

    tijolo = 0;
    for (tijolo = 0; tijolo < 63; tijolo ++){
        printf("%c", 178);
    }

    cadastro();
}

void cadastro(){

    char apelido[20];
    char senha[16];
    char senha2[16];
    char numero[11];

    printf("\nDigite um apelido: ");
    fflush(stdin);
    gets(apelido);
    
    printf("\nDigite uma senha: ");
    fflush(stdin);
    gets(senha);

    printf("\nConfirme a senha: ");
    fflush(stdin);
    gets(senha2);

    printf("\nDigite seu numero de celular: ");
    gets(numero);
    getch();

    puts(apelido);
    puts(senha);
    puts(senha2);
    puts(numero);

}