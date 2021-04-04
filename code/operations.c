#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "stack.h"
#include "operations.h"

void add(stack *s)
{
    int x = pop(s).data.int_value;
    int y = pop(s).data.int_value;

    push(s, STACK_INT, x + y);
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


void line_after (stack *s)
{
    char value[SIZE];
    assert(scanf("%s", value) == 1);
    push(s, STACK_POINTER, value);
}

void peek_stack (stack *s)
{
    stack_elem top = peek(s);

    if (top.type == STACK_CHAR)
    {
         printf("%c\n", top.data.char_value);
    }

    else if (top.type == STACK_POINTER)
    {
         printf("%s\n", top.data.string_value);
    }

    else if (top.type == STACK_INT)
    {
         printf("%d\n", top.data.int_value);
    }

    else if (top.type == STACK_LONG)
    {
         printf("%li\n", top.data.long_value);
    }

    else if (top.type == STACK_FLOAT)
    {
         printf("%f\n", top.data.float_value);
    }

    else if (top.type == STACK_DOUBLE)
    {
         printf("%f\n", top.data.double_value);
    }

    else
    {
         fprintf(stderr, "O tipo não existe!\n");
         exit(EXIT_FAILURE);
    }
}
