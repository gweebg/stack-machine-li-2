#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "stack.h"
#include "operations.h"

void add(stack *s)
{
    stack_elem x = pop(s);
    stack_elem y = pop(s);

    stack_type x_type = x.type;
    stack_type y_type = y.type;

    if (x_type == STACK_INT && y_type == STACK_INT) push(s, STACK_INT, x.data.int_value + y.data.int_value);
    else if (x_type == STACK_FLOAT && y_type == STACK_FLOAT) push(s, STACK_FLOAT, x.data.float_value + y.data.float_value);
    else if (x_type == STACK_INT && y_type == STACK_FLOAT) push(s, STACK_FLOAT, (x.data.int_value) + y.data.float_value);
    else if (x_type == STACK_FLOAT && y_type == STACK_INT) push(s, STACK_FLOAT, (x.data.float_value + y.data.int_value));
    else { fprintf(stderr, "Operação inválida!\n"); exit(EXIT_FAILURE); }
            
}

void sub(stack *s)
{
    stack_elem x = pop(s);
    stack_elem y = pop(s);

    stack_type x_type = x.type;
    stack_type y_type = y.type;

    if (x_type == STACK_INT && y_type == STACK_INT) push(s, STACK_INT, y.data.int_value - x.data.int_value);
    else if (x_type == STACK_FLOAT && y_type == STACK_FLOAT) push(s, STACK_FLOAT, y.data.float_value - x.data.float_value);
    else if (x_type == STACK_INT && y_type == STACK_FLOAT) push(s, STACK_FLOAT, (y.data.float_value) - x.data.int_value);
    else if (x_type == STACK_FLOAT && y_type == STACK_INT) push(s, STACK_FLOAT, (y.data.int_value - x.data.float_value));
    else { fprintf(stderr, "Operação inválida!\n"); exit(EXIT_FAILURE); }
}

void mult(stack *s)
{
    stack_elem x = pop(s);
    stack_elem y = pop(s);

    stack_type x_type = x.type;
    stack_type y_type = y.type;

    if (x_type == STACK_INT && y_type == STACK_INT) push(s, STACK_INT, x.data.int_value * y.data.int_value);
    else if (x_type == STACK_FLOAT && y_type == STACK_FLOAT) push(s, STACK_FLOAT, x.data.float_value * y.data.float_value);
    else if (x_type == STACK_INT && y_type == STACK_FLOAT) push(s, STACK_FLOAT, (x.data.int_value) * y.data.float_value);
    else if (x_type == STACK_FLOAT && y_type == STACK_INT) push(s, STACK_FLOAT, (x.data.float_value * y.data.int_value));
    else { fprintf(stderr, "Operação inválida!\n"); exit(EXIT_FAILURE); }
}

void division(stack *s)
{

    stack_elem x = pop(s);
    stack_elem y = pop(s);

    stack_type x_type = x.type;
    stack_type y_type = y.type;

    if (x_type == STACK_INT && y_type == STACK_INT) push(s, STACK_INT, y.data.int_value / x.data.int_value);
    else if (x_type == STACK_FLOAT && y_type == STACK_FLOAT) push(s, STACK_FLOAT, y.data.float_value / x.data.float_value);
    else if (x_type == STACK_INT && y_type == STACK_FLOAT) push(s, STACK_FLOAT, (y.data.float_value) / x.data.int_value);
    else if (x_type == STACK_FLOAT && y_type == STACK_INT) push(s, STACK_FLOAT, (y.data.int_value / x.data.float_value));
    else { fprintf(stderr, "Operação inválida!\n"); exit(EXIT_FAILURE); }
}

void power(stack *s)
{
    
    stack_elem x = pop(s);
    stack_elem y = pop(s);

    stack_type x_type = x.type;
    stack_type y_type = y.type;

    if (x_type == STACK_INT && y_type == STACK_INT) push(s, STACK_INT, (int)pow(y.data.int_value, x.data.int_value));
    else if (x_type == STACK_FLOAT && y_type == STACK_FLOAT) push(s, STACK_FLOAT, pow(y.data.float_value, x.data.float_value));
    else if (x_type == STACK_INT && y_type == STACK_FLOAT) push(s, STACK_FLOAT, pow((y.data.float_value), x.data.int_value));
    else if (x_type == STACK_FLOAT && y_type == STACK_INT) push(s, STACK_FLOAT, pow(y.data.int_value, x.data.float_value));
    else { fprintf(stderr, "Operação inválida!\n"); exit(EXIT_FAILURE); }
}

