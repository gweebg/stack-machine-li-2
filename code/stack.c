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
    stack myStack;
    myStack.pointer = -1; // O stack pointer é sempre inicializado com o valor -1
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

    int status = stackStatus(s);

    if (status != 1)
    {

        va_list ap;
        va_start(ap, type);

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
            fprintf(stderr, "O tipo não existe!\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "A stack está cheia!\n");
        exit(EXIT_FAILURE);
    }
}

stack_elem pop(stack *s)
{

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
            printf("%c", elem.data.char_value);
            break;

        case STACK_INT:
            printf("%d", elem.data.int_value);
            break;

        case STACK_LONG:
            printf("%ld", elem.data.long_value);
            break;

        case STACK_FLOAT: ;
            printf("%g", elem.data.float_value);
            break;

        case STACK_DOUBLE: 
            printf("%g", elem.data.double_value);
            break;

        case STACK_POINTER:
            printf("%s", elem.data.string_value);
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

