/**
 * @file operations.c - Contém todas as funções para poder realizar as operações da linguagem.
 * Para melhor legibilidade do código, separou-se as operações da Stack num módulo separado.
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "operations.h"

// * Operações com números.
void add(stack *s)
{
    stack_elem x = pop(s);
    stack_elem y = pop(s);

    if (x.type == STACK_INT && y.type == STACK_INT)
        push(s, STACK_INT, x.data.int_value + y.data.int_value);
    else if (x.type == STACK_FLOAT && y.type == STACK_FLOAT)
        push(s, STACK_FLOAT, x.data.float_value + y.data.float_value);
    else if (x.type == STACK_INT && y.type == STACK_FLOAT)
        push(s, STACK_FLOAT, (x.data.int_value) + y.data.float_value);
    else if (x.type == STACK_FLOAT && y.type == STACK_INT)
        push(s, STACK_FLOAT, (x.data.float_value + y.data.int_value));
    else
    {
        fprintf(stderr, "Operação inválida!\n");
        exit(EXIT_FAILURE);
    }
}

void sub(stack *s)
{
    stack_elem x = pop(s);
    stack_elem y = pop(s);

    if (x.type == STACK_INT && y.type == STACK_INT)
        push(s, STACK_INT, y.data.int_value - x.data.int_value);
    else if (x.type == STACK_FLOAT && y.type == STACK_FLOAT)
        push(s, STACK_FLOAT, y.data.float_value - x.data.float_value);
    else if (x.type == STACK_INT && y.type == STACK_FLOAT)
        push(s, STACK_FLOAT, (y.data.float_value) - x.data.int_value);
    else if (x.type == STACK_FLOAT && y.type == STACK_INT)
        push(s, STACK_FLOAT, (y.data.int_value - x.data.float_value));
    else
    {
        fprintf(stderr, "Operação inválida!\n");
        exit(EXIT_FAILURE);
    }
}

void mult(stack *s)
{
    stack_elem x = pop(s);
    stack_elem y = pop(s);

    if (x.type == STACK_INT && y.type == STACK_INT)
        push(s, STACK_INT, x.data.int_value * y.data.int_value);
    else if (x.type == STACK_FLOAT && y.type == STACK_FLOAT)
        push(s, STACK_FLOAT, x.data.float_value * y.data.float_value);
    else if (x.type == STACK_INT && y.type == STACK_FLOAT)
        push(s, STACK_FLOAT, (x.data.int_value) * y.data.float_value);
    else if (x.type == STACK_FLOAT && y.type == STACK_INT)
        push(s, STACK_FLOAT, (x.data.float_value * y.data.int_value));
    else
    {
        fprintf(stderr, "Operação inválida!\n");
        exit(EXIT_FAILURE);
    }
}

void division(stack *s)
{

    stack_elem x = pop(s);
    stack_elem y = pop(s);

    stack_type x_type = x.type;
    stack_type y_type = y.type;

    if (x_type == STACK_INT && y_type == STACK_INT)
        push(s, STACK_INT, y.data.int_value / x.data.int_value);
    else if (x_type == STACK_FLOAT && y_type == STACK_FLOAT)
        push(s, STACK_FLOAT, y.data.float_value / x.data.float_value);
    else if (x_type == STACK_INT && y_type == STACK_FLOAT)
        push(s, STACK_FLOAT, (y.data.float_value) / x.data.int_value);
    else if (x_type == STACK_FLOAT && y_type == STACK_INT)
        push(s, STACK_FLOAT, (y.data.int_value / x.data.float_value));
    else
    {
        fprintf(stderr, "Operação inválida!\n");
        exit(EXIT_FAILURE);
    }
}

void power(stack *s)
{

    stack_elem x = pop(s);
    stack_elem y = pop(s);

    stack_type x_type = x.type;
    stack_type y_type = y.type;

    if (x_type == STACK_INT && y_type == STACK_INT)
        push(s, STACK_INT, (int)pow(y.data.int_value, x.data.int_value));
    else if (x_type == STACK_FLOAT && y_type == STACK_FLOAT)
        push(s, STACK_FLOAT, pow(y.data.float_value, x.data.float_value));
    else if (x_type == STACK_INT && y_type == STACK_FLOAT)
        push(s, STACK_FLOAT, pow((y.data.float_value), x.data.int_value));
    else if (x_type == STACK_FLOAT && y_type == STACK_INT)
        push(s, STACK_FLOAT, pow(y.data.int_value, x.data.float_value));
    else
    {
        fprintf(stderr, "Operação inválida!\n");
        exit(EXIT_FAILURE);
    }
}

void modulus(stack *s)
{
    stack_elem x = pop(s);
    stack_elem y = pop(s);

    stack_type x_type = x.type;
    stack_type y_type = y.type;

    if (x_type == STACK_INT && y_type == STACK_INT)
        push(s, STACK_INT, y.data.int_value % x.data.int_value);
    else if (x_type == STACK_FLOAT && y_type == STACK_FLOAT)
        push(s, STACK_INT, (int)y.data.float_value % (int)x.data.float_value);
    else if (x_type == STACK_INT && y_type == STACK_FLOAT)
        push(s, STACK_INT, (int)(y.data.float_value) % x.data.int_value);
    else if (x_type == STACK_FLOAT && y_type == STACK_INT)
        push(s, STACK_INT, (y.data.int_value % (int)x.data.float_value));
    else
    {
        fprintf(stderr, "Operação inválida!\n");
        exit(EXIT_FAILURE);
    }
}

void dec(stack *s)
{

    stack_elem x = pop(s);

    switch (x.type)
    {
    case STACK_INT:
        push(s, STACK_INT, x.data.int_value - 1);
        break;
    case STACK_FLOAT:
        push(s, STACK_FLOAT, x.data.float_value - 1);
        break;
    case STACK_DOUBLE:
        push(s, STACK_FLOAT, x.data.double_value - 1);
        break;
    case STACK_CHAR:
        push(s, STACK_CHAR, x.data.char_value - 1);
        break;
    default:
        fprintf(stderr, "Operação inválida!\n");
        exit(EXIT_FAILURE);
        break;
    }
}

void inc(stack *s)
{
    stack_elem x = pop(s);

    switch (x.type)
    {
    case STACK_INT:
        push(s, STACK_INT, x.data.int_value + 1);
        break;
    case STACK_FLOAT:
        push(s, STACK_FLOAT, x.data.float_value + 1);
        break;
    case STACK_DOUBLE:
        push(s, STACK_FLOAT, x.data.double_value + 1);
        break;
    case STACK_CHAR:
        push(s, STACK_CHAR, x.data.char_value + 1);
        break;
    default:
        fprintf(stderr, "Operação inválida!\n");
        exit(EXIT_FAILURE);
        break;
    }
}

// ? "bitwise operators are only defined for integral types, and do not work for floating pointing types"
void and (stack * s)
{
    int x = pop(s).data.int_value;
    int y = pop(s).data.int_value;

    push(s, STACK_INT, y & x);
}

void or (stack * s)
{

    int x = pop(s).data.int_value;
    int y = pop(s).data.int_value;

    push(s, STACK_INT, y | x);
}

void xor (stack * s) {
    int x = pop(s).data.int_value;
    int y = pop(s).data.int_value;

    push(s, STACK_INT, y ^ x);
}

    void not(stack * s)
{

    int x = pop(s).data.int_value;
    push(s, STACK_INT, ~x);
}

// * Operações com a stack.

void duplicate(stack *s)
{
    stack_elem top = peek(s);

    switch (top.type)
    {
    case STACK_FLOAT:
        push(s, STACK_FLOAT, top.data.float_value);
        break;
    default:
        push(s, top.type, top.data);
    }
}

void swap(stack *s)
{
    stack_elem x = pop(s);
    stack_elem y = pop(s);

    switch (x.type)
    {
    case (STACK_CHAR):
        push(s, x.type, x.data.char_value);
        break;

    case (STACK_INT):
        push(s, x.type, x.data.int_value);
        break;

    case (STACK_FLOAT):
        push(s, x.type, x.data.float_value);
        break;

    case (STACK_POINTER):
        push(s, x.type, x.data.string_value);
        break;

    default:
        push(s, x.type, x.data);
    }

    switch (y.type)
    {
    case (STACK_CHAR):
        push(s, y.type, y.data.char_value);
        break;

    case (STACK_INT):
        push(s, y.type, y.data.int_value);
        break;

    case (STACK_FLOAT):
        push(s, y.type, y.data.float_value);
        break;

    case (STACK_POINTER):
        push(s, y.type, y.data.string_value);
        break;

    default:
        push(s, x.type, y.data);
    }
}

void swap_three(stack *s)
{
    stack_elem a = pop(s);
    stack_elem b = pop(s);
    stack_elem c = pop(s);

    // a b c --> b c a (lembrando que c está no topo da stack)

    push(s, b.type, b.data);
    push(s, a.type, a.data);
    push(s, c.type, c.data);
}

void bring_top(stack *s)
{
    int val = pop(s).data.int_value;
    int index = s->pointer - val;

    stack_elem new_val = s->elems[index];
    push(s, new_val.type, new_val.data);
}

// * Funções de IO.

void line_after(stack *s)
{
    char value[10240]; // Mudar para malloc
    assert(scanf("%s", value) == 1);
    push(s, STACK_POINTER, value);
}

void peek_stack(stack *s)
{
    stack_elem top = peek(s);

    switch (top.type)
    {
    case STACK_CHAR:
        printf("%c\n", top.data.char_value);
        break;
    case STACK_POINTER:
        printf("%s\n", top.data.string_value);
        break;
    case STACK_INT:
        printf("%d\n", top.data.int_value);
        break;
    case STACK_LONG:
        printf("%li\n", top.data.long_value);
        break;
    case STACK_FLOAT:
        printf("%f\n", top.data.float_value);
        break;
    case STACK_DOUBLE:
        printf("%f\n", top.data.double_value);
        break;
    default:
        fprintf(stderr, "O tipo não existe!\n");
        exit(EXIT_FAILURE);
        break;
    }
}

// * Funções de conversão de tipos.

void to_int(stack *s)
{
    stack_elem x = pop(s);

    switch (x.type)
    {
    case STACK_INT:
        push(s, STACK_INT, x.data.int_value);
        break;
    case STACK_FLOAT:
        push(s, STACK_INT, (int)x.data.float_value);
        break;
    case STACK_CHAR:
        push(s, STACK_INT, (int)x.data.char_value);
        break;
    case STACK_POINTER:;
        char *end;
        int num = strtol(x.data.string_value, &end, 10);

        push(s, STACK_INT, num);
        break;
    default:
        fprintf(stderr, "Operação inválida!\n");
        exit(EXIT_FAILURE);
        break;
    }
}

void to_double(stack *s)
{
    stack_elem x = pop(s);

    switch (x.type)
    {
    case STACK_INT:;
        float num = (float)x.data.int_value;
        push(s, STACK_FLOAT, num);
        break;
    case STACK_FLOAT:
        push(s, STACK_FLOAT, x.data.float_value);
        break;
    case STACK_DOUBLE:
        push(s, STACK_FLOAT, x.data.float_value);
        break;
    case STACK_POINTER:;
        char *end;
        float num_ = strtof(x.data.string_value, &end);

        push(s, STACK_FLOAT, num_);
        break;
    default:
        fprintf(stderr, "Operação inválida!\n");
        exit(EXIT_FAILURE);
        break;
    }
}

void to_char(stack *s)
{
    stack_elem x = pop(s);

    switch (x.type)
    {
    case STACK_INT:
        push(s, STACK_CHAR, x.data.int_value);
        break;
    case STACK_CHAR:
        push(s, STACK_CHAR, x.data.char_value);
        break;
    case STACK_FLOAT:;
        float temp = x.data.float_value;
        int num = (int)temp;

        push(s, STACK_CHAR, num);
        break;
    case STACK_DOUBLE:;
        double temp_ = x.data.double_value;
        int num_ = (int)temp_;

        push(s, STACK_CHAR, num_);
        break;
    case STACK_POINTER:;
        char c = x.data.string_value[0];
        push(s, STACK_CHAR, c);
        break;
    default:
        push(s, STACK_CHAR, x.data.int_value);
        break;
    }
}

void to_string(stack *s)
{
    stack_elem x = pop(s);

    switch (x.type)
    {
    case STACK_INT:;
        char temp[SIZE];
        int num = x.data.int_value;

        sprintf(temp, "%d", num);
        push(s, STACK_POINTER, temp);
        break;
    case STACK_FLOAT:;
        float num_ = x.data.float_value;
        char temp_[SIZE];

        sprintf(temp_, "%g", num_);
        push(s, STACK_POINTER, temp_);
        break;
    case STACK_CHAR:;
        char c = x.data.char_value;
        char temp__[SIZE];

        temp__[0] = c;
        push(s, STACK_POINTER, temp__);
        break;
    default:
        push(s, STACK_POINTER, x.data.string_value);
        break;
    }
}

// * Operações lógicas

/*
0 ou {} -> False
!= 0 -> Verdadeiro
= -> Igual
< -> Menor
> -> Maior
! -> Não
e& -> E (com shortcut)
e| -> Ou (com shortcut)
e< -> Coloca o menor dos 2 valores na stack
e> -> Coloca o maior dos 2 valores na stack
? -> If-Then-Else
*/

