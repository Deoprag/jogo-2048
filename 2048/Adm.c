#include <stdio.h>
#include <stdlib.h>
#include <windows.h>    // SetConsoleCursorPosition
#include <string.h>     // funçoes str
#include <conio.h>      // getch()
#include <ctype.h>      // isdigit, isalpha, etc.

#define MAX_CADASTROS 30

void cadastrar();
void listar();

typedef struct{
    char apelido[20];
    char senha[20];
    char celular[15];
    int ativo;
} Cadastro;
Cadastro cadastros[MAX_CADASTROS];

int main(){
    SetConsoleTitle("ADMINISTRACAO DE CADASTROS");

    int opcao = 0;

    printf("-----------------------------------------\n");
    printf("|                                       |\n");
    printf("|                                       |\n");
    printf("|          1- Realizar Cadastro         |\n");
    printf("|          2- Listar Cadastros          |\n");
    printf("|                                       |\n");
    printf("|                                       |\n");
    printf("-----------------------------------------\n");
    printf("Digite a opcao desejada: ");
    scanf("%i", &opcao);
    switch(opcao){

        case 0:
        
            break;
        case 1:
            system("cls");
            cadastrar();
            break;
        case 2:
            system("cls");
            listar();
            break;
        case 3:
        
            break;
        case 4:
        
            break;
        case 5:
        
            break;
        default:

            break;
    }

}

cadastrar(){
    char apelido[20];
    char senha[20];
    char celular[15];
    int op, cadastrados = 0;

    printf("-----------------------------------------\n");
    printf("--------------- CADASTRAR ---------------\n");
    printf("-----------------------------------------\n");
    do{

        printf("\nDigite seu apelido: ");
        scanf("%s", &apelido);
        printf("\nDigite sua senha: ");
        scanf("%s", &senha);
        printf("\nDigite seu numero de celular: ");
        scanf("%s", &celular);

        for (int i = cadastrados; i < MAX_CADASTROS; i++){
            if ( cadastros[i].ativo == 0 ) {
                strcpy(cadastros[i].apelido, apelido);
                strcpy(cadastros[i].senha, senha);
                strcpy(cadastros[i].celular, celular);
                cadastrados++;
                break;
            }
        }

        printf("\n1- Continuar\t0- Sair");
        op = getch();

    } while (op == 49);

    system("cls");
    main();
}

listar(){
    system("cls");
    printf("-----------------------------------------\n");
    printf("------------ LISTAR CADASTROS -----------\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < MAX_CADASTROS; i++){
            printf("------------ CADASTRO Num %i -------------\n", i);
            printf("\tApelido:  %s\n", cadastros[i].apelido);
            printf("\tSenha:    %s\n", cadastros[i].senha);
            printf("\tCelular:  %s\n", cadastros[i].celular);
            printf("-----------------------------------------\n");
    }
    getch();
}