#include "cad_produtos.h"

typedef struct Produto produto; 

struct Nop* pesq_prod(Lista_prod lista, char* nome_prod){
    struct Nop* pro_it;
     for (pro_it = lista.pinicio; pro_it != NULL; pro_it = pro_it->prox) {
        if (strcasecmp(pro_it->Dados.nome_prod, nome_prod) == 0) {
            return pro_it;
        }
    }
    return NULL; 
}

void ad_produto(Produto **produto, int *qtdpod, Lista_prod* pblista){
    *produto = realloc(*produto, (*qtdpod + 1) *sizeof(Produto));
    if(*produto == NULL){
        printf("erro alocar memoria \n");
        exit(1);
    }
    do {
    printf("Informe o nome do produto: \n");
    scanf(" %[^\n]", (*produto)[*qtdpod].nome_prod);
        while((getchar()) != '\n');
        if(pesq_prod(*pblista, (*produto)->nome_prod) != NULL){
            system ("cls");
            printf("Esse produto ja foi cadastrado %s por favor, informe um outro produto\n", (*produto)->nome_prod);
        }
    }while(pesq_prod(*pblista, (*produto)->nome_prod) !=NULL);
    printf("Insira o tipo do produto: \n");
    scanf(" %[^\n]", (*produto)[*qtdpod].tip_prod);
    printf("Insira um preco para o produto: \n");
    scanf("%f", (*produto)[*qtdpod].preco);
    printf("Informe a quantidade desse produto: \n");
    scanf("%d", (*produto)[*qtdpod].qtd);
}

void salva_prod(Lista_prod *pblista) {
    FILE *arquivo = fopen ("produto.txt"," w+");
    if (arquivo==NULL){
    printf("Erro ao abri o arquivo.\n");
    exit(1);
    }
struct  Nop *pro_it; 
for (pro_it = pblista->pinicio; pro_it != NULL; pro_it = pro_it -> prox){
    fprintf(arquivo,"Produto: %s \n Tipo: %s \n Preco: %f  \n Quantidade: %d", pro_it->Dados.nome_prod, pro_it->Dados.tip_prod, pro_it->Dados.preco, pro_it->Dados.qtd);

}
fclose(arquivo);
}

void insere_prod(Lista_prod  *pblista, Produto Dados){
    struct Nop *novo = (struct Nop*) malloc(sizeof(struct Nop));
if (novo == NULL){
    printf("Erro ao alocar memoria\n");
    exit(1);
}
novo-> Dados = Dados;
novo-> prox = pblista->pinicio;
pblista->pinicio = novo;
salva_prod(pblista);
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
        fprintf(arquivo, "nome: %s\n", produto[i].nome_prod);
        fprintf(arquivo, "Tipo: %s\n", produto[i].tip_prod);
        fprintf(arquivo, "Preco: %.2f\n", produto[i].preco);
        fprintf(arquivo, "Quantidade: %d\n", produto[i].qtd);
    }
    fclose(arquivo);
    printf("Produto removido com sucesso!\n");
}

void venda_prod(){
   
}