int checkNbool(stack *s, int n)
{
    n--;
    while (n >= 0)
    {
        if ((s->elems[(s->pointer)]).type != STACK_INT)
            return 0;
    }
    return 1;
}

void equal(stack *s)
{
    // Queremos os dois elementos no topo da stack.
    stack_elem x = pop(s);
    stack_elem y = pop(s);

    // Precisamos de passar todos os casos possíveis de tipos.
    // Por exemplo Int-Int ; Int-Float ; Float-Int
    // ! É preciso criar uma função para "automatizar" este processo.
    if (x.type == STACK_INT && y.type == STACK_INT && (x.data.int_value == y.data.int_value))
    {
        push(s, STACK_INT, 1);
    }
    else if (x.type == STACK_FLOAT && y.type == STACK_FLOAT && (x.data.float_value == y.data.float_value))
    {
        push(s, STACK_FLOAT, 1);
    }
    else if (x.type == STACK_CHAR && y.type == STACK_CHAR && (x.data.char_value == y.data.char_value))
    {
        push(s, STACK_FLOAT, 1);
    }
    else if (x.type == STACK_POINTER && y.type == STACK_POINTER && (strlen(x.data.string_value) == strlen(y.data.string_value)))
    {
        push(s, STACK_INT, 1);
    }
    else if (x.type == STACK_INT && y.type == STACK_FLOAT && ((float)x.data.int_value == y.data.float_value))
    {
        push(s, STACK_INT, 1);
    }
    else if (x.type == STACK_FLOAT && y.type == STACK_INT && (x.data.float_value == (float)y.data.int_value))
    {
        push(s, STACK_INT, 1);  
    }
    else
    {
        push(s, STACK_INT, 0); 
    }
}

