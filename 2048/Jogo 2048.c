#include <stdio.h>
#include <stdlib.h>
#include <windows.h>    // SetConsoleCursorPosition
#include <string.h>     // funçoes str
#include <conio.h>      // getch()
#include <ctype.h>      // isdigit, isalpha, etc.

// DEFINE DAS TECLAS
#define CIMA 72
#define BAIXO 80
#define ESQUERDA 75
#define DIREITA 77
#define ESC 27
#define ENTER 13
#define TAM5 5
#define TAM4 4
#define TAM3 3

// VARIAVEIS GLOBAIS
int inicial, opcao, jogada, pontos = 0;
int x, y, i = 0;
int matrizJogo[5][5];
int matrizJogoChecar[5][5];
char apelido[20], senha[20], confSenha[20], celular[15];

// DECLARACAO DE PROCEDIMENTOS
void gotoxy();
void inicio();
void login();
void cadastro();
void cadastroSucesso();
void cadastroFalhou();
void configuracoes();
void cores();
void selecao();
void tijolos();
void logo();
void dificuldadeFacil();
void dificuldadeMedia();
void dificuldadeDificil();
void dificuldadeHardcore();
void jogar3x3();
void jogar4x4Media();
void jogar4x4Dificil();
void jogar5x5();
void selecaoRanking();
void rankingPontuacaoDif();
void rankingPontuacao();
void rankingVelDif();
void rankingVel();
void jogosSalvos();
void movDireita5x5();
void movEsquerda5x5();
void movBaixo5x5();
void movCima5x5();
void valorAleatorio();
void cor();

// DECLARACAO DE FUNCOES
int checarMovimento();
int checarVitoriaMedia();
int checarVitoriaDificil();
int checarVitoriaFacil();
int checarVitoriaHardcore();

