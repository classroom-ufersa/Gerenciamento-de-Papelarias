#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto {
char nome_prod [70];
char tip_prod [70];
float preco;
int qtd;
}Produto;

// Função para cadastrar uma produto
void ad_produto(Produto **produto, int *qtdpod);

// Função para renover um produto 
void remover_produto(Produto *produto, int *qtdprod, char nomeprod);

// Função para adquirir produtos para papelaria
// Essa fução se encontrara na opção repor estoque
void venda_prod();

// Função para buscar produtos cadastrados em uma papelaria
void busca_prod(Produto *produto, int *qtdpod, char nomepod);
