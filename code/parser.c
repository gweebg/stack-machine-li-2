/**
 * @file parser.c - Módulo responsável por analisar e decompor o input do utilizador
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "parser.h"
#include "stack.h"
#include "operations.h"

bool check_reserved(char c)
{

     char *reserved = "+-*/()%#&|^~-;\\@$ltpifcs";
     int i = 0;

     while (reserved[i] != '\0')
     {

          char r = reserved[i];

          if (c == r)
               return true; // True se é reservado

          i++;
     }

     return false; // False se não é reservado
}

void parser(char *line)
{

     stack s = create();
     // printf("Stack criada com sucesso!\n");

     char *delim = " \t\n";
     char *token = strtok(line, delim); // Divide a string tendo em conta delimitadores (definidos em delim).

     char *endptr_int;
     char *endptr_float;
     char *endptr_double;

     long int_value;
     float float_value;
     double double_value;

     while (token != NULL)
     {

          int_value = strtol(token, &endptr_int, 10);
          float_value = strtof(token, &endptr_float);
          double_value = strtod(token, &endptr_double);

          if (strlen(endptr_int) == 0) push(&s, STACK_INT, int_value);
          else if (strlen(endptr_float) == 0) push(&s, STACK_FLOAT, float_value);
          else if (strlen(endptr_double) == 0) push(&s, STACK_DOUBLE, double_value);
          else if (strlen(token) == 1 && !check_reserved(token[0])) push(&s, STACK_CHAR, token[0]);
          else if (strlen(token) > 1) push(&s, STACK_POINTER, token);
          
          // Operações com números.
          else if (strcmp(token, "+") == 0) add(&s);
          else if (strcmp(token, "-") == 0) sub(&s);
          else if (strcmp(token, "*") == 0) mult(&s);
          else if (strcmp(token, "/") == 0) division(&s);
          else if (strcmp(token, "#") == 0) power(&s);
          else if (strcmp(token, "%") == 0) modulus(&s);
          else if (strcmp(token, "(") == 0) dec(&s);
          else if (strcmp(token, ")") == 0) inc(&s);
          else if (strcmp(token, "&") == 0) and(&s);
          else if (strcmp(token, "|") == 0) or(&s);
          else if (strcmp(token, "^") == 0) xor(&s);
          else if (strcmp(token, "~") == 0) not(&s);

          // Operações com a stack.
          else if (strcmp(token, "_") == 0) duplicate(&s);
          else if (strcmp(token, ";") == 0) pop(&s);
          else if (strcmp(token, "\\") == 0) swap(&s);
          else if (strcmp(token, "$") == 0) bring_top(&s);
          else if (strcmp(token, "@") == 0) swap_three(&s);
          
          // Operações de IO.
          else if (strcmp(token, "l") == 0)
          {
               char value[SIZE];
               assert(scanf("%s", value) == 1);
               push(&s, STACK_POINTER, value);
          }
          else if (strcmp(token, "p") == 0)
          {
               stack_elem top = peek(&s);

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

          token = strtok(NULL, delim);

          // TODO: Fazer função para ver os tipos dos 2 primeiros elementos
          // TODO: Usar esse tipo na conversão de dados e forçar a ser INT
          // Como está, dá 100% guião 1.
     }

     dumpStack(&s);

     // int status = stackStatus(&s);
     // printf("Stack Status: %d\nStack pointer: %d\n", status, s.pointer);
}