void less(stack *s)
{
    stack_elem x = pop(s);
    stack_elem y = pop(s);

    if (x.type == STACK_INT && y.type == STACK_INT && (x.data.int_value > y.data.int_value))
    {
        push(s, STACK_INT, 1);
    }
    else if (x.type == STACK_FLOAT && y.type == STACK_FLOAT && (x.data.float_value > y.data.float_value))
    {
        push(s, STACK_FLOAT, 1);
    }
    else if (x.type == STACK_CHAR && y.type == STACK_CHAR && (x.data.char_value > y.data.char_value))
    {
        push(s, STACK_FLOAT, 1);
    }
    else if (x.type == STACK_POINTER && y.type == STACK_POINTER && (strlen(x.data.string_value) > strlen(y.data.string_value)))
    {
        push(s, STACK_INT, 1);
    }
    else
    {
        push(s, STACK_INT, 0);
    }
}

void greater(stack *s)
{
    stack_elem x = pop(s);
    stack_elem y = pop(s);

    if (x.type == STACK_INT && y.type == STACK_INT && (x.data.int_value < y.data.int_value))
    {
        push(s, STACK_INT, 1);
    }
    else if (x.type == STACK_FLOAT && y.type == STACK_FLOAT && (x.data.float_value < y.data.float_value))
    {
        push(s, STACK_FLOAT, 1);
    }
    else if (x.type == STACK_CHAR && y.type == STACK_CHAR && (x.data.char_value < y.data.char_value))
    {
        push(s, STACK_FLOAT, 1);
    }
    else if (x.type == STACK_POINTER && y.type == STACK_POINTER && (strlen(x.data.string_value) < strlen(y.data.string_value)))
    {
        push(s, STACK_INT, 1);
    }
    else
    {
        push(s, STACK_INT, 0);
    }
}