void modulus(stack *s)
{
    stack_elem x = pop(s);
    stack_elem y = pop(s);

    stack_type x_type = x.type;
    stack_type y_type = y.type;

    if (x_type == STACK_INT && y_type == STACK_INT) push(s, STACK_INT, y.data.int_value % x.data.int_value);
    else if (x_type == STACK_FLOAT && y_type == STACK_FLOAT) push(s, STACK_INT, (int)y.data.float_value % (int)x.data.float_value);
    else if (x_type == STACK_INT && y_type == STACK_FLOAT) push(s, STACK_INT, (int)(y.data.float_value) % x.data.int_value);
    else if (x_type == STACK_FLOAT && y_type == STACK_INT) push(s, STACK_INT, (y.data.int_value % (int)x.data.float_value));
    else { fprintf(stderr, "Operação inválida!\n"); exit(EXIT_FAILURE); }
}

void dec(stack *s)
{

    stack_elem x = pop(s);

    stack_type x_type = x.type;

    if (x_type == STACK_INT) push(s, STACK_INT, x.data.int_value - 1);
    else if (x_type == STACK_FLOAT) push(s, STACK_FLOAT, x.data.float_value - 1);
    else if (x_type == STACK_DOUBLE) push(s, STACK_FLOAT, x.data.double_value - 1);
    else { fprintf(stderr, "Operação inválida!\n"); exit(EXIT_FAILURE); }
}

void inc(stack *s)
{
    stack_elem x = pop(s);

    stack_type x_type = x.type;

    if (x_type == STACK_INT) push(s, STACK_INT, x.data.int_value + 1);
    else if (x_type == STACK_FLOAT) push(s, STACK_FLOAT, x.data.float_value + 1);
    else if (x_type == STACK_DOUBLE) push(s, STACK_FLOAT, x.data.double_value + 1);
    else { fprintf(stderr, "Operação inválida!\n"); exit(EXIT_FAILURE); }
}

// "bitwise operators are only defined for integral types, and do not work for floating pointing types"
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

/*
 * i Converter o topo da stack num inteiro
 * f Converter o topo da stack num double
 * c Converter o topo da stack para caratere
 * s Converter o topo da stack para string 
*/

void to_int(stack *s)
{
    stack_elem x = pop(s);
    stack_type x_type = x.type;

    if (x_type == STACK_INT)
        push(s, STACK_INT, x.data.int_value);
    else if (x_type == STACK_FLOAT)
        push(s, STACK_INT, (int)x.data.float_value);
    else if (x_type == STACK_CHAR)
        push(s, STACK_INT, (int)x.data.char_value);
    else
    {
        fprintf(stderr, "Operação inválida!\n");
        exit(EXIT_FAILURE);
    }
}

void to_double(stack *s)
{
    stack_elem x = pop(s);
    stack_type x_type = x.type;

    if (x_type == STACK_INT)
    {
        float num = (float)x.data.int_value;
        push(s, STACK_FLOAT, num);
    }
    else if (x_type == STACK_FLOAT)
    {
        push(s, STACK_DOUBLE, x.data.float_value);
    }
    else if (x_type == STACK_DOUBLE)
    {
        push(s, STACK_DOUBLE, x.data.float_value);
    }
    else if (x_type == STACK_POINTER)
    {
        char *string = x.data.string_value;
        double num = strtod(string, NULL);

        push(s, STACK_DOUBLE, num);
    }
    else
    {
        fprintf(stderr, "Operação inválida!\n");
        exit(EXIT_FAILURE);
    }
}

void to_char(stack *s)
{
    stack_elem x = pop(s);
    stack_type x_type = x.type;

    if (x_type == STACK_INT) push(s, STACK_CHAR, x.data.int_value);
    else if (x_type == STACK_FLOAT) 
    {
        float temp = x.data.float_value;
        int num = (int)temp;

        push(s, STACK_CHAR, num);

    }
    else if (x_type == STACK_DOUBLE)
    {
        double temp = x.data.double_value;
        int num = (int)temp;
        push(s, STACK_CHAR, num);

    }
    else if (x_type == STACK_POINTER)
    {
        char c = x.data.string_value[0];
        push(s, STACK_CHAR, c);

    }

}

// Função retirada de : https://stackoverflow.com/questions/9655202/how-to-convert-integer-to-string-in-c
char* itoa(int i, char b[]){
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}

void to_string(stack *s)
{
    stack_elem x = pop(s);
    stack_type x_type = x.type;

    if (x_type == STACK_INT)
    {
        char temp[SIZE];
        int num = x.data.int_value;

        itoa(num, temp);
        push(s, STACK_POINTER, temp);

    }

}
