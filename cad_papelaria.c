#include "cad_papelaria.h"

void cad_pap(Papelaria **papelaria, Lista *plista) {
    *papelaria = (Papelaria*) malloc(sizeof(Papelaria));
    if (*papelaria == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    do {
        printf("Insira o nome da nova papelaria: \n");
        scanf(" %[^\n]", (*papelaria)->nome);
        while ((getchar()) != '\n');
        if(pesquisar(*plista, (*papelaria)->nome) != NULL){
            system ("cls");
            printf("uma papelaria ja foi cadastrada com esse nome %s por favor, insira um nome diferente.\n", (*papelaria)->nome);
        }
    } while(pesquisar(*plista, (*papelaria)->nome) != NULL);
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
    novo->proximo = plista->inicio;
    plista->inicio = novo;
  salva_dados(plista);
   }
    
    void deletar_pap (Lista *plista, char* nome){
        if (plista->inicio ==NULL){
            printf("Sem papelaria\n");
        } else if(strcmp(plista->inicio->dado.nome, nome) == 0) {
            struct No* pi = plista->inicio;
            plista->inicio = pi ->proximo;
            free(pi);    
        }else if (plista->inicio->proximo==NULL){
            if  (strcmp(plista->inicio->dado.nome, nome) != 0){
                printf("A papelaria nao pode ser removida\n");
            }
        }else {
            struct No * pa;
            struct No * pi;
            for (pi = plista->inicio; pi != NULL && strcmp(pi->dado.nome, nome) != 0; pi = pi->proximo){
                pa = pi;
            } if (pi == NULL){
                printf(" A papelaria nao pode ser renovida\n");
            } else {
                pa->proximo = pi->proximo;
                free(pi);
            }         
        }
        atualizar_arquivo(plista);
    }

void listar_pap(Lista lista){
struct No * pi;
for (pi = lista.inicio; pi  != NULL; pi = pi->proximo) {
        printf("Nome: %s|\t Endereco: %s|\n", pi-> dado.nome,  pi-> dado.local);
        }
}

struct No* pesquisar(Lista lista, char* nome){
    struct No* pi;
     for (pi = lista.inicio; pi != NULL; pi = pi->proximo) {
        if (strcasecmp(pi->dado.nome, nome) == 0) {
            return pi;
        }
    }
    return NULL; 
}
void salva_dados(Lista *plista) {
    FILE *file = fopen ("papelaria.txt"," w+");
    if (file==NULL){
    printf("Erro ao abri o arquivo.\n");
    exit(1);
    }
struct  No *pi; 
for (pi = plista->inicio; pi != NULL; pi = pi -> proximo){
    fprintf(file,"Nomes %s |Endereco %s \n", pi->dado.nome, pi->dado.local);

}
fclose(file);

}

void carregar_dados(Lista *plista) {
    FILE *file = fopen("papelaria.txt", "r");  
    if (file == NULL){
        file = fopen("papelaria.txt", "w");  
        if (file == NULL) {
            printf("Erro ao criar o arquivo.\n");
            exit(1);
        }
    } else {
        Papelaria papelaria;
        while (fscanf(file, "Nomec %s \n", papelaria.nome) != EOF && fscanf(file, "Endereco %s \n", papelaria.local) != EOF){
             if (strlen(papelaria.nome) == 0) {
                printf("Erro: Nome da papelaria vazio no arquivo.\n");
                exit(1);
            }
            inserir(plista, papelaria);
        }
    }
    fclose(file);
}

void atualizar_arquivo(Lista *plista){
    FILE *file =fopen("papelaria.txt","w");
      if (file==NULL){
    printf("Erro ao abri o arquivo.\n");
    exit(1);
    }
    struct  No *pi; 
for (pi = plista->inicio; pi != NULL; pi = pi -> proximo){
    fprintf(file,"Nome %s Endereco %s \n", pi->dado.nome, pi->dado.local);
 }
fclose(file);

}
