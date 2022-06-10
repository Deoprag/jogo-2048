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
int jogada, pontos = 0;
int x, y, i = 0;
int matrizJogo[5][5];
int matrizJogoChecar[5][5];

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
void tutorial();
void rankingPontuacaoDif();
void rankingPontuacao();
void jogosSalvos();
void salvarJogo();
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
int perdeu();

// STRUCTS:
typedef struct{
    char apelido[20];
    char senha[20];
    char celular[15];
    int numCadastro;
    int ativo;
} Cadastro;

typedef struct{
    char apelido[20];
    int pontuacaoFacil;
    int pontuacaoMedia;
    int pontuacaoDificil;
    int pontuacaoHardcore;
} Pontuacoes;

typedef struct{
	int matrizSalva[5][5];
	int dificuldade;
	int posicao;
} JogosSalvos;

// FUNCAO PRINCIPAL
int main (){

    SetConsoleTitle("2048 :: Pedro Rocha");

    tijolos();
    Sleep(100);
    Beep(370, 200);

    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(100);
    Beep(370, 200);

    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(100);
    Beep(370, 200);

    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(100);
    Beep(370, 200);

    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(100);
    Beep(370, 200);

    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(100);
    Beep(370, 200);

    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(100);
    Beep(370, 200);

    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(100);
    Beep(370, 200);

    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(100);
    Beep(370, 200);

    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(100);
    Beep(370, 200);

    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);
    Sleep(100);
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
    int opcao = 0;
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

    char c, apelido[17], senha[17];
    int verificador, opcao = 0;
    int i = 0;

    FILE *leitura;

    Cadastro usuario;

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c       INICIAR SESSAO        %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
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

    do{
        i = verificador = 0;

        gotoxy(30,24);
        printf("                  ");
        gotoxy(30,24);

        fflush(stdin);
        do{
            c = getch();
            if( isalnum(c) != 0 ) {
                if (i < 16){

                    apelido[i] = c;
                    i++;
                    putch(c);
                }
            } else if (c == 8 && i) {

                apelido[i] = '\0';
                i--;
                printf("\b \b");
            } else if (c == ESC) {
                system("cls");
                inicio();
                verificador = 1;
            }
        } while (c != 13);
        apelido[i] = '\0';

        leitura = fopen("Cadastros.TXT", "rb");
        while (fread(&usuario, sizeof(Cadastro), 1, leitura) == 1 ){
            if (strcmp(apelido, usuario.apelido) == 0){
                gotoxy(51,24);
                printf("                        ");
                gotoxy(51,24);
                cor(10);
                printf("OK");
                cor(7);
                verificador = 1;
            }
        }
        fclose(leitura);

        if (verificador != 1){
            gotoxy(51,24);
            cor(12);
            printf("USUARIO NAO ENCONTRADO!");
            cor(7);
            Beep(1400, 200);
            Beep(1600, 200);
        }

    } while (verificador != 1);

    do{
        i = verificador = 0;

        gotoxy(30,30);
        printf("                  ");
        gotoxy(30,30);

        fflush(stdin);
        do{
            c = getch();
            if( isalnum(c) != 0 ){
                if (i < 16){
                    senha[i] = c;
                    i++;
                    putch('*');
                }
            } else if (c == 8 && i){
                senha[i] = '\0';
                i--;
                printf("\b \b");
            } else if (c == ESC) {
                system("cls");
                inicio();
                verificador = 1;
            }
        } while (c != 13);
        senha[i] = '\0';

        leitura = fopen("Cadastros.TXT", "rb");
        while (fread(&usuario, sizeof(Cadastro), 1, leitura) == 1 ){
            if ( (strcmp(apelido, usuario.apelido) == 0) && (strcmp(senha, usuario.senha) == 0) ){
                gotoxy(51,30);
                printf("                        ");
                gotoxy(51,30);
                cor(10);
                printf("OK");
                cor(7);
                verificador = 1;
            }
        }
        fclose(leitura);

        if (verificador != 1){
            gotoxy(51,30);
            cor(12);
            printf("SENHA INCORRETA");
            cor(7);
            Beep(1400, 200);
            Beep(1600, 200);
        }
    } while (verificador != 1);

    gotoxy(2,35);
    printf("                     ");
    cor(4);
    printf("[ESC] VOLTAR");
    cor(9);
    printf("     [ENTER] CONFIRMAR\n\n\n\n\n\n");
    cor(7);

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
	
    char c, apelido[17], senha[17], celular[12];
    int opcao, i, continuar = 0;

    FILE *cadastros;
    FILE *leitura;
    Cadastro usuario;



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
    printf("%c%c                  CELULAR: %c                    %c                           %c%c\n", 219, 219, 179, 179, 219, 219);
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
	
    //---------------------------------------------------------------------------------- APELIDO
    do {
        i = continuar = 0;
        gotoxy(30,22);
        printf("                  ");
        gotoxy(30,22);
        fflush(stdin);
        do{
            c = getch();
            if( isalnum(c) != 0 ){
                if (i < 16){

                    apelido[i] = c;
                    i++;
                    putch(c);
                }
            } else if (c == 8 && i){

                apelido[i] = '\0';
                i--;
                printf("\b \b");
            } else if (c == ESC) {
                system("cls");
                inicio();
            }
        } while (c != 13);
        apelido[i] = '\0';
        
        leitura = fopen("Cadastros.txt", "rb");
        while ( fread(&usuario, sizeof(Cadastro), 1, leitura) == 1 ){
            if (strcmp(apelido, usuario.apelido) == 0){
                gotoxy(20,24);
                printf("                                                  ");
                gotoxy(20,24);
                cor(12);
                printf("ESSE APELIDO JA FOI ESCOLHIDO POR OUTRO JOGADOR");
                cor(7);
                Beep(1400, 200);
                Beep(1600, 200);
                continuar = 1;
            }
        }
        fclose(leitura);

        if (i < 5){
            gotoxy(20,24);
            printf("                                                  ");
            gotoxy(20,24);
            cor(12);
            printf("SEU APELIDO PRECISA TER NO MINIMO 5 CARACTERES");
            cor(7);
            Beep(1400, 200);
            Beep(1600, 200);
            continuar = 1;
        }

    } while (continuar == 1);

    gotoxy(20,24);
    printf("                                                  ");
    gotoxy(51,22);
    cor(10);
    printf("OK");
    cor(7);
    //---------------------------------------------------------------------------------- SENHA
    do{
        i = continuar = 0;
        gotoxy(30,26);
        printf("                  ");
        gotoxy(30,26);
        fflush(stdin);
        do{
            c = getch();
            if( isalnum(c) != 0 ){
                if (i < 16){
                    senha[i] = c;
                    i++;
                    putch('*');
                }
            } else if (c == 8 && i){
                senha[i] = '\0';
                i--;
                printf("\b \b");
            } else if (c == ESC) {
                system("cls");
                inicio();
            }
        } while (c != 13);
        senha[i] = '\0';

        if (i < 8){
            gotoxy(20,28);
            cor(12);
            printf("SUA SENHA PRECISA TER NO MINIMO 8 CARACTERES");
            cor(7);
            Beep(1400, 200);
            Beep(1600, 200);
            continuar = 1;
        }
    } while (continuar == 1);

    gotoxy(20,28);
    printf("                                                  ");
    gotoxy(51,26);
    cor(10);
    printf("OK");
    cor(7);
    //---------------------------------------------------------------------------------- CELULAR
        do{
            i = continuar = 0;
            gotoxy(30,30);
            printf("                  ");
            gotoxy(30,30);
            fflush(stdin);
            do{
                c = getch();
                if( isdigit(c) != 0 ){
                    if (i < 11){
                        if (i == 0){
                            printf("(");
                        } else if (i == 2){
                            printf(")");
                        } else if (i == 7){
                            printf("-");
                        }
                        celular[i] = c;
                        i++;
                        putch(c);
                        
                    }
                } else if (c == 8 && i){
                    if ( i == 1 || i == 2 || i == 7){
                        printf("\b \b");
                        celular[i] = '\0';
                        i--;
                        printf("\b \b");
                    } else {
                        celular[i] = '\0';
                        i--;
                        printf("\b \b");
                    }
                }
            }while(c != 13);
            celular[i] = '\0';

            if (i < 10){
                gotoxy(4,32);
                cor(12);
                printf("NUMERO DE CELULAR PRECISAR TER NO MINIMO 10 CARACTERES. [(xx)xxxxx-xxxx]");
                cor(7);
                Beep(1400, 200);
                Beep(1600, 200);
                continuar = 1;
            }   
        } while (continuar == 1);
    gotoxy(4,32);
    printf("                                                                          ");
    gotoxy(51,30);
    cor(10);
    printf("OK");
    cor(7);
    //---------------------------------------------------------------------------------- FIM INPUTS
    cadastros = fopen("Cadastros.txt", "ab");

    strcpy(usuario.apelido, apelido);
    strcpy(usuario.senha, senha);
    strcpy(usuario.celular, celular);
    usuario.ativo = 1;

    fwrite(&usuario, sizeof(Cadastro), 1, cadastros);

    fclose(cadastros);

    gotoxy(2,38);
    printf("                     ");
    cor(4);
    printf("[ESC] VOLTAR");
    cor(9);
    printf("     [ENTER] CONFIRMAR\n\n\n");
    cor(7);    
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
    int opcao = 0;

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

