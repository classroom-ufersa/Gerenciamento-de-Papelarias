#include "cad_produtos.h"

typedef struct produto{
char nome_prod [70];
char tip_prod [70];
float preco;
int quant;
}Produto;

void busca_produto(){
    printf("Qual produto esta procurando: \n");

    /*
    Aviso de tratativa caso o produto não exista na lista
    ideia: perguntar se o usuario deseja cadastrar o produto

    printf("O produto buscado não esta cadastrado! \n");
    */
}

void adiciona_produto(){
    printf("Insira o nome do produto: \n");
    scanf(" %[^\n]",);
    printf("Informe o tipo do produto: \n");
    scanf(" %[^\n]",);
    printf("Informe o preco do produto: \n");
    scanf(" %f",);
    printf("Informe a quantidade desse produto: \n");
    scanf("%d",);
}

void remover_produto(){

}

void comprar_produtos(){
    printf("Oque deseja comprar: \n");
    scanf("%d",);
}