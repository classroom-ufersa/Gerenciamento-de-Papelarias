#include "cad_papelaria.h"
#include "cad_produtos.h"

int main(void){
Lista lista ;
lista.inicio = NULL;
Produto *produto = NULL;
Papelaria *papelaria = NULL;
int opc, op2, op3, qtdpod, qtdprod; 
char nome[50];
char nomeprod[50];

do {
           printf("***************[ SISTEMA OS EMPAPELADOS ]***************\n");
printf("    Nos informe oque deseja fazer\n");
printf(" (1)-Gerenciar Papelarias. \n (2)-Gerenciar Produtos. \n (3)-Sair do programa.\n ");
scanf("%d", &opc);
    if(opc == 1){
       
             printf("------------ OQUE DESEJA FAZER ------------\n");
        printf(" (1)-Adiocionar uma nova Papelaria. \n (2)-pesquisar por papelaria. \n (3)-Listar Papelarias e produtos.\n  (4)-Remover uma papelaria existente. \n");
        scanf("%d",&op2);
            switch(op2){
                case 1:
                 cad_pap(&papelaria, &lista);
                 inserir(&lista, *papelaria);
                break;

                case 2:
               ((getchar()) != '\n');
                printf("informe o nome da papelaria\n");
                scanf("%[^\n]",nome);
              struct No* pi = pesquisar(lista, nome);
              if (pi !=NULL){
                printf("%s %s\n", pi->dado.nome, pi->dado.local);
              }
              else {
                printf("paprarlia nao encontrada\n");
              }
                break;

                case 3:  
                listar_pap(lista);
                break;

                case 4: 
               ((getchar()) != '\n');
                printf("informr a papelaria que deseja Remover\n");
                scanf("%[^\n]",nome);
                deletar_pap(&lista, nome);
                atualizar_arquivo(&lista);
                break;
            }
            } 
        else if(opc == 2){
        printf("------------ OQUE DESEJA FAZER ------------\n");
        printf("(1)-Buscar Produto. \n (2)-Adiocionar novo Produto. \n (3)-Remover um produto existente. \n (4)-Repor estoque. \n");
          scanf("%d", &op3);
            switch(op3){
                case 1:
                struct No* pesq_prod(lista, nome_prod);
                break; 

                case 2:
                ad_produto(&produto, &qtdpod);
                insere_prod(plista, *Produto);
                break;

                case 3:
                remover_produto( produto, &qtdprod, nomeprod);
                break; 
                
                case 4:
                break;

            }
    }
    else if(opc == 3){
        
    }
    }while(opc != 3);
   
  free(papelaria);
 
    return 0;
}
 
