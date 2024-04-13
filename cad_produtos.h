#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto {
char nome_prod [70];
char tip_prod [70];
float preco;
int qtd;
}Produto;

struct No{
    Dados produtos;
     struct  No * proximo;
    };

typedef struct lista_prod{
  struct No * inicio;
} Lista_prod;

// Adiciona os itens aos campos pedidos ao usuario
void ad_produto(Produto **produto, int *qtdpod);

// Salva os dados fornecidos pelo usuario no .txt
void salva_prod(Lista_prod *plista);

// Insere os dados fornecidos a lista
void insere_prod(Lista_prod *plista, Dados Produto);

// Struct para busca de produtos
struct No* pesq_prod(lista_prod lista, char* nome_prod);

// Função para cadastrar uma produto
void ad_produto(Produto **produto, int *qtdpod);

// Função para remover um produto 
void remover_produto(Produto *produto, int *qtdprod, char nomeprod[]);

/*
Essa fução se encontrara na opção repor estoque
Função para adquirir produtos para papelaria
*/
void venda_prod();

// Função para buscar produtos cadastrados em uma papelaria
void busca_prod(Produto *produto, int *qtdpod, char nomepod);
