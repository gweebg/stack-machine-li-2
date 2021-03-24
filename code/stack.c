/**
 * @file stack.c - Ficheiro que contém todas as funções relacionadas com a stack
 * @copyright Copyright (c) 2021
 */

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>

# include "stack.h"

stack create() {

    stack myStack;
    myStack.pointer = -1; // O stack pointer é sempre inicializado com o valor -1 
    return myStack;

}

int stackStatus(stack *s) {

    int r;

    if (s->pointer == -1) { // s->pointer é equivalente a (*s).pointer

        r = 0; // Retorna 0 caso a stack esteja vazia

    }
    else if (s->pointer == SIZE) {

        r = 1; // Retorna 1 caso a stack esteja cheia

    }
    else {

        r = 2; // Retorna 2 caso a stack não esteja cheia nem vazia
    
    } 

    return r; 

}

int pop(stack *s) {

    int r; 
    int status = stackStatus(s);

    if(status != 0) {
        
        r = s->elems[s->pointer]; // Guarda o valor do topo no stack pointer (sp)
        s->pointer--; // Decrementa o sp, pois retiramos um elemento
        return r;

    }
    else {

        return 1; // Retorna 1 caso a stack esteja vazia

    }

}

int push(stack *s, int value) {

    int status = stackStatus(s);

    if(status != 1) {

        s->pointer++; // Incrementa 1 no stack pointer pois estamos a adicionar um elemento na stack
        s->elems[s->pointer] = value; // Adiciona o valor na stack
        return 0;

    }
    else{

        return 1; // Retorna 1 caso a stack esteja cheia

    }

}

void dumpStack(stack *s) {

    // printf("Stack Dump: ");
    for (int i = 0; i < s->pointer+1; i++) {

        printf("%ld", s->elems[i]);

    }
    printf("\n");
}
