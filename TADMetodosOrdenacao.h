/* 
 * File:   TADMetodosOrdenaçao.h
 * Author: vinicius
 *
 * Created on October 17, 2015, 11:54 PM
 */

typedef struct{
    int elemento;
}Titem;

typedef struct{
    int comparacoes;
    int movimentacoes;
    int tempo;
}AnaliseAlgoritmo;

typedef struct{
    Titem *item;
    AnaliseAlgoritmo Analise;
    int primeiro;
    int ultimo;
    int tamanho;
}TLista;

void inicializa(TLista *lista, int tamanhoVetor);
void zeraContadores(TLista *lista);
void inserir(TLista *lista, Titem x);
void imprimir(TLista *lista);
void selectionSort(TLista *lista,int tamanho);
void insertionSort(TLista *lista,int tamanho);
void shellSort(TLista *lista,int tamanho);
void quickSort(TLista *lista, int esquerda, int direita);
void HeapSort(TLista *lista,int tamanho);
void build(TLista *lista, int tamanho);
void rebuild(TLista *lista, int limit, int pos);



