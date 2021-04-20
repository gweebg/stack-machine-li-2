/**
 * @file stack.c - Ficheiro que contém todas as funções relacionadas com a stack
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

#include "stack.h"

stack create()
{
    stack myStack; // Inicialização da stack
    myStack.size = SIZE; // Tamanho da stack igual a 100
    myStack.pointer = -1; // O stack pointerinicializado com o valor -1
    myStack.elems = (stack_elem *)malloc(myStack.size * sizeof(stack_elem)); // Alocação de memória para guardar os elementos
    return myStack;
}

int stackStatus(stack *s)
{

    int r;

    if (s->pointer == -1)
        r = 0; // 0 for empty
    else if (s->pointer == SIZE)
        r = 1; // 1 for full
    else
        r = 2; // 2 for not !full or !empty

    return r;
}

void push(stack *s, const enum stack_type type, ...)
{

    // Estado da stack
    int status = stackStatus(s);

    if (status == 1) // Se a stack estiver cheia.
    {
        // Realocar a memória para ser possivel meter todos os valores.
        stack_elem *tmp = (stack_elem *)realloc(s->elems, s->size * sizeof(stack_elem));

        // Verificamos se foi possível realocar mais memória.
        if (tmp == NULL) fprintf(stderr, "Limite de memória excedido.\n"); 
        else s->elems = tmp; 
    }

    va_list ap;
    va_start(ap, type);

    // Push do elemento de acordo com o seu tipo relativo à stack.
    switch (type)
    {
    case STACK_CHAR:
        s->pointer++;
        s->elems[s->pointer].data.char_value = (char)va_arg(ap, int);
        s->elems[s->pointer].type = type;
        break;

    case STACK_INT:
        s->pointer++;
        s->elems[s->pointer].data.int_value = va_arg(ap, int);
        s->elems[s->pointer].type = type;
        break;

    case STACK_LONG:
        s->pointer++;
        s->elems[s->pointer].data.long_value = va_arg(ap, long);
        s->elems[s->pointer].type = type;
        break;

    case STACK_FLOAT:
        s->pointer++;
        s->elems[s->pointer].data.float_value = (float)va_arg(ap, double);
        s->elems[s->pointer].type = type;
        break;

    case STACK_DOUBLE:
        s->pointer++;
        s->elems[s->pointer].data.double_value = va_arg(ap, double);
        s->elems[s->pointer].type = type;
        break;

    case STACK_POINTER:
        s->pointer++;
        s->elems[s->pointer].data.string_value = va_arg(ap, char *);
        s->elems[s->pointer].type = type;
        break;

    default:
        fprintf(stderr, "O tipo não existe!\n"); // Erro caso o tipo não exista.
        exit(EXIT_FAILURE);
    }
}

stack_elem pop(stack *s)
{

    // Estado da stack.
    int status = stackStatus(s);

    if (status != 0)
    {
        stack_elem elem = s->elems[s->pointer];
        s->pointer--;
        return elem;
    }
    else
    {
        fprintf(stderr, "A stack está vazia!\n");
        exit(EXIT_FAILURE);
    }
}

void dumpStack(stack *s)
{

    // printf("Stack Dump: ");
    for (int i = 0; i < s->pointer + 1; i++)
    {
        stack_elem elem = s->elems[i];
        stack_type type = elem.type;

        switch (type)
        {
        case STACK_CHAR:
            printf("%c ", elem.data.char_value);
            break;

        case STACK_INT:
            printf("%d ", elem.data.int_value);
            break;

        case STACK_LONG:
            printf("%ld ", elem.data.long_value);
            break;

        case STACK_FLOAT:;
            printf("%g", elem.data.float_value);
            break;

        case STACK_DOUBLE:
            printf("%g", elem.data.double_value);
            break;

        case STACK_POINTER:
            printf("%s ", elem.data.string_value);
            break;

        default:
            fprintf(stderr, "unknown");
            exit(EXIT_FAILURE);
        }
    }
    printf("\n");
}

stack_elem peek(stack *s)
{
    return s->elems[s->pointer];
}