void pushAnd(stack *s)
{
    stack_elem y = pop(s);
    stack_elem x = pop(s);

    double a, b;
    switch (x.type)
    {
    case STACK_INT:
        a = x.data.int_value;
        break;

    case STACK_FLOAT:
        a = x.data.float_value;
        break;

    case STACK_POINTER:
        a = atoi(x.data.string_value);
        break;

    default:
        a = 0;
        break;
    }

    switch (y.type)
    {
    case STACK_INT:
        b = y.data.int_value;
        break;

    case STACK_FLOAT:
        b = y.data.float_value;
        break;

    case STACK_POINTER:
        b = atoi(y.data.string_value);
        break;

    default:
        b = 0;
        break;
    }
    if (a && b)
    {
        switch (x.type)
        {
        case STACK_INT:
            push(s, x.type, (int)a);
            break;
        case STACK_FLOAT:
            push(s, x.type, a);
            break;
        case STACK_POINTER:
            push(s, x.type, x.data.string_value);
            break;

        default:
            push(s, x.type, a);
            break;
        }
    }
    else
        push(s, STACK_INT, 0);
}

void pushOr(stack *s)
{
    stack_elem y = pop(s);
    stack_elem x = pop(s);
    double a, b;
    switch (x.type)
    {
    case STACK_INT:
        a = x.data.int_value;
        break;
    case STACK_FLOAT:
        a = x.data.float_value;
        break;
    case STACK_POINTER:
        a = atoi(x.data.string_value);
        break;

    default:
        a = 0;
        break;
    }

    switch (y.type)
    {
    case STACK_INT:
        b = y.data.int_value;
        break;

    case STACK_FLOAT:
        b = y.data.float_value;
        break;

    case STACK_POINTER:
        b = atoi(y.data.string_value);
        break;

    default:
        b = 0;
        break;
    }

    if (a)
    {
        switch (x.type)
        {
        case STACK_INT:
            push(s, x.type, (int)a);
            break;
        case STACK_FLOAT:
            push(s, x.type, a);
            break;
        case STACK_POINTER:
            push(s, x.type, x.data.string_value);
            break;

        default:
            push(s, x.type, a);
            break;
        }
    }

    else
    {
        switch (y.type)
        {
        case STACK_INT:
            push(s, y.type, (int)b);
            break;
        case STACK_FLOAT:
            push(s, y.type, b);
            break;
        case STACK_POINTER:
            push(s, y.type, y.data.string_value);
            break;

        default:
            push(s, x.type, b);
            break;
        }
    }
}

