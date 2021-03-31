/**
 * @file stack.c - Ficheiro que contém todas as funções relacionadas com a stack
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdarg.h>

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
                s->elems[s->pointer].data.char_value = (char)va_arg(ap, int);
                s->elems[s->pointer].type = type;
                break;

            case STACK_INT:
                s->elems[s->pointer].data.int_value = (int)va_arg(ap, int);
                s->elems[s->pointer].type = type;
                break;

            case STACK_LONG:
                s->elems[s->pointer].data.long_value = (float)va_arg(ap, long);
                s->elems[s->pointer].type = type;
                break;

            case STACK_FLOAT:
                s->elems[s->pointer].data.float_value = (float)va_arg(ap, double);
                s->elems[s->pointer].type = type;
                break;

            case STACK_DOUBLE:
                s->elems[s->pointer].data.double_value = va_arg(ap, double);
                s->elems[s->pointer].type = type;
                break;

            case STACK_POINTER:
                s->elems[s->pointer].data.pointer_value = va_arg(ap, void *);
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

stack_type pop(stack *s, const enum stack_type type)
{

    int status = stackStatus(s);

    if (status == 0)
    {

        switch (type)
        {
            case STACK_CHAR: ;
                char c = s->elems[s->pointer].data.char_value; 
                s->pointer--;                                  
                return c;

            case STACK_INT: ;
                int i = s->elems[s->pointer].data.int_value;
                s->pointer--;
                return i;

            case STACK_LONG: ;
                long l = s->elems[s->pointer].data.long_value;
                s->pointer--;
                return l;

            case STACK_FLOAT: ;
                float f = s->elems[s->pointer].data.float_value;
                s->pointer--;
                return f;

            case STACK_DOUBLE: ;
                double d = s->elems[s->pointer].data.double_value;
                s->pointer--;
                return d;

            case STACK_POINTER: ;
                void *p = s->elems[s->pointer].data.pointer_value;
                s->pointer--;
                return p; // FIXME:

            default:
                fprintf(stderr, "O tipo não existe!\n");
                exit(EXIT_FAILURE);
        }
    }

    else
    {
        fprintf(stderr, "A stack está vazia!\n");
        exit(EXIT_FAILURE);
    }
}

// void dumpStack(stack *s)
// {

//     // printf("Stack Dump: ");
//     for (int i = 0; i < s->pointer + 1; i++)
//     {
//         switch(s->elems[i].type)
//         {
//             case STACK_CHAR: ;
//                 char c = s->elems[s->pointer].data.char_value;                          
//                 printf("%c ",c);

//             case STACK_INT: ;
//                 int i = s->elems[s->pointer].data.int_value;                          
//                 printf("%d ",i);

//             case STACK_LONG: ;
//                 long l = s->elems[s->pointer].data.long_value;                          
//                 printf("%ld ",l);

//             case STACK_FLOAT: ;
//                 float f = s->elems[s->pointer].data.float_value;                          
//                 printf("%f ",f);

//             case STACK_DOUBLE: ;
//                 double d = s->elems[s->pointer].data.double_value;                          
//                 printf("%lf ", d);

//             case STACK_POINTER: ;
//                 void *p = s->elems[s->pointer].data.pointer_value;                          
//                 printf("%p ",p);

//             default:
//                 fprintf(stderr, "unknown");
//                 exit(EXIT_FAILURE);
//         }

//     }
//     printf("\n");
// }
