#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "stack.h"
#include "array.h"
#include "parser.h"

void printArray(stack *s)
{
    printf("[");
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
    printf("]");
}

void splitString(stack *s, char *string)
{
    char *delim = "\n";
    char *token = strtok(string, delim);

    while(token != NULL)
    {
        push(s, STACK_STRING, token);
        // printf("Push do %s\n",token);
        token = strtok(NULL, delim);
    }
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
        strcat(result,temp); // Introduzimos a linha lida no result.
    }

    // Meter na stack a string acumulada.
    splitString(s, result);
}

void initArray(stack *s)
{

    stack_elem array; // Inicialização do array.
    array.type = STACK_ARRAY; // Tipo do elemento.
    array.data.array_value = (stack *)malloc(s->size * sizeof(stack)); // Alocação de memória para o array.

    array.data.array_value->size = s->size; // Tamanho do array
    array.data.array_value->pointer = -1; // Índice do elemento no topo do array.
    array.data.array_value->elems = (stack_elem *)malloc(s->size * sizeof(stack_elem)); // Alocação de memória para os elementos doa array.

    push(s, STACK_ARRAY, array.data.array_value);
}

char* getInside(char *line)
{
    // Contagem de '[' e ']'.
    int count = 0;
    // O start indica-nos a primeira posição do char '[' e o end do ']'.
    int start = 0; int end = 0; int c = 0;
    // Variável temporária onde vamos guardar partes da linha orginial.
    char *string = (char *)malloc(strlen(line) * sizeof(char));

    // Posição do primeiro '['. [start]
    for (unsigned long i = 0; i < strlen(line); i++)
    {
        if (line[i] == '[')
        { 
            start = i; 
            break; // Temos de dar break pois queremos apenas a primeira ocorrência do '['.
        }
    }

    // printf("Indice do '[' : %d\n", start);

    // Posição do ']' coorespondente ao '[' definido acima. [end]
    for (unsigned long j = 0; j < strlen(line); j++)
    {
        if (line[j] == '[') count++; // Precisamos de saber a contagem dos '['. 
        else if (line[j] == ']') 
        {            
            if (count % 2 != 0) // Se o numero total de chars '[]' for ímpar significa que o proximo ']' fecha o primeiro '['.
            {
                end = j;
                break;
            }       

            count++;
        }
    }

    // Agora que temos a posição dos brackets, queremos extrair o seu conteúdo.
    // Começamos por remover o lixo na esquerda.
    for (int z = 0; z < end; z++)
    {
        string[c] = line[z];
        c++;
    }

    // printf("Linha depois do for : %s\n",string);

    // Agora removemos o lixo da direita.
    char *final = (char*)malloc(sizeof(char) * strlen(line));

    // Sabemos onde o char '[' está, assim podemos usar o strncpy para copiar para *final, a parte da string que começa do indíce do start+1. 
    strncpy(final, &string[start + 1], strlen(string) - start);
    free(string);
    // printf("[DEBUG]: %s\n", final);

    return final; // Finalmente retornamos a string modificada.
}

char* getRestToken(char *line)
{
    int count = 0; int end = 0;

    char *result = (char*)malloc(strlen(line) * sizeof(char));

    for (unsigned long j = 0; j < strlen(line); j++)
    {
        if (line[j] == '[') count++; // Precisamos de saber a contagem dos '['. 
        else if (line[j] == ']') 
        {            
            if (count % 2 != 0) // Se o numero total de chars '[]' for ímpar significa que o proximo ']' fecha o primeiro '['.
            {
                end = j;
                break;
            }       

            count++;
        }
    }

    strncpy(result, &line[end + 1], strlen(line) - end);
    // printf("[DEBUG]: %s\n", result);

    return result;
}

// Tipo int, porque vai devolver o status, 0 se executou esta função, 1 caso contrário. 
void parseArray(stack *s, char *line) // Vai atualizar o token para depois do []
{
    initArray(s); // Iniciamos o array, pois encontramos o char '['. 
    // varStart(s); Inicializar as variaveis.
    // printf("\nLinha passada : %s\n",line);

    char *parsed = getInside(line); // parsed passa a ser a string com o conteudo do array que vai ser processado pelo parser.
    printf("A string é : %s\n", parsed);

    stack_elem array = peek(s); // Isto vai nos dar o array.
    // printf("[Array pointer] : %d\n",array.data.array_value->pointer);

    parser(parsed, array.data.array_value);
    // printf("Executou o parser.\n");
}

// ===============================
// Operações com arrays.
// ===============================

void typePush(stack *s, stack_elem elem)
{
    switch (elem.type)
    {
        case STACK_INT: push(s, STACK_INT, elem.data.int_value); break; 
        case STACK_FLOAT:push(s, STACK_FLOAT, elem.data.float_value); break; 
        case STACK_CHAR: push(s, STACK_CHAR, elem.data.char_value); break; 
        case STACK_STRING: push(s, STACK_STRING, elem.data.string_value); break; 
        case STACK_ARRAY: push(s, STACK_ARRAY, elem.data.array_value); break; 
        default: fprintf(stderr, "Erro na funçao [typePush] em array.c : switch to default.\n"); exit(EXIT_FAILURE); break;
    }
}

void dumpArray(stack *s) // ~ Colocar na stack todos os elementos do array
{
    stack_elem array = pop(s); 

    if (array.type == STACK_ARRAY) // Só para ter a certeza que é um array.
    {
        for (int i = 0; i < array.data.array_value->pointer + 1; i++)
        {
            // A função typePush dá push do elemento para a stack de acordo com o tipo do elemento.
            typePush(s, array.data.array_value->elems[i]);
        }
    }
}

void spawnArray(stack *s, int size)
{

    initArray(s); // Criar um novo array na nossa stack.
    stack_elem array = pop(s); // Vamos aceder ao nosso array.
    // printf("Tipo : %d\n", array.type);

    for (int i = 0; i < size; i++) push(array.data.array_value, STACK_INT, i);
    
    push(s, STACK_ARRAY, array.data.array_value); // Voltamos a inserir o array na stack.
}

void arrayRange(stack *s)
{
    // Primeira coisa a ser verificada é se o elemento anterior é um array ou um inteiro.
    // Caso seja inteiro n, criamos um array com n elementos. 
    // Caso seja um array, pushamos para a stack o tamanho do array.

    stack_elem elem = pop(s);
    // printf("Elem: %d\n", elem.data.int_value);

    switch(elem.type)
    {
        case STACK_INT: spawnArray(s, elem.data.int_value); break;
        case STACK_ARRAY: push(s, STACK_INT, elem.data.array_value->pointer + 1); break;
        default: fprintf(stderr, "Erro na funçao [typePush] em array.c : tipo inválido.\n"); exit(EXIT_FAILURE); break;
    } 
}

void getValueByIndex(stack *s)
{
    // Número do índice.
    stack_elem index = pop(s);
    // Esta função só se aplica a arrays, por isso temos a certeza que ao dar pop(s) vamos obter um array.
    stack_elem array = pop(s);

    if (index.type == STACK_INT && array.type == STACK_ARRAY) // Só para confirmar :D
        typePush(s, array.data.array_value->elems[index.data.int_value]);
}


/**
""   Criar uma string
+    Concatenar strings ou arrays (ou array/string com elemento)
*     Concatenar várias vezes strings ou arrays
#    Procurar substring na string e devolver o índice ou -1 se não encontrar
**/