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
#include "array.h"

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

    case STACK_INT:;
        s->pointer++;
        s->elems[s->pointer].data.int_value = va_arg(ap, int);
        s->elems[s->pointer].type = type;
        break;

    case STACK_FLOAT:
        s->pointer++;
        s->elems[s->pointer].data.float_value = (float)va_arg(ap, double);
        s->elems[s->pointer].type = type;
        break;

    case STACK_STRING:
        s->pointer++;
        s->elems[s->pointer].data.string_value = va_arg(ap, char *);
        s->elems[s->pointer].type = type;
        break;
    
    case STACK_ARRAY:
        s->pointer++;
        s->elems[s->pointer].data.array_value = va_arg(ap, stack *);
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
            printf("%c", elem.data.char_value);
            break;

        case STACK_INT:
            printf("%d", elem.data.int_value);
            break;

        case STACK_LONG:
            printf("%ld", elem.data.long_value);
            break;

        case STACK_FLOAT:;
            printf("%g", elem.data.float_value);
            break;

        case STACK_DOUBLE:
            printf("%g", elem.data.double_value);
            break;

        case STACK_STRING:
            printf("%s", elem.data.string_value);
            break;
        
        case STACK_ARRAY:
            printArray(elem.data.array_value);
            break;

        default:
            fprintf(stderr, "unknown");
            exit(EXIT_FAILURE);
        }
    }

    printf("\n"); // Retirar o "\n" para evitar breaks ao dar print de um array, pois é recursivo.
}

stack_elem peek(stack *s)
{
    return s->elems[s->pointer];
}

void pushVar(stack *s, char var_letter)
{

    // Ao retirar 65 à letra (ASCII) obtemos o seu índice no array.
    // Por exemplo : A = 65, 65 - 65 = 0 | B = 66, 66 - 65 = 1
    int index = var_letter - 65; 
    stack_elem var_element = peek(s);

    // Queremos copiar o elemento no topo para a variável.
    s->vars[index] = var_element;

}

void varStart(stack *stack)
{

    // Inicialização das variáveis default da linguagem.
    stack_elem a, b, c, d, e, f, n, s, x, y, z;

    // Valores default de cada variável
    a.type = STACK_INT; a.data.int_value = 10;
    b.type = STACK_INT; b.data.int_value = 11;
    c.type = STACK_INT; c.data.int_value = 12;
    d.type = STACK_INT; d.data.int_value = 13;
    e.type = STACK_INT; e.data.int_value = 14;
    f.type = STACK_INT; f.data.int_value = 15;

    n.type = STACK_CHAR; n.data.char_value = '\n';
    s.type = STACK_CHAR; s.data.char_value = ' ';

    x.type = STACK_INT; x.data.int_value = 0;
    y.type = STACK_INT; y.data.int_value = 1;
    z.type = STACK_INT; z.data.int_value = 2;

    // Atribuição de cada variável a um indice do array das variaveis.
    stack->vars[0] = a;
    stack->vars[1] = b;
    stack->vars[2] = c;
    stack->vars[3] = d;
    stack->vars[4] = e;
    stack->vars[5] = f;

    stack->vars[13] = n;
    stack->vars[18] = s;

    stack->vars[23] = x;
    stack->vars[24] = y;
    stack->vars[25] = z;
    
}

void getVar(stack *s, char var_letter)
{                      

    // Segue o mesmo raciocínio da função pushVar.
    int index = var_letter - 65;
                
    // O valor da variável que cuja letra cooresponde ao índice var_letter - 65.
    // Por exemplo, var_letter = S => index = 85 - 65 = 18 = índice do S no array das variáveis definido na estrutura da stack.
    stack_elem onVariable = s->vars[index];

    // Um caso para cada tipo.
    switch(onVariable.type)
    {
        case STACK_INT: push(s, STACK_INT, onVariable.data.int_value); break;
        case STACK_FLOAT: push(s, STACK_FLOAT, onVariable.data.float_value); break;
        case STACK_DOUBLE: push(s, STACK_DOUBLE, onVariable.data.double_value); break;
        case STACK_CHAR: push(s, STACK_CHAR, onVariable.data.char_value); break;
        case STACK_STRING: push(s, STACK_STRING, onVariable.data.string_value); break;
        default: fprintf(stderr, "Erro ao adicionar elemento!\n[function::getVar]"); break;
    }

}

stack_type getSecondType(stack *s)
{
    stack_type type;

    // Pop do topo; peek do topo; push do topo.
    stack_elem elem = s->elems[s->pointer - 1];
    type = elem.type;

    return type;
}

void copyVarStack(stack *s)
{
    // Copiar as variáveis da stack para o array.
    stack_elem array = peek(s);

    for (int i = 0; i < 26; i++)
    {
        array.data.array_value->vars[i] = s->vars[i];
    }

}

void copyVarArray(stack *s)
{
    // Fazer o inverso da função de cima, queremos passar as variaveis do Array para as da stack.
    stack_elem array = peek(s);

    for (int i = 0; i < 26; i++)
    {
        s->vars[i] = array.data.array_value->vars[i];
    }
}