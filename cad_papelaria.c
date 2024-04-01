#include "cad_papelaria.h"

typedef struct papelaria Papelaria;

void cad_pap( Papelaria **papelaria, int *quant) {
    *papelaria = realloc(*papelaria, (*quant + 1) * sizeof(papelaria));
    if (*papelaria == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    printf("Insira o nome da nova papelaria: \n");
    scanf(" %[^\n]", (*papelaria)[*quant].nome);
    printf("Insira o endereco da papelaria: \n");
    scanf(" %[^\n]", (*papelaria)[*quant].local);
    printf("Informe os produtos presentes nessa papelaria: \n");
    scanf(" %[^\n]", (*papelaria)[*quant].produtos);
     (*quant)++;
}

    void rem_pap(Papelaria *papelaria, int *quant, char *nomePap) {
    int i, j;
    for (i = 0; i < *quant; i++) {
        if (strcmp(papelaria[i].nome, nomePap) == 0) {
           
            for (j = i; j < *quant - 1; j++) {
                strcpy(papelaria[j].nome, papelaria[j + 1].nome);
                strcpy(papelaria[j].local, papelaria[j + 1].local);
                strcpy(papelaria[j].produtos, papelaria[j + 1].produtos);
            }
            (*quant)--;
            break;
        }
    }
    FILE *arquivo = fopen("papelarias.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    for (i = 0; i < *quant; i++) {
        fprintf(arquivo, "Nome: %s | Local: %s | Produtos: %s \n", papelaria[i].nome, papelaria[i].local, papelaria[i].produtos);
    }
    fclose(arquivo);

    printf("Papelaria %s removida com sucesso.\n", nomePap);
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
