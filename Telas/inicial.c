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
int tijolos();

// FUNCAO PRINCIPAL
int main()
{
    system("color 0F");
    inicio();
     
}

// FUNCOES SECUNDARIAS
inicio(){

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
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t  [1]Login  \t[2]Cadastro\t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t     [3]Configuracoes    \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t        [0] Sair         \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

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

login(){

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
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[1] Apelido: [             ]\t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[2] Senha:   [             ]\t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[0] Voltar  [9] Confirmar\t             %c%c\n", 219, 219, 219, 219);        //FUNCAO PARA CONFIRMAR SERA APLICADA DEPOIS (NAO ESTA FUNCIONAL AINDA)
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);

    tijolos();
    
        printf("Digite aqui a opcao desejada: ");
        scanf("%i", &opcao);

    do
    {
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
        	break;

        default:
            printf("\nERRO\nOpcao invalida\n\n");
        }
    } while (opcao != 0);
}

cadastro(){

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

configuracoes(){

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
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t          IDIOMA:        \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t            \t           \t             %c%c\n", 219, 219, 219, 219);
    printf("%c%c             \t[1]Portugues\t [2]Ingles \t             %c%c\n", 219, 219, 219, 219);
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
            printf("\nIdioma alterado para Portugues!\n\n");
            break;

        case 2:
            printf("\nLanguage changed to English!\n\n");
            break;

        default:
            printf("\nERRO\nOpcao invalida\n\n");
        }
    
}

tijolos(){
    tijolo = 0;
    for (tijolo = 0; tijolo < 63; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");
}
