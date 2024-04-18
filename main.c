#include "cad_papelaria.h"
#include "cad_produtos.h"

int main(void){
Lista_prod lista_prod;
lista_prod.pinicio = NULL;
Lista lista;lista.inicio = NULL;
Produto *produto = NULL;
int opc, op2, op3;

do {
           printf("***************[ SISTEMA OS EMPAPELADOS ]***************\n");
printf("    Nos informe oque deseja fazer\n");
printf(" (1)-Gerenciar Papelarias. \n (2)-Gerenciar Produtos. \n (3)-Listar Papelarias e seus produtos.\n (4)-Sair. \n ");
obter_opcao_valida(&opc);
    if(opc == 1){
      
             printf("------------ OQUE DESEJA FAZER ------------\n");
        printf(" (1)-Adiocionar uma nova Papelaria. \n (2)-pesquisar por papelaria. \n (3)-Listar Papelarias e produtos.\n  (4)-Remover uma papelaria existente. \n");
        obter_opcao_valida(&op2);
            switch(op2){
                case 1:{
                papelaria dadopap;
                cad_pap (&dadopap, &lista);
                inserir_lista(&lista, dadopap);
                salva_dados(&lista);
                }
            break;  

                case 2:{
                char nome[50];
                ((getchar()) != '\n');
                printf("Informe o nome da papelaria\n");
                scanf("%[^\n]",nome);
                struct No * pi = pesquisar(lista,nome);
                if (pi !=NULL){
                printf("%s %s\n", pi->dado.nome, pi->dado.local);
              }
              else {
                printf("Ops :-( | Papelaria nao foi encontrada \n");
                }
              }
            break;

            case 3:  
            lista = ler_arquivo();
              mostrar(lista);
            break;

           case 4:
      {
        char sn[10];
        char nome[50];
        do
        {
          printf("-------------------- Remover Papelaria ----------------------------\n");
          printf("|Atencao ao remover a papelaria todos os produtos sarao removidos |\n");
          printf("|              deseja comtinuar  sim ou nao                        |\n");
          printf("-------------------------------------------------------------------\n");
          scanf(" %[^\n]", sn);
          if (strcmp(sn, "sim") == 0 || strcmp(sn, "s") ==0)
          {
            printf("Informe o nome da papelaria que deseja remover: \n");
            ((getchar()) != '\n');
            scanf("%[^\n]", nome);
            deletar_pap(&lista, nome);
            atualizar_arquivo(&lista);
          }
          else if (strcmp(sn, "nao") == 0 || strcmp(sn, "n") == 0)
          {
            printf("Operacao cancelada.\n");
          }
          else
          {
            printf("Por favor, insira um numero valido.\n");
          }
        } while (strcmp(sn, "sim") && strcmp(sn, "s") && strcmp(sn, "nao") && strcmp(sn, "n") != 0);
      }
      break;
                }
            } 
        else if(opc == 2){
        printf("------------ OQUE DESEJA FAZER ------------\n");
        printf("(1)-Buscar Produto. \n (2)-Adiocionar novo Produto. \n (3)-Remover um produto existente. \n (4)-Repor estoque. \n");
        obter_opcao_valida(&op3);
            switch(op3){
              case 1:{
              char nome_prod[50];
              printf("informe o nome do Produto\n");
              ((getchar()) != '\n');
              scanf("%[^\n]",nome_prod);
              struct Nop* pro_it = pesq_prod(lista_prod, nome_prod); 
              if (pro_it !=NULL){
              printf("Produto: %s | Preco: %.2f | Quantidade: %d | \n", pro_it->Dados.nome_prod, pro_it->Dados.preco,pro_it->Dados.tip_prod);
              }   
              else {
              printf("Produto nao encontrado\n");
                }
              }
              break; 

              case 2:
              produto = malloc(sizeof(Produto));
              if(produto == NULL){
              printf("erro ao alocar memoria \n");
              exit(1);
              }
              ad_produto(&produto, &lista_prod, &lista);
              insere_prod(&lista_prod, *produto);
              salva_dados(&lista);
              break;

              case 3:{
                char nome_papelaria[50];
                char nome_prod[50];
              printf("----------------- Remover produto ----------------------\n");
              printf("Informe a papelaria na qual deseja remover o produto: \n");
              printf("--------------------------------------------------------\n");
              scanf(" %[^\n]",nome_papelaria );
               printf("----------------- Remover produto ----------------------\n");
              printf("Informe o produto que deseja remover: \n");
               printf("--------------------------------------------------------\n");
              scanf(" %[^\n]",nome_prod);
              remover_produto(&lista ,nome_papelaria, nome_prod);
              }
              break; 
                
              case 4:
               
              break;

          }
    }
    else if(opc == 3){
    mostrar_prod(&lista);
      } 
    }while(opc != 4);

/*
Coisas a fazer para Terminar o Projeto

> Consertar a busca do produto
> Fazer a função de venda
> Salvar os dados do .txt sempre que sair do programa
*/
           
           
    return 0;
}
 
