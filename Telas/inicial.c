#include <stdio.h>
#include <stdlib.h>

int tijolo, inicial, opcao = 0;
char apelido[20], senha[16], celular[11];

int inicio();
int login();
int cadastro();
int configuracoes();

int main()
{
    inicio();
     
}

inicio(){

    opcao = 0;
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

    printf("\n");
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t  [1]Login  \t[2]Cadastro\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t     [3]Configuracoes    \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t        [0] Sair         \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);

    tijolo = 0;
    for (tijolo = 0; tijolo < 63; tijolo ++){
        printf("%c", 178);
    }

    printf("\n");
    do{
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 0:
            system("cls");
            printf("\nTchauuuu...");
            return 0;
            break;

        case 1:
            system("cls");
            login();
            break;

        case 2:
            system("cls");
            cadastro();
            break;

        case 3:
            system("cls");
            configuracoes();
            break;
    
        default:
            printf("\nOpcao invalida. Tente novamente\n\n");
        }
    } while (opcao > 3 || opcao < 0);
}

login(){

    opcao = 0;
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

    printf("\n");
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[1] Apelido: [             ]\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[2] Senha:   [             ]\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t       [0] Voltar        \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);

    tijolo = 0;
    for (tijolo = 0; tijolo < 63; tijolo ++){
        printf("%c", 178);
    }
    
    printf("\n");
    do{
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 0:
            system("cls");
            inicio();
            break;

        case 1:
            printf("\nDigite aqui seu apelido: ");
            scanf("%s", &apelido);
            break;

        case 2:
            printf("\nDigite aqui sua senha: ");
            scanf("%s", &senha);
            break;

        default:
            printf("\nOpcao invalida. Tente novamente\n\n");
        }
    } while (opcao > 3 || opcao < 0 || opcao != 9);
    
}

cadastro(){

    opcao = 0;
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

    printf("\n");
    printf("%c%c             \t            \t                   \t     %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t                   \t     %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t                   \t     %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t                   \t     %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t                   \t     %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[1] Apelido:         [             ]\t     %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[2] Senha:           [             ]\t     %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[3] Confirma Senha:  [             ]\t     %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[4] Celular:         [             ]\t     %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t                   \t     %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t                   \t     %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t                   \t     %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t       [0] Voltar        \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t                   \t     %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t                   \t     %c%c\n", 178, 178, 178, 178);

    tijolo = 0;
    for (tijolo = 0; tijolo < 63; tijolo ++){
        printf("%c", 178);
    }

    printf("\n");
    do{
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 0:
            system("cls");
            inicio();
            break;

        case 1:
            printf("\nDigite seu apelido: ");
            scanf("%s", &apelido);
            break;

        case 2:
            printf("\nDigite sua senha: ");
            scanf("%s", &senha);
            break;

        case 3:
            printf("\nConfirme sua senha: ");
            scanf("%s", &senha);
            break;
        case 4:
            printf("\nDigite seu numero de celular: ");
            scanf("%s", &celular);
            break;
    
        default:
            printf("\nOpcao invalida. Tente novamente\n\n");
        }
    } while (opcao > 4 || opcao < 0 || opcao != 9);
}

configuracoes(){

    opcao = 0;
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

    printf("\n");
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t          IDIOMA:        \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[1]Portugues\t [2]Ingles \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t       [0] Voltar        \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);

    tijolo = 0;
    for (tijolo = 0; tijolo < 63; tijolo ++){
        printf("%c", 178);
    }

    printf("\n");
    do
    {
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 0:
            system("cls");
            inicio();
            break;

        case 1:
            printf("\nIdioma alterado para Portugues!\n");                      // AO SELECIONAR UMA DAS OPCOES O PROGRAMA ESTA JOGANDO O USUARIO PARA OUTRA FUNCAO. CORRIGIR DEPOIS
            break;

        case 2:
            printf("\nLanguage changed to English!\n");
            break;

        default:
            printf("\nOpcao invalida. Tente novamente\n\n");
        }
    } while (opcao < 0 || opcao > 2);
    
}
