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
int tijolo, inicial, opcao, tam = 0;
char apelido[20], senha[20], confSenha[20], celular[15];

// DECLARACAO DE FUNCOES
int inicio();
int login();
int cadastro();
int cadastroSucesso();
int cadastroFalhou();
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


//  PRINCIPAL
int main ()
{
    system("color 0F");
    inicio();
}

//  SECUNDARIAS

inicio(){                                                                                           // TELA INICIAL

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             [1] INICIAR SESSAO                             %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                              [2] NOVO JOGADOR                              %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             [3]  CONFIGURACOES                             %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                             [ESC] SAIR DO JOGO                             %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    do
    {
        opcao = getch();

        if (opcao == 27){
            exit(0);
        } else if (opcao == 49){
            system("cls");
            login();
            opcao = 0;
        } else if (opcao == 50){
            system("cls");
            cadastro();
            opcao = 0;
        } else if (opcao == 51){
            system("cls");
            configuracoes();
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

    tijolos();

    tam = 0;
    gotoxy(30,24);
    fflush(stdin);
    do
    {   
        apelido[tam] = getch();          
        if (apelido[tam] == 0x08 && tam > 0){       // APAGAR
            printf("\b \b"); 
            apelido[tam] = 0x00;
            tam--;
        } else if (apelido[tam] == 13){             // ENTER
            apelido[tam] = 0x00;
            break;
        } else if (apelido[tam] != 0x08){
            putchar(apelido[tam]);
            tam++;              
        }

    } while(tam < 16);

    tam = 0;
    gotoxy(30,30);
    fflush(stdin);
    do
    {   
        senha[tam] = getch();          
        if(senha[tam] == 0x08 && tam > 0){          // APAGAR
            printf("\b \b"); 
            senha[tam] = 0x00;
            tam--;
        } else if (senha[tam] == 13){               // ENTER
            senha[tam] = 0x00;
            break;
        } else if (senha[tam] != 0x08){
            putchar('*');
            tam++;
        }
    } while(tam < 16);

    gotoxy(0,35);
    printf("");
    printf("%c%c                     [ESC] VOLTAR     [ENTER] CONFIRMAR                     %c%c\n", 219, 219, 219, 219);
    
    do
    {
        opcao = getch();
        if (opcao == 27){
            system("cls");
            inicio();
            opcao = 0;
        } else if (opcao == 13){
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
    printf("%c%c                  SENHA:   %c                    %c                           %c%c\n", 219, 219, 179, 179, 219, 219);
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
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    tam = 0;
    gotoxy(30,22);
    fflush(stdin);
    do
    {   
        apelido[tam] = getch();          
        if (apelido[tam] == 0x08 && tam > 0){       // APAGAR
            printf("\b \b"); 
            apelido[tam] = 0x00;
            tam--;
        } else if (apelido[tam] == 13){             // ENTER
            apelido[tam] = 0x00;
            break;
        } else if (apelido[tam] != 0x08){
            putchar(apelido[tam]);
            tam++;              
        }

    } while(tam < 16);

    tam = 0;
    gotoxy(30,26);
    fflush(stdin);
    do
    {   
        senha[tam] = getch();          
        if(senha[tam] == 0x08 && tam > 0){          // APAGAR
            printf("\b \b"); 
            senha[tam] = 0x00;
            tam--;
        } else if (senha[tam] == 13){               // ENTER
            senha[tam] = 0x00;
            break;
        } else if (senha[tam] != 0x08){
            putchar('*');
            tam++;
        }
    } while(tam < 16);

    tam = 0;
    gotoxy(30,30);
    fflush(stdin);
    do
    {   
        confSenha[tam] = getch();          
        if(confSenha[tam] == 0x08 && tam > 0){      // APAGAR
            printf("\b \b"); 
            confSenha[tam] = 0x00;
            tam--;

        } else if (confSenha[tam] == 13){           // ENTER
            confSenha[tam] = 0x00;
            break;
        } else if (confSenha[tam] != 0x08){
            putchar('*');
            tam++;
        }
    } while(tam < 16);

    tam = 0;
    gotoxy(30,34);
    fflush(stdin);
    do
    {   
        celular[tam] = getch();          
        if (celular[tam] == 0x08 && tam > 0){       // APAGAR
            printf("\b \b"); 
            celular[tam] = 0x00;
            tam--;
        } else if (celular[tam] == 13){              // ENTER
            celular[tam] = 0x00;
            break;
        } else if (celular[tam] != 0x08){
            putchar(celular[tam]);
            tam++;
        }

    } while(tam < 11);

    gotoxy(0,39);
    printf("");
    printf("%c%c                     [ESC] VOLTAR     [ENTER] CONFIRMAR                     %c%c\n", 219, 219, 219, 219);
    
    do
    {
        opcao = getch();
        if (opcao == 27){
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
    printf("%c%c                     APERTE [ENTER] PARA INICIAR SESSAO                     %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                   OU                                       %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                  APERTE [ESC] PARA IR PARA A TELA INICIAL                  %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    
    tijolos();

    do
    {
        opcao = getch();
        if (opcao == 27){
            system("cls");
            inicio();
            opcao = 0;
        } else if (opcao == 13){
            system("cls");
            login();
            opcao = 0;
        }

    } while (opcao != 0);
}

cadastroFalhou(){

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

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
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
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       [ENTER] SELECIONAR DIFICULDADE                       %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [D]   PROXIMA DIFICULDADE                          %c%c\n", 219, 219, 219, 219);
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
            system("cls");
            selecao();
        } else if (opcao == 13){
            system("cls");
            jogar5x5();
            opcao = 0;
        } else if ((opcao == 100) || (opcao == 68)){
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
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       [ENTER] SELECIONAR DIFICULDADE                       %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [D]   PROXIMA DIFICULDADE                          %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [A]   DIFICULDADE ANTERIOR                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
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
            system("cls");
            selecao();
        } else if (opcao == 13){
            system("cls");
            jogar4x4();
            opcao = 0;
        } else if ((opcao == 100) || (opcao == 68)){
            system("cls");
            dificuldadeDificil();
            opcao = 0;
        } else if ((opcao == 97) || (opcao == 65)){
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
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       [ENTER] SELECIONAR DIFICULDADE                       %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [D]   PROXIMA DIFICULDADE                          %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [A]   DIFICULDADE ANTERIOR                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
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
            system("cls");
            selecao();
        } else if (opcao == 13){
            system("cls");
            jogar4x4();
            opcao = 0;
        } else if ((opcao == 100) || (opcao == 68)){
            system("cls");
            dificuldadeHardcore();
            opcao = 0;
        } else if ((opcao == 97) || (opcao == 65)){
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
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                       [ENTER] SELECIONAR DIFICULDADE                       %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                         [A]   DIFICULDADE ANTERIOR                         %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
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
            system("cls");
            selecao();
        } else if (opcao == 13){
            system("cls");
            jogar4x4();
            opcao = 0;
        } else if ((opcao == 97) || (opcao == 65)){
            system("cls");
            dificuldadeDificil();
            opcao = 0;
        }
    } while (opcao != 0);
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
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c (O) RANKING         %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c (ENTER) SAIR        %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c   16    %c%c    4    %c%c    2    %c%c         %c%c         %c%c  UNIFACEAR - 2022   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c         %c%c                     %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();
    
    do{
        opcao = getch();
        if (opcao == 13){
            system("cls");
            selecao();
        }
    } while (opcao != 13);
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
    printf("%c%c   16    %c%c         %c%c         %c%c         %c%c (O) RANKING   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c         %c%c         %c%c         %c%c         %c%c (ENTER SAIR   %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    
    tijolos();

    do{
        opcao = getch();
        if (opcao == 13){
            system("cls");
            selecao();
        }
    } while (opcao != 13);
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
    printf("%c%c\t    UNIFACEAR - 2022           %c%c (O) RANKING        %c%c\n", 219, 219, 219, 219, 219, 219);
    printf("%c%c\t                               %c%c (ENTER) SAIR       %c%c\n", 219, 219, 219, 219, 219, 219);
    
    tijolos();

    do{
        opcao = getch();
        if (opcao == 13){
            system("cls");
            selecao();
        }
    } while (opcao != 13);
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
        opcao = getch();
        if (opcao == 48){
            system("cls");
            selecaoRanking();
            opcao = 0;
        } else if ((opcao == 49)){
            system("cls");
            rankingPontuacaoDif();
            opcao = 0;
        } else if ((opcao == 50)){
            system("cls");
            rankingTempoDif();
            opcao = 0;
        }
    } while (opcao != 0);
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
        opcao = getch();
        if (opcao == 48){
            system("cls");
            selecao();
            opcao = 0;
        } else if ((opcao > 48) && (opcao < 52)){
            system("cls");
            rankingTempo();
            opcao = 0;
        }
    } while (opcao != 0);
}

rankingPontuacao(){

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                            RANKING DE PONTUACAO                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                MODO: XXXXXX                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                               [ENTER] VOLTAR                               %c%c\n", 219, 219, 219, 219);
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

    do{
        opcao = getch();
        if (opcao == 13){
            system("cls");
            selecao();
        }
    } while (opcao != 13);
    
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
        opcao = getch();
        if (opcao == 48){
            system("cls");
            selecaoRanking();
            opcao = 0;
        } else if ((opcao > 48) && (opcao < 52)){
            system("cls");
            rankingTempo();
            opcao = 0;
        }
    } while (opcao != 0);
}

rankingTempo(){

    logo();

    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);
    printf("%c%c                              RANKING DE TEMPO                              %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                MODO: XXXXXX                                %c%c\n", 219, 219, 219, 219);
    printf("%c%c                               [ENTER] VOLTAR                               %c%c\n", 219, 219, 219, 219);
    printf("%c%c                                                                            %c%c\n", 219, 219, 219, 219);

    tijolos();

    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c        COLOCACAO        %c%c       JOGADOR      %c%c           TEMPO           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);

    tijolos();

    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c      1 %c   LUGAR        %c%c      Augusto01     %c%c    [  52 MOVIMENTOS  ]    %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c      2 %c   LUGAR        %c%c    PedroTeste123   %c%c    [  59 MOVIMENTOS  ]    %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c      3 %c   LUGAR        %c%c    TerceiroLugar   %c%c    [  61 MOVIMENTOS  ]    %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c      4 %c   LUGAR        %c%c    PedroTeste002   %c%c    [  64 MOVIMENTOS  ]    %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c      5 %c   LUGAR        %c%c     QuintoLugar    %c%c    [  70 MOVIMENTOS  ]    %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    printf("%c%c      24 %c  LUGAR        %c%c   VigesimoQuarto   %c%c    [  103 MOVIMENTOS ]    %c%c\n", 219, 219, 167, 219, 219, 219, 219, 219, 219);
    printf("%c%c                         %c%c                    %c%c                           %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219);
    
    tijolos();

    do{
        opcao = getch();
        if (opcao == 13){
            system("cls");
            selecao();
        }
    } while (opcao != 13);
    
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
    for (tijolo = 0; tijolo != 80; tijolo ++){
        printf("%c", 219);
    }
    printf("\n");
}
