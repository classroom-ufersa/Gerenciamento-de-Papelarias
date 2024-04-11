#include "cad_papelaria.h"


void cad_pap( Papelaria **papelaria) {
     *papelaria = (Papelaria*) malloc(sizeof(Papelaria));
       if (*papelaria == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    printf("Insira o nome da nova papelaria: \n");
    scanf(" %[^\n]", (*papelaria)->nome);
    while ((getchar()) != '\n');
    printf("Insira o endereco da papelaria: \n");
    scanf(  "%[^\n]", (*papelaria)->local);
    }

void inserir(Lista *plista, Papelaria dado) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));  
     if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->dado = dado;
    novo->porx = plista->inicio;
    plista->inicio = novo;
   }
  void deletar_pap (Lista *plista, char* nome){
        if (plista->inicio ==NULL){
            printf("Sem papelaria\n");
       } else if(strcmp(plista->inicio->dado.nome, nome) == 0) {
            struct No* pi = plista->inicio;
            plista->inicio = pi ->porx;
            free(pi);    
        }else if (plista->inicio->porx==NULL){
              if  (strcmp(plista->inicio->dado.nome, nome) != 0){
                printf("A papelaria nao pode ser removida\n");
            }
        }else {
            struct No * pa;
            struct No * pi;
              for (pi = plista->inicio; pi != NULL && strcmp(pi->dado.nome, nome) != 0; pi = pi->porx){
                pa = pi;
            } if (pi == NULL){
                printf(" A papelaria nao pode ser renovida\n");
            } else {
                pa->porx = pi->porx;
                free(pi);
            }         
        }
    }

void listar_pap(Lista lista){
struct No * pi;
for (pi = lista.inicio; pi  != NULL; pi = pi->porx) {
        printf("Nome: %s|\t Endereco: %s|\n", pi-> dado.nome,  pi-> dado.local);
                
}
}

struct No* pesquisar(Lista lista, char* nome){
    struct No* pi;
     for (pi = lista.inicio; pi != NULL; pi = pi->porx) {
        if (strcmp(pi->dado.nome, nome) == 0) {
            return pi;
        }
    }
    return NULL; 
}

/*
Correção: Listar papelaria tambem deve listar os produtos das papelarias

fazemos depois: tratativas para uma papelaria ou produto ja existente na lista 
*/
