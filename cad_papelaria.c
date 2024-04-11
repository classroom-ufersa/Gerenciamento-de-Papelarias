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

void pap_salva(Papelaria *papelaria, int quant){
    FILE *arquivo = fopen("papelarias.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    for (int i = 0; i < quant; i++) {
        fprintf(arquivo, "Nome: %s | Local: %s | Produtos: %s \n ", papelaria[i].nome, papelaria[i].local, papelaria[i].produtos);
    }

    fclose(arquivo);
}

void carr_pap(Papelaria **papelaria, int *quant) {
   FILE *arquivo = fopen("papelarias.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de papelarias não encontrado.\n");
        return;
    }

    while (!feof(arquivo)) {
        *papelaria = realloc(*papelaria, (*quant + 1) * sizeof(Papelaria));
        if (*papelaria == NULL) {
            printf("Erro ao alocar memória.\n");
            exit(1);
        }
        fscanf(arquivo, "%[^|]|%[^|]|%[^\n]\n", (*papelaria)[*quant].nome, (*papelaria)[*quant].local, (*papelaria)[*quant].produtos);
        (*quant)++;
    }

    fclose(arquivo);
}

void listar_pap(Papelaria *papelaria, int quant){
     printf("\nDados fornecidos:\n");
    for (int i = 0; i < quant; i++) {
        printf("Papelaria %d\n", i + 1);
        printf(" Nome: %s \n Local: %s\n Produtos: %s\n", papelaria[i].nome, papelaria[i].local, papelaria[i].produtos);
        printf("--------------------------\n");
       

    }
}

/*
Correção: Listar papelaria tambem deve listar os produtos das papelarias

fazemos depois: tratativas para uma papelaria ou produto ja existente na lista 
*/
