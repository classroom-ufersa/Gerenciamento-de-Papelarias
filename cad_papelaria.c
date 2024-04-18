#include "cad_papelaria.h"

void cad_pap(papelaria *dadopapelaria , Lista *plista){
    do {
        printf("Insira o nome da nova papelaria: \n");
        scanf(" %[^\n]", dadopapelaria->nome);
        while ((getchar()) != '\n');
        if(pesquisar(*plista, dadopapelaria->nome) != NULL){
            system ("cls");
            printf("uma papelaria ja foi cadastrada com esse nome %s por favor, insira um nome diferente.\n", dadopapelaria->nome);
        }
    } while(pesquisar(*plista, dadopapelaria->nome) != NULL);
    printf("Insira o endereco da papelaria: \n");
    scanf(  "%[^\n]",dadopapelaria->local);
        dadopapelaria->produtos = malloc(sizeof(Produto) * 1000);
    dadopapelaria->num_produtos = 0;
}

// função para inserir os dados da papelaria na lista
void inserir_lista(Lista *plista , papelaria dado){
  No *novo = (struct No*) malloc(sizeof( No));
  if (novo == NULL){
    printf("Erro ao alocar memoria\n");
    exit(1);
}
    novo-> dado = dado;
    novo->proximo = NULL;
    if (plista->inicio == NULL){
        plista->inicio = novo;
    }
    else{
      No* pi;
        for(pi = plista->inicio; pi->proximo != NULL; pi = pi ->proximo);
        pi->proximo = novo;
    }
}

// função para mostra dados da papelaria na lista
void mostrar(Lista lista){
  No* pi;
    for(pi = lista.inicio; pi != NULL; pi = pi->proximo){
    printf("Nome: %s|\t Endereco: %s|\n", pi->dado.nome, pi->dado.local);
    }
}

// função para pesquisar uma papelaria 
 No* pesquisar(Lista lista, char* nome){
  No* pi;
     for (pi = lista.inicio; pi != NULL; pi = pi->proximo) {
        if (strcasecmp(pi->dado.nome, nome) == 0) {
            return pi;
        }
    }
    return NULL;
}

// função para deletar uma papelaria em especifico
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
        printf(" A papelaria nao pode ser removida\n");
        } else {
        pa->proximo = pi->proximo;
        free(pi);
        free(pi->dado.produtos);
        }         
    }
    atualizar_arquivo(plista);
}

// função para ler os dados aquivo 
Lista ler_arquivo(){
        Lista lista;
    lista.inicio = NULL;
    FILE *file = fopen("papelaria.txt", "r");
    if (file == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return lista;
    }
    papelaria e;
    while(fread(&e, sizeof(papelaria),1, file)){
        inserir_lista(&lista,e);
    }  
    fclose(file);
    return lista;
}

// função para salva os dados no arquivo 
void salva_dados(Lista *plista){

    FILE *file = fopen("papelaria.txt", "a");
    if (file == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    for (No *atual = plista->inicio; atual != NULL; atual = atual->proximo){
        fprintf(file, "Papelaria: %s| Endereco: %s \n", atual->dado.nome, atual->dado.local);
        for (int i = 0; i < atual->dado.num_produtos; i++){
            fprintf(file, "Produto: %s| Tipo: %s| \n Preco por quantidade: %.2f| Quantidade: %d\n", atual->dado.produtos[i].nome_prod, atual->dado.produtos[i].tip_prod, atual->dado.produtos[i].preco, atual->dado.produtos[i].qtd);
        }
    }
    fclose(file);
}

// função para atualizar os dados no arquivo quando ouver auterasao
void atualizar_arquivo(Lista *plista){
    FILE *file =fopen("papelaria.txt","w");
      if (file==NULL){
    printf("Erro ao abri o arquivo.\n");
    exit(1);
    }
    int num_nos = 0;
    for (No* temp = plista->inicio; temp != NULL; temp = temp->proximo) {
        num_nos++;
     No *atual; 
for ( No *atual = plista->inicio; temp != NULL; temp = temp -> proximo){
   
    }
    fclose(file);
}
}

void obter_opcao_valida(int *opc) {
    int result;
    do {
        result = scanf("%d", opc);
        while(getchar() != '\n');  
        if(result != 1) {
            printf("Por favor, insira um numero valido.\n");
        }
    } while(result != 1);
}
