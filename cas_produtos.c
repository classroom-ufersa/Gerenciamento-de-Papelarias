#include "cad_produtos.h"

typedef struct Produto produto; 

void busca_produto(){
    printf("Qual produto esta procurando: \n");

    /*
    Aviso de tratativa caso o produto não exista na lista
    ideia: perguntar se o usuario deseja cadastrar o produto

    printf("O produto buscado não esta cadastrado! \n");
    */
}

void adiciona_produto(Produto *produto){
    printf("Insira o nome do produto: \n");
    scanf(" %[^\n]", produto->nome_prod);
    printf("Informe o tipo do produto: \n");
    scanf(" %[^\n]", produto->nome_prod);
    printf("Informe o preco do produto: \n");
    scanf(" %f", &produto->preco);
    printf("Informe a quantidade desse produto: \n");
    scanf("%d", &produto->quant);
}
 
void remover_produto(){

}

void comprar_produtos(){
    printf("Oque deseja comprar: \n");
    
}