#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tijolo01, tijolo02, tijolo03, inicial = 0;

    for (tijolo01 = 0; tijolo01 < 63; tijolo01 ++){
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

    for (tijolo02 = 0; tijolo02 < 63; tijolo02 ++){
        printf("%c", 178);
    }

    printf("\n");
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[1]Login    \t[2]Cadastro\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t     [3]Configuracoes    \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);

    for (tijolo03 = 0; tijolo03 < 63; tijolo03 ++){
        printf("%c", 178);
    }

    opcaoinicial:

    printf("\nDigite aqui a opcao desejada:");
    scanf("%i", &inicial);
    
    if(inicial == 1){
        goto login;
    } else if (inicial == 2){
        goto cadastro;
    } else if (inicial == 3){
        goto configuracoes;
    } else {
        printf("Escolha uma opcao valida!\n");
        goto opcaoinicial;
    }

    login:
    printf("Sistema de login\n");
    system ("pause");

    cadastro:
    printf("Sistema de cadastro\n");
    system ("pause");
    
    configuracoes:
    printf("Configuracoes\n");
    system ("pause");

    return 0;
}
