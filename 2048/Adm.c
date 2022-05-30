#include <stdio.h>
#include <stdlib.h>
#include <windows.h>    // SetConsoleCursorPosition
#include <string.h>     // funçoes str
#include <conio.h>      // getch()
#include <ctype.h>      // isdigit, isalpha, etc.

#define MAX_CADASTROS 30

void cadastrar();
void listar();
void remover();
void consultar();

typedef struct{
    char apelido[20];
    char senha[20];
    char celular[15];
    int numCadastro;
    int ativo;
} Cadastro;
Cadastro usuario[MAX_CADASTROS];

int main(){
    SetConsoleTitle("ADMINISTRACAO DE CADASTROS");

    int opcao = 0;

    printf("-----------------------------------------\n");
    printf("|                                       |\n");
    printf("|      ADMINISTRACAO DE CADASTROS:      |\n");
    printf("|                                       |\n");
    printf("|                                       |\n");
    printf("|                                       |\n");
    printf("|          1- Realizar Cadastro         |\n");
    printf("|                                       |\n");
    printf("|          2- Listar Cadastros          |\n");
    printf("|                                       |\n");
    printf("|          3- Consultar Cadastro        |\n");
    printf("|                                       |\n");
    printf("|          4- Excluir Cadastro          |\n");
    printf("|                                       |\n");
    printf("|               ESC - Sair              |\n");
    printf("|                                       |\n");
    printf("-----------------------------------------\n");
    printf("Digite a opcao desejada: ");
    opcao = getch();
    switch(opcao){

        case 0:
        
            break;
        case 49:
            system("cls");
            cadastrar();
            break;
        case 50:
            system("cls");
            listar();
            break;
        case 51:
            system("cls");
            consultar();
            break;
        case 52:
            system("cls");
            remover();
            break;\
        case 29:
            exit(1);
            break;
        default:

            break;
    }

}

cadastrar(){
    int op, i, cads = 0;
    char apelido[17];
    char senha[17];
    char celular[12];
    char c;

    FILE *cadastros;

    printf("-----------------------------------------\n");
    printf("--------------- CADASTRAR ---------------\n");
    printf("-----------------------------------------\n");

    cadastros = fopen("Cadastros.txt", "ab");
    if (cadastros == NULL){
        printf("Nao foi possivel abrir o arquivo.");
    } else {
        do{
                // ------------------------------------------------------------ APELIDO
            printf("\nDigite seu apelido: ");
            i = 0;
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
                }
            } while (c != 13);
            apelido[i] = '\0';
            // VERIFICAR SE JA EXISTE
            // ------------------------------------------------------------ SENHA
            printf("\nDigite sua senha: ");
            i = 0;
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
                }
            } while (c != 13);
            senha[i] = '\0';
            // ------------------------------------------------------------ CELULAR
            printf("\nDigite seu numero de celular \n(XX)XXXXX-XXXX: ");
            i = 0;
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
            } while (c != 13);
            celular[i] = '\n';
            i++;
            celular[i] = '\0';

            if(cads < MAX_CADASTROS){
                if ( usuario[cads].ativo == 0 ) {
                    strcpy(usuario[cads].apelido, apelido);
                    strcpy(usuario[cads].senha, senha);
                    strcpy(usuario[cads].celular, celular);
                    usuario[cads].ativo = 1;
                }
            }
            fwrite(&usuario[cads], sizeof(Cadastro), 1, cadastros);
            cads++;

            printf("\n1 - Continuar | 0 - Sair\n");
            fflush(stdin);
            op = getch();

        } while (op == 49);
        fclose(cadastros);
    }   
    
    system("cls");
    main();
}

listar(){
    system("cls");
    printf("-----------------------------------------\n");
    printf("----------- DADOS CADASTRAIS ------------\n");
    printf("-----------------------------------------\n");

    FILE *cadastros;
    Cadastro usuario;

    cadastros = fopen("Cadastros.TXT", "rb");
    if (cadastros == NULL){
        printf("|  Não foi possivel listar os usuarios  |\n");
    } else {
        printf("-----------------------------------------\n");
        while ( fread(&usuario, sizeof(Cadastro), 1, cadastros) == 1 ){
            printf("Apelido: %s\n", usuario.apelido);
            printf("Senha:   %s\n", usuario.senha);
            printf("Celular: %s", usuario.celular);
            printf("-----------------------------------------\n");
        }
    }
    fclose(cadastros);
    getch();
    system("cls");
    main();
}

