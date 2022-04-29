#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // SetConsoleCursorPosition

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// VARIAVEIS GLOBAIS
int tijolo, inicial, opcao = 0;
char apelido[20], senha[16], celular[11];

// DECLARACAO DE FUNCOES
int inicio();
int login();
int cadastro();
int configuracoes();
int selecao();
int tijolos();
int logo();
int dificuldadeFacil();
int dificuldadeMedia();
int dificuldadeDificil();
int dificuldadeHardcore();
int jogar4x4();
int jogar5x5();
int jogar3x3();
int selecaoRanking();
int rankingPontuacaoDif();
int rankingPontuacao();
int rankingTempoDif();
int rankingTempo();


// FUNCAO PRINCIPAL
int main ()
{
    system("color 0F");
    inicio();
}

// FUNCOES SECUNDARIAS

inicio(){                                                                                           // TELA INICIAL

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                   [1] INICIAR SESSAO    [2] NOVO JOGADOR                   %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             [3] CONFIGURACOES                              %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                              [0] SAIR DO JOGO                              %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

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
            printf("\nERRO\nOpcao invalida\n\n");
        }
}

login(){                                                                                            // LOGIN

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c I N I C I A R   S E S S A O %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                           %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                  APELIDO: %c                    %c                           %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                           %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                           %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                           %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                  SENHA:   %c                    %c                           %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                           %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                           %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                      %c 0 %c VOLTAR     %c 1 %c CONFIRMAR                      %c%c\n", 219, 219, 179, 179, 179, 179, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();
    
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 0:
            system("cls");
            inicio();
            break;

        case 1:
            printf("\nApelido: ");
            scanf("%s", &apelido);
            system("cls");
            login();
            break;

        case 2:
            printf("\nSenha: ");
            scanf("%s", &senha);
            system("cls");
            login();
            break;
            
        case 9:
            system("cls");
            selecao();
        	break;

        default:
            printf("\nERRO\nOpcao invalida\n\n");
        }
}

cadastro(){                                                                                         // CADASTRO

    logo();

    printf("%c%c             \t            \t                   \t     %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t                   \t     %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t                   \t     %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t                   \t     %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t                   \t     %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[1] Apelido:         [             ]\t     %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[2] Senha:           [             ]\t     %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[3] Confirmar Senha: [             ]\t     %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[4] Celular:         [             ]\t     %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t                   \t     %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t                   \t     %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t                   \t     %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t    [0] Voltar  [9] Confirmar    \t     %c%c\n", 219, 219, 219, 219);        //FUNCAO PARA CONFIRMAR SERA APLICADA DEPOIS (NAO ESTA FUNCIONAL AINDA)
    printf("%c%c             \t            \t                   \t     %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t                   \t     %c%c\n", 219, 219, 219, 219);

    tijolos();

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
            
        case 9:
        	break;
    
        default:
            printf("\nERRO\nOpcao invalida\n\n");
        }
}

configuracoes(){                                                                                    // CONFIGURAÇÕES

    logo();

    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t       [0] Voltar        \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 0:
            system("cls");
            inicio();
            break;

        case 1:
             
            break;

        case 2:
             
            break;

        default:
            printf("\nERRO\nOpcao invalida\n\n");
        }
    
}

selecao(){
                                                                      
    logo();

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
            inicio();
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
    
    logo();

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
            jogar5x5();
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

    logo();

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
            jogar4x4();
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

    logo();

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
            jogar4x4();
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

    logo();

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
            jogar3x3();
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

jogar5x5(){

    logo();

    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t         MODO: FACIL     \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t         [0] VOLTAR      \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c       PONTOS:       %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c  1024   %c%c   512   %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c      | 99999 |      %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c      MOVIMENTO:     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c   256   %c%c   32    %c%c   16    %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c       W A S D       %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c(P) SALVAR JOGO      %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c   64    %c%c   32    %c%c    4    %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c(V) VOLTAR MOVIMENTO %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    
    tijolos();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c (R) REINICIAR JOGO  %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c (O) RANKING         %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c   16    %c%c    4    %c%c    2    %c%c         %c%c         %c%c  UNIFACEAR - 2022   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();
    
    do
    {
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);
        if (opcao == 0){
            system("cls");
            selecao();
        } else {
            printf("\nValor Inválido. Tente Novamente");
        }

    } while (opcao != 0);
}

jogar4x4(){
    
    logo();

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

    do
    {
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);
        if (opcao == 0){
            system("cls");
            selecao();
        } else {
            printf("\nValor Inválido. Tente Novamente");
        }

    } while (opcao != 0);
}

jogar3x3(){

    logo();

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

    do
    {
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);
        if (opcao == 0){
            system("cls");
            selecao();
        } else {
            printf("\nValor Inválido. Tente Novamente");
        }

    } while (opcao != 0);
}

selecaoRanking(){

    logo();

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

    logo();

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

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                            RANKING DE PONTUACAO                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                MODO: XXXXXX                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                 [0] VOLTAR                                 %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c        COLOCACAO        %c%c       JOGADOR      %c%c         PONTUACAO         %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c      1 %c   LUGAR        %c%c      Augusto01     %c%c     [  12.564  pts  ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c      2 %c   LUGAR        %c%c    PedroTeste123   %c%c     [  11.866  pts  ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c      3 %c   LUGAR        %c%c    TerceiroLugar   %c%c     [  10.528  pts  ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c      4 %c   LUGAR        %c%c    PedroTeste002   %c%c     [  9.444   pts  ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c      5 %c   LUGAR        %c%c     QuintoLugar    %c%c     [  9.134   pts  ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c      24 %c  LUGAR        %c%c   VigesimoQuarto   %c%c     [  6.232   pts  ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    
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

    logo();

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

    logo();

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

logo(){
    tijolos();
    
    printf("%c%c*********|                                                        |*********%c%c\n", 219, 219, 219, 219);
    printf("%c%c****_****|      .d8888b.    .d8888b.       d8888    .d8888b.      |****_****%c%c\n", 219, 219, 219, 219);
    printf("%c%c***/ \\***|     d88P  Y88b  d88P  Y88b     d8P888   d88P  Y88b     |***/ \\***%c%c\n", 219, 219, 219, 219);
    printf("%c%c**( 2 )**|            888  888    888    d8P 888   Y88b. d88P     |**( 4 )**%c%c\n", 219, 219, 219, 219);
    printf("%c%c***\\_/***|          .d88P  888    888   d8P  888    'Y88888'      |***\\_/***%c%c\n", 219, 219, 219, 219);
    printf("%c%c****_****|      .od888P'   888    888  d88   888   .d8P''Y8b.     |****_****%c%c\n", 219, 219, 219, 219);
    printf("%c%c***/ \\***|     d88P'       888    888  8888888888  888    888     |***/ \\***%c%c\n", 219, 219, 219, 219);
    printf("%c%c**( 0 )**|     888'        Y88b  d88P        888   Y88b  d88P     |**( 8 )**%c%c\n", 219, 219, 219, 219);
    printf("%c%c***\\_/***|     888888888    'Y8888P'         888    'Y8888P'      |***\\_/***%c%c\n", 219, 219, 219, 219);
    printf("%c%c*********|                                                        |*********%c%c\n", 219, 219, 219, 219);

    tijolos();
}

tijolos(){
    for (tijolo = 0; tijolo != 80; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");
}
