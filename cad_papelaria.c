#include "cad_papelaria.h"

typedef struct papelaria{
char nome [50];
char local [100];
char produtos [100];
}Papelaria;

void cad_papelaria(){
    printf("Insira o nome da nova papelaria: \n");
    scanf(" %[^\n]",);
    printf("Insira o endereco da papelaria: \n");
    scanf(" %[^\n]",);
    printf("Informe os produtos presentes nessa papelaria: \n");
    scanf(" %[^\n]",);
}

void rem_papelaria(){
    printf("Qual papelaria deseja remover: \n");
    scanf("",);
}

void listar_pap(){

}