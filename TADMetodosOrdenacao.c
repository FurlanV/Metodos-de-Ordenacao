#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "TADMetodosOrdenacao.h"

void inicializa(TLista *lista,int tamanho)
{
    lista->item = (Titem*)malloc(tamanho*sizeof(int));
    lista->primeiro = 0;
    lista->ultimo = lista->primeiro;
    lista->tamanho = tamanho;
}

void zeraContadores(TLista *lista)
{
    lista->Analise.movimentacoes = 0;
    lista->Analise.comparacoes = 0;
    lista->Analise.tempo = 0;
}

void inserir(TLista *lista, Titem x)
{
    if(lista->ultimo == lista->tamanho){
        printf("lista cheia\n");
        exit(1);
    }
    else{
        lista->item[lista->ultimo] = x;
        lista->ultimo++;
    }
}

void imprimir(TLista *lista)
{
    int i;
    
    if(lista->ultimo != lista->primeiro){
        printf("Lista: ");
        for(i=lista->primeiro;i<lista->ultimo;i++){
            printf("%5d ",lista->item[i].elemento);
        }
    
        printf("\n        ");
    
        for(i=0; i<lista->tamanho; i++)
            printf("   ^  ");
    
        printf("\nOrdem: ");
        for(i=0; i<lista->tamanho; i++)
            printf("%5d ",i+1);
    
        printf("\n\n");
    }
}

void selectionSort(TLista *lista,int tamanho)
{
    struct timeval inicio,fim;
    int tempoDecorrido;
    int i,j,min,aux;
    int nComparacoes=0,nMovimentacoes=0;
    
    gettimeofday(&inicio,NULL);
    
    for (i = 0; i < (tamanho-1); i++) 
    {
      min = i;
      for (j = (i+1); j < tamanho; j++) {
        if(lista->item[j].elemento < lista->item[min].elemento) {
            min = j;
        }
        nComparacoes++;
     }
     if (i != min) {
       aux = lista->item[i].elemento;
       lista->item[i].elemento = lista->item[min].elemento;
       lista->item[min].elemento = aux;
       nMovimentacoes++;
     }
   }
  
    gettimeofday(&fim,NULL);
    tempoDecorrido = (int) (1000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000);
    
    lista->Analise.comparacoes += nComparacoes;
    lista->Analise.movimentacoes += nMovimentacoes;
    lista->Analise.tempo += tempoDecorrido;
    
    printf("\nSelection Sort:\n");
    printf("Tempo Decorrido: %d ms\n",tempoDecorrido);
    printf("Comparacoes: %d\n",nComparacoes);
    printf("Movimentacoes: %d\n\n",nMovimentacoes);
}

void insertionSort(TLista *lista,int tamanho)
{
    struct timeval inicio,fim;
    int tempoDecorrido;
    int i, j, eleito;
    int nComparacoes=0,nMovimentacoes=0;
    
    gettimeofday(&inicio,NULL);
    
    for (i = 1; i < tamanho; i++){
      eleito = lista->item[i].elemento;
      j = i - 1;
      
      while ((j>=0) && (eleito < lista->item[j].elemento)) {
         nComparacoes++;
         lista->item[j+1].elemento = lista->item[j].elemento;
         nMovimentacoes++;
         j--;
      }

      lista->item[j+1].elemento = eleito;
      nMovimentacoes++;
   }
    
    gettimeofday(&fim,NULL);
    tempoDecorrido = (int) (1000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000);
    
    lista->Analise.comparacoes += nComparacoes;
    lista->Analise.movimentacoes += nMovimentacoes;
    lista->Analise.tempo += tempoDecorrido;
    
    printf("Insertion Sort:\n");
    printf("Tempo Decorrido: %d ms\n",tempoDecorrido);
    printf("Comparacoes: %d\n",nComparacoes);
    printf("Trocas: %d\n\n",nMovimentacoes);
}