// FUNCAO PRINCIPAL
int main (){

    SetConsoleTitle("2048 :: Pedro Rocha");

    tijolos();
    Sleep(300);
    Beep(370, 200);

    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(150);
    Beep(370, 200);
    printf("%c%c****_****%c      .d8888b.    .d8888b.       d8888    .d8888b.      %c****_****%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(150);
    Beep(370, 200);
    printf("%c%c***/ \\***%c     d88P  Y88b  d88P  Y88b     d8P888   d88P  Y88b     %c***/ \\***%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(150);
    Beep(370, 200);
    printf("%c%c**( 2 )**%c            888  888    888    d8P 888   Y88b. d88P     %c**( 4 )**%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(150);
    Beep(370, 200);
    printf("%c%c***\\_/***%c          .d88P  888    888   d8P  888    'Y88888'      %c***\\_/***%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(150);
    Beep(370, 200);
    printf("%c%c****_****%c      .od888P'   888    888  d88   888   .d8P''Y8b.     %c****_****%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(150);
    Beep(370, 200);
    printf("%c%c***/ \\***%c     d88P'       888    888  8888888888  888    888     %c***/ \\***%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(150);
    Beep(370, 200);
    printf("%c%c**( 0 )**%c     888'        Y88b  d88P        888   Y88b  d88P     %c**( 8 )**%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(150);
    Beep(370, 200);
    printf("%c%c***\\_/***%c     888888888    'Y8888P'         888    'Y8888P'      %c***\\_/***%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(150);
    Beep(370, 200);
    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(150);
    Beep(370, 150);

    tijolos();
    
    Beep(370, 150);
    Beep(400, 150);
    Beep(440, 150);
    Beep(470, 200);
    Beep(260, 200);

    system("cls");
    inicio();
}

inicio(){                                                                                           // TELA INICIAL

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c     B E M  -  V I N D O     %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                    [1] INICIAR SESSAO  [2] NOVO JOGADOR                    %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             ", 219, 219);
    cor(4);
    printf("[ESC] SAIR DO JOGO");
    cor(7);
    printf("                             %c%c\n", 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    do
    {
        opcao = getch();

        if (opcao == 27){
            Beep(370, 200);
            gotoxy(2,34);
            cor(4);
            printf("        APERTE [ESC] NOVAMENTE PARA SAIR OU OUTRA TECLA PARA CANCELAR\n\n\n\n\n\n");
            cor(7);
            opcao = getch();
            if (opcao == 27){
                exit(0);
            } else {
                Beep(370, 200);
                gotoxy(2,34);
                printf("                                                                            ");
                opcao = 1;
            }
        } else if (opcao == 49){
            Beep(370, 200);
            system("cls");
            login();
            opcao = 0;
        } else if (opcao == 50){
            Beep(370, 200);
            system("cls");
            cadastro();
            opcao = 0;
        }
    } while (opcao != 0);
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
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);


    tijolos();

    int tam = 0;
    gotoxy(30,24);
    fflush(stdin);
    do
    {   
        apelido[tam] = getch();          
        if (apelido[tam] == 8 && tam > 0){       // APAGAR
            printf("\b \b"); 
            apelido[tam] = 0x00;
            tam--;
        } else if (apelido[tam] == 13){             // ENTER
            apelido[tam] = 0x00;
            break;
        } else if (apelido[tam] != 8){
            putchar(apelido[tam]);
            tam++;              
        }

    } while(tam < 16);

    gotoxy(51,24);
    cor(10);
    printf("OK");
    cor(7);

    tam = 0;
    gotoxy(30,30);
    fflush(stdin);
    do
    {   
        senha[tam] = getch();          
        if(senha[tam] == 8 && tam > 0){          // APAGAR
            printf("\b \b"); 
            senha[tam] = 0x00;
            tam--;
        } else if (senha[tam] == 13){               // ENTER
            senha[tam] = 0x00;
            break;
        } else if (senha[tam] != 8){
            putchar('*');
            tam++;
        }
    } while(tam < 16);

    gotoxy(51,30);
    cor(10);
    printf("OK");
    cor(7);

    gotoxy(2,35);
    printf("");
    printf("                     [ESC] VOLTAR     [ENTER] CONFIRMAR\n\n\n\n\n\n");
    
    do
    {
        opcao = getch();
        if (opcao == 27){
            Beep(370, 200);
            system("cls");
            inicio();
            opcao = 0;
        } else if (opcao == 13){
            Beep(370, 200);
            system("cls");
            selecao();
            opcao = 0;
        }

    } while (opcao != 0);
}

cadastro(){                                                                                         // CADASTRO

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c   N O V O   J O G A D O R   %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                           %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                  APELIDO: %c                    %c                           %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                           %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                           %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                           %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                    SENHA: %c                    %c                           %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                           %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                           %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                           %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c           CONFIRMA SENHA: %c                    %c                           %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                           %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                           %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                           %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                  CELULAR: %c                    %c                           %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                           %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                           %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    int tam = 0;
    gotoxy(30,22);
    fflush(stdin);
    do
    {   
        apelido[tam] = getch();                     // APELIDO
        if (apelido[tam] == 8 && tam > 0){          // APAGAR
            printf("\b \b"); 
            apelido[tam] = 0x00;
            tam--;
        } else if (apelido[tam] == 13){             // ENTER
            apelido[tam] = 0x00;
            break;
        } else if (apelido[tam] != 8){
            putchar(apelido[tam]);
            tam++;              
        }

    } while(tam < 16);

    gotoxy(51,22);
    cor(10);
    printf("OK");
    cor(7);

    tam = 0;
    gotoxy(30,26);
    fflush(stdin);
    do
    {   
        senha[tam] = getch();                       // SENHA   
        if(senha[tam] == 0x08 && tam > 0){          // APAGAR
            printf("\b \b"); 
            senha[tam] = 0x00;
            tam--;
        } else if (senha[tam] == 13){               // ENTER
            senha[tam] = 0x00;
            break;
        } else if (senha[tam] != 8){
            putchar('*');
            tam++;
        }
    } while(tam < 16);

    gotoxy(51,26);
    cor(10);
    printf("OK");
    cor(7);

    tam = 0;
    gotoxy(30,30);
    fflush(stdin);
    do
    {   
        confSenha[tam] = getch();                   // CONFIRMACAO DE SENHA
        if(confSenha[tam] == 8 && tam > 0){         // APAGAR
            printf("\b \b"); 
            confSenha[tam] = 0x00;
            tam--;

        } else if (confSenha[tam] == 13){           // ENTER
            confSenha[tam] = 0x00;
            break;
        } else if (confSenha[tam] != 8){
            putchar('*');
            tam++;
        }
    } while(tam < 16);

    gotoxy(51,30);
    cor(10);
    printf("OK");
    cor(7);

    tam = 0;
    gotoxy(30,34);
    fflush(stdin);
    do
    {   
        celular[tam] = getch();                     // CELULAR
        if (celular[tam] == 0x08 && tam > 0){       // APAGAR
            printf("\b \b"); 
            celular[tam] = 0x00;
            tam--;
        } else if (celular[tam] == 13){              // ENTER
            celular[tam] = 0x00;
            break;
        } else if (celular[tam] != 8){
            putchar(celular[tam]);
            tam++;
        }

    } while(tam < 11);

    gotoxy(51,34);
    cor(10);
    printf("OK");
    cor(7);

    gotoxy(2,38);
    printf("");
    printf("                     [ESC] VOLTAR     [ENTER] CONFIRMAR\n\n\n");    
    do
    {
        opcao = getch();
        if (opcao == 27){
            Beep(370, 200);
            system("cls");
            inicio();
            opcao = 0;
        } else if (opcao == 13){
            system("cls");
            cadastroSucesso();
            opcao = 0;
        }

    } while (opcao != 0);
}

cadastroSucesso(){

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c   CADASTRADO COM SUCESSO!   %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                %c%c\n", 219, 219, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187, 219, 219);
    printf("%c%c                %c                                          %c                %c%c\n", 219, 219, 186, 186, 219, 219);
    printf("%c%c                %c    APERTE [ENTER] PARA INICIAR SESSAO    %c                %c%c\n", 219, 219, 186, 186, 219, 219);
    printf("%c%c                %c                                          %c                %c%c\n", 219, 219, 186, 186, 219, 219);
    printf("%c%c                %c                   OU                     %c                %c%c\n", 219, 219, 186, 186, 219, 219);
    printf("%c%c                %c                                          %c                %c%c\n", 219, 219, 186, 186, 219, 219);
    printf("%c%c                %c APERTE [ESC] PARA IR PARA A TELA INICIAL %c                %c%c\n", 219, 219, 186, 186, 219, 219);
    printf("%c%c                %c                                          %c                %c%c\n", 219, 219, 186, 186, 219, 219);
    printf("%c%c                %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                %c%c\n", 219, 219, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    
    tijolos();

    Beep(880, 200);
    Beep(932, 200);
    Beep(987, 200);
    Beep(1046, 200);
    Beep(987, 250);
    Beep(1046, 250);

    do                              
    {
        opcao = getch();            
        if (opcao == 27){           
            Beep(370, 200);
            system("cls");        
            inicio();             
            opcao = 0;              
        } else if (opcao == 13){   
            Beep(370, 200);
            system("cls");         
            login();                
            opcao = 0;            
        }

    } while (opcao != 0);
}

configuracoes(){                                                                                    // CONFIGURAÇÕES

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c  C O N F I G U R A C O E S  %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                              [1] COR DA TELA                               %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] VOLTAR                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    do{
        opcao = getch();
        if (opcao == 27){
            Beep(370, 200);
            system("cls");
            selecao();
            opcao = 0;
        } else if (opcao == 49){
            Beep(370, 200);
            system("cls");
            cores();
            opcao = 0;
        }
    } while (opcao != 0);
    
}

cores(){

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c     ALTERAR COR DA TELA     %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                  OPCOES:                                   %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       ", 219, 219);
    printf("[1] AMARELO");
    printf("         [6] CINZA                        ");           
    printf("%c%c\n", 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       ", 219, 219);
    printf("[2] AZUL");
    printf("            [7] LILAS                        ");
    printf("%c%c\n", 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    
    printf("%c%c                       [3] AZUL CLARO      [8] SALMAO                       %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       [4] BRANCO          [9] VERDE                        %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       [5] CIANO           [0] VERMELHO                     %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] VOLTAR                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    do{
        opcao = getch();
        if (opcao == 27){
            Beep(370, 200);
            system("cls");
            configuracoes();
        } else if (opcao == 49){
            system("color 06");     // 1- AMARELO
            Beep(470, 200);
            Beep(470, 200);
            Beep(570, 400);
        } else if (opcao == 50){
            system("color 01");     // 2- AZUL
            Beep(470, 200);
            Beep(470, 200);
            Beep(570, 400);
        }  else if (opcao == 51){
            system("color 09");     // 3- AZUL CLARO
            Beep(470, 200);
            Beep(470, 200);
            Beep(570, 400);
        } else if (opcao == 52){
            system("color 0F");     // 4- BRANCO
            Beep(470, 200);
            Beep(470, 200);
            Beep(570, 400);
        } else if (opcao == 53){
            system("color 0B");     // 5- CIANO
            Beep(470, 200);
            Beep(470, 200);
            Beep(570, 400);
        } else if (opcao == 54){
            system("color 07");     // 6- CINZA (PADRAO)
            Beep(470, 200);
            Beep(470, 200);
            Beep(570, 400);
        } else if (opcao == 55){
            system("color 0D");     // 7- LILAS
            Beep(470, 200);
            Beep(470, 200);
            Beep(570, 400);
        } else if (opcao == 56){
            system("color 0C");     // 8- SALMAO
            Beep(470, 200);
            Beep(470, 200);
            Beep(570, 400);
        } else if (opcao == 57){
            system("color 0A");     // 9- VERDE
            Beep(470, 200);
            Beep(470, 200);
            Beep(570, 400);
        } else if (opcao == 48){
            system("color 04");     // 0- VERMELHO
            Beep(470, 200);
            Beep(470, 200);
            Beep(570, 400);
        }
    } while (opcao != 27);
}

selecao(){
                                                                      
    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c    VOCE ENTROU NO JOGO !    %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                      [1] NOVO JOGO    [2] VER RANKING                      %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                    [3] JOGOS SALVOS   [4] CONFIGURACOES                    %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           ", 219, 219);
    cor(4);
    printf("[ESC] ENCERRAR SESSAO");
    cor(7);
    printf("                            %c%c\n", 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    do{
        opcao = getch();
        if (opcao == 49){
            Beep(370, 200);
            system("cls");
            dificuldadeFacil();
            opcao = 0;
        } else if (opcao == 50){
            Beep(370, 200);
            system("cls");
            selecaoRanking();
            opcao = 0;
        } else if (opcao == 51){
            Beep(370, 200);
            system("cls");
            jogosSalvos();
            opcao = 0;
        } else if (opcao == 52){
            Beep(370, 200);
            system("cls");
            configuracoes();
            opcao = 0;
        } else if (opcao == 27){
            Beep(370, 200);
            gotoxy(2,34);
            cor(4);
            printf("  APERTE [ESC] NOVAMENTE PARA ENCERRAR SESSAO OU OUTRA TECLA PARA CANCELAR\n\n\n\n\n\n");
            cor(7);
            opcao = getch();
            if (opcao == 27){
                Beep(370, 200);
                system("cls");
                inicio();
                opcao = 0;
            } else {
                Beep(370, 200);
                gotoxy(2,34);
                printf("                                                                            ");
                opcao = 1;
            }
        }
    } while (opcao != 0);
}

dificuldadeFacil(){
    
    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                 %c FACIL %c                                  %c%c\n", 219, 219, 174, 175, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                          ________________________                          %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         |  4 |  2 |  4 |  2 |    |                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         |____|____|____|____|____|                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         | 32 |  4 |    |    |    |                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         |____|____|____|____|____|                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         | 64 | 32 | 16 |    |    |                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         |____|____|____|____|____|                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         | 64 | 16 |  4 |  2 |    |                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         |____|____|____|____|____|                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         |256 |128 | 64 | 32 |    |                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         |____|____|____|____|____|                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       [ENTER] SELECIONAR DIFICULDADE                       %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [>]   PROXIMA DIFICULDADE                          %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                  | 5x5 |                                   %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         > OBJETIVO = 2048 PONTOS <                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] Voltar                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    do{
        opcao = getch();
        if (opcao == 27){
            Beep(370, 200);
            system("cls");
            selecao();
        } else if (opcao == 13){
            Beep(370, 200);
            system("cls");
            jogar5x5();
            opcao = 0;
        } else if ((opcao == 77)){
            Beep(370, 200);
            system("cls");
            dificuldadeMedia();
            opcao = 0;
        }
    } while (opcao != 0);
}

dificuldadeMedia(){

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                 %c MEDIA %c                                  %c%c\n", 219, 219, 174, 175, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                            ___________________                             %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           |  4 |  2 |  4 |    |                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           |____|____|____|____|                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           | 32 |    |    |    |                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           |____|____|____|____|                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           | 64 | 32 |    |    |                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           |____|____|____|____|                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           | 64 | 16 |  4 |  2 |                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           |____|____|____|____|                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       [ENTER] SELECIONAR DIFICULDADE                       %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [>]   PROXIMA DIFICULDADE                          %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [<]   DIFICULDADE ANTERIOR                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                  | 4x4 |                                   %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         > OBJETIVO = 2048 PONTOS <                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] Voltar                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    do{
        opcao = getch();
        if (opcao == 27){
            Beep(370, 200);
            system("cls");
            selecao();
        } else if (opcao == 13){
            Beep(370, 200);
            system("cls");
            jogar4x4Media();
            opcao = 0;
        } else if ((opcao == 77)){
            Beep(370, 200);
            system("cls");
            dificuldadeDificil();
            opcao = 0;
        } else if ((opcao == 75)){
            Beep(370, 200);
            system("cls");
            dificuldadeFacil();
            opcao = 0;
        }
    } while (opcao != 0);
}

dificuldadeDificil(){

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                %c DIFICIL %c                                 %c%c\n", 219, 219, 174, 175, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                            ___________________                             %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           |  4 |  2 |  4 |    |                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           |____|____|____|____|                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           | 32 |    |    |    |                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           |____|____|____|____|                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           | 64 | 32 |    |    |                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           |____|____|____|____|                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           | 64 | 16 |  4 |  2 |                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                           |____|____|____|____|                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       [ENTER] SELECIONAR DIFICULDADE                       %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [>]   PROXIMA DIFICULDADE                          %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [<]   DIFICULDADE ANTERIOR                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                  | 4x4 |                                   %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         > OBJETIVO = 4096 PONTOS <                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] Voltar                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    do{
        opcao = getch();
        if (opcao == 27){
            Beep(370, 200);
            system("cls");
            selecao();
        } else if (opcao == 13){
            Beep(370, 200);
            system("cls");
            jogar4x4Dificil();
            opcao = 0;
        } else if ((opcao == 77)){
            Beep(370, 200);
            system("cls");
            dificuldadeHardcore();
            opcao = 0;
        } else if ((opcao == 75)){
            Beep(370, 200);
            system("cls");
            dificuldadeMedia();
            opcao = 0;
        }
    } while (opcao != 0);
}

dificuldadeHardcore(){

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                               %c HARDCORE %c                                 %c%c\n", 219, 219, 174, 175, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                              ______________                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             |  4 |  2 |  4 |                               %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             |____|____|____|                               %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             | 32 |    |    |                               %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             |____|____|____|                               %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             | 64 | 32 |    |                               %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             |____|____|____|                               %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       [ENTER] SELECIONAR DIFICULDADE                       %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [<]   DIFICULDADE ANTERIOR                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                  | 3x3 |                                   %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         > OBJETIVO = 1024 PONTOS <                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] Voltar                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    do{
        opcao = getch();
        if (opcao == 27){
            Beep(370, 200);
            system("cls");
            selecao();
        } else if (opcao == 13){
            Beep(370, 200);
            system("cls");
            jogar3x3();
            opcao = 0;
        } else if ((opcao == 75)){
            Beep(370, 200);
            system("cls");
            dificuldadeDificil();
            opcao = 0;
        }
    } while (opcao != 0);
}

jogar5x5(){
    
    int ver, x, y, continuar = 0;
    int tam = TAM5;
	pontos = jogada = 0;

	for (x = 0; x < tam; x++){
        for (y = 0; y < tam; y++){
            matrizJogo[x][y] = 0;
			matrizJogoChecar[x][y] = 0;
        }
    }
    
    valorAleatorio(TAM5);
    system("cls");
	
    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             DIFICULDADE: FACIL                             %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] VOLTAR                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c   PONTOS:  |      | %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c MOVIMENTOS:|      | %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c [P] SALVAR JOGO     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c [R] REINICIAR JOGO  %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c [O] RANKING         %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c        DICA:        %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   UTILIZE AS SETAS  %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c   DO TECLADO PARA   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c    MOVIMENTAR O     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c     TABULEIRO       %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    cor(2);
    printf("  UNIFACEAR - 2022   ");
    cor(7);
    printf("%c%c\n", 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    valorAleatorio(TAM5);
    imprimirValores(TAM5);

    do{

        cor(11);
        gotoxy(70,18);
        printf("%i", pontos);                   // PRINTA OS PONTOS NA TELA
        gotoxy(70,19);
        printf("%i", jogada);                   // PRINTA A QUANTIDADE DE MOVIMENTOS NA TELA
        cor(7);
        gotoxy(80,39);

        if(checarVitoriaFacil() == 0 && (continuar != 1)){
            cor(2);
            gotoxy(2,13);
			printf("                       VOCE VENCEU! ESCOLHA UMA OPCAO:                      ");
            gotoxy(2,14);
            printf("             [J] JOGAR DIFICULDADE MEDIA [C] CONTINUAR JOGANDO              ");
            cor(7);
            do{
                opcao = getch();
                if ( (opcao == 74) || (opcao == 106) ){
                    system("color 07");
                    system("cls");
                    jogar4x4Media();
                    opcao = 1;
                } else if ( (opcao == 67) || (opcao == 99) ){
                    gotoxy(2,13);
                    printf("                             DIFICULDADE: FACIL                             ");
                    gotoxy(2,14);
                    printf("                                [ESC] VOLTAR                                ");
                    opcao = continuar = 1;
                }
            } while(opcao != 1);
        }

        opcao = getch();

        if ( (opcao == DIREITA) ) {               	// DIREITA

            movDireita5x5();
			imprimirValores(TAM5);
            
        } else if ( (opcao == ESQUERDA) ) {			// ESQUERDA

            movEsquerda5x5();
			imprimirValores(TAM5);

            
        } else if ( (opcao == BAIXO) ) {			// BAIXO

            movBaixo5x5();
			imprimirValores(TAM5);


        } else if ( (opcao == CIMA) ) {				// CIMA

            movCima5x5();
			imprimirValores(TAM5);

        } else if ( (opcao == ESC) ) {    				// ESC
            system("cls");
			selecao();
        }
        
    } while ( opcao != 27 );
}

jogar4x4Media(){

    int ver, x, y, continuar = 0;
    int tam = TAM4;
    pontos = jogada = 0;

    for (x = 0; x < tam; x++){
        for (y = 0; y < tam; y++){
            matrizJogo[x][y] = 0;
			matrizJogoChecar[x][y] = 0;
        }
    }

    valorAleatorio(TAM4);
    system("cls");

    matrizJogo[0][0] = 1024;
    matrizJogo[0][1] = 1024;

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             DIFICULDADE: MEDIA                             %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] VOLTAR                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   PONTOS:  |     | %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c MOVIMENTOS:|     | %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c [P] SALVAR JOGO    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c [R] REINICIAR JOGO %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c [O] RANKING        %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c        DICA:       %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c  UTILIZE AS SETAS  %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c  DO TECLADO PARA   %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    MOVIMENTAR O    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c     TABULEIRO      %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  UNIFACEAR - 2022  %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);

    tijolos();

    valorAleatorio(TAM4);
    imprimirValores(TAM4);

    do{

        gotoxy(71,18);
        cor(11);
        printf("%i", pontos);                   // PRINTA OS PONTOS NA TELA
        gotoxy(71,19);
        printf("%i", jogada);                   // PRINTA A QUANTIDADE DE MOVIMENTOS NA TELA
        cor(7);
        gotoxy(80,40);

        if(checarVitoriaMedia() == 0 && (continuar != 1)){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            gotoxy(2,13);
			printf("                       VOCE VENCEU! ESCOLHA UMA OPCAO:                      ");
            gotoxy(2,14);
            printf("            [J] JOGAR DIFICULDADE DIFICIL [C] CONTINUAR JOGANDO             ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            do{
                opcao = getch();
                if ( (opcao == 74) || (opcao == 106) ){
                    system("color 07");
                    system("cls");
                    system("color 07");
                    jogar4x4Dificil();
                    opcao = 1;
                } else if ( (opcao == 67) || (opcao == 99) ){
                    gotoxy(2,13);
                    printf("                             DIFICULDADE: MEDIA                             ");
                    gotoxy(2,14);
                    printf("                                [ESC] VOLTAR                                ");
                    opcao = continuar = 1;
                }
            } while(opcao != 1);
        }

        opcao = getch();

        if ( (opcao == DIREITA) ) {                 // DIREITA

            movDireita4x4();
            imprimirValores(TAM4);
            
        } else if ( (opcao == ESQUERDA) ) {			// ESQUERDA

            movEsquerda4x4();
            imprimirValores(TAM4);
            
        } else if ( (opcao == BAIXO) ) {			// BAIXO

            movBaixo4x4();
            imprimirValores(TAM4);

        } else if ( (opcao == CIMA) ) {			    // CIMA

            movCima4x4();
            imprimirValores(TAM4);

        } else if (opcao == ESC) {                   // ESC
            system("cls");
			selecao();
        }
        
    } while ( opcao != 27 );
}

jogar4x4Dificil(){

    int ver, x, y, continuar = 0;
    int tam = TAM4;
    pontos = jogada = 0;

    for (x = 0; x < tam; x++){
        for (y = 0; y < tam; y++){
            matrizJogo[x][y] = 0;
			matrizJogoChecar[x][y] = 0;
        }
    }

    valorAleatorio(TAM4);
    system("cls");

    matrizJogo[0][0] = 2048;
    matrizJogo[0][1] = 2048;

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                            DIFICULDADE: DIFICIL                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] VOLTAR                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   PONTOS:  |     | %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c MOVIMENTOS:|     | %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c [P] SALVAR JOGO    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c [R] REINICIAR JOGO %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c [O] RANKING        %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c        DICA:       %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c  UTILIZE AS SETAS  %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c  DO TECLADO PARA   %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    MOVIMENTAR O    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c     TABULEIRO      %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  UNIFACEAR - 2022  %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);

    tijolos();

    valorAleatorio(TAM4);
    imprimirValores(TAM4);

    do{

        cor(11);
        gotoxy(71,18);
        printf("%i", pontos);                   // PRINTA OS PONTOS NA TELA
        gotoxy(71,19);
        printf("%i", jogada);                   // PRINTA A QUANTIDADE DE MOVIMENTOS NA TELA
        gotoxy(80,40);
        cor(7);

        if(checarVitoriaDificil() == 0 && (continuar != 1)){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            gotoxy(2,13);
			printf("                       VOCE VENCEU! ESCOLHA UMA OPCAO:                      ");
            gotoxy(2,14);
            printf("           [J] JOGAR DIFICULDADE HARDCORE [C] CONTINUAR JOGANDO             ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            do{
                opcao = getch();
                if ( (opcao == 74) || (opcao == 106) ){
                    system("color 07");
                    system("cls");
                    jogar3x3();
                    opcao = 1;
                } else if ( (opcao == 67) || (opcao == 99) ){
                    gotoxy(2,13);
                    printf("                            DIFICULDADE: DIFICIL                            ");
                    gotoxy(2,14);
                    printf("                                [ESC] VOLTAR                                ");
                    opcao = continuar = 1;
                }
            } while(opcao != 1);
            
        }

        

        opcao = getch();

        if ( (opcao == DIREITA) ) {                 // DIREITA

            movDireita4x4();
            imprimirValores(TAM4);
            
        } else if ( (opcao == ESQUERDA) ) {			// ESQUERDA

            movEsquerda4x4();
            imprimirValores(TAM4);
            
        } else if ( (opcao == BAIXO) ) {			// BAIXO

            movBaixo4x4();
            imprimirValores(TAM4);

        } else if ( (opcao == CIMA) ) {			    // CIMA

            movCima4x4();
            imprimirValores(TAM4);

        } else if (opcao == ESC) {                   // ESC
            system("cls");
			selecao();
        }   
        
    } while ( opcao != 27 );
}

jogar3x3(){

    int ver, x, y, continuar = 0;
    int tam = TAM3;
    pontos = jogada = 0;

    for (x = 0; x < tam; x++){
        for (y = 0; y < tam; y++){
            matrizJogo[x][y] = 0;
			matrizJogoChecar[x][y] = 0;
        }
    }

    valorAleatorio(TAM3);
    system("cls");

    matrizJogo[0][0] = 512;
    matrizJogo[0][1] = 512;

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                            DIFICULDADE: HARDCORE                           %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] VOLTAR                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    PONTOS:  |     | %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  MOVIMENTOS:|     | %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c [P] SALVAR JOGO     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c [R] REINICIAR JOGO  %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c [O] RANKING         %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c        DICA:        %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  UTILIZE AS TECLAS  %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c   DO TECLADO PARA   %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c     MOVIMENTAR O    %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c      TABULEIRO      %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  UNIFACEAR - 2022   %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);

    tijolos();

    valorAleatorio(TAM3);
    imprimirValores(TAM3);

    do{

        cor(11);
        gotoxy(71,18);
        printf("%i", pontos);                   // PRINTA OS PONTOS NA TELA
        gotoxy(71,19);
        printf("%i", jogada);                   // PRINTA A QUANTIDADE DE MOVIMENTOS NA TELA
        gotoxy(80,40);
        cor(7);

        if(checarVitoriaHardcore() == 0 && (continuar != 1)){
            cor(2);
            gotoxy(2,13);
			printf("                       VOCE VENCEU! ESCOLHA UMA OPCAO:                      ");
            gotoxy(2,14);
            printf("                  [R] REINICIAR JOGO [C] CONTINUAR JOGANDO                  ");
            cor(7);
            do{
                opcao = getch();
                if ( (opcao == 82) || (opcao == 114) ){
                    system("cls");
                    jogar3x3();
                    opcao = 1;
                } else if ( (opcao == 67) || (opcao == 99) ){
                    gotoxy(2,13);
                    printf("                            DIFICULDADE: HARDCORE                           ");
                    gotoxy(2,14);
                    printf("                                [ESC] VOLTAR                                ");
                    opcao = continuar = 1;
                }
            } while(opcao != 1);
        }

        opcao = getch();

        if ( (opcao == DIREITA) ) {               // DIREITA

            movDireita3x3();
            imprimirValores(TAM3);
            
        } else if ( (opcao == ESQUERDA) ) {			// ESQUERDA

            movEsquerda3x3();\
            imprimirValores(TAM3);
            
        } else if ( (opcao == BAIXO) ) {			// BAIXO

            movBaixo3x3();
            imprimirValores(TAM3);

        } else if ( (opcao == CIMA) ) {			// CIMA

            movCima3x3();
            imprimirValores(TAM3);

        } else if ( (opcao == 27) ) {    // ESC
                        system("cls");
			selecao();
        }
        
    } while ( opcao != 27 );
}

selecaoRanking(){

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c        R A N K I N G        %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [1] PONTOS  [2] VELOCIDADE                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] VOLTAR                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    do
    {
        opcao = getch();
        if (opcao == 27){
            Beep(370, 200);
            system("cls");
            selecao();
            opcao = 0;
        } else if ((opcao == 49)){
            Beep(370, 200);
            system("cls");
            rankingPontuacaoDif();
            opcao = 0;
        } else if ((opcao == 50)){
            Beep(370, 200);
            system("cls");
            rankingVelDif();
            opcao = 0;
        }
    } while (opcao != 0);
}

