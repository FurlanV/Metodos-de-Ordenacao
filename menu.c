#include <stdlib.h>
#include <stdio.h>
#include "TADMetodosOrdenacao.h"

void menu(TLista *lista)
{
    Titem item;
    int mediaTempo,mediaComp,mediaMov;
    int tamanho,i,j,func=0;
    
    while(func!=6){
        printf("1- Selection sort | 2- Insertion sort | 3- ShellSort | 4- Quicksort | 5- Heapsort | 6- Sair\n");
        scanf("%d",&func);   
    
        switch(func){
            case 1:            
                printf("Digite o tamanho do vetor\n");
                scanf("%d",&tamanho);
                
                zeraContadores(lista);
                
                for(i=0;i<30;i++){
                    inicializa(lista,tamanho);
                    
                    for(j=0;j<tamanho;j++){
                    item.elemento = (rand()%200);
                    inserir(lista,item);
                    }         
                    //imprimir(lista);
                    selectionSort(lista,tamanho);
                    //imprimir(lista);
                }
                
                mediaTempo = (int)(lista->Analise.tempo / 30);
                mediaComp = (int)(lista->Analise.comparacoes / 30);
                mediaMov = (int)(lista->Analise.movimentacoes / 30);
                
                printf("A media de tempo foi: %d ms\n",mediaTempo);
                printf("A media de comparacoes foi: %d\n",mediaComp);
                printf("A media de movimentacoes foi: %d\n\n",mediaMov);                
                break;
            case 2:
               printf("Digite o tamanho do vetor\n");
                scanf("%d",&tamanho);
                
                zeraContadores(lista);
                
                for(i=0;i<30;i++){
                    inicializa(lista,tamanho);
                    
                    for(j=0;j<tamanho;j++){
                    item.elemento = (rand()%200);
                    inserir(lista,item);
                    }         
                    //imprimir(lista);
                    insertionSort(lista,tamanho);
                    //imprimir(lista);
                }
                
                mediaTempo = (int)(lista->Analise.tempo / 30);
                mediaComp = (int)(lista->Analise.comparacoes / 30);
                mediaMov = (int)(lista->Analise.movimentacoes / 30);
                
                printf("A media de tempo foi: %d ms\n",mediaTempo);
                printf("A media de comparacoes foi: %d\n",mediaComp);
                printf("A media de movimentacoes foi: %d\n\n",mediaMov);
                break;
        case 3:
            printf("Digite o tamanho do vetor\n");
                scanf("%d",&tamanho);
                
                zeraContadores(lista);
                
                for(i=0;i<30;i++){
                    inicializa(lista,tamanho);
                    
                    for(j=0;j<tamanho;j++){
                    item.elemento = (rand()%200);
                    inserir(lista,item);
                    }         
                    //imprimir(lista);
                    shellSort(lista,tamanho);
                    //imprimir(lista);
                }
                
                mediaTempo = (int)(lista->Analise.tempo / 30);
                mediaComp = (int)(lista->Analise.comparacoes / 30);
                mediaMov = (int)(lista->Analise.movimentacoes / 30);
                
                printf("A media de tempo foi: %d ms\n",mediaTempo);
                printf("A media de comparacoes foi: %d\n",mediaComp);
                printf("A media de movimentacoes foi: %d\n\n",mediaMov);
                break;
            case 4:
                printf("Digite o tamanho do vetor\n");
                scanf("%d",&tamanho);
                
                zeraContadores(lista);
                
                for(i=0;i<30;i++){
                    inicializa(lista,tamanho);
                    
                    for(j=0;j<tamanho;j++){
                    item.elemento = (rand()%200);
                    inserir(lista,item);
                    }         
                    //imprimir(lista);
                    quickSort(lista,lista->primeiro,tamanho-1);
                    //imprimir(lista);
                }
                
                mediaTempo = (int)(lista->Analise.tempo / 30);
                mediaComp = (int)(lista->Analise.comparacoes / 30);
                mediaMov = (int)(lista->Analise.movimentacoes / 30);
                
                printf("A media de tempo foi: %d ms\n",mediaTempo);
                printf("A media de comparacoes foi: %d\n",mediaComp);
                printf("A media de movimentacoes foi: %d\n\n",mediaMov);
                break;
            case 5:
                printf("Digite o tamanho do vetor\n");
                scanf("%d",&tamanho);
                
                zeraContadores(lista);
                
                for(i=0;i<30;i++){
                    inicializa(lista,tamanho);
                    
                    for(j=0;j<tamanho;j++){
                    item.elemento = (rand()%250);
                    inserir(lista,item);
                    }         
                    
                    //imprimir(lista);
                    HeapSort(lista,tamanho);
                    //imprimir(lista);
                }
                
                mediaTempo = (int)(lista->Analise.tempo / 30);
                mediaComp = (int)(lista->Analise.comparacoes / 30);
                mediaMov = (int)(lista->Analise.movimentacoes / 30);
                
                printf("A media de tempo foi: %d ms\n",mediaTempo);
                printf("A media de comparacoes foi: %d\n",mediaComp);
                printf("A media de movimentacoes foi: %d\n\n",mediaMov);
                break;
            case 6:
                printf("Saindo..\n");
                break;
            default:
                printf("Metodo de ordenacao nao existe !\n");
                break;
        }
    }
}

