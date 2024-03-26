#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct papelaria {
char nome [50];
char local [100];
char produtos [100];
}Papelaria;

// Função para cadastrar papelaria
void cad_papelaria(Papelaria *papelaria, char cadastro);
//Função para remover papelaria
void rem_papelaria(Papelaria *papelaria, int qtdpapelaria);
// Função para lista as papelaria cadastradas
void listar_pap();