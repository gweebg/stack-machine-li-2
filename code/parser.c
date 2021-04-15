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

     char *reserved = "+-*/()%#&|^~_;\\@$ltpifcs";
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

bool check_reserved_string(char *s)
{
     char reserved[6][10] = {"e&", "e|", "e<", "e>"};

     for (int i = 0; i < 6; i++)
     {
          if (strcmp(s, reserved[i]) == 0) return true;
               
     }

     return false;  

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

          // Push dos diferentes tipos para a stack.
          if (strlen(endptr_int) == 0) push(&s, STACK_INT, int_value);
          else if (strlen(endptr_float) == 0) push(&s, STACK_FLOAT, float_value);
          else if (strlen(endptr_double) == 0) push(&s, STACK_DOUBLE, double_value);
          else if (strlen(token) == 1 && !check_reserved(token[0])) push(&s, STACK_CHAR, token[0]);
          else if (strlen(token) > 1 && !check_reserved_string(token)) push(&s, STACK_POINTER, token);

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
          else if (strcmp(token, "l") == 0) line_after (&s);
          else if (strcmp(token, "p") == 0) peek_stack (&s);

          // Funções para conversão de tipos.
          else if (strcmp(token, "i") == 0) to_int(&s);
          else if (strcmp(token, "f") == 0) to_double(&s);
          else if (strcmp(token, "c") == 0) to_char(&s);
          else if (strcmp(token, "s") == 0) to_string(&s);

          // Funções lógicas.
          else if (strcmp(token, "e>") == 0) largest(&s);
     
          token = strtok(NULL, delim);

     }

     dumpStack(&s);

     // int status = stackStatus(&s);
     // printf("Stack Status: %d\nStack pointer: %d\n", status, s.pointer);
}
