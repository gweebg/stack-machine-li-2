/************************************************
 * @file Ficheiro que contém todas as funções relacionadas com a stack.
 ***********************************************/

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>

# include "stack.h"


/************************************************
 * \brief Função que inicializa uma stack (structure definida em stack.h).
 * @returns Devolve a stack criada.
 ***********************************************/
stack create() {

    stack myStack;
    myStack.pointer = -1;
    return myStack;

}

/************************************************
 * \brief Função que verifica o estado da stack.
 * 
 * Determina o estado verificando o valor do stack pointer.
 * @param s Stack a ser avaliada.
 * @returns 
 * Devolve :
 * * 0, se a stack estiver vazia;
 * * 1, se a stack estiver cheia;
 * * 2, se a stack não estiver cheia nem vazia.
 ***********************************************/
int stackStatus(stack *s) {

    int r;

    if (s->pointer == -1) { 

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

/************************************************
 * \brief Retira o elemento no topo da stack.
 * 
 * A stack rege-se por "last in, first out", daí termos de retirar o primeiro elemento e decrementar o stack pointer.
 * @param s Stack a ser avaliada.
 * @returns
 * Devolve :
 * * O elemento retirado se a stack não estiver vazia;
 * * 1, se a stack estiver vazia.
 ***********************************************/
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

/************************************************
 * \brief Adiciona um elemento no topo da stack.
 * 
 * @param s Stack a ser avaliada.
 * @returns
 * Devolve :
 * * 0, se foi possivel adiconar o elemento;
 * * 1, se a stack estiver cheia.
 ***********************************************/
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

/************************************************
 * \brief Esta função despeja todos os elementos contidos na stack.
 * 
 * @param s Stack a ser avaliada.
 * @returns 
 * Escreve a stack no ecrã, porém não devolve nada, sendo que é do tipo void.
 ***********************************************/
void dumpStack(stack *s) {

    printf("Stack Dump: ");
    for (int i = 0; i < s->pointer+1; i++) {

        printf("%ld ", s->elems[i]);

    }
    printf("\n");
}
