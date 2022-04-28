#include <stdio.h>
#include <stdlib.h>

// VARIAVEIS GLOBAIS
int opcao, tijolo = 0;

// DECLARACAO DE FUNCOES
int selecao();
int tijolos();
int dificuldadeFacil();
int dificuldadeMedia();
int dificuldadeDificil();
int dificuldadeHardcore();
int jogarCxC();
int jogarQxQ();
int jogarTxT();
int selecaoRanking();
int rankingPontuacaoDif();
int rankingPontuacao();
int rankingTempoDif();
int rankingTempo();


// FUNCAO PRINCIPAL
int main ()
{
    system("color 0F");
    selecao();
}

// FUNCOES SECUNDARIAS
selecao(){

    opcao = 0;                                                                        // A PRINCIPIO ESSE ARQUIVO DE JOGO ESTARÁ SEPARADO DO INICIAL POR CONTA DO LOGIN
    tijolos();                                                                        // QUANDO A FUNCIONALIDADE DE CADASTRO/AUTENTICACAO FOR APLICADA AS TELAS SERÃO JUNTADAS
    
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c    222222   \t 0000000000 \t    4444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222222222 \t0000    0000\t   44444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c          222\t000      000\t  44 444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c        22222\t00        00\t 44  444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c     22222   \t00        00\t44444444444\t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c   22222     \t000      000\t     444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222       \t0000    0000\t     444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  22222222222\t 0000000000 \t     444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t        BEM-VINDO!       \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t [1] JOGAR   [2] RANKING \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t        [0] VOLTAR       \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    do
    {
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 0:
            system("cls");
            selecao();
            break;

        case 1:
            system("cls");
            dificuldadeFacil();
            break;
        
        case 2:
            system("cls");
            selecaoRanking();
            break;

        default:
            printf("\nOpcao invalida. Tente novamente\n\n");
        }
    } while (opcao > 2 || opcao < 0);
}

dificuldadeFacil(){
    
    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c    222222   \t 0000000000 \t    4444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222222222 \t0000    0000\t   44444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c          222\t000      000\t  44 444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c        22222\t00        00\t 44  444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c     22222   \t00        00\t44444444444\t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c   22222     \t000      000\t     444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222       \t0000    0000\t     444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  22222222222\t 0000000000 \t     444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t        %c FACIL %c       \t             %c%c\n", 219, 219, 174, 175, 219, 219);
    printf("%c%c             \t ________________________ \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t|  4 |  2 |  4 |  2 |    |\t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t|____|____|____|____|____|\t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t| 32 |  4 |    |    |    |\t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t|____|____|____|____|____|\t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t| 64 | 32 | 16 |    |    |\t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t|____|____|____|____|____|\t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t| 64 | 16 |  4 |  2 |    |\t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t|____|____|____|____|____|\t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t|256 |128 | 64 | 32 |    |\t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t|____|____|____|____|____|\t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[1] SELECIONAR DIFICULDADE\t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[2] PROXIMA DIFICULDADE   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t           5x5            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t         2048 pts         \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t        [0] Voltar        \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    do
    {
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 0:
            system("cls");
            selecao();
            break;

        case 1:
            system("cls");
            jogarCxC();
            break;
        
        case 2:
            system("cls");
            dificuldadeMedia();
            break;

        default:
            printf("\nOpcao invalida. Tente novamente\n\n");
        }
    } while (opcao > 2 || opcao < 0);
}

dificuldadeMedia(){

    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c    222222   \t 0000000000 \t    4444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222222222 \t0000    0000\t   44444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c          222\t000      000\t  44 444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c        22222\t00        00\t 44  444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c     22222   \t00        00\t44444444444\t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c   22222     \t000      000\t     444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222       \t0000    0000\t     444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  22222222222\t 0000000000 \t     444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c             \t             \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t         %c MEDIA %c       \t             %c%c\n", 219, 219, 174, 175, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t    ___________________    \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   |  4 |  2 |  4 |    |   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   |____|____|____|____|   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   | 32 |    |    |    |   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   |____|____|____|____|   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   | 64 | 32 |    |    |   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   |____|____|____|____|   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   | 64 | 16 |  4 |  2 |   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   |____|____|____|____|   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[1] SELECIONAR DIFICULDADE \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[2] PROXIMA DIFICULDADE    \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            4x4            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t          2048 pts         \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t         [0] Voltar        \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    do
    {
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 0:
            system("cls");
            selecao();
            break;

        case 1:
            system("cls");
            jogarQxQ();
            break;
        
        case 2:
            system("cls");
            dificuldadeDificil();
            break;

        default:
            printf("\nOpcao invalida. Tente novamente\n\n");
        }
    } while (opcao > 2 || opcao < 0);
}

