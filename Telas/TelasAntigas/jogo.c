#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tijolo;

/*
    printf ("_____________________________________________________\n");
    printf ("|                           |           |           |\n");
    printf ("|       2                   |  PONTOS:  |           |\n");
    printf ("|          0  4             |           |Controles: |\n");
    printf ("|                8          |   00000   |           |\n");
    printf ("|___________________________|___________|___________|\n");
    printf ("|      |      |      |      |           |           |\n");
    printf ("|  02  |      |      |  02  | V-Voltar  | DIREITA > |\n");
    printf ("|______|______|______|______|___________|___________|\n");
    printf ("|      |      |      |      |           |           |\n");
    printf ("|  04  |  02  |      |      | S-Salvar  |ESQUERDA < |\n");
    printf ("|______|______|______|______|___________|___________|\n");
    printf ("|      |      |      |      |           |           |\n");
    printf ("|  02  |  16  |  04  |      |R-Reiniciar|   CIMA ^  |\n");
    printf ("|______|______|______|______|___________|___________|\n");
    printf ("|      |      |      |      |           |           |\n");
    printf ("|  16  |  32  |  64  |      | N-Ranking |  BAIXO V  |\n");
    printf ("|______|______|______|______|___________|___________|\n");

    ESSE É O PROTÓTIPO DA TELA PRINCIPAL DE JOGO. MUITAS ALTERAÇÕES AINDA SERÃO FEITAS 
*/

