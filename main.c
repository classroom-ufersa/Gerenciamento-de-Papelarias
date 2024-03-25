#include "cad_papelaria.h"
#include "cad_produtos.h"

int main(void){

int opc, op2, op3; 

printf("***************[ SISTEMA OS EMPAPELADOS ]***************\n");
printf("Nos informe oque deseja fazer\n");
printf(" (1)-Gerenciar Papelarias. \n (2)-Gerenciar Produtos. \n (3)-Sair do programa.");
scanf("%d", &opc);
    if(opc = 1){
        Printf("------------ OQUE DESEJA FAZER ------------\n");
        printf("(1)-Adiocionar uma nova Papelaria. \n (2)-Remover uma papelaria existente. \n (3)-Listar Papelarias e produtos. ");
        scanf("%d",op2);
            switch(op2){
                case 1:
                break;

                case 2:
                break;

                case 3:
                break;
            }
    }
    else if(opc = 2){
        printf("------------ OQUE DESEJA FAZER ------------\n");
        printf("(1)-Buscar Produto. \n (2)-Adiocionar novo Produto. \n (3)-Remover um produto existente. \n (4)-Repor estoque. ");
            switch(op3){
                case 1:
                break; 

                case 2:
                break;

                case 3:
                break; 
                
                case 4:
                break;

            }
    }
    else if(opc = 3){
        
    }

    return 0;
}