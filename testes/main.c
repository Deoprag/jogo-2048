#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char apelido[20];
    char senha[16];
    char telefone[11];
} Cadastro;

int tam = 100;
Cadastro lista[100];
int quant = 0;

int cadastroPessoa(){
    if(quant < tam){
        Cadastro p;
        scanf("%*c");
        printf("Digite um apelido: ");
        fgets(p.apelido, 20, stdin);
        printf("Digite uma senha: ");
        fgets(p.senha, 16, stdin);
        printf("Digite seu telefone: ");
        fgets(p.telefone, 11, stdin);
        lista[quant] = p;
        quant++;
        return 1;
    } else {
        printf("ERRO: Não existe mais espaço para cadastro de usuários\n\n");
        return 0;
    }
}

int loginPessoa(){
    Cadastro login;
    char apver[20];
    char pwver[16];
    printf("\nDigite seu apelido: \n");
    fgets(apver, 20, stdin);
    printf("\nDigite sua senha: \n");
    fgets(pwver, 16, stdin);
    if (apver == login.apelido && pwver == login.senha)
    {
        printf("Logado com sucesso!!");
    } else {
        printf("Voce digitou algum dado incorreto...");
    }
    

}

void imprimirVetor(){
    int i;
    for(i = 0; i < quant; i++){
        printf("\n--------------------------------------------\n");
        printf("\nNome: %s\n", lista[i].apelido);
        printf("\nSenha: %s\n", lista[i].senha);
        printf("\nTelefone: %s\n", lista[i].telefone);
    }
}

int main(){
    int op;
    do
    {
        printf("\n1- Cadastrar\n2- Consultar\n3- Login\n0- Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf ("\nTchauuuu...\n\n");
            break;
        case 1:
            cadastroPessoa();
            break;
        case 2:
            imprimirVetor();
            break;
        case 3:
            loginPessoa();
            break;
        default:
            printf("\nOpcao invalida. Tente novamente\n\n");
            break;
        }
    } while (op != 0);
    
}