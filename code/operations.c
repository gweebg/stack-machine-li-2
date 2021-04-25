/**
 * @file operations.c - Contém todas as funções para poder realizar as operações da linguagem.
 * Para melhor legibilidade do código, separou-se as operações da Stack num módulo separado.
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

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

    if (x.type == STACK_FLOAT && y.type == STACK_FLOAT)
    {
        push(s, STACK_FLOAT, x.data.float_value);
        push(s, STACK_FLOAT, y.data.float_value);
    }
    else if (x.type == STACK_FLOAT && y.type == STACK_INT)
    {
        push(s, STACK_FLOAT, x.data.float_value);
        push(s, STACK_INT, y.data.int_value);
    }
    else if (x.type == STACK_INT && y.type == STACK_FLOAT)
    {
        push(s, STACK_INT, x.data.int_value);
        push(s, STACK_FLOAT, y.data.float_value);
    }
    else
    {
        push(s, x.type, x.data);
        push(s, y.type, y.data);
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

void largest(stack *s)
{

    stack_elem x = pop(s);
    stack_elem y = pop(s);

    if (x.type == STACK_INT && y.type == STACK_INT)
    {
        if (x.data.int_value < y.data.int_value)
            push(s, STACK_INT, y.data.int_value);
    }
    else if (x.type == STACK_FLOAT && y.type == STACK_FLOAT)
    {
        if (x.data.float_value < y.data.float_value)
            push(s, STACK_FLOAT, y.data.float_value);
    }
    else if (x.type == STACK_INT && y.type == STACK_FLOAT)
    {
        if (x.data.int_value < y.data.float_value)
            push(s, STACK_FLOAT, y.data.float_value);
    }
    else if (x.type == STACK_FLOAT && y.type == STACK_INT)
    {
        if (x.data.float_value < y.data.int_value)
            push(s, STACK_INT, y.data.int_value);
    }
    else if (x.type == STACK_CHAR && y.type == STACK_CHAR)
    {
        if (x.data.char_value < y.data.char_value)
            push(s, STACK_CHAR, y.data.char_value);
    }
}

// * Operações relacionadas com variáveis

/*
:<Letra> Copia topo da stack à variável
A Valor por omissão: 10
B Valor por omissão: 11
C Valor por omissão: 12
D Valor por omissão: 13
E Valor por omissão: 14
F Valor por omissão: 15
N Valor por omissão: '\n'
S Valor por omissão: ' '
X Valor por omissão: 0
Y Valor por omissão: 1
Z Valor por omissão: 2
*/

void choose_var(stack *s, char *var)
{
    // Na parser.c estamos a filtrar pelo caratere ":" por isso, aqui, temos de usar o segundo elemento da string.
    // Daí vem o var[1]. O programa ignora qualquer outro char na frente do token pois estamos apenas a filtrar por :A, :B...
    switch(var[0])
    {
        case 'A': // A = 10
            push(s, STACK_INT, 10);
            break;
        case 'B': // B = 11
            push(s, STACK_INT, 11);
            break;
        case 'C': // C = 12
            push(s, STACK_INT, 12);
            break;
        case 'D': // D = 13
            push(s, STACK_INT, 13);
            break;
        case 'E': // E = 14
            push(s, STACK_INT, 14);
            break;
        case 'F': // F = 15
            push(s, STACK_INT, 15);
            break;
        case 'N': // N = "\n"
            push(s, STACK_POINTER, "\n");
            break;
        case 'S': // S = " "
            push(s, STACK_POINTER, " ");
            break;
        case 'X': // X = 0
            push(s, STACK_INT, 0);
            break;
        case 'Y': // Y = 1
            push(s, STACK_INT, 1);
            break;
        case 'Z': // Z = 2
            push(s, STACK_INT, 2);
            break;
        default: // Esta parte nunca vai correr, o filtro impede que alguma variavel não definida entre.
            fprintf(stderr, "Variável não existente!\n");
            exit(EXIT_FAILURE);
            break;
    }

}
