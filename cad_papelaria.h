#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct papelaria {
    char nome[50];
    char local[100];
    struct Produto *produtos;
} Papelaria;

typedef struct lista{
  struct No * inicio;
} Lista;

struct No{
    Papelaria dado;
     struct  No * porx;
    };

void cad_pap( Papelaria **papelaria, Lista *plista) ;
//Função para remover papelaria;
void inserir(Lista *plista, Papelaria dado);

void deletar_pap (Lista *plista, char* nome);

void listar_pap(Lista lista);

struct No* pesquisar(Lista lista, char* nome);

void salva_dados(Lista *plista);

void carregar_dados(Lista *plista);

void atualizar_arquivo(Lista *plista);