selecao(){
    int opcao = 0;

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
    printf("%c%c                              [3] JOGOS SALVOS                              %c%c\n", 219, 219, 219, 219);
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
            rankingPontuacaoDif();
            opcao = 0;
        } else if (opcao == 51){
            Beep(370, 200);
            system("cls");
            jogosSalvos();
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
    int opcao = 0;

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
    int opcao = 0;

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
    int opcao = 0;

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
    int opcao = 0;

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

jogar5x5(int volta){
    
    int x, y, continuar, opcao = 0;
    int tam = TAM5;

    if (volta != 1){
        for (x = 0; x < TAM5; x++){
            for (y = 0; y < TAM5; y++){
                matrizJogo[x][y] = 0;
                matrizJogoChecar[x][y] = 0;
            }
        }
        valorAleatorio(TAM5);
        valorAleatorio(TAM5);
        pontos = jogada = 0;
    }
    
    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             DIFICULDADE: FACIL                             %c%c\n", 219, 219, 219, 219);
    printf("%c%c", 219, 219);
    cor(4);
    printf("                                [ESC] VOLTAR                                ");
    cor(7);
    printf("%c%c\n", 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c   PONTOS:  |      | %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c MOVIMENTOS:|      | %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c [S] SALVAR JOGO     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c [R] REINICIAR JOGO  %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c [C] COMO JOGAR      %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

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
                    Beep(370, 200);
                    system("color 07");
                    system("cls");
                    jogar4x4Media();
                    opcao = 1;
                } else if ( (opcao == 67) || (opcao == 99) ){
                    Beep(370, 200);
                    gotoxy(2,13);
                    printf("                             DIFICULDADE: FACIL                             ");
                    gotoxy(2,14);
                    printf("                                [ESC] VOLTAR                                ");
                    opcao = continuar = 1;
                }
            } while(opcao != 1);
        }
        if (perdeu(TAM5) == 1) {
            cor(4);
            gotoxy(2,13);
			printf("                                VOCE PERDEU!                                ");
            gotoxy(2,14);
            printf("                  [R] REINICIAR JOGO  [ESC] MENU PRINCIPAL                  ");
            cor(7);
            Beep(1400, 200);
            Beep(1600, 200);
            do{
                opcao = getch();
                if ( (opcao == 82) || (opcao == 114) ){
                    Beep(370, 200);
                    system("cls");
                    jogar5x5();
                    opcao = 1;
                } else if ( (opcao == ESC) ){
                    Beep(370, 200);
                    system("cls");
                    selecao();
                    opcao = 1;
                }
            } while (opcao != 1);
        }

        opcao = getch();

        if ( (opcao == DIREITA) ) {               	        // DIREITA

            movDireita5x5();
			imprimirValores(TAM5);
            
        } else if ( (opcao == ESQUERDA) ) {			        // ESQUERDA

            movEsquerda5x5();
			imprimirValores(TAM5);

            
        } else if ( (opcao == BAIXO) ) {			        // BAIXO

            movBaixo5x5();
			imprimirValores(TAM5);


        } else if ( (opcao == CIMA) ) {				        // CIMA

            movCima5x5();
			imprimirValores(TAM5);

        } else if ( (opcao == ESC) ) {    				    // ESC

            Beep(370, 200);
            system("cls");
			selecao();

        } else if ( (opcao == 83) || (opcao == 115) ) {     // S

            Beep(370, 200);
            system("cls");
            salvarJogo(1);

        } else if ( (opcao == 82) || (opcao == 114) ) {     // R

            Beep(370, 200);
            system("cls");
            jogar5x5();

        } else if ( (opcao == 67 ) || (opcao == 99) ) {     // C
            
            Beep(370, 200);
            system("cls");
            tutorial(1);

        }
        
    } while ( opcao != 27 );
}