inicio:
    tijolo = 0; // Esse modelo poderá ser utilizado no modo FACIL

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");
    
    printf("%c%c\t\t\t             \t            \t           \t             \t\t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t\t    222222   \t 0000000000 \t    4444   \t 888888888   \t\t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t\t  2222222222 \t0000    0000\t   44444   \t88888888888  \t\t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t\t          222\t000      000\t  44 444   \t888     888  \t\t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t\t        22222\t00        00\t 44  444   \t 888888888   \t\t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t\t     22222   \t00        00\t44444444444\t 888888888   \t\t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t\t   22222     \t000      000\t     444   \t888     888  \t\t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t\t  2222       \t0000    0000\t     444   \t88888888888  \t\t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t\t  22222222222\t 0000000000 \t     444   \t 888888888   \t\t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t\t             \t            \t           \t             \t\t\t%c%c\n", 219, 219, 219, 219);

    tijolo = 0;

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c\t         \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c\t PONTOS: \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c\t1024\t%c%c\t512 \t%c%c    128    %c%c\t64  \t%c%c           %c%c\t         \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c\t| 99999 |\t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c\t         \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolo = 0;

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c\tCONTROLES:   \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c (A) DIREITA \t\t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c    256    %c%c    32     %c%c    16     %c%c           %c%c           %c%c (D) ESQUERDA\t\t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c (W) CIMA    \t\t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c (S) BAIXO   \t\t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolo = 0;

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c                     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c (P) SALVAR JOGO     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c\t64  \t%c%c    32     %c%c\t4   \t%c%c           %c%c           %c%c                     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c (V) VOLTAR MOVIMENTO\t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c                     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    
    tijolo = 0;

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c                   \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c (R) REINICIAR JOGO\t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c    32     %c%c    16     %c%c           %c%c           %c%c           %c%c                   \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c (O) RANKING       \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c                   \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolo = 0;

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c                     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c                     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c    16     %c%c\t4   \t%c%c\t2   \t%c%c           %c%c           %c%c   UNIFACEAR - 2022  \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c                     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c           %c%c                     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolo = 0;

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    system("pause");
    system("cls");
    tijolo = 0; // Esse modelo poderá ser utilizado nos modos NORMAL e DIFICIL

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");
    
    printf("%c%c\t\t             \t            \t           \t             \t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t    222222   \t 0000000000 \t    4444   \t 888888888   \t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t  2222222222 \t0000    0000\t   44444   \t88888888888  \t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t          222\t000      000\t  44 444   \t888     888  \t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t        22222\t00        00\t 44  444   \t 888888888   \t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t     22222   \t00        00\t44444444444\t 888888888   \t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t   22222     \t000      000\t     444   \t888     888  \t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t  2222       \t0000    0000\t     444   \t88888888888  \t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t  22222222222\t 0000000000 \t     444   \t 888888888   \t\t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t\t             \t            \t           \t             \t\t%c%c\n", 219, 219, 219, 219);

    tijolo = 0;

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c           %c%c           %c%c           %c%c           %c%c\t         \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c\t PONTOS: \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c\t1024\t%c%c\t512 \t%c%c    128    %c%c           %c%c\t         \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c\t| 99999 |\t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c\t         \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolo = 0;

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c           %c%c           %c%c           %c%c           %c%c\tCONTROLES:   \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c (A) DIREITA \t\t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c    256    %c%c    32     %c%c    16     %c%c           %c%c (D) ESQUERDA\t\t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c (W) CIMA    \t\t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c (S) BAIXO   \t\t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolo = 0;

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c           %c%c           %c%c           %c%c           %c%c                     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c (P) SALVAR JOGO     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c\t64  \t%c%c    32     %c%c\t4   \t%c%c           %c%c                     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c (V) VOLTAR MOVIMENTO\t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c                     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    
    tijolo = 0;

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c           %c%c           %c%c           %c%c           %c%c                     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c (R) REINICIAR JOGO  \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c    32     %c%c           %c%c\t2   \t%c%c           %c%c                     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c (O) RANKING         \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c           %c%c                     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    
    tijolo = 0;

    for (tijolo = 0; tijolo < 90; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    system("pause");
    system("cls");
    tijolo = 0; // Esse modelo poderá ser utilizado no modo HARDCORE

    for (tijolo = 0; tijolo < 74; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");
    
    printf("%c%c\t             \t            \t           \t             \t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t    222222   \t 0000000000 \t    4444   \t 888888888   \t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t  2222222222 \t0000    0000\t   44444   \t88888888888  \t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t          222\t000      000\t  44 444   \t888     888  \t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t        22222\t00        00\t 44  444   \t 888888888   \t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t     22222   \t00        00\t44444444444\t 888888888   \t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t   22222     \t000      000\t     444   \t888     888  \t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t  2222       \t0000    0000\t     444   \t88888888888  \t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t  22222222222\t 0000000000 \t     444   \t 888888888   \t%c%c\n", 219, 219, 219, 219);
    printf("%c%c\t             \t            \t           \t             \t%c%c\n", 219, 219, 219, 219);

    tijolo = 0;

    for (tijolo = 0; tijolo < 74; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c           %c%c           %c%c           %c%c\t         \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c\t PONTOS: \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c\t1024\t%c%c    128    %c%c           %c%c\t         \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c\t| 99999 |\t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c\t         \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolo = 0;

    for (tijolo = 0; tijolo < 74; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c           %c%c           %c%c           %c%c\tCONTROLES:    \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c (A) DIREITA    \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c    256    %c%c    32     %c%c    16     %c%c (D) ESQUERDA   \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c (W) CIMA       \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c (S) BAIXO      \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolo = 0;

    for (tijolo = 0; tijolo < 74; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c           %c%c           %c%c           %c%c                     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c (P) SALVAR JOGO     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c                     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c (V) VOLTAR MOVIMENTO\t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c           %c%c           %c%c           %c%c                     \t%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    
    tijolo = 0;

    for (tijolo = 0; tijolo < 74; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");

    printf("%c%c\t\t                \t\t%c%c                   \t%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c\t\t                \t\t%c%c (R) REINICIAR JOGO\t%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c\t\tUNIFACEAR - 2022\t\t%c%c                   \t%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c\t\t                \t\t%c%c (O) RANKING       \t%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c\t\t                \t\t%c%c                   \t%c%c\n", 219, 219, 219, 219, 219, 219);
    
    tijolo = 0;

    for (tijolo = 0; tijolo < 74; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");
    system("pause");

    goto inicio; // Faz as telas ficarem em LOOP
}
