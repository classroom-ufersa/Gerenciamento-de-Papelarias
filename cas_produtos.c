#include "cad_produtos.h"

typedef struct Produto produto; 

void busca_prod(Produto *produto, int *qtdpod, char nomepod){

    /*
    Aviso de tratativa caso o produto não exista na lista
    ideia: perguntar se o usuario deseja cadastrar o produto

    printf("O produto buscado não esta cadastrado! \n");
    */
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

void remover_produto(Produto *produto, int *qtdprod, char nomeprod){
int i, j;
    for(i = 0; i < *qtdprod; i++){
        if(strcmp(produto[i].nome_prod, nomeprod) == 0){
            for(j = i; j < *qtdprod - 1; j++){
                strcpy(produto[j].nome_prod, produto[j + 1].nome_prod);
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
    fprintf(arquivo, "Nome: %s", produto[i].nome_prod);
    }
    fclose(arquivo);
    printf("Produto removido com exito! \n");
}

/*
Aviso de trataiva: para checar se o produto foi realmente removido
Ideia: imprimir a papelaria em que o produto foi removido para checar a ação
*/

void venda_prod(){
    /*
    Não é necessario utilizar o saldo para venda do produto apenas diminuir
    o numero de produtos em cada papelaria

    a função venda deve ser implementada na opção repor estoque onde estara
    no menu das papelarias

    procurar ajuda sobre o algoritmo de busca que sera implementado nas funções
    */
}

    
    
 