jogar4x4Media(int volta){

    int x, y, continuar, opcao = 0;
    int tam = TAM4;

    if (volta != 1){
        for (x = 0; x < TAM5; x++){
            for (y = 0; y < TAM5; y++){
                matrizJogo[x][y] = 0;
                matrizJogoChecar[x][y] = 0;
            }
        }
        valorAleatorio(TAM4);
        valorAleatorio(TAM4);
        pontos = jogada = 0;
    }
    

    /*matrizJogo[0][1] = 1024;
    matrizJogo[1][0] = 512;
    matrizJogo[1][1] = 512;*/

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             DIFICULDADE: MEDIA                             %c%c\n", 219, 219, 219, 219);
    printf("%c%c", 219, 219);
    cor(4);
    printf("                                [ESC] VOLTAR                                ");
    cor(7);
    printf("%c%c\n", 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   PONTOS:  |     | %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c MOVIMENTOS:|     | %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c [S] SALVAR JOGO    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c [R] REINICIAR JOGO %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c [C] COMO JOGAR     %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
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

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219);
    cor(2);
    printf("  UNIFACEAR - 2022  ");
    cor(7);
    printf("%c%c\n", 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);

    tijolos();

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
            cor(2);
            gotoxy(2,13);
			printf("                       VOCE VENCEU! ESCOLHA UMA OPCAO:                      ");
            gotoxy(2,14);
            printf("            [J] JOGAR DIFICULDADE DIFICIL [C] CONTINUAR JOGANDO             ");
            cor(7);
            do{
                opcao = getch();
                if ( (opcao == 74) || (opcao == 106) ){
                    Beep(370, 200);
                    system("color 07");
                    system("cls");
                    system("color 07");
                    jogar4x4Dificil();
                    opcao = 1;
                } else if ( (opcao == 67) || (opcao == 99) ){
                    Beep(370, 200);
                    gotoxy(2,13);
                    printf("                             DIFICULDADE: MEDIA                             ");
                    gotoxy(2,14);
                    printf("                                [ESC] VOLTAR                                ");
                    opcao = continuar = 1;
                }
            } while(opcao != 1);
        }
        if (perdeu(TAM4) == 1) {
            cor(4);
            gotoxy(2,13);
			printf("                                VOCE PERDEU!                                ");
            gotoxy(2,14);
            printf("                  [R] REINICIAR JOGO  [ESC] MENU PRINCIPAL                  ");
            cor(7);
            Beep(1400, 200);
            Beep(1600, 200);
            do{
                opcao = getch();
                if ( (opcao == 82) || (opcao == 114) ){
                    Beep(370, 200);
                    system("cls");
                    jogar4x4Media();
                    opcao = 1;
                } else if ( (opcao == ESC) ){
                    Beep(370, 200);
                    system("cls");
                    selecao();
                    opcao = 1;
                }
            } while (opcao != 1);
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
            
            Beep(370, 200);            
            system("cls");
			selecao();

        } else if ( (opcao == 83) || (opcao == 115) ) {     // S
            
            Beep(370, 200);
            system("cls");
            salvarJogo(2);
        } else if ( (opcao == 82) || (opcao == 114) ) {     // R

            Beep(370, 200);
            system("cls");
            jogar4x4Media();

        } else if ( (opcao == 67 ) || (opcao == 99) ) {     // C

            Beep(370, 200);
            system("cls");
            tutorial(2);
        }
        
    } while ( opcao != 27 );
}