void smallest(stack *s)
{

    stack_elem x = pop(s);
    stack_elem y = pop(s);

    if (x.type == STACK_INT && y.type == STACK_INT)
    {
        if (x.data.int_value > y.data.int_value)
            push(s, STACK_INT, y.data.int_value);
        else
            push(s, STACK_INT, x.data.int_value);
    }
    else if (x.type == STACK_FLOAT && y.type == STACK_FLOAT)
    {
        if (x.data.float_value > y.data.float_value)
            push(s, STACK_FLOAT, y.data.float_value);
        else
            push(s, STACK_FLOAT, x.data.float_value);
    }
    else if (x.type == STACK_INT && y.type == STACK_FLOAT)
    {
        if (x.data.int_value > y.data.float_value)
            push(s, STACK_FLOAT, y.data.float_value);
        else
            push(s, STACK_FLOAT, x.data.float_value);
    }
    else if (x.type == STACK_FLOAT && y.type == STACK_INT)
    {
        if (x.data.float_value > y.data.int_value)
            push(s, STACK_INT, y.data.int_value);
        else
            push(s, STACK_INT, x.data.int_value);
    }
    else if (x.type == STACK_CHAR && y.type == STACK_CHAR)
    {
        if (x.data.char_value > y.data.char_value)
            push(s, STACK_CHAR, y.data.char_value);
        else
            push(s, STACK_CHAR, x.data.char_value);
    }
}