remover(){
    int i;
    char remover[20];
    int op = 0;

    system("cls");
    printf("-----------------------------------------\n");
    printf("------------ EXCLUIR CADASTRO -----------\n");
    printf("-----------------------------------------\n");

    do{
        int encontrado = 0;
        printf("\nDigite o apelido do usuario a ser excluido: ");
        scanf("%s", remover);
        for (i = 0; i < MAX_CADASTROS; i++){
            if(usuario[i].ativo == 1){
                if( (strcmp(usuario[i].apelido, remover) == 0) ){
                    printf("\n---------- USUARIO ENCONTRADO -----------\n");
                    printf("\tApelido:  %s\n", usuario[i].apelido);
                    printf("\tSenha:    %s\n", usuario[i].senha);
                    printf("\tCelular:  %s\n", usuario[i].celular);
                    printf("-----------------------------------------\n");
                    printf("\n1 - Excluir Cadastro | 0 - Cancelar\n");

                    op = getch();
                    encontrado = 1;
                    if (op == 49){
                        usuario[i].ativo = 0;
                        printf("\nUsuario com o apelido [%s] foi excluido com sucesso!", remover);
                        break;
                    } else if (op ==48) {
                        printf("Usuario nao excluido!");
                    } else {
                        printf("Opcao invalida!");
                    }
                }
            }
        }
        if (encontrado != 1){
            printf("Usuario nao encontrado.\n");
        }
        printf("\n1 - Tentar Novamente | 0 - Sair\n");
        op = getch();
    } while(op == 49);

    system("cls");
    main();
}

consultar(){
    int i;
    char consulta[20];
    int op = 0;
    char c;

    system("cls");
    printf("-----------------------------------------\n");
    printf("----------- CONSULTAR CADASTRO ----------\n");
    printf("-----------------------------------------\n");

    do{
        int encontrado = 0;
        printf("Escolha o metodo de pesquisa.\n[1] Apelido [2] Celular: ");
        op = getch();
        if (op == 49){
            printf("\nDigite o apelido do usuario a ser consultado: ");
            i = 0;
            fflush(stdin);
            do{
                c = getch();
                if( isalnum(c) != 0 ){
                    if (i < 16){

                        consulta[i] = c;
                        i++;
                        putch(c);
                    }
                } else if (c == 8 && i){

                    consulta[i] = '\0';
                    i--;
                    printf("\b \b");
                }
            } while (c != 13);
            consulta[i] = '\0';
            for (i = 0; i < MAX_CADASTROS; i++){
                if(usuario[i].ativo == 1){
                    if( (strcmp(usuario[i].apelido, consulta) == 0) ){
                        printf("\n---------- USUARIO ENCONTRADO -----------\n");
                        printf("\tApelido:  %s\n", usuario[i].apelido);
                        printf("\tSenha:    %s\n", usuario[i].senha);
                        printf("\tCelular:  %s\n", usuario[i].celular);
                        printf("-----------------------------------------\n");
                        encontrado = 1;
                    }
                }
            }
        } else if (op == 50){
            printf("\nDigite o celular do usuario a ser consultado: ");
            i = 0;
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
                        consulta[i] = c;
                        i++;
                        putch(c);
                        
                    }
                } else if (c == 8 && i){
                    if ( i == 1 || i == 2 || i == 7){
                        printf("\b \b");
                        consulta[i] = '\0';
                        i--;
                        printf("\b \b");
                    } else {
                        consulta[i] = '\0';
                        i--;
                        printf("\b \b");
                    }
                }
            } while (c != 13);
            consulta[i] = '\0';
            for (i = 0; i < MAX_CADASTROS; i++){
                if(usuario[i].ativo == 1){
                    if( (strcmp(usuario[i].celular, consulta) == 0) ){
                        printf("\n---------- USUARIO ENCONTRADO -----------\n");
                        printf("\tApelido:  %s\n", usuario[i].apelido);
                        printf("\tSenha:    %s\n", usuario[i].senha);
                        printf("\tCelular:  %s\n", usuario[i].celular);
                        printf("-----------------------------------------\n");
                        encontrado = 1;
                    }
                }
            }
        }
        if (encontrado != 1){
            printf("\nUsuario nao encontrado.\n");
        }
        printf("\n1 - Consultar novamente | 0 - Sair\n");
        op = getch();
    } while (op == 49);

    system("cls");
    main();
}