jogar4x4Dificil(int volta){

    int x, y, continuar, opcao = 0;
    int tam = TAM4;

    if (volta != 1){
        for (x = 0; x < TAM5; x++){
            for (y = 0; y < TAM5; y++){
                matrizJogo[x][y] = 0;
                matrizJogoChecar[x][y] = 0;
            }
        }
        valorAleatorio(TAM4);
        valorAleatorio(TAM4);
        pontos = jogada = 0;
    }

    

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                            DIFICULDADE: DIFICIL                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c", 219, 219);
    cor(4);
    printf("                                [ESC] VOLTAR                                ");
    cor(7);
    printf("%c%c\n", 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   PONTOS:  |     | %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c MOVIMENTOS:|     | %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c [S] SALVAR JOGO    %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c [R] REINICIAR JOGO %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c [C] COMO JOGAR     %c%c\n", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219, 219, 219);
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

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 219, 219);
    cor(2);
    printf("  UNIFACEAR - 2022  ");
    cor(7);
    printf("%c%c\n", 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                    %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);

    tijolos();

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
            cor(2);
            gotoxy(2,13);
			printf("                       VOCE VENCEU! ESCOLHA UMA OPCAO:                      ");
            gotoxy(2,14);
            printf("           [J] JOGAR DIFICULDADE HARDCORE [C] CONTINUAR JOGANDO             ");
            cor(7);
            do{
                opcao = getch();
                if ( (opcao == 74) || (opcao == 106) ){
                    Beep(370, 200);
                    system("color 07");
                    system("cls");
                    jogar3x3();
                    opcao = 1;
                } else if ( (opcao == 67) || (opcao == 99) ){
                    Beep(370, 200);
                    gotoxy(2,13);
                    printf("                            DIFICULDADE: DIFICIL                            ");
                    gotoxy(2,14);
                    printf("                                [ESC] VOLTAR                                ");
                    opcao = continuar = 1;
                }
            } while(opcao != 1);
            
        }
        if (perdeu(TAM4) == 1) {
            cor(4);
            gotoxy(2,13);
			printf("                                VOCE PERDEU!                                ");
            gotoxy(2,14);
            printf("                  [R] REINICIAR JOGO  [ESC] MENU PRINCIPAL                  ");
            cor(7);
            Beep(1400, 200);
            Beep(1600, 200);
            do{
                opcao = getch();
                if ( (opcao == 82) || (opcao == 114) ){
                    Beep(370, 200);
                    system("cls");
                    jogar4x4Dificil();
                    opcao = 1;
                } else if ( (opcao == ESC) ){
                    Beep(370, 200);
                    system("cls");
                    selecao();
                    opcao = 1;
                }
            } while (opcao != 1);
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

            Beep(370, 200);
            system("cls");
			selecao();

        } else if ( (opcao == 83) || (opcao == 115) ) {     // S

            Beep(370, 200);
            system("cls");
            salvarJogo(3);

        } else if ( (opcao == 82) || (opcao == 114) ) {     // R

            Beep(370, 200);
            system("cls");
            jogar4x4Dificil();

        } else if ( (opcao == 67 ) || (opcao == 99) ) {     // C
            
            Beep(370, 200);
            system("cls");
            tutorial(3);
        }
        
    } while ( opcao != 27 );
}

