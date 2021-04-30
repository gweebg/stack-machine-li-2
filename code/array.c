#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "stack.h"
#include "array.h"

/*
stack_elem array;
array.type = STACK_ARRAY;
array.data.array_value[10] = 1;
*/

// Tipo do array : stack_elem ??
// Exemplo de adição para stack : 
void example()
{

    stack_elem array1;
    array1.type = STACK_ARRAY; 
    array1.data.array_value.size = 100;
    array1.data.array_value.num = 0;
    array1.data.array_value.elems = malloc(array1.data.array_value.size * (sizeof(stack_elem)));

    stack_elem elem1;
    elem1.type = STACK_INT; elem1.data.int_value = 200;

    array1.data.array_value.elems[0] = elem1;

    printf("O valor no índice 0 é %d.\n", array1.data.array_value.elems[0]);


}