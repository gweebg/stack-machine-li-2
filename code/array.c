#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "stack.h"
#include "array.h"

int example()
{
    // Iniciar o array.
    stack_elem array;
    array.type = STACK_ARRAY;
    array.data.array_value = malloc(SIZE * sizeof(stack_elem));
    array.data.array_value->size = SIZE;
    array.data.array_value->elems = malloc(array.data.array_value->size * sizeof(stack_elem));
    array.data.array_value->pointer = 0;

    stack_elem a;
    a.type = STACK_INT;
    a.data.int_value = 11;
    stack_elem b;
    b.type = STACK_FLOAT;
    b.data.float_value = 22.22;
    stack_elem c;
    c.type = STACK_STRING;
    c.data.string_value = "Rin";

    array.data.array_value->elems[array.data.array_value->pointer] = a;
    array.data.array_value->pointer++;
    array.data.array_value->elems[array.data.array_value->pointer] = b;
    array.data.array_value->pointer++;
    array.data.array_value->elems[array.data.array_value->pointer] = c;
    array.data.array_value->pointer++;

    printf("Elementos do array :\n0 -> %d\n1 -> %g\n2 -> %s\n", a.data.int_value, b.data.float_value, c.data.string_value);

    return 0;
}



char* chop(char *s)
{
    s[strcspn(s, "\n" )] = ' '; // strcspn calcula o índice da string onde o "\n" está contido. Assim podemos substituir todos os "\n" por white spaces.
    return s;
}

void multipleLines(stack *s)
{
    char temp[1024]; // String temporária.
    char result[10240]; // String final onde tudo vai ser guardada.

    // Vamos ler as linhas enquanto o fgets não for null.
    while (fgets(temp, sizeof(temp), stdin))
    {
        // Para garantir que o tamanho não ultrapassa os 1024 bytes.
        assert(temp[strlen(temp) - 1] == '\n');
        strcat(result,chop(temp));
    }

    // Meter na stack a string acumulada.
    push(s, STACK_STRING, result);

}