jogar3x3(int volta){

    int ver, x, y, continuar, opcao = 0;
    int tam = TAM3;

    if (volta != 1){
        for (x = 0; x < TAM5; x++){
            for (y = 0; y < TAM5; y++){
                matrizJogo[x][y] = 0;
                matrizJogoChecar[x][y] = 0;
            }
        }
        valorAleatorio(TAM3);
        valorAleatorio(TAM3);
        pontos = jogada = 0;
    }

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                            DIFICULDADE: HARDCORE                           %c%c\n", 219, 219, 219, 219);
    printf("%c%c", 219, 219);
    cor(4);
    printf("                                [ESC] VOLTAR                                ");
    cor(7);
    printf("%c%c\n", 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c    PONTOS:  |     | %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  MOVIMENTOS:|     | %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c [S] SALVAR JOGO     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c [R] REINICIAR JOGO  %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c         %c%c         %c%c         %c%c%c%c%c%c%c%c%c%c%c%c%c [C] COMO JOGAR      %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);
    
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
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219);
    cor(2);
    printf("  UNIFACEAR - 2022   ");
    cor(7);
    printf("%c%c\n", 219, 219);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                     %c%c\n", 219, 219, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219);

    tijolos();

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
                    Beep(370, 200);
                    system("cls");
                    jogar3x3();
                    opcao = 1;
                } else if ( (opcao == 67) || (opcao == 99) ){
                    Beep(370, 200);
                    gotoxy(2,13);
                    printf("                            DIFICULDADE: HARDCORE                           ");
                    gotoxy(2,14);
                    printf("                                [ESC] VOLTAR                                ");
                    opcao = continuar = 1;
                }
            } while(opcao != 1);

        }
		if (perdeu(TAM3) == 1) {
            cor(4);
            gotoxy(2,13);
			printf("                                VOCE PERDEU!                                ");
            gotoxy(2,14);
            printf("                  [R] REINICIAR JOGO  [ESC] MENU PRINCIPAL                  ");
            cor(7);
            Beep(1400, 200);
            Beep(1600, 200);
            do{
                opcao = getch();
                if ( (opcao == 82) || (opcao == 114) ){
                    Beep(370, 200);
                    system("cls");
                    jogar3x3();
                    opcao = 1;
                } else if ( (opcao == ESC) ){
                    Beep(370, 200);
                    system("cls");
                    selecao();
                    opcao = 1;
                }
            } while (opcao != 1);
        }

        opcao = getch();

        if ( (opcao == DIREITA) ) {                         // DIREITA

            movDireita3x3();
            imprimirValores(TAM3);
            
        } else if ( (opcao == ESQUERDA) ) {			        // ESQUERDA

            movEsquerda3x3();\
            imprimirValores(TAM3);
            
        } else if ( (opcao == BAIXO) ) {			        // BAIXO

            movBaixo3x3();
            imprimirValores(TAM3);

        } else if ( (opcao == CIMA) ) {			            // CIMA

            movCima3x3();
            imprimirValores(TAM3);

        } else if ( (opcao == 27) ) {                       // ESC

            Beep(370, 200);
            system("cls");
			selecao();

        } else if ( (opcao == 83) || (opcao == 115) ) {     // S

            Beep(370, 200);
            system("cls");
            salvarJogo(4);

        } else if ( (opcao == 82) || (opcao == 114) ) {     // R

            Beep(370, 200);
            system("cls");
            jogar3x3();

        } else if ( (opcao == 67 ) || (opcao == 99) ) {     // C

            Beep(370, 200);
            system("cls");
            tutorial(4);
        }
        
    } while ( opcao != 27 );
}

