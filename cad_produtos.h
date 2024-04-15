#ifndef CAD_PRODUTOS_H
#define CAD_PRODUTOS_H
#include "cad_papelaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista_prod{
  struct Nop * pinicio;
} Lista_prod;

struct Nop{
    Produto Dados ;
     struct  Nop * prox;
    };

// Adiciona os itens aos campos pedidos ao usuario
void ad_produto(Produto **produto, Lista_prod *pblista, Lista* plista);

// Salva os dados fornecidos pelo usuario no .txt
void salva_prod(Lista_prod *plista);

// Insere os dados fornecidos a lista
void insere_prod(Lista_prod *pblista, Produto Dados );

// Struct para busca de produtos
struct Nop* pesq_prod(Lista_prod lista, char* nome_prod);

// Função para remover um produto 
void remover_produto(Lista* plista, char* nome_papelaria, char* nome_prod);

/*
Essa fução se encontrara na opção repor estoque
Função para adquirir produtos para papelaria
*/
void venda_prod();

// Função para buscar produtos cadastrados em uma papelaria
void busca_prod(Produto *produto, int *qtdpod, char nomepod);

void mostrar_prod(Lista* plista);

#endif 
