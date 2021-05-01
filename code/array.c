#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "stack.h"
#include "array.h"

int example()
{
    stack_elem array;
    array.type = STACK_ARRAY;
    array.data.array_value = malloc(100 * sizeof(stack_elem));

    array.data.array_value[0].size = 100;
    array.data.array_value[0].elems = malloc(array.data.array_value[0].size * sizeof(stack_elem));
    array.data.array_value[0].num = 0;

    stack_elem elem, elem2, elem3;
    elem.type = STACK_INT; elem2.type = STACK_FLOAT; elem3.type = STACK_ARRAY;
    elem.data.int_value = 10; elem2.data.float_value = 22.22; elem3.data.array_value = malloc(100 * sizeof(stack_elem));
                                        
    array.data.array_value[0].elems[array.data.array_value[0].num] = elem; array.data.array_value[0].num++;
    array.data.array_value[0].elems[array.data.array_value[0].num] = elem2; array.data.array_value[0].num++;
    array.data.array_value[0].elems[array.data.array_value[0].num] = elem3; array.data.array_value[0].num++;

    printf("Elem 1 : %d \nElem 2 : %d \n Elem 3 : %d \n",array.data.array_value[0].elems[0].type,
                                                         array.data.array_value[0].elems[1].type,
                                                         array.data.array_value[0].elems[2].type);
    
    return 1;

}
