#include "cad_papelaria.h"
#include "cad_produtos.h"


int main(){
Produto *produto = NULL;
Papelaria *papelaria = NULL;
int quant = 0, qtdpob = 0;
int opc, op2, op3; 
char nomePap[50];
char nomeprod[50];


printf("***************[ SISTEMA OS EMPAPELADOS ]***************\n");
printf("Nos informe oque deseja fazer\n");
printf(" (1)-Gerenciar Papelarias. \n (2)-Gerenciar Produtos. \n (3)-Sair do programa.\n ");
scanf("%d", &opc);
    if(opc == 1){
        carr_pap(&papelaria, &quant);
        do {
             printf("------------ OQUE DESEJA FAZER ------------\n");
        printf("(1)-Adiocionar uma nova Papelaria. \n (2)-Remover uma papelaria existente. \n (3)-Listar Papelarias e produtos.\n ");
        scanf("%d",&op2);
            switch(op2){
                case 1:
                 cad_pap(&papelaria, &quant);
                 pap_salva(papelaria, quant);
                break;

                case 2:
                 printf("Informe o nome da papelaria a ser removida: ");
                 scanf(" %[^\n]", nomePap);
                 rem_pap(papelaria, &quant, nomePap);
                break;

                case 3:  
                listar_pap(papelaria, quant);
                break;
            }
            } while(op2 != 4);
       
    }
    else if(opc == 2){
        printf("------------ OQUE DESEJA FAZER ------------\n");
        printf("(1)-Buscar Produto. \n (2)-Adiocionar novo Produto. \n (3)-Remover um produto existente. \n (4)-Repor estoque. \n");
            switch(op3){
                case 1:
                ad_produto(produto, &qtdpod);
                break; 

                case 2:
                break;

                case 3:
                remover_produto(produto, &qtdprod, nomeprod);
                break; 
                
                case 4:
                break;

            }
    }
    else if(opc == 3){
        
    }
  free(papelaria);
    return 0;
}


 
