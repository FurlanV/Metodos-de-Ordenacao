/* 
 * File:   main.c
 * Author: vinicius
 *
 * Created on October 17, 2015, 11:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "TADMetodosOrdenacao.h"
#include "menu.h"

/*
 * 
 */
int main(int argc, char** argv) 
{
    TLista *lista;
    
    menu(&lista);
    free(lista);
    return (EXIT_SUCCESS);
}