void largest(stack *s)
{
    stack_elem x = pop(s);
    stack_elem y = pop(s);

    if (x.type == STACK_INT && y.type == STACK_INT)
    {
        if (x.data.int_value < y.data.int_value)
            push(s, STACK_INT, y.data.int_value);
        else
            push(s, STACK_INT, x.data.int_value);
    }
    else if (x.type == STACK_FLOAT && y.type == STACK_FLOAT)
    {
        if (x.data.float_value < y.data.float_value)
            push(s, STACK_FLOAT, y.data.float_value);
        else
            push(s, STACK_FLOAT, x.data.float_value);
    }
    else if (x.type == STACK_INT && y.type == STACK_FLOAT)
    {
        if (x.data.int_value < y.data.float_value)
            push(s, STACK_FLOAT, y.data.float_value);
        else
            push(s, STACK_FLOAT, x.data.float_value);
    }
    else if (x.type == STACK_FLOAT && y.type == STACK_INT)
    {
        if (x.data.float_value < y.data.int_value)
            push(s, STACK_INT, y.data.int_value);
        else
            push(s, STACK_INT, x.data.int_value);
    }
    else if (x.type == STACK_CHAR && y.type == STACK_CHAR)
    {
        if (x.data.char_value < y.data.char_value)
            push(s, STACK_CHAR, y.data.char_value);
        else
            push(s, STACK_CHAR, x.data.char_value);
    }
}

void invertBool(stack *s)
{
    stack_elem x = pop(s);

    switch (x.type)
    {
    case STACK_INT:
        if ((x.data.int_value) != 0)
            push(s, STACK_INT, 0);
        else
            push(s, STACK_INT, 1);
        break;
    case STACK_FLOAT:
        if ((x.data.float_value) != 0.0)
            push(s, STACK_INT, 0);
        else
            push(s, STACK_INT, 1);
        break;
    case STACK_CHAR:
        if ((x.data.char_value) != 0)
            push(s, STACK_INT, 0);
        else
            push(s, STACK_INT, 1);
        break;
    default:
        push(s, STACK_INT, 0);
        break;
    }
}

void ifThenElse(stack *s)
{
    stack_elem x = pop(s);
    stack_elem y = pop(s);
    stack_elem z = pop(s); // Conditional

    if (z.data.int_value)
        push(s, STACK_INT, y.data.int_value);
    else
        push(s, STACK_INT, x.data.int_value);
}
