#include <stdio.h>
#include <stdlib.h>

int opcao, tijolo = 0;

// Declaração de Funções:

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

// Função principal

int main (){
    selecao();
}

// Funções
selecao(){
    
    opcao = 0;                                                                        // A PRINCIPIO ESSE ARQUIVO DE JOGO ESTARÁ SEPARADO DO INICIAL POR CONTA DO LOGIN
    tijolos();                                                                        // QUANDO A FUNCIONALIDADE DE CADASTRO/AUTENTICACAO FOR APLICADA AS TELAS SERÃO JUNTADAS
    
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

    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t        BEM-VINDO!       \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t [1] JOGAR   [2] RANKING \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t        [0] VOLTAR       \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);

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

    tijolos();

    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t        %c FACIL %c       \t             %c%c\n", 178, 178, 174, 175, 178, 178);
    printf("%c%c             \t ________________________ \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t|  4 |  2 |  4 |  2 |    |\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t|____|____|____|____|____|\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t| 32 |  4 |    |    |    |\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t|____|____|____|____|____|\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t| 64 | 32 | 16 |    |    |\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t|____|____|____|____|____|\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t| 64 | 16 |  4 |  2 |    |\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t|____|____|____|____|____|\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t|256 |128 | 64 | 32 |    |\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t|____|____|____|____|____|\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[1] SELECIONAR DIFICULDADE\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[2] PROXIMA DIFICULDADE   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t           5x5            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t         2048 pts         \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t        [0] Voltar        \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);

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

    tijolos();

    printf("%c%c             \t             \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t         %c MEDIA %c       \t             %c%c\n", 178, 178, 174, 175, 178, 178);
    printf("%c%c             \t    ___________________    \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   |  4 |  2 |  4 |    |   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   |____|____|____|____|   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   | 32 |    |    |    |   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   |____|____|____|____|   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   | 64 | 32 |    |    |   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   |____|____|____|____|   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   | 64 | 16 |  4 |  2 |   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   |____|____|____|____|   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t             \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[1] SELECIONAR DIFICULDADE \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[2] PROXIMA DIFICULDADE    \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t             \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            4x4            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t          2048 pts         \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t         [0] Voltar        \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t             \t             %c%c\n", 178, 178, 178, 178);

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

    tijolos();

    printf("%c%c             \t             \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t         %c DIFICIL %c     \t             %c%c\n", 178, 178, 174, 175, 178, 178);
    printf("%c%c             \t    ___________________    \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   |  4 |  2 |  4 |    |   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   |____|____|____|____|   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   | 32 |    |    |    |   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   |____|____|____|____|   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   | 64 | 32 |    |    |   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   |____|____|____|____|   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   | 64 | 16 |  4 |  2 |   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   |____|____|____|____|   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t             \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[1] SELECIONAR DIFICULDADE \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[2] PROXIMA DIFICULDADE    \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t             \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            4x4            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t          4096 pts         \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t         [0] Voltar        \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t             \t            \t             %c%c\n", 178, 178, 178, 178);

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

    tijolos();

    printf("%c%c             \t             \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t        %c HARDCORE %c     \t             %c%c\n", 178, 178, 174, 175, 178, 178);
    printf("%c%c             \t       ______________      \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t      |  4 |  2 |  4 |     \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t      |____|____|____|     \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t      | 32 |    |    |     \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t      |____|____|____|     \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t      | 64 | 32 |    |     \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t      |____|____|____|     \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t             \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[1] SELECIONAR DIFICULDADE \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[2] PROXIMA DIFICULDADE    \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t             \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            3x3            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t          1024 pts         \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t         [0] Voltar        \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t             \t            \t             %c%c\n", 178, 178, 178, 178);

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

    for (tijolo = 0; tijolo < 106; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");
    
    printf("%c%c\t\t\t             \t            \t           \t             \t\t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t\t    222222   \t 0000000000 \t    4444   \t 888888888   \t\t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t\t  2222222222 \t0000    0000\t   44444   \t88888888888  \t\t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t\t          222\t000      000\t  44 444   \t888     888  \t\t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t\t        22222\t00        00\t 44  444   \t 888888888   \t\t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t\t     22222   \t00        00\t44444444444\t 888888888   \t\t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t\t   22222     \t000      000\t     444   \t888     888  \t\t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t\t  2222       \t0000    0000\t     444   \t88888888888  \t\t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t\t  22222222222\t 0000000000 \t     444   \t 888888888   \t\t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t\t             \t            \t           \t             \t\t\t%c%c\n", 178, 178, 178, 178);

    tijolo = 0;

    for (tijolo = 0; tijolo < 106; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");

    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t         \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t PONTOS: \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t1024\t%c%c\t512 \t%c%c\t128 \t%c%c\t64  \t%c%c\t    \t%c%c\t         \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t| 99999 |\t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t         \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);

    tijolo = 0;

    for (tijolo = 0; tijolo < 106; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");

    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\tCONTROLES:   \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (A) DIREITA \t\t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t256 \t%c%c\t32  \t%c%c\t16  \t%c%c\t    \t%c%c\t    \t%c%c (D) ESQUERDA\t\t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (W) CIMA    \t\t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (S) BAIXO   \t\t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);

    tijolo = 0;

    for (tijolo = 0; tijolo < 106; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");

    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c                     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (P) SALVAR JOGO     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t64  \t%c%c\t32  \t%c%c\t4   \t%c%c\t    \t%c%c\t    \t%c%c                     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (V) VOLTAR MOVIMENTO\t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c                     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    
    tijolo = 0;

    for (tijolo = 0; tijolo < 106; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");

    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c                   \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (R) REINICIAR JOGO\t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t32  \t%c%c\t16  \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c                   \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (O) RANKING       \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c                   \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);

    tijolo = 0;

    for (tijolo = 0; tijolo < 106; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");

    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c                     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c                     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t16  \t%c%c\t4   \t%c%c\t2   \t%c%c\t    \t%c%c\t    \t%c%c   UNIFACEAR - 2022  \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c                     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c                     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);

    tijolo = 0;

    for (tijolo = 0; tijolo < 106; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");

}

jogarQxQ(){
    tijolo = 0; // Esse modelo poderá ser utilizado nos modos NORMAL e DIFICIL

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");
    
    printf("%c%c\t\t             \t            \t           \t             \t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t    222222   \t 0000000000 \t    4444   \t 888888888   \t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t  2222222222 \t0000    0000\t   44444   \t88888888888  \t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t          222\t000      000\t  44 444   \t888     888  \t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t        22222\t00        00\t 44  444   \t 888888888   \t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t     22222   \t00        00\t44444444444\t 888888888   \t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t   22222     \t000      000\t     444   \t888     888  \t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t  2222       \t0000    0000\t     444   \t88888888888  \t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t  22222222222\t 0000000000 \t     444   \t 888888888   \t\t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t\t             \t            \t           \t             \t\t%c%c\n", 178, 178, 178, 178);

    tijolo = 0;

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");

    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t         \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t PONTOS: \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t1024\t%c%c\t512 \t%c%c\t128 \t%c%c\t    \t%c%c\t         \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t| 99999 |\t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t         \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);

    tijolo = 0;

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");

    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\tCONTROLES:   \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (A) DIREITA \t\t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t256 \t%c%c\t32  \t%c%c\t16  \t%c%c\t    \t%c%c (D) ESQUERDA\t\t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (W) CIMA    \t\t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (S) BAIXO   \t\t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);

    tijolo = 0;

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");

    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c                     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (P) SALVAR JOGO     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t64  \t%c%c\t32  \t%c%c\t4   \t%c%c\t    \t%c%c                     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (V) VOLTAR MOVIMENTO\t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c                     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    
    tijolo = 0;

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");

    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c                     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (R) REINICIAR JOGO  \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t32  \t%c%c\t    \t%c%c\t2   \t%c%c\t    \t%c%c                     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (O) RANKING         \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c                     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    
    tijolo = 0;

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");
}

jogarTxT(){
    tijolo = 0; // Esse modelo poderá ser utilizado no modo HARDCORE

    for (tijolo = 0; tijolo < 74; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");
    
    printf("%c%c\t             \t            \t           \t             \t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t    222222   \t 0000000000 \t    4444   \t 888888888   \t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t  2222222222 \t0000    0000\t   44444   \t88888888888  \t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t          222\t000      000\t  44 444   \t888     888  \t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t        22222\t00        00\t 44  444   \t 888888888   \t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t     22222   \t00        00\t44444444444\t 888888888   \t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t   22222     \t000      000\t     444   \t888     888  \t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t  2222       \t0000    0000\t     444   \t88888888888  \t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t  22222222222\t 0000000000 \t     444   \t 888888888   \t%c%c\n", 178, 178, 178, 178);
    printf("%c%c\t             \t            \t           \t             \t%c%c\n", 178, 178, 178, 178);

    tijolo = 0;

    for (tijolo = 0; tijolo < 74; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");

    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t         \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t PONTOS: \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t1024\t%c%c\t128 \t%c%c\t    \t%c%c\t         \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t| 99999 |\t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\t         \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);

    tijolo = 0;

    for (tijolo = 0; tijolo < 74; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");

    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c\tCONTROLES:    \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (A) DIREITA    \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t256 \t%c%c\t32  \t%c%c\t16  \t%c%c (D) ESQUERDA   \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (W) CIMA       \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (S) BAIXO      \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);

    tijolo = 0;

    for (tijolo = 0; tijolo < 74; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");

    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c                     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (P) SALVAR JOGO     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c                     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c (V) VOLTAR MOVIMENTO\t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c\t    \t%c%c\t    \t%c%c\t    \t%c%c                     \t%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
    
    tijolo = 0;

    for (tijolo = 0; tijolo < 74; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");

    printf("%c%c\t\t                \t\t%c%c                   \t%c%c\n", 178, 178, 178, 178, 178, 178);
    printf("%c%c\t\t                \t\t%c%c (R) REINICIAR JOGO\t%c%c\n", 178, 178, 178, 178, 178, 178);
    printf("%c%c\t\tUNIFACEAR - 2022\t\t%c%c                   \t%c%c\n", 178, 178, 178, 178, 178, 178);
    printf("%c%c\t\t                \t\t%c%c (O) RANKING       \t%c%c\n", 178, 178, 178, 178, 178, 178);
    printf("%c%c\t\t                \t\t%c%c                   \t%c%c\n", 178, 178, 178, 178, 178, 178);
    
    tijolo = 0;

    for (tijolo = 0; tijolo < 74; tijolo ++){
        printf("%c", 178);
    }
    printf("\n");
}

selecaoRanking(){

    tijolos();

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

    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t         RANKING         \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[1] PONTUACAO  [2] TEMPO \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t        [0] VOLTAR       \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);

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

    tijolos();

    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   RANKING DE PONTUACAO   \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[1] FACIL   \t[2] NORMAL  \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[3] DIFICIL \t[4] HARDCORE\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t       [0] VOLTAR         \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);

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

    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t   RANKING DE PONTUACAO  \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t        MODO: XXXXXX     \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t         [0] VOLTAR      \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);

    tijolos();

    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c     COLOCACAO     %c%c     JOGADOR     %c%c     PONTUACAO     %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);

    tijolos();

    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c     1%c LUGAR      %c%c    Augusto01    %c%c    [12564 pts]    %c%c\n", 178, 178, 167, 178, 178, 178, 178, 178, 178);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);

    tijolos();

    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c     2%c LUGAR      %c%c  PedroTeste123  %c%c    [11256 pts]    %c%c\n", 178, 178, 167, 178, 178, 178, 178, 178, 178);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);

    tijolos();

    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c     3%c LUGAR      %c%c  TerceiroLugar  %c%c    [11120 pts]    %c%c\n", 178, 178, 167, 178, 178, 178, 178, 178, 178);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);

    tijolos();

    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c     4%c LUGAR      %c%c  PedroTeste002  %c%c    [10848 pts]    %c%c\n", 178, 178, 167, 178, 178, 178, 178, 178, 178);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);

    tijolos();

    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c     5%c LUGAR      %c%c   QuintoLugar   %c%c    [10424 pts]    %c%c\n", 178, 178, 167, 178, 178, 178, 178, 178, 178);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);

    tijolos();

    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c     24%c LUGAR     %c%c VigesimoQuarto  %c%c    [6248 pts]     %c%c\n", 178, 178, 167, 178, 178, 178, 178, 178, 178);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    
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

    tijolos();

    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t     RANKING DE TEMPO     \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[1] FACIL   \t[2] NORMAL  \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t[3] DIFICIL \t[4] HARDCORE\t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t       [0] VOLTAR         \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t            \t             %c%c\n", 178, 178, 178, 178);

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

    tijolos();

    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t     RANKING DE TEMPO    \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t        MODO: XXXXXX     \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t         [0] VOLTAR      \t             %c%c\n", 178, 178, 178, 178);
    printf("%c%c             \t            \t           \t             %c%c\n", 178, 178, 178, 178);

    tijolos();

    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c     COLOCACAO     %c%c     JOGADOR     %c%c     PONTUACAO     %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);

    tijolos();

    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c     1%c LUGAR      %c%c    Augusto01    %c%c    [12564 pts]    %c%c\n", 178, 178, 167, 178, 178, 178, 178, 178, 178);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);

    tijolos();

    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c     2%c LUGAR      %c%c  PedroTeste123  %c%c    [11256 pts]    %c%c\n", 178, 178, 167, 178, 178, 178, 178, 178, 178);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);

    tijolos();

    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c     3%c LUGAR      %c%c  TerceiroLugar  %c%c    [11120 pts]    %c%c\n", 178, 178, 167, 178, 178, 178, 178, 178, 178);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);

    tijolos();

    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c     4%c LUGAR      %c%c  PedroTeste002  %c%c    [10848 pts]    %c%c\n", 178, 178, 167, 178, 178, 178, 178, 178, 178);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);

    tijolos();

    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c     5%c LUGAR      %c%c   QuintoLugar   %c%c    [10424 pts]    %c%c\n", 178, 178, 167, 178, 178, 178, 178, 178, 178);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);

    tijolos();

    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    printf("%c%c     24%c LUGAR     %c%c VigesimoQuarto  %c%c    [6248 pts]     %c%c\n", 178, 178, 167, 178, 178, 178, 178, 178, 178);
    printf("%c%c                   %c%c                 %c%c                   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178);
    
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
        printf("%c", 178);
    }
    printf("\n");
}
