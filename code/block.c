/**
 * @file parser.c - Módulo responsável por executar funções relacionadas a blocos.
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "stack.h"
#include "parser.h"
#include "operations.h"
#include "block.h"

char* readBlock(char *line)
{
    // Esta função vai ser executada quando é lido o token '{'. 
    // Queremos pegar em tudo dentro das chavetas incluindo-as.

    // Contagem de '{' e '}'.
    int count = 0;

    // O start indica-nos a primeira posição do char '{' e o end do '}'.
    int start = 0;
    int end = 0;
    int c = 0;

    // Variável temporária onde vamos guardar partes da linha orginial.
    char *string = (char *)malloc(strlen(line) * sizeof(char));

    // Posição do primeiro '{' :: start.
    for (unsigned long i = 0; i < strlen(line); i++)
    {
        if (line[i] == '{')
        {
            start = i;
            break; // Temos de dar break pois queremos apenas a primeira ocorrência do '{'.
        }
    }

    // Posição do '}' coorespondente ao '{' definido acima.
    for (unsigned long j = 0; j <= strlen(line); j++)
    {
        if (line[j] == '{')
            count++; // Precisamos de saber a contagem dos '{'.
        else if (line[j] == '}')
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
    for (int z = 0; z <= end; z++)
    {
        string[c] = line[z];
        c++;
    }

    // printf("Linha depois do for : %s\n",string);

    // Agora removemos o lixo da direita.
    char *final = (char *)malloc(sizeof(char) * strlen(line));

    // Sabemos onde o char '[' está, assim podemos usar o strncpy para copiar para *final, a parte da string que começa do indíce do start+1.
    strncpy(final, &string[start], strlen(string) - start);
    free(string);
    // printf("[DEBUG]: %s\n", final);

    return final; // Finalmente retornamos a string modificada.
}

void pushBlock(stack *s, char *full_string)
{
    // Obter o input parsed.
    char *string = readBlock(full_string);
    // Mandar o bloco para a stack.
    push(s, STACK_BLOCK, string);
}

char* parseBlock(char *full_block)
{
    // Retira o primeiro e último char de uma string.
    int len = strlen(full_block); 

    if(len > 0) full_block++; // Retira full_block[0]
    if(len > 1) full_block[len - 2] = '\0'; // Substitui full_block[size-2] por '\0' para retirar o último char.
    
    // Devolve a string modificada.
    return full_block;
}

void executeBlock(stack *s)
{
    // Obter o bloco.
    char *block = parseBlock(pop(s).data.block_value);
    // printf("%s\n", block);
    parser(block, s); // Chama-se o parser para tratar do que está dentro do bloco.

    return;
}

char* getRestTokenB(char *full_string)
{
    int count = 0;
    int end = 0;

    char *result = (char *)malloc(strlen(full_string) * sizeof(char) + 1);

    for (unsigned long j = 0; j < strlen(full_string); j++)
    {
        if (full_string[j] == '{')
            count++; // Precisamos de saber a contagem dos '{'.
        else if (full_string[j] == '}')
        {
            if (count % 2 != 0) // Se o numero total de chars '{}' for ímpar significa que o proximo '}' fecha o primeiro '{'.
            {
                end = j;
                break;
            }

            count++;
        }
    }

    strncpy(result, &full_string[end + 1], strlen(full_string) - end);
    // printf("[DEBUG]: %s\n", result);

    return result;
}