tutorial(int dificuldade){
    int opcao = 0;

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c     C O M O   J O G A R     %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c     > O OBJETIVO PRINCIPAL DO JOGO E ALCANCAR A CELULA DE VALOR MAIS ALTO  %c%c\n", 219, 219, 219, 219);
    printf("%c%c     (PODENDO VARIAR ENTRE 1024, 2048 E 4096, DEPENDENDO DA DIFICULDADE);   %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c     > VOCE CONSEGUE AS CELULAS DE MAIOR VALOR ATRAVES DE 2 CELULAS IGUAIS  %c%c\n", 219, 219, 219, 219);
    printf("%c%c     DE MENOR VALOR, POR EXEMPLO, SE JUNTARMOS 2 CELULAS DE 2, OBTEREMOS    %c%c\n", 219, 219, 219, 219);
    printf("%c%c     UMA CELULA DE VALOR 4 (4 + 4 = 8 / 8 + 8 = 16 /... E ASSIM POR DIANTE);%c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c     > VOCE PODE SE MOVIMENTAR ATRAVES DO TABULEIRO UTILIZANDO AS SETAS     %c%c\n", 219, 219, 219, 219);
    printf("%c%c     DO TECLADO. AS CELULAS IGUAIS IRAO SE MESCLAR DE ACORDO COM O LADO     %c%c\n", 219, 219, 219, 219);
    printf("%c%c     QUE O JOGADOR DECIDIU SE MOVIMENTAR;                                   %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c     > CASO CONSIGA CHEGAR NA RESPECTIVA CELULA DE VITORIA DO MODO EM QUE   %c%c\n", 219, 219, 219, 219);
    printf("%c%c     ESTA JOGANDO, VOCE PODERA ESCOLHER CONTINUAR JOGANDO PARA OBTER UMA    %c%c\n", 219, 219, 219, 219);
    printf("%c%c     COLOCACAO MAIS ALTA NO RANKING OU JOGAR UMA DIFICULDADE MAIS DIFICIL   %c%c\n", 219, 219, 219, 219);
    printf("%c%c     (EXCETO NO MODO HARDCORE).                                             %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                ", 219, 219);
    cor(4);
    printf("[ESC] VOLTAR");
    cor(7);
    printf("                                %c%c\n", 219, 219);    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    do
    {
        opcao = getch();
        if (opcao == 27){
            Beep(370, 200);
            system("cls");
            if (dificuldade == 1) {
            	jogar5x5(1);
			} else if (dificuldade == 2) {
				jogar4x4Media(1);
			} else if (dificuldade == 3) {
				jogar4x4Dificil(1);
			} else if (dificuldade == 4) {
				jogar3x3(1);
			}    
        }

    } while (opcao != 27);
}

rankingPontuacaoDif(){
    int opcao = 0;

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
    printf("%c%c", 219, 219);
    cor(4);
    printf("                                [ESC] VOLTAR                                ");
    cor(7);
    printf("%c%c\n", 219, 219);
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
        } else if ( (opcao == 49) ) {
            Beep(370, 200);
            system("cls");
            rankingPontuacao(1);
            opcao = 0;
        } else if ( (opcao == 50) ) {
            Beep(370, 200);
            system("cls");
            rankingPontuacao(2);
            opcao = 0;
        } else if ( (opcao == 51) ) {
            Beep(370, 200);
            system("cls");
            rankingPontuacao(3);
            opcao = 0;
        } else if ( (opcao == 52) ) {
            Beep(370, 200);
            system("cls");
            rankingPontuacao(4);
            opcao = 0;
        }
    } while (opcao != 0);
}