dificuldadeDificil(){

    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c    222222   \t 0000000000 \t    4444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222222222 \t0000    0000\t   44444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c          222\t000      000\t  44 444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c        22222\t00        00\t 44  444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c     22222   \t00        00\t44444444444\t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c   22222     \t000      000\t     444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222       \t0000    0000\t     444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  22222222222\t 0000000000 \t     444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c             \t             \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t         %c DIFICIL %c     \t             %c%c\n", 219, 219, 174, 175, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t    ___________________    \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   |  4 |  2 |  4 |    |   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   |____|____|____|____|   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   | 32 |    |    |    |   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   |____|____|____|____|   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   | 64 | 32 |    |    |   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   |____|____|____|____|   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   | 64 | 16 |  4 |  2 |   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   |____|____|____|____|   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[1] SELECIONAR DIFICULDADE \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[2] PROXIMA DIFICULDADE    \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            4x4            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t          4096 pts         \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t         [0] Voltar        \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t             \t            \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    do
    {
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 0:
            system("cls");
            selecao();
            break;

        case 1:
            system("cls");
            jogarQxQ();
            break;
        
        case 2:
            system("cls");
            dificuldadeHardcore();
            break;

        default:
            printf("\nOpcao invalida. Tente novamente\n\n");
        }
    } while (opcao > 2 || opcao < 0);
}

dificuldadeHardcore(){

    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c    222222   \t 0000000000 \t    4444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222222222 \t0000    0000\t   44444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c          222\t000      000\t  44 444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c        22222\t00        00\t 44  444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c     22222   \t00        00\t44444444444\t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c   22222     \t000      000\t     444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222       \t0000    0000\t     444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  22222222222\t 0000000000 \t     444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c             \t             \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t        %c HARDCORE %c     \t             %c%c\n", 219, 219, 174, 175, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t       ______________      \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t      |  4 |  2 |  4 |     \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t      |____|____|____|     \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t      | 32 |    |    |     \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t      |____|____|____|     \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t      | 64 | 32 |    |     \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t      |____|____|____|     \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[1] SELECIONAR DIFICULDADE \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[2] PROXIMA DIFICULDADE    \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t             \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            3x3            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t          1024 pts         \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t         [0] Voltar        \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t             \t            \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    do
    {
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 0:
            system("cls");
            selecao();
            break;

        case 1:
            system("cls");
            jogarTxT();
            break;
        
        case 2:
            system("cls");
            dificuldadeFacil();
            break;

        default:
            printf("\nOpcao invalida. Tente novamente\n\n");
        }
    } while (opcao > 2 || opcao < 0);
}

