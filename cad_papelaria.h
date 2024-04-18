#ifndef CAD_PAPELARIA_H
#define CAD_PAPELARIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct produto Produto;
 typedef struct Papelaria {
    char nome[50];
    char local[100];
    Produto* produtos; 
    int num_produtos;
} papelaria;

// definisao do  no
typedef struct No {
    papelaria dado;
    struct No *proximo;
} No;
// definisao da lista
typedef struct ista {
    No *inicio;
} Lista;

// Função para cadastrar papelaria
void cad_pap(papelaria *dadopapelaria, Lista *plista);

// Função para remover papelaria;
void inserir_lista(Lista *plista , papelaria dado);

// Função para remover papelaria escolhida junto aos produtos
void deletar_pap (Lista *plista, char* nome);

// Lista papelarias existentes junto aos produtos
void mostrar(Lista lista);

// Struct responsavel pela busca das papelarias
No* pesquisar(Lista lista, char* nome);

void salva_dados(Lista *plista);

void carregar_dados(Lista *plista);

void atualizar_arquivo(Lista *plista);

void obter_opcao_valida(int *opc);
Lista ler_arquivo();


#include "cad_produtos.h"  
#endif 

