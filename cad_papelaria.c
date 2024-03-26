#include "cad_papelaria.h"


typedef struct papelaria Papelaria;


void cad_papelaria(Papelaria *papelaria, char cadastro){
    printf("Insira o nome da nova papelaria: \n");
    scanf(" %[^\n]", papelaria->nome);
    printf("Insira o endereco da papelaria: \n");
    scanf(" %[^\n]", papelaria->local);
    printf("Informe os produtos presentes nessa papelaria: \n");
    scanf(" %[^\n]", papelaria->produtos);
}

void rem_papelaria(Papelaria *papelaria, int qtdpapelaria){
    char rempapel[50];
    printf("Qual papelaria deseja remover: \n");
    scanf("%s",rempapel);
    for (int i = 0; i<qtdpapelaria; i++){
        if(strcmp(papelaria[i].nome,rempapel) == 0){
            printf("papelaria removida: %s \n", papelaria[i].nome);
        }

    }
}

void listar_pap(){

}