jogarCxC(){
    tijolo = 0;

    for (tijolo = 0; tijolo < 79; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");
    
    printf("%c%c                    \t            \t           \t                     %c%c\n", 219, 219, 219, 219);
    printf("%c%c           222222   \t 0000000000 \t    4444   \t 888888888           %c%c\n", 219, 219, 219, 219);
    printf("%c%c         2222222222 \t0000    0000\t   44444   \t88888888888          %c%c\n", 219, 219, 219, 219);
    printf("%c%c                 222\t000      000\t  44 444   \t888     888          %c%c\n", 219, 219, 219, 219);
    printf("%c%c               22222\t00        00\t 44  444   \t 888888888           %c%c\n", 219, 219, 219, 219);
    printf("%c%c            22222   \t00        00\t44444444444\t 888888888           %c%c\n", 219, 219, 219, 219);
    printf("%c%c          22222     \t000      000\t     444   \t888     888          %c%c\n", 219, 219, 219, 219);
    printf("%c%c         2222       \t0000    0000\t     444   \t88888888888          %c%c\n", 219, 219, 219, 219);
    printf("%c%c         22222222222\t 0000000000 \t     444   \t 888888888           %c%c\n", 219, 219, 219, 219);
    printf("%c%c                    \t            \t           \t                     %c%c\n", 219, 219, 219, 219);

    tijolo = 0;

    for (tijolo = 0; tijolo < 79; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c      PONTOS:       %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c  1024   %c%c   512   %c%c         %c%c         %c%c         %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c     | 99999 |      %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolo = 0;

    for (tijolo = 0; tijolo < 79; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c     MOVIMENTO:     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c   256   %c%c   32    %c%c   16    %c%c         %c%c         %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c      W A S D       %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolo = 0;

    for (tijolo = 0; tijolo < 79; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c(P) SALVAR JOGO     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c   64    %c%c   32    %c%c    4    %c%c         %c%c         %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c(V) VOLTAR MOVIMENTO%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    
    tijolo = 0;

    for (tijolo = 0; tijolo < 79; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c (R) REINICIAR JOGO %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c (O) RANKING        %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolo = 0;

    for (tijolo = 0; tijolo < 79; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c   16    %c%c    4    %c%c    2    %c%c         %c%c         %c%c  UNIFACEAR - 2022  %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolo = 0;

    for (tijolo = 0; tijolo < 79; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");
    system("pause");
}

jogarQxQ(){
    
    tijolos();
    
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c    222222   \t 0000000000 \t    4444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222222222 \t0000    0000\t   44444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c          222\t000      000\t  44 444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c        22222\t00        00\t 44  444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c     22222   \t00        00\t44444444444\t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c   22222     \t000      000\t     444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222       \t0000    0000\t     444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  22222222222\t 0000000000 \t     444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c    PONTOS:    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c  1024   %c%c   512   %c%c   128   %c%c         %c%c               %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c   | 99999 |   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c   MOVIMENTO:  %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c   256   %c%c   32    %c%c   16    %c%c         %c%c               %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c    W A S D    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c(P) SALVAR JOGO%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c   64    %c%c   32    %c%c    4    %c%c         %c%c               %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c(V) VOLTAR MOV.%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    
    tijolos();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c (R) REINICIAR %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c   16    %c%c         %c%c         %c%c         %c%c               %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c (O) RANKING   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    
    tijolos();

    system("pause");
}

jogarTxT(){

    tijolos();
    
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c    222222   \t 0000000000 \t    4444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222222222 \t0000    0000\t   44444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c          222\t000      000\t  44 444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c        22222\t00        00\t 44  444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c     22222   \t00        00\t44444444444\t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c   22222     \t000      000\t     444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222       \t0000    0000\t     444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  22222222222\t 0000000000 \t     444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c           %c%c           %c%c           %c%c       PONTOS:      %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c    1024   %c%c    128    %c%c           %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c      | 99999 |     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    printf("%c%c           %c%c           %c%c           %c%c     MOVIMENTO:     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c    256    %c%c    32     %c%c    16     %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c      W A S D       %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    printf("%c%c           %c%c           %c%c           %c%c(P) SALVAR JOGO     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c(V) VOLTAR MOVIMENTO%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    
    tijolos();

    printf("%c%c\t                               %c%c (R) REINICIAR JOGO %c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c\t    UNIFACEAR - 2022           %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c\t                               %c%c (O) RANKING        %c%c\n", 219, 219, 219, 219, 219, 219);
    
    tijolos();
    system("pause");
}

selecaoRanking(){

    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c    222222   \t 0000000000 \t    4444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222222222 \t0000    0000\t   44444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c          222\t000      000\t  44 444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c        22222\t00        00\t 44  444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c     22222   \t00        00\t44444444444\t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c   22222     \t000      000\t     444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222       \t0000    0000\t     444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  22222222222\t 0000000000 \t     444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t         RANKING         \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[1] PONTUACAO  [2] TEMPO \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t        [0] VOLTAR       \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    do
    {
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 0:
            system("cls");
            selecao();
            break;

        case 1:
            system("cls");
            rankingPontuacaoDif();
            break;
        
        case 2:
            system("cls");
            rankingTempoDif();
            break;

        default:
            printf("\nOpcao invalida. Tente novamente\n\n");
        }
    } while (opcao > 2 || opcao < 0);
}

rankingPontuacaoDif(){

    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c    222222   \t 0000000000 \t    4444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222222222 \t0000    0000\t   44444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c          222\t000      000\t  44 444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c        22222\t00        00\t 44  444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c     22222   \t00        00\t44444444444\t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c   22222     \t000      000\t     444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222       \t0000    0000\t     444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  22222222222\t 0000000000 \t     444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   RANKING DE PONTUACAO   \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[1] FACIL   \t[2] NORMAL  \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[3] DIFICIL \t[4] HARDCORE\t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t       [0] VOLTAR         \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    do
    {
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 0:
            system("cls");
            selecao();
            break;

        case 1:
            system("cls");
            rankingPontuacao();
            break;
        
        case 2:
            system("cls");
            rankingPontuacao();
            break;

        case 3:
            system("cls");
            rankingPontuacao();
            break;

        case 4:
            system("cls");
            rankingPontuacao();
            break;

        default:
            printf("\nOpcao invalida. Tente novamente\n\n");
        }
    } while (opcao > 4 || opcao < 0);
}

rankingPontuacao(){

    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c    222222   \t 0000000000 \t    4444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222222222 \t0000    0000\t   44444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c          222\t000      000\t  44 444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c        22222\t00        00\t 44  444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c     22222   \t00        00\t44444444444\t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c   22222     \t000      000\t     444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222       \t0000    0000\t     444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  22222222222\t 0000000000 \t     444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t   RANKING DE PONTUACAO  \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t        MODO: XXXXXX     \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t         [0] VOLTAR      \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     COLOCACAO     %c%c     JOGADOR     %c%c     PONTUACAO     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     1%c LUGAR      %c%c    Augusto01    %c%c    [12564 pts]    %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     2%c LUGAR      %c%c  PedroTeste123  %c%c    [11256 pts]    %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     3%c LUGAR      %c%c  TerceiroLugar  %c%c    [11120 pts]    %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     4%c LUGAR      %c%c  PedroTeste002  %c%c    [10848 pts]    %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     5%c LUGAR      %c%c   QuintoLugar   %c%c    [10424 pts]    %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     24%c LUGAR     %c%c VigesimoQuarto  %c%c    [6248 pts]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    
    tijolos();

    do
    {
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 0:
            system("cls");
            selecao();
            break;

        default:
            printf("\nOpcao invalida. Tente novamente\n\n");
        }
    } while (opcao != 0);
}

rankingTempoDif(){

    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c    222222   \t 0000000000 \t    4444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222222222 \t0000    0000\t   44444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c          222\t000      000\t  44 444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c        22222\t00        00\t 44  444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c     22222   \t00        00\t44444444444\t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c   22222     \t000      000\t     444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222       \t0000    0000\t     444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  22222222222\t 0000000000 \t     444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t     RANKING DE TEMPO     \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[1] FACIL   \t[2] NORMAL  \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[3] DIFICIL \t[4] HARDCORE\t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t       [0] VOLTAR         \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t            \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    do
    {
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 0:
            system("cls");
            selecao();
            break;

        case 1:
            system("cls");
            rankingTempo();
            break;
        
        case 2:
            system("cls");
            rankingTempo();
            break;

        case 3:
            system("cls");
            rankingTempo();
            break;

        case 4:
            system("cls");
            rankingTempo();
            break;

        default:
            printf("\nOpcao invalida. Tente novamente\n\n");
        }
    } while (opcao > 4 || opcao < 0);
}

rankingTempo(){

    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c    222222   \t 0000000000 \t    4444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222222222 \t0000    0000\t   44444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c          222\t000      000\t  44 444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c        22222\t00        00\t 44  444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c     22222   \t00        00\t44444444444\t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c   22222     \t000      000\t     444   \t888     888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  2222       \t0000    0000\t     444   \t88888888888  %c%c\n", 219, 219, 219, 219);
    printf("%c%c  22222222222\t 0000000000 \t     444   \t 888888888   %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t     RANKING DE TEMPO    \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t        MODO: XXXXXX     \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t         [0] VOLTAR      \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c                  %c%c                 %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c    COLOCACAO     %c%c     JOGADOR     %c%c       TEMPO        %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                  %c%c                 %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    printf("%c%c                  %c%c                 %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c    1%c LUGAR      %c%c    Augusto01    %c%c     [2min 24s]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                  %c%c                 %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c    2%c LUGAR      %c%c  PedroTeste123  %c%c     [2min 56s]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                  %c%c                 %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c    3%c LUGAR      %c%c  TerceiroLugar  %c%c     [3min 15s]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                  %c%c                 %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c    4%c LUGAR      %c%c  PedroTeste002  %c%c     [3min 49s]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                  %c%c                 %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c    5%c LUGAR      %c%c   QuintoLugar   %c%c     [4min 03s]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                  %c%c                 %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c    24%c LUGAR     %c%c VigesimoQuarto  %c%c     [9min 42s]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                  %c%c                 %c%c                    %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    
    tijolos();

    do
    {
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 0:
            system("cls");
            selecao();
            break;

        default:
            printf("\nOpcao invalida. Tente novamente\n\n");
        }
    } while (opcao != 0);
}

tijolos(){
    tijolo = 0;
    for (tijolo = 0; tijolo < 63; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");
}