rankingPontuacaoDif(){

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c      RANKING DE PONTOS      %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [1] FACIL     [2] MEDIA                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [3] DIFICIL   [4] HARDCORE                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] VOLTAR                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    do
    {
        opcao = getch();
        if (opcao == 27){
            Beep(370, 200);
            system("cls");
            selecaoRanking();
            opcao = 0;
        } else if ((opcao > 48) && (opcao < 53)){
            Beep(370, 200);
            system("cls");
            rankingPontuacao();
            opcao = 0;
        }
    } while (opcao != 0);
}

rankingPontuacao(){

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c      RANKING DE PONTOS      %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c    DIFICULDADE: XXXXXXXX    %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c        [ESC] VOLTAR         %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c      COLOCACAO      %c%c         JOGADOR        %c%c         PONTUACAO         %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     1%c  LUGAR       %c%c        Exemplo01       %c%c     [ 10.892 PONTOS ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     2%c  LUGAR       %c%c        Exemplo02       %c%c     [ 10.128 PONTOS ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     3%c  LUGAR       %c%c      TerceiroLugar     %c%c     [ 9.626  PONTOS ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     4%c  LUGAR       %c%c       QuartoLugar      %c%c     [ 9.338  PONTOS ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     5%c  LUGAR       %c%c       QuintoLugar      %c%c     [ 8.928  PONTOS ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     24%c LUGAR       %c%c     VigesimoQuarto     %c%c     [ 4.628  PONTOS ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    do{
        opcao = getch();
        Beep(370, 200);
        if (opcao == 27){
            system("cls");
            rankingPontuacaoDif();
        }
    } while (opcao != 27);
    
}

rankingVelDif(){

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c    RANKING DE VELOCIDADE    %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [1] FACIL     [2] MEDIA                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [3] DIFICIL   [4] HARDCORE                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] VOLTAR                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    do
    {
        opcao = getch();
        if (opcao == 27){
            Beep(370, 200);
            system("cls");
            selecaoRanking();
            opcao = 0;
        } else if ((opcao > 48) && (opcao < 53)){
            Beep(370, 200);
            system("cls");
            rankingVel();
            opcao = 0;
        }
    } while (opcao != 0);
}

rankingVel(){

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c    RANKING DE VELOCIDADE    %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c    DIFICULDADE: XXXXXXXX    %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c        [ESC] VOLTAR         %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c      COLOCACAO      %c%c         JOGADOR        %c%c         VELOCIDADE        %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     1%c  LUGAR       %c%c        Exemplo01       %c%c     [ 50 MOVIMENTOS ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     2%c  LUGAR       %c%c        Exemplo02       %c%c     [ 58 MOVIMENTOS ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     3%c  LUGAR       %c%c      TerceiroLugar     %c%c     [ 63 MOVIMENTOS ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     4%c  LUGAR       %c%c       QuartoLugar      %c%c     [ 71 MOVIMENTOS ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     5%c  LUGAR       %c%c       QuintoLugar      %c%c     [ 73 MOVIMENTOS ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     24%c LUGAR       %c%c     VigesimoQuarto     %c%c     [ 109 MOVIMENTOS ]    %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    
    tijolos();

    do{
        opcao = getch();
        if (opcao == 27){
            Beep(370, 200);
            system("cls");
            rankingVelDif();
        }
    } while (opcao != 27);
    
}

jogosSalvos(){

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c        JOGOS SALVOS         %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                     SEUS JOGOS SALVOS APARECERAO AQUI:                     %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [1] **********************                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [2] **********************                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [3] **********************                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [4] **********************                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [5] **********************                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                [ESC] VOLTAR                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    do
    {
        opcao = getch();
        if (opcao == 27){
            Beep(370, 200);
            system("cls");
            selecao();
            opcao = 0;
        }
    } while (opcao != 0);

}

logo(){
    tijolos();
    
    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c****_****%c      .d8888b.    .d8888b.       d8888    .d8888b.      %c****_****%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c***/ \\***%c     d88P  Y88b  d88P  Y88b     d8P888   d88P  Y88b     %c***/ \\***%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c**( 2 )**%c            888  888    888    d8P 888   Y88b. d88P     %c**( 4 )**%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c***\\_/***%c          .d88P  888    888   d8P  888    'Y88888'      %c***\\_/***%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c****_****%c      .od888P'   888    888  d88   888   .d8P''Y8b.     %c****_****%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c***/ \\***%c     d88P'       888    888  8888888888  888    888     %c***/ \\***%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c**( 0 )**%c     888'        Y88b  d88P        888   Y88b  d88P     %c**( 8 )**%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c***\\_/***%c     888888888    'Y8888P'         888    'Y8888P'      %c***\\_/***%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);

    tijolos();
}

tijolos(){
	int tijolo;
    for (tijolo = 0; tijolo != 80; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");
}

movDireita5x5(){

    for(y = 4; y >= 0; y--) {
                    
        for(x = 0; x < TAM5; x++) {
            
            matrizJogoChecar[x][y] = matrizJogo[x][y];
        
            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] == 0) && (matrizJogo[x][y - 3] == 0) && (y > 2) && (matrizJogo[x][y - 4] != 0) && (y > 3) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y - 4];
                matrizJogo[x][y - 4] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] == 0) && (matrizJogo[x][y - 3] != 0) && (y > 2) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y - 3];
                matrizJogo[x][y - 3] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] != 0) && (y > 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y - 2];
                matrizJogo[x][y - 2] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] != 0) && (y > 0) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y - 1];
                matrizJogo[x][y - 1] = 0;
                
            }

            if ( (matrizJogo[x][y]) != 0 ) {

                if ( (matrizJogo[x][y - 1] == matrizJogo[x][y]) && (y > 0) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y - 1] = 0;

                } else if ( (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] == matrizJogo[x][y]) && (y > 1) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y - 2] = 0;

                } else if ( (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] == 0) && (matrizJogo[x][y - 3] == matrizJogo[x][y]) && (y > 2) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y - 3] = 0;

                } else if ( (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] == 0) && (matrizJogo[x][y - 3] == 0) && (matrizJogo[x][y - 4] == matrizJogo[x][y]) && (y > 3) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y - 4] = 0;

                }
            }
        }
    }
    if (checarMovimento(TAM5) == 0) {
        jogada++;
        valorAleatorio(TAM5);
    }

}

movEsquerda5x5(){
    for(y = 0; y < TAM5; y++) {
            
        for(x = 4; x >= 0; x--) {

            matrizJogoChecar[x][y] = matrizJogo[x][y];

            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == 0) && (matrizJogo[x][y + 3] == 0) && (matrizJogo[x][y + 4] != 0) && (y < 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y + 4];
                matrizJogo[x][y + 4] = 0;
            
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == 0) && (matrizJogo[x][y + 3] != 0) && (y < 2) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y + 3];
                matrizJogo[x][y + 3] = 0;
            
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] != 0) && (y < 3) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y + 2];
                matrizJogo[x][y + 2] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] != 0) && (y < 4) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y + 1];
                matrizJogo[x][y + 1] = 0;
        
            }
            
            if ( (matrizJogo[x][y]) != 0 ) {
                
                if ( (matrizJogo[x][y + 1] == matrizJogo[x][y]) && (y < 4) ) {

                pontos = pontos + (matrizJogo[x][y]*2);
                matrizJogo[x][y] = matrizJogo[x][y]*2;
                matrizJogo[x][y + 1] = 0;

                } else if ( (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == matrizJogo[x][y]) && (y < 3) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y + 2] = 0;

                } else if ( (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == 0) && (matrizJogo[x][y + 3] == matrizJogo[x][y]) && (y < 2) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y + 3] = 0;

                } else if ( (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == 0) && (matrizJogo[x][y + 3] == 0) && (matrizJogo[x][y + 4] == matrizJogo[x][y]) && (y < 1) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y + 4] = 0;

                }
            }
        }
    }
    if (checarMovimento(TAM5) == 0) {
        jogada++;
        valorAleatorio(TAM5);
    }
}

movBaixo5x5(){
    for(x = 4; x >= 0; x--) {
            
        for(y = 0; y < TAM5; y++) {

            matrizJogoChecar[x][y] = matrizJogo[x][y];
            
            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] == 0) && (matrizJogo[x - 3][y] == 0) && (matrizJogo[x - 4][y] != 0) && (x > 3) ) {
            
                matrizJogo[x][y] = matrizJogo[x - 4][y];
                matrizJogo[x - 4][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] == 0) && (matrizJogo[x - 3][y] != 0) && (x > 2) ) {
            
                matrizJogo[x][y] = matrizJogo[x - 3][y];
                matrizJogo[x - 3][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] != 0) && (x > 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x - 2][y];
                matrizJogo[x - 2][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] != 0) && (x > 0) ) {
            
                matrizJogo[x][y] = matrizJogo[x - 1][y];
                matrizJogo[x - 1][y] = 0;
                
            }
            
            if ( (matrizJogo[x][y]) != 0 ) {

                if ( (matrizJogo[x - 1][y] == matrizJogo[x][y]) && (x > 0) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;

                    matrizJogo[x - 1][y] = 0;

                } else if ( (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] == matrizJogo[x][y]) && (x > 1) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x - 2][y] = 0;

                } else if ( (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] == 0) && (matrizJogo[x - 3][y] == matrizJogo[x][y]) && (x > 2) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x - 3][y] = 0;

                } else if ( (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] == 0) && (matrizJogo[x - 3][y] == 0) && (matrizJogo[x - 4][y] == matrizJogo[x][y]) && (x > 3) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x - 4][y] = 0;

                }
            }
        }
    }
    if (checarMovimento(TAM5) == 0) {
        jogada++;
        valorAleatorio(TAM5);
    }
}

movCima5x5(){
    for(x = 0; x < TAM5; x++) {   

        for(y = 4; y >= 0; y--) {

            matrizJogoChecar[x][y] = matrizJogo[x][y];
            
            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == 0) && (matrizJogo[x + 3][y] == 0) && (matrizJogo[x + 4][y] != 0) && (x < 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x + 4][y];
                matrizJogo[x + 4][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == 0) && (matrizJogo[x + 3][y] != 0) && (x < 2) ) {
            
                matrizJogo[x][y] = matrizJogo[x + 3][y];
                matrizJogo[x + 3][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] != 0) && (x < 3) ) {
            
                matrizJogo[x][y] = matrizJogo[x + 2][y];
                matrizJogo[x + 2][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] != 0) && (x < 4) ) {
            
                matrizJogo[x][y] = matrizJogo[x + 1][y];
                matrizJogo[x + 1][y] = 0;
                
            }
            
            if ( (matrizJogo[x][y]) != 0 ) {

                if ( (matrizJogo[x + 1][y] == matrizJogo[x][y]) && (x < 4) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x + 1][y] = 0;

                } else if ( (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == matrizJogo[x][y]) && (x < 3) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x + 2][y] = 0;

                } else if ( (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == 0) && (matrizJogo[x + 3][y] == matrizJogo[x][y]) && (x < 2) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x + 3][y] = 0;

                } else if ( (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == 0) && (matrizJogo[x + 3][y] == 0) && (matrizJogo[x + 4][y] == matrizJogo[x][y]) && (x < 1) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x + 4][y] = 0;

                }
            }
        }
    }
    if (checarMovimento(TAM5) == 0) {
        jogada++;
        valorAleatorio(TAM5);
    }
}

movDireita4x4(){
    int x, y = 0;

    for(y = 3; y >= 0; y--) {
                    
        for(x = 0; x < TAM4; x++) {
            
            matrizJogoChecar[x][y] = matrizJogo[x][y];
        
            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] == 0) && (matrizJogo[x][y - 3] != 0) && (y > 2) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y - 3];
                matrizJogo[x][y - 3] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] != 0) && (y > 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y - 2];
                matrizJogo[x][y - 2] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] != 0) && (y > 0) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y - 1];
                matrizJogo[x][y - 1] = 0;
                
            }

            if ( (matrizJogo[x][y]) != 0 ) {

                if ( (matrizJogo[x][y - 1] == matrizJogo[x][y]) && (y > 0) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y - 1] = 0;

                } else if ( (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] == matrizJogo[x][y]) && (y > 1) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y - 2] = 0;

                } else if ( (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] == 0) && (matrizJogo[x][y - 3] == matrizJogo[x][y]) && (y > 2) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y - 3] = 0;

                }
            }
        }
    }
    if (checarMovimento(TAM4) == 0) {
        jogada++;
        valorAleatorio(TAM4);
    }

}

movEsquerda4x4(){
    int x, y = 0;

    for(y = 0; y < TAM4; y++) {
            
        for(x = 3; x >= 0; x--) {

            matrizJogoChecar[x][y] = matrizJogo[x][y];

            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == 0) && (matrizJogo[x][y + 3] != 0) && (y < 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y + 3];
                matrizJogo[x][y + 3] = 0;
            
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] != 0) && (y < 2) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y + 2];
                matrizJogo[x][y + 2] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] != 0) && (y < 3) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y + 1];
                matrizJogo[x][y + 1] = 0;
        
            }
            
            if ( (matrizJogo[x][y]) != 0 ) {
                
                if ( (matrizJogo[x][y + 1] == matrizJogo[x][y]) && (y < 3) ) {

                pontos = pontos + (matrizJogo[x][y]*2);
                matrizJogo[x][y] = matrizJogo[x][y]*2;
                matrizJogo[x][y + 1] = 0;

                } else if ( (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == matrizJogo[x][y]) && (y < 2) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y + 2] = 0;

                } else if ( (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == 0) && (matrizJogo[x][y + 3] == matrizJogo[x][y]) && (y < 1) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y + 3] = 0;

                }
            }
        }
    }
    if (checarMovimento(TAM4) == 0) {
        jogada++;
        valorAleatorio(TAM4);
    }
}

movBaixo4x4(){
    int x, y = 0;

    for(x = 3; x >= 0; x--) {
            
        for(y = 0; y < TAM4; y++) {

            matrizJogoChecar[x][y] = matrizJogo[x][y];
            
            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] == 0) && (matrizJogo[x - 3][y] != 0) && (x > 2) ) {
            
                matrizJogo[x][y] = matrizJogo[x - 3][y];
                matrizJogo[x - 3][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] != 0) && (x > 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x - 2][y];
                matrizJogo[x - 2][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] != 0) && (x > 0) ) {
            
                matrizJogo[x][y] = matrizJogo[x - 1][y];
                matrizJogo[x - 1][y] = 0;
                
            }
            
            if ( (matrizJogo[x][y]) != 0 ) {

                if ( (matrizJogo[x - 1][y] == matrizJogo[x][y]) && (x > 0) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;

                    matrizJogo[x - 1][y] = 0;

                } else if ( (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] == matrizJogo[x][y]) && (x > 1) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x - 2][y] = 0;

                } else if ( (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] == 0) && (matrizJogo[x - 3][y] == matrizJogo[x][y]) && (x > 2) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x - 3][y] = 0;

                }
            }
        }
    }
    if (checarMovimento(TAM4) == 0) {
        jogada++;
        valorAleatorio(TAM4);
    }
}

movCima4x4(){
    int x, y = 0;
    for(x = 0; x < TAM4; x++) {   

        for(y = 3; y >= 0; y--) {

            matrizJogoChecar[x][y] = matrizJogo[x][y];
            
            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == 0) && (matrizJogo[x + 3][y] != 0) && (x < 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x + 3][y];
                matrizJogo[x + 3][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] != 0) && (x < 2) ) {
            
                matrizJogo[x][y] = matrizJogo[x + 2][y];
                matrizJogo[x + 2][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] != 0) && (x < 3) ) {
            
                matrizJogo[x][y] = matrizJogo[x + 1][y];
                matrizJogo[x + 1][y] = 0;
                
            }
            
            if ( (matrizJogo[x][y]) != 0 ) {

                if ( (matrizJogo[x + 1][y] == matrizJogo[x][y]) && (x < 3) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x + 1][y] = 0;

                } else if ( (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == matrizJogo[x][y]) && (x < 2) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x + 2][y] = 0;

                } else if ( (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == 0) && (matrizJogo[x + 3][y] == matrizJogo[x][y]) && (x < 1) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x + 3][y] = 0;

                }
            }
        }
    }
    if (checarMovimento(TAM4) == 0) {
        jogada++;
        valorAleatorio(TAM4);
    }
}

movDireita3x3(){

    for(y = 2; y >= 0; y--) {
                    
        for(x = 0; x < TAM3; x++) {
            
            matrizJogoChecar[x][y] = matrizJogo[x][y];
        
            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] != 0) && (y > 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y - 2];
                matrizJogo[x][y - 2] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y - 1] != 0) && (y > 0) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y - 1];
                matrizJogo[x][y - 1] = 0;
                
            }

            if ( (matrizJogo[x][y]) != 0 ) {

                if ( (matrizJogo[x][y - 1] == matrizJogo[x][y]) && (y > 0) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y - 1] = 0;

                } else if ( (matrizJogo[x][y - 1] == 0) && (matrizJogo[x][y - 2] == matrizJogo[x][y]) && (y > 1) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y - 2] = 0;

                }
            }
        }
    }
    if (checarMovimento(TAM3) == 0) {
        jogada++;
        valorAleatorio(TAM3);
    }

}

movEsquerda3x3(){
    for(y = 0; y < TAM3; y++) {
            
        for(x = 2; x >= 0; x--) {

            matrizJogoChecar[x][y] = matrizJogo[x][y];

            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] != 0) && (y < 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y + 2];
                matrizJogo[x][y + 2] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x][y + 1] != 0) && (y < 2) ) {
            
                matrizJogo[x][y] = matrizJogo[x][y + 1];
                matrizJogo[x][y + 1] = 0;
        
            }
            
            if ( (matrizJogo[x][y]) != 0 ) {
                
                if ( (matrizJogo[x][y + 1] == matrizJogo[x][y]) && (y < 2) ) {

                pontos = pontos + (matrizJogo[x][y]*2);
                matrizJogo[x][y] = matrizJogo[x][y]*2;
                matrizJogo[x][y + 1] = 0;

                } else if ( (matrizJogo[x][y + 1] == 0) && (matrizJogo[x][y + 2] == matrizJogo[x][y]) && (y < 1) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x][y + 2] = 0;

                }
            }
        }
    }
    if (checarMovimento(TAM3) == 0) {
        jogada++;
        valorAleatorio(TAM3);
    }
}

movBaixo3x3(){
    for(x = 2; x >= 0; x--) {
            
        for(y = 0; y < TAM3; y++) {

            matrizJogoChecar[x][y] = matrizJogo[x][y];
            
            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] != 0) && (x > 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x - 2][y];
                matrizJogo[x - 2][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x - 1][y] != 0) && (x > 0) ) {
            
                matrizJogo[x][y] = matrizJogo[x - 1][y];
                matrizJogo[x - 1][y] = 0;
                
            }
            
            if ( (matrizJogo[x][y]) != 0 ) {

                if ( (matrizJogo[x - 1][y] == matrizJogo[x][y]) && (x > 0) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;

                    matrizJogo[x - 1][y] = 0;

                } else if ( (matrizJogo[x - 1][y] == 0) && (matrizJogo[x - 2][y] == matrizJogo[x][y]) && (x > 1) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x - 2][y] = 0;

                }
            }
        }
    }
    if (checarMovimento(TAM3) == 0) {
        jogada++;
        valorAleatorio(TAM3);
    }
}

movCima3x3(){
    for(x = 0; x < TAM3; x++) {   

        for(y = 2; y >= 0; y--) {

            matrizJogoChecar[x][y] = matrizJogo[x][y];
            
            if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] != 0) && (x < 1) ) {
            
                matrizJogo[x][y] = matrizJogo[x + 2][y];
                matrizJogo[x + 2][y] = 0;
                
            } else if ( (matrizJogo[x][y] == 0) && (matrizJogo[x + 1][y] != 0) && (x < 2) ) {
            
                matrizJogo[x][y] = matrizJogo[x + 1][y];
                matrizJogo[x + 1][y] = 0;
                
            }
            
            if ( (matrizJogo[x][y]) != 0 ) {

                if ( (matrizJogo[x + 1][y] == matrizJogo[x][y]) && (x < 2) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x + 1][y] = 0;

                } else if ( (matrizJogo[x + 1][y] == 0) && (matrizJogo[x + 2][y] == matrizJogo[x][y]) && (x < 1) ) {

                    pontos = pontos + (matrizJogo[x][y]*2);
                    matrizJogo[x][y] = matrizJogo[x][y]*2;
                    matrizJogo[x + 2][y] = 0;

                }
            }
        }
    }
    if (checarMovimento(TAM3) == 0) {
        jogada++;
        valorAleatorio(TAM3);
    }
}

checarMovimento(int tam){
    int x, y = 0;

	if (jogada > 0){
		for(x = 0; x < tam; x++){
			for(y = 0; y < tam; y++){
				if (matrizJogo[x][y] != matrizJogoChecar[x][y]){
					return 0;
					break;
				}
			}
		}
		return 1;
	} else {
		return 0;
	}

}

gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

valorAleatorio(int tam){
    srand(time(NULL));
	
    do{
        x = (rand() % tam);     // GERAR VALOR ALEATORIO PRA POSICAO X
        y = (rand() % tam);     // GERAR VALOR ALEATORIO PRA POSICAO Y

        if (matrizJogo[x][y] == 0) {
            matrizJogo[x][y] = 2;
            i = 0;
        } else {
            i = 1;
        }
    }while(i != 0);
	
}

imprimirValores(int tam){
	
	int posx, posy = 0;
	
	if (tam == 3){											// 3X3
		posy = 23;
        for (x = 0; x < TAM3; x++){                   		// PRINTA OS VALORES DA MATRIZ NAS POSICOES CORRESPONDENTES
            posx = 16;
            for (y = 0; y < TAM3; y++){
                gotoxy(posx,posy);                 			// COLUNA / LINHA
                    if (matrizJogo[x][y] != 0){
                    	printf("      ");
                    	gotoxy(posx,posy);
                        printf("%i  ", matrizJogo[x][y]);
                    } else {
                        printf("      ");
                    }
                posx += 11;
            }
            posy += 5;
        }
	} else if (tam == 4){									// 4X4
		posy = 20;
        for (x = 0; x < tam; x++){                   		// PRINTA OS VALORES DA MATRIZ NAS POSICOES CORRESPONDENTES
            posx = 11;
            for (y = 0; y < tam; y++){
                gotoxy(posx,posy);                 			// COLUNA / LINHA
                    if (matrizJogo[x][y] != 0){
                    	printf("      ");
                    	gotoxy(posx,posy);
                        printf("%i  ", matrizJogo[x][y]);
                    } else {
                        printf("      ");
                    }
                posx += 11;
            }
            posy += 5;
    	}
	} else if (tam == 5){									// 5X5
		posy = 18;
        for (x = 0; x < TAM5; x++){                   		// PRINTA OS VALORES DA MATRIZ NAS POSICOES CORRESPONDENTES
            posx = 5;
            for (y = 0; y < TAM5; y++){
                gotoxy(posx,posy);                 			// COLUNA / LINHA
                    if (matrizJogo[x][y] != 0){
                    	printf("      ");
                    	gotoxy(posx,posy);
                        printf("%i  ", matrizJogo[x][y]);
                    } else {
                        printf("      ");
                    }
                posx += 11;
            }
            posy += 5;
        }
	}
}

checarVitoriaFacil(){
    int x, y = 0;
	for ((x = 0); (x < TAM5); x++) {
		for ((y = 0); (y < TAM5); y++) {
			if (matrizJogo[x][y] == 2048) {
				// TELA DE VITORIA COM A COR
				// GETCH
				// RETORNA COR ANTERIOR
				return 0;
			}
		}
	}
	return 1;
}

checarVitoriaMedia(){
    int x, y = 0;
	for ((x = 0); (x < TAM4); x++) {
		for ((y = 0); (y < TAM4); y++) {
			if (matrizJogo[x][y] == 2048) {
				return 0;
			}
		}
	}
	return 1;
}

checarVitoriaDificil(){
    int x, y = 0;
	for ((x = 0); (x < TAM4); x++) {
		for ((y = 0); (y < TAM4); y++) {
			if (matrizJogo[x][y] == 4096) {
				return 0;
			}
		}
	}
	return 1;
}

checarVitoriaHardcore(){
    int x, y = 0;
	for ((x = 0); (x < TAM3); x++) {
		for ((y = 0); (y < TAM3); y++) {
			if (matrizJogo[x][y] == 1024) {
				return 0;
			}
		}
	}
	return 1;
}

cor(int cor){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}