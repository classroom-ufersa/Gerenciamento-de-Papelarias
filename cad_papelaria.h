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


// Função para cadastrar papelaria
void cad_pap( Papelaria **papelaria);

// Função para remover papelaria;
void inserir(Lista *plista, Papelaria dado);

// Função para remover papelaria escolhida junto aos produtos
void deletar_pap (Lista *plista, char* nome);

// Lista papelarias existentes junto aos produtos
void listar_pap(Lista lista);

// Struct responsavel pela busca das papelarias
struct No* pesquisar(Lista lista, char* nome);



