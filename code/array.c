#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "stack.h"
#include "array.h"
#include "parser.h"

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
    int end = 0; // Posição onde está o char ']'.
    int start = 0; // Posição do char '['.
    // Precisamos de alocar memória para a string.
    char *string = (char*)malloc(sizeof(char) * strlen(line));
    int c = 0; // Contador usado mais abaixo.

    // Loop para calcular o start.
    for (long unsigned i = 0; i < strlen(line); i++)
    {
        // Definimos os limites da parte que queremos.
        if (line[i] == '[') 
        {
            start = i;
            break; // Apenas queremos a primeira ocorrência.
        }
    }

    // Loop para calcular o end. É preciso este loop, pois podem existir arrays aninhados, ou seja, se fizessemos a travessia da esquerda para a direita apenas a obter o indice da primeira ocorrência do char ']'.
    for (long unsigned i = strlen(line); i > 0; i--)
    {
        // Definimos os limites da parte que queremos.
        if (line[i] == ']') 
        {
            end = i;
            break;
        }
    }

    // printf("end %d \n",end);

    // Agora que temos a posição dos brackets, queremos extrair o seu conteúdo.
    // Começamos por remover o lixo na esquerda.
    for (int j = 0; j < end; j++)
    {
        string[c] = line[j];
        c++;
    }

    // printf("Linha depois do for : %s\n",string);

    // Agora removemos o lixo da direita.
    char *final = (char*)malloc(sizeof(char) * strlen(line));

    // Sabemos onde o char '[' está, assim podemos usar o strncpy para copiar para *final, a parte da string que começa do indíce do start+1. 
    strncpy(final, &string[start + 1], strlen(string) - start);
    printf("[DEBUG]: %s\n", final);

    return final; // Finalmente retornamos a string modificada.
}

char* getRestToken(char *line)
{
    int end = 0;
    char *result = malloc(strlen(line) * sizeof(char));

    // Loop para calcular o end.
    for (long unsigned i = strlen(line); i > 0; i--)
    {
        // Definimos os limites da parte que queremos.
        if (line[i] == ']') 
        {
            end = i;
            break;
        }
    }

    strncpy(result, &line[end + 1], strlen(line) - end);
    printf("[DEBUG]: %s\n", result);

    return result;
}

// Tipo int, porque vai devolver o status, 0 se executou esta função, 1 caso contrário. 
void parseArray(stack *s, char *line) // Vai atualizar o token para depois do []
{
    initArray(s); // Iniciamos o array, pois encontramos o char '['. 
    // printf("\nLinha passada : %s\n",line);

    char *parsed = getInside(line); // parsed passa a ser a string com o conteudo do array que vai ser processado pelo parser.
    printf("A string é : %s\n", parsed);

    stack_elem array = peek(s); // Isto vai nos dar o array.
    printf("[Array pointer] : %d\n",array.data.array_value->pointer);

    parser(parsed, array.data.array_value);
    printf("Executou o parser.\n");
    
    free(parsed);
}

