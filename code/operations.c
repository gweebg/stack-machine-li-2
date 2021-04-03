#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "stack.h"
#include "operations.h"

// void add(stack *s)
// {
//     int x = pop(s).data.int_value;
//     int y = pop(s).data.int_value;

//     push(s, STACK_INT, x + y);
// }

void add(stack *s)
{
    stack_elem x = pop(s);
    stack_elem y = pop(s);

    stack_type x_type = x.type;
    stack_type y_type = y.type;

    if (x_type == STACK_INT && y_type == STACK_INT) push(s, STACK_INT, x.data.int_value + y.data.int_value);
    else if (x_type == STACK_FLOAT && y_type == STACK_FLOAT) push(s, STACK_FLOAT, x.data.float_value + y.data.float_value);
    else if (x_type == STACK_DOUBLE && y_type == STACK_DOUBLE) push(s, STACK_DOUBLE, x.data.double_value + y.data.double_value);
    else if (x_type == STACK_INT && y_type == STACK_FLOAT) push(s, STACK_FLOAT, (x.data.int_value) + y.data.float_value);
    else if (x_type == STACK_FLOAT && y_type == STACK_INT) push(s, STACK_FLOAT, (x.data.float_value + y.data.int_value));
    else { fprintf(stderr, "Operação inválida!\n"); exit(EXIT_FAILURE); }
            
}

void sub(stack *s)
{
    int x = pop(s).data.int_value;
    int y = pop(s).data.int_value;

    push(s, STACK_INT, y - x);
}

void mult(stack *s)
{
    int x = pop(s).data.int_value;
    int y = pop(s).data.int_value;

    push(s, STACK_INT, x * y);
}

void division(stack *s)
{

    int x = pop(s).data.int_value;
    int y = pop(s).data.int_value;

    push(s, STACK_INT, y / x);
}

void power(stack *s)
{
    int x = pop(s).data.int_value;
    int y = pop(s).data.int_value;

    push(s, STACK_INT, (int)pow(y, x));
}

void modulus(stack *s)
{
    int x = pop(s).data.int_value;
    int y = pop(s).data.int_value;

    push(s, STACK_INT, y % x);
}

void dec(stack *s)
{
    int x = pop(s).data.int_value;

    push(s, STACK_INT, x - 1);
}

void inc(stack *s)
{
    int x = pop(s).data.int_value;

    push(s, STACK_INT, x + 1);
}

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

void duplicate(stack *s)
{
    // Duplicar o que está no topo
    stack_elem top = peek(s);
    stack_type type = top.type;

    push(s, type, top.data);
}

void swap(stack *s)
{
    stack_elem x = pop(s);
    stack_elem y = pop(s);

    push(s, x.type, x.data);
    push(s, y.type, y.data);
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