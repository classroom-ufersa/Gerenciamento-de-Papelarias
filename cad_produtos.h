#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct produto {
char nome_prod [70];
char tip_prod [70];
float preco;
int quant;
}Produto;

// Função para cadastrar uma produto
void adiciona_produto(Produto *produto);
// Função para renover um produto 
void remover_produto();

void comprar_produtos();
// Função para buscar produtos cadastrados em uma papelaria
void busca_produto();