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
void menu();
int senha();

typedef struct{
    char apelido[20];
    char senha[20];
    char celular[15];
    int numCadastro;
    int ativo;
} Cadastro;
Cadastro usuario[MAX_CADASTROS];

int cads = 0;
    
int main(){
    SetConsoleTitle("ADMINISTRACAO DE CADASTROS");
    if (senha() == 0){
    	menu();
    }
}

menu(){
	system("cls");
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
    printf("|          3- Pesquisar Cadastro        |\n");
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
            break;
        case 29:
            exit(1);
            break;
        default:

            break;
    }
}

senha(){
    int i, acesso = 0;
    char c;
    char chave[15] = "senhacadastros";
    char senha[15];
    do{
	    printf("Digite a senha de acesso: ");
	    i = 0;
        fflush(stdin);
        do{
            c = getch();
            if( isalnum(c) != 0 ){
                if (i < 14){
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

        if (strcmp(senha, chave) == 0){
            acesso = 1;
            return 0;
        } else {
            printf("\n[ENTER] Senha incorreta. Tente novamente!");
            getch();
        }
        system("cls");
    } while(acesso != 1);
}

cadastrar(){
    int op, i, continua = 0;
    char apelido[16];
    char senha[16];
    char celular[11];
    char c;

    FILE *cadastros;
    FILE *leitura;
    Cadastro usuario;

    printf("-----------------------------------------\n");
    printf("--------------- CADASTRAR ---------------\n");
    printf("-----------------------------------------\n");

    cadastros = fopen("Cadastros.txt", "ab");
    if (cadastros == NULL){
        printf("Nao foi possivel abrir o arquivo.");
    } else {
        // ------------------------------------------------------------ APELIDO	
        do {
        	continua = 0;
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
        	
        	leitura = fopen("Cadastros.txt", "rb");
            while ( fread(&usuario, sizeof(Cadastro), 1, leitura) == 1 ){
	            if (strcmp(apelido, usuario.apelido) == 0){
	            	printf("\nAlguem ja escolheu esse apelido. Escolha outro e tente novamente!");
	            	continua = 1;
				}
	        }
	        fclose(leitura);
        } while (continua == 1);
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

        strcpy(usuario.apelido, apelido);
        strcpy(usuario.senha, senha);
        strcpy(usuario.celular, celular);
        usuario.ativo = 1;

        fwrite(&usuario, sizeof(Cadastro), 1, cadastros);

        printf("\n\n          Cadastro realizado com sucesso!\n        Aperte qualquer tecla para voltar\n");
        getch();
    fclose(cadastros);
    }   
    system("cls");
    menu();
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
    menu();
}

consultar(){
	char consulta[16];
    int op, i, encontrado = 0;
    char c;
    
    FILE *cadastros;
    Cadastro usuario;

    system("cls");
    printf("-----------------------------------------\n");
    printf("----------- CONSULTAR CADASTRO ----------\n");
    printf("-----------------------------------------\n");

	do{
		cadastros = fopen("Cadastros.TXT", "rb");
    	if (cadastros == NULL){
        	printf("|  Não foi possivel listar os usuarios  |\n");
		} else {
    
    		consulta[0] = '\0';
			i = encontrado = 0;
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
        	while ( fread(&usuario, sizeof(Cadastro), 1, cadastros) == 1 ){
            	if (strcmp(consulta, usuario.apelido) == 0){
            		printf("\n---------- USUARIO ENCONTRADO -----------\n");
                    printf("\tApelido:  %s\n", usuario.apelido);
                    printf("\tSenha:    %s\n", usuario.senha);
                    printf("\tCelular:  %s", usuario.celular);
                    printf("-----------------------------------------\n");
                    encontrado = 1;
				}
        	}
	        if (encontrado != 1){
	            printf("\nUsuario nao encontrado.\n");
	        }
	        printf("\n[1] Consultar novamente\t[0] Sair\n");
	        op = getch();
		}
		fclose(cadastros);
	} while (op == 49);
    system("cls");
    menu();
}

remover(){
    char remover[16];
    int op, i, encontrado = 0;
    char c;

    FILE *cadastros, *temp;
    Cadastro usuario;

    system("cls");
    printf("-----------------------------------------\n");
    printf("------------ EXCLUIR CADASTRO -----------\n");
    printf("-----------------------------------------\n");

    do{
        cadastros = fopen("Cadastros.TXT", "r+b");
        temp = fopen("Temp.TXT", "wb");

        remover[0] = '\0';
        i = op = encontrado = 0;
        printf("\nDigite o apelido do usuario a ser excluido: ");
        fflush(stdin);
        do{
            c = getch();
            if( isalnum(c) != 0 ){
                if (i < 16){
                    remover[i] = c;
                    i++;
                    putch(c);
                }
            } else if (c == 8 && i){

                remover[i] = '\0';
                i--;
                printf("\b \b");
            }
        } while (c != 13);

        remover[i] = '\0';

        while ( fread(&usuario, sizeof(Cadastro), 1, cadastros) == 1 ){
            if (strcmp(remover, usuario.apelido) == 0){
            	printf("\nUsuario encontrado e excluido com sucesso");
                encontrado = 1;
            } else if (strcmp(remover, usuario.apelido) != 0){
                fwrite(&usuario, sizeof(Cadastro), 1, temp);
            }
        }
        if (encontrado != 1){
            printf("\nUsuario nao encontrado.\n");
        }

        fclose(cadastros);
        fclose(temp);

        remove("Cadastros.TXT");
        rename("Temp.TXT", "Cadastros.TXT");

        printf("\nDeseja pesquisar outro usuario?\n[1] Sim\t[0] Nao\n");
	} while (op == 49);

    getch();
    system("cls");
    menu();
}



