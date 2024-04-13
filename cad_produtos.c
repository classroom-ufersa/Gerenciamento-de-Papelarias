#include "cad_produtos.h"

typedef struct Produto produto; 

void busca_prod(Produto *produto, int *qtdpod, char nomepod){

}

void ad_produto(Produto **produto, int *qtdpod){
    *produto = realloc(*produto, (*qtdpod + 1) *sizeof(produto));
        if(*produto == NULL){
            printf("erro alocar memoria \n");
            exit(1);
        }
    printf("Informe o nome do produto: \n");
    scanf(" %[^\n]", (*produto)[*qtdpod].nome_prod);
    printf("Insira o tipo do produto: \n");
    scanf(" %[^\n]", (*produto)[*qtdpod].tip_prod);
    printf("Insira um preco para o produto: \n");
    scanf("%f", (*produto)[*qtdpod].preco);
    printf("Informe a quantidade desse produto: \n");
    scanf("%d", (*produto)[*qtdpod].qtd);

}

void remover_produto(Produto *produto, int *qtdprod, char nomeprod[]) {
    int i, j;
    for (i = 0; i < *qtdprod; i++) {
        if (strcmp(produto[i].nome_prod, nomeprod) == 0) {
            for (j = i; j < *qtdprod - 1; j++) {
                strcpy(produto[j].nome_prod, produto[j + 1].nome_prod);
                strcpy(produto[j].tip_prod, produto[j + 1].tip_prod);
                produto[j].preco = produto[j + 1].preco;
                produto[j].qtd = produto[j + 1].qtd;
            }
            (*qtdprod)--;
            break;
        }
    }
    FILE *arquivo = fopen("produto.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    for (i = 0; i < *qtdprod; i++) {
        fprintf(arquivo, "Nome: %s\n", produto[i].nome_prod);
        fprintf(arquivo, "Tipo: %s\n", produto[i].tip_prod);
        fprintf(arquivo, "Preco: %.2f\n", produto[i].preco);
        fprintf(arquivo, "Quantidade: %d\n", produto[i].qtd);
    }
    fclose(arquivo);
    printf("Produto removido com sucesso!\n");
}

void venda_prod(){
   
}