rankingPontuacao(int dificuldade){
    int opcao = 0;

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c        R A N K I N G        %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c    DIFICULDADE:             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c        ", 219, 219, 179);
    cor(4);
    printf("[ESC] VOLTAR");
    cor(7);
    printf("         %c                      %c%c\n", 179, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c      COLOCACAO      %c%c         JOGADOR        %c%c         PONTUACAO         %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     1%c  LUGAR       %c%c                        %c%c     [               ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     2%c  LUGAR       %c%c                        %c%c     [               ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     3%c  LUGAR       %c%c                        %c%c     [               ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     4%c  LUGAR       %c%c                        %c%c     [               ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c     5%c  LUGAR       %c%c                        %c%c     [               ]     %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219);
    printf("%c%c                     %c%c                        %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    gotoxy(43,16);
    if (dificuldade == 1) {
        cor(3);
        printf("FACIL");
        cor(7);
    } else if (dificuldade == 2) {
        cor(6);
        printf("MEDIA");
        cor(7);
    } else if (dificuldade == 3) {
        cor(12);
        printf("DIFICIL");
        cor(7);
    } else if (dificuldade == 4) {
        cor(13);
        printf("HARDCORE");
        cor(7);
    }
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    do{
        opcao = getch();
        Beep(370, 200);
        if (opcao == 27){
            system("cls");
            rankingPontuacaoDif();
        }
    } while (opcao != 27);
    
}

jogosSalvos(){
    int opcao = 0;
    
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
    printf("%c%c                         [1]                                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [2]                                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [3]                                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [4]                                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [5]                                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c", 219, 219);
    cor(4);
    printf("                                [ESC] VOLTAR                                ");
    cor(7);
    printf("%c%c\n", 219, 219);
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

salvarJogo(int dificuldade){
	/*FILE *salvos;
	JogosSalvos salvar;
    */
    int opcao, x, y, i, posx, posy = 0;

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c         SALVAR JOGO         %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c                             %c                      %c%c\n", 219, 219, 179, 179, 219, 219);
    printf("%c%c                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                      %c%c\n", 219, 219, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                   ESCOLHA UMA POSICAO PARA SALVAR O JOGO:                  %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [1]                                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [2]                                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [3]                                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [4]                                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [5]                                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c", 219, 219);
    cor(4);
    printf("                                [ESC] VOLTAR                                ");
    cor(7);
    printf("%c%c\n", 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();
	
    do
    {
        opcao = getch();
        if (opcao == 27){
            if (dificuldade == 1) {
                Beep(370, 200);
                system("cls");
                jogar5x5(1);
                opcao = 0;
            } else if (dificuldade == 2) {
                Beep(370, 200);
                system("cls");
                jogar4x4Media(1);
                opcao = 0;
            } else if (dificuldade == 3) {
                Beep(370, 200);
                system("cls");
                jogar4x4Dificil(1);
                opcao = 0;
            } else if (dificuldade == 4) {
                Beep(370, 200);
                system("cls");
                jogar3x3(1);
                opcao = 0;
            }
        } else if (opcao == 49) {
            
		} else if (opcao == 50) {
			
		} else if (opcao == 51) {
			
		} else if (opcao == 52) {
			
		} else if (opcao == 53) {
			
		}
	
    } while (opcao != 0);

}

logo(){
    cor(7); 
    tijolos();
    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c****", 219, 219);
    cor(14);
    printf("_");
    cor(7);
    printf("****%c", 219);
    cor(11);
    printf("      .d8888b.    .d8888b.       d8888    .d8888b.      ");
    cor(7);
    printf("%c****", 219);
    cor(14);
    printf("_");
    cor(7);
    printf("****%c%c\n", 219, 219);

    printf("%c%c***", 219,219);
    cor(14);
    printf("/ \\");
    cor(7);
    printf("***%c", 219);
    cor(11);
    printf("     d88P  Y88b  d88P  Y88b     d8P888   d88P  Y88b     ");
    cor(7);
    printf("%c***", 219);
    cor(14);
    printf("/ \\");
    cor(7);
    printf("***%c%c\n", 219, 219);

    printf("%c%c**", 219, 219);
    cor(14);
    printf("( 2 )");
    cor(7);
    printf("**%c", 219);
    cor(11);
    printf("            888  888    888    d8P 888   Y88b. d88P     ");
    cor(7);
    printf("%c**", 219);
    cor(14);
    printf("( 4 )");
    cor(7);
    printf("**%c%c\n", 219, 219);

    printf("%c%c***", 219, 219);
    cor(14);
    printf("\\_/");
    cor(7);
    printf("***%c", 219);
    cor(11);
    printf("          .d88P  888    888   d8P  888    'Y88888'      ");
    cor(7);
    printf("%c***", 219);
    cor(14);
    printf("\\_/");
    cor(7);
    printf("***%c%c\n", 219, 219);

    printf("%c%c****", 219, 219);
    cor(14);
    printf("_");
    cor(7);
    printf("****%c", 219);
    cor(11);
    printf("      .od888P'   888    888  d88   888   .d8P''Y8b.     ");
    cor(7);
    printf("%c****", 219);
    cor(14);
    printf("_");
    cor(7);
    printf("****%c%c\n", 219, 219);

    printf("%c%c***", 219, 219);
    cor(14);
    printf("/ \\");
    cor(7);
    printf("***%c", 219);
    cor(11);
    printf("     d88P'       888    888  8888888888  888    888     ");
    cor(7);
    printf("%c***", 219);
    cor(14);
    printf("/ \\");
    cor(7);
    printf("***%c%c\n", 219, 219);

    printf("%c%c**", 219, 219);
    cor(14);
    printf("( 0 )");
    cor(7);
    printf("**%c", 219);
    cor(11);
    printf("     888'        Y88b  d88P        888   Y88b  d88P     ");
    cor(7);
    printf("%c**", 219);
    cor(14);
    printf("( 8 )");
    cor(7);
    printf("**%c%c\n", 219, 219);

    printf("%c%c***", 219, 219);
    cor(14);
    printf("\\_/");
    cor(7);
    printf("***%c", 219);
    cor(11);
    printf("     888888888    'Y8888P'         888    'Y8888P'      ");
    cor(7);
    printf("%c***", 219);
    cor(14);
    printf("\\_/");
    cor(7);
    printf("***%c%c\n", 219, 219);

    printf("%c%c*********%c                                                        %c*********%c%c\n", 219, 219, 219, 219, 219, 219);
    tijolos();
}

tijolos(){
    for (int tijolo = 0; tijolo != 80; tijolo++){
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
		posy = 22;
        for (x = 0; x < TAM3; x++){                   		// PRINTA OS VALORES DA MATRIZ NAS POSICOES CORRESPONDENTES
            posx = 13;
            for (y = 0; y < TAM3; y++){
                gotoxy(posx,posy);                 			// COLUNA / LINHA
                    switch(matrizJogo[x][y]){
                        case 2:
                            cor(240);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("    2    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 4:
                            cor(128);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("    4    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 8:
                            cor(16);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("    8    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 16:
                            cor(48);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   16    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 32:
                            cor(160);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   32    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 64:
                            cor(32);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   64    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 128:
                            cor(224);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   128   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 256:
                            cor(96);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   256   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 512:
                            cor(192);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   512   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 1024:
                            cor(64);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("  1024   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        default:
                            cor(15);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("         ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                    }
                posx += 11;
            }
            posy += 5;
        }
	} else if (tam == 4){									// 4X4
		posy = 19;
        for (x = 0; x < tam; x++){                   		// PRINTA OS VALORES DA MATRIZ NAS POSICOES CORRESPONDENTES
            posx = 8;
            for (y = 0; y < tam; y++){
                gotoxy(posx,posy);                 			// COLUNA / LINHA
                    gotoxy(posx,posy);                 			// COLUNA / LINHA
                    switch(matrizJogo[x][y]){
                        case 2:
                            cor(240);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("    2    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 4:
                            cor(128);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("    4    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 8:
                            cor(16);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("    8    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 16:
                            cor(48);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   16    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 32:
                            cor(160);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   32    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 64:
                            cor(32);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   64    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 128:
                            cor(224);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   128   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 256:
                            cor(96);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   256   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 512:
                            cor(192);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   512   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 1024:
                            cor(64);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("  1024   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 2048:
                            cor(208);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("  2048   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 4096:
                            cor(80);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("  4096   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        default:
                            cor(15);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("         ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                    }
                posx += 11;
            }
            posy += 5;
    	}
	} else if (tam == 5){									// 5X5
		posy = 17;
        for (x = 0; x < TAM5; x++){                   		// PRINTA OS VALORES DA MATRIZ NAS POSICOES CORRESPONDENTES
            posx = 2;
            for (y = 0; y < TAM5; y++){
                gotoxy(posx,posy);                 			// COLUNA / LINHA
                    switch(matrizJogo[x][y]){
                        case 2:
                            cor(240);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("    2    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 4:
                            cor(128);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("    4    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 8:
                            cor(16);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("    8    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 16:
                            cor(48);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   16    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 32:
                            cor(160);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   32    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 64:
                            cor(32);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   64    ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 128:
                            cor(224);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   128   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 256:
                            cor(96);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   256   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 512:
                            cor(192);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("   512   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 1024:
                            cor(64);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("  1024   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 2048:
                            cor(208);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("  2048   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 4096:
                            cor(80);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("  4096   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        case 8192:
                            cor(80);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("  8192   ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
                        default:
                            cor(15);
                            printf("         ");
                            gotoxy(posx, posy + 1);
                            printf("         ");
                            gotoxy(posx, posy + 2);
                            printf("         ");
                            gotoxy(posx, posy + 3);
                            printf("         ");
                            cor(7);
                            break;
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

perdeu(int tam){
    int vazios = 0;
    vazios = tam * tam;
    for(int x = 0; x < tam; x++){
        for (int y = 0; y < tam; y++){
            if (matrizJogo[x][y] != 0){
                vazios--;
            }
        }
    }
    if ( vazios != 0 ) {
        return 0;
    } else if (vazios == 0) {
        for(int x = 0; x < tam; x++) {
            for (int y = 0; y < tam; y++) {
                if (matrizJogo[x][y] == matrizJogo[x][y - 1] || matrizJogo[x][y] == matrizJogo[x][y + 1]) {
                    return 0;
                } else if (matrizJogo[x][y] == matrizJogo[x - 1][y] || matrizJogo[x][y] == matrizJogo[x + 1][y]) {
                    return 0;
                }
            }
        }
        return 1;
    }
}

cor(int cor){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}
