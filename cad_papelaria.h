#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct papelaria {
char nome [50];
char local [100];
char produtos [100];
}Papelaria;

// Função para cadastrar papelaria
void cad_pap( Papelaria **papelaria, int *quant);
//Função para remover papelaria;
void rem_pap(Papelaria *papelaria, int *quant, char *nomePap);

void pap_salva(Papelaria *papelaria, int quant);

void carr_pap(Papelaria **papelaria, int *quant);
// Função para lista as papelaria cadastradas
void listar_pap(Papelaria *papelaria, int quant);
