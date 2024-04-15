#include "cad_produtos.h"


struct Nop* pesq_prod(Lista_prod lista, char* nome_prod){
    struct Nop* pro_it;
     for (pro_it = lista.pinicio; pro_it != NULL; pro_it = pro_it->prox) {
        if (strcasecmp(pro_it->Dados.nome_prod, nome_prod) == 0) {
            return pro_it;
        }
    }
    return NULL; 
}

void ad_produto(Produto **produto, Lista_prod* pblista, Lista* plista){
    printf("--------------------- Adiocionar  Produto ------------------------\n");
    printf(" Ola :-) Para qual papelaria gostaria de adicionar o seu produto: \n");
    printf("------------------------------------------------------------------\n");
    char nome_papelaria[50];
    scanf(" %[^\n]", nome_papelaria);
    No* pi = pesquisar(*plista, nome_papelaria);
    if (pi == NULL) {
    printf("--------------------- Adiocionar  Produto ---------------------------\n");
    printf(" Ops :-( | Parece que a papelaria ainda nao foi cadastrada. Por favor,\n cadastre a papelaria primeiro.\n");
    printf("---------------------------------------------------------------------\n");
        papelaria dadopapelaria; 
        cad_pap(&dadopapelaria, plista);
        inserir_lista(plista, dadopapelaria);
        pi = pesquisar(*plista, nome_papelaria);
    }

    printf("Informe o nome do produto: \n");
    scanf(" %[^\n]", (*produto)->nome_prod);
    while((getchar()) != '\n');

    printf("Insira o tipo do produto: \n"); 
    scanf(" %[^\n]", (*produto)->tip_prod);
    printf("Insira um preco para o produto: \n");
    scanf("%f",&(*produto)->preco);
    printf("Informe a quantidade desse produto: \n");
    scanf("%d", &(*produto)->qtd);

    pi->dado.produtos = realloc(pi->dado.produtos, (pi->dado.num_produtos + 1) * sizeof(Produto));
    pi->dado.produtos[pi->dado.num_produtos] = **produto;
    pi->dado.num_produtos++;
}

void insere_prod(Lista_prod  *pblista, Produto Dados){
    struct Nop *novo = (struct Nop*) malloc(sizeof(struct Nop));
    if (novo == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    novo-> Dados = Dados;
    novo-> prox = NULL;
    if (pblista->pinicio == NULL){
        pblista->pinicio = novo;
    } else {
        struct Nop* pro_it;
        for(pro_it = pblista->pinicio; pro_it->prox != NULL; pro_it = pro_it ->prox);
        pro_it->prox = novo;
    }
}

void mostrar_prod(Lista* plista){
    int num_nos = 0;
    for (No* temp = plista->inicio; temp != NULL; temp = temp->proximo) {
        num_nos++;
    }
    for (No* atual = plista->inicio; num_nos > 0; atual = atual->proximo, num_nos--) {
        printf("Papelaria: %s|", atual->dado.nome);
        for (int i = 0; i < atual->dado.num_produtos; i++) {
            printf("Produto: %s| Tipo: %s| Preco: %.2f|, Quantidade: %d|\n",atual->dado.produtos[i].nome_prod,atual->dado.produtos[i].tip_prod, atual->dado.produtos[i].preco,atual->dado.produtos[i].qtd);
        }
    }
}

void remover_produto(Lista* plista, char* nome_papelaria, char* nome_prod){
    No* pi = pesquisar(*plista, nome_papelaria);
    if (pi == NULL ){
        printf("Paprlaroa nao existe \n");
        exit(1);
    }
    for (int i = 0; i < pi->dado.num_produtos; i++) {
        if (strcmp(pi->dado.produtos[i].nome_prod, nome_prod) == 0) {
            for (int j = i; j < pi->dado.num_produtos - 1; j++) {
                pi->dado.produtos[j] = pi->dado.produtos[j + 1];
            }
            pi->dado.num_produtos--;
            pi->dado.produtos = realloc(pi->dado.produtos, pi->dado.num_produtos * sizeof(Produto));
            printf("Produto removido com sucesso.\n");
            return;
        }
    }
    printf("O produto nao foi encontrado na papelaria.\n");
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

void venda_prod(){
   
}