void shellSort(TLista *lista,int tamanho)
{
   
    struct timeval inicio,fim;
    int tempoDecorrido;
    int i , j , value;
    int gap = 1;
    int nComparacoes=0,nMovimentacoes=0;
    
    gettimeofday(&inicio,NULL);
    while(gap < tamanho) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < tamanho; i++) {
            value = lista->item[i].elemento;
            j = i - gap;
            while (j >= 0 && value < lista->item[j].elemento) {
                nComparacoes++;
                lista->item[j + gap].elemento = lista->item[j].elemento;
                nMovimentacoes++;
                j -= gap;
            }
            lista->item[j + gap].elemento = value;
            nMovimentacoes++;
        }
    }
    gettimeofday(&fim,NULL);
    tempoDecorrido = (int) (1000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000);
    
    lista->Analise.comparacoes += nComparacoes;
    lista->Analise.movimentacoes += nMovimentacoes;
    lista->Analise.tempo += tempoDecorrido;
    
    printf("Shell Sort:\n");
    printf("Tempo Decorrido: %d ms\n",tempoDecorrido);
    printf("Comparacoes: %d\n",nComparacoes);
    printf("Trocas: %d\n\n",nMovimentacoes);
    
}

void quickSort(TLista *lista, int esquerda, int direita)
{
    struct timeval inicio,fim;
    int tempoDecorrido;
    int nComparacoes=0,nMovimentacoes=0;
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = lista->item[(esquerda + direita) / 2].elemento;

    gettimeofday(&inicio,NULL);
    while(i <= j)
    {
        while(lista->item[i].elemento < x && i < direita)
        {
            i++;
            nComparacoes++;
        }
        while(lista->item[j].elemento > x && j > esquerda)
        {
            j--;
            nComparacoes++;
        }
        if(i <= j)
        {
            y = lista->item[i].elemento;
            lista->item[i].elemento = lista->item[j].elemento;
            lista->item[j].elemento = y;
            i++;
            j--;
            nMovimentacoes++;
        }
    }
    if(j > esquerda)
    {
        quickSort(lista, esquerda, j);
    }
    if(i < direita)
    {
        quickSort(lista,  i, direita);
    }
    
    gettimeofday(&fim,NULL);
    tempoDecorrido = (int) (1000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000);
    
    lista->Analise.comparacoes += nComparacoes;
    lista->Analise.movimentacoes += nMovimentacoes;
    lista->Analise.tempo += tempoDecorrido;
}

// rebuild recursive
void rebuild(TLista *lista, int limit, int pos)
{		
	int c1, c2;
	
	c1 = 2 * pos;
	c2 = c1 + 1;
	
	if(c1 > limit || (lista->item[pos-1].elemento >= lista->item[c1-1].elemento && lista->item[pos-1].elemento >= lista->item[c2-1].elemento)){
            lista->Analise.comparacoes++;
            return;
        }
	
	int greater_index = -1;
	
	if(c2 > limit)
		greater_index = c1;
	else
	{		
		if(lista->item[c1-1].elemento > lista->item[c2-1].elemento){
                        lista->Analise.comparacoes++;
			greater_index = c1;
                }
		else{
                    lista->Analise.comparacoes++;
			greater_index = c2;
                }
	}
	
	if(greater_index != -1)
	{
		int aux = lista->item[greater_index - 1].elemento;
		lista->item[greater_index - 1].elemento = lista->item[pos - 1].elemento;
		lista->item[pos - 1].elemento = aux;
                lista->Analise.movimentacoes++;
		rebuild(lista, limit, greater_index);
	}
}


void build(TLista *lista, int tamanho)
{
	int left;
	
	if(tamanho % 2 == 0)
		left = tamanho / 2 + 1;
	else
		left = (tamanho - 1) / 2 + 1;
	
	while(left > 1) 
	{
		left--;
		rebuild(lista, tamanho, left);
	}
}               

void HeapSort(TLista *lista, int tamanho)
{
    struct timeval inicio,fim;
    int tempoDecorrido;
    int limit = tamanho;
    
        gettimeofday(&inicio,NULL);
	build(lista,tamanho);
	
	while(1)
	{		
		int aux = lista->item[0].elemento;
		lista->item[0].elemento = lista->item[limit-1].elemento;
		lista->item[limit-1].elemento = aux;
		
		rebuild(lista, limit - 1, 1);
			
		limit--;
		
		if(limit <= 2 && lista->item[0].elemento <= lista->item[1].elemento)
			break;
	}
        gettimeofday(&fim,NULL);
        tempoDecorrido = (int) (1000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000);
        
        lista->Analise.tempo += tempoDecorrido;
        
}
