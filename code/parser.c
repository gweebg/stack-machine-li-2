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

bool check_reserved(char c)
{

     char *reserved = "ltpifcsw+-/&%#*";
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

     // Queremos iterar sobre todos os tokens na string dada.
     // Mudar isto para outro módulo / função, está feio assim.
     while (token != NULL)
     {

          int_value = strtol(token, &endptr_int, 10);
          float_value = strtof(token, &endptr_float);
          double_value = strtod(token, &endptr_double);

          if (strlen(endptr_int) == 0)
          {
               // Pushes integer/long to stack
               push(&s, STACK_INT, int_value);
          }
          else if (strlen(endptr_float) == 0)
          {
               // Pushes float to stack
               push(&s, STACK_FLOAT, float_value);
          }
          else if (strlen(endptr_double) == 0)
          {
               // Pushes double to stack
               push(&s, STACK_DOUBLE, double_value);
          }
          // else if (strlen(token) == 1)
          // {

          //      char c = token[0]; // Como temos a certeza de que a string só tem um elemento, podemos aceder ao seu primeiro elemento para depois usar no push.
          //      // Temos de verificar se o char não é um comando
          //      if (!check_reserved(c))
          //           push(&s, STACK_CHAR, c); // Push do caratére c para a stack.
          // }
          else if (strlen(token) > 1)
          {
               // Push da string para a stack.
               push(&s, STACK_POINTER, token);
          }
          else if (strcmp(token, "+") == 0)
          {

               // printf("%s\n", token);
               int x = pop(&s).data.int_value;
               int y = pop(&s).data.int_value;

               push(&s, STACK_INT, x + y);
               // printf("%d + %d = %d\n", x, y, (x+y));
          }
          else if (strcmp(token, "-") == 0)
          {

               // printf("%s\n", token);
               int x = pop(&s).data.int_value;
               int y = pop(&s).data.int_value;

               push(&s, STACK_INT, y - x);
               // printf("%d - %d = %d\n", x, y, (y-x));
          }
          else if (strcmp(token, "*") == 0)
          {

               // printf("%s\n", token);
               int x = pop(&s).data.int_value;
               int y = pop(&s).data.int_value;

               push(&s, STACK_INT, x * y);
               // printf("%d * %d = %d\n", x, y, (x*y));
          }
          else if (strcmp(token, "/") == 0)
          {

               // printf("%s\n", token);
               int x = pop(&s).data.int_value;
               int y = pop(&s).data.int_value;

               push(&s, STACK_INT, y / x);
               // printf("%d / %d = %d\n", y, x, (y/x));
          }
          else if (strcmp(token, "#") == 0)
          {

               // printf("%s\n", token);
               int x = pop(&s).data.int_value;
               int y = pop(&s).data.int_value;

               push(&s, STACK_INT, (int)pow(y, x));
               // printf("%d ^ %d = %f\n", y, x, (pow(y,x)));

          }
          else if (strcmp(token, "%") == 0)
          {

               // printf("%s\n", token);
               int x = pop(&s).data.int_value;
               int y = pop(&s).data.int_value;

               push(&s, STACK_INT, y % x);
               // printf("%d + %d = %d\n", x, y, (x+y));
          }
          else if (strcmp(token, "(") == 0)
          {

               // printf("%s\n", token);
               int x = pop(&s).data.int_value;
               push(&s, STACK_INT, x - 1);
               // printf("%d + %d = %d\n", x, y, (x+y));
          }
          else if (strcmp(token, ")") == 0)
          {

               // printf("%s\n", token);
               int x = pop(&s).data.int_value;
               push(&s, STACK_INT, x + 1);
               // printf("%d + %d = %d\n", x, y, (x+y));
          }
          else if (strcmp(token, "&") == 0)
          {

               int x = pop(&s).data.int_value;
               int y = pop(&s).data.int_value;

               push(&s, STACK_INT, y & x);
               // printf("%d & %d = %d\n", y, x, y&x);
          }
          else if (strcmp(token, "|") == 0)
          {

               int x = pop(&s).data.int_value;
               int y = pop(&s).data.int_value;

               push(&s, STACK_INT, y | x);
          }
          else if (strcmp(token, "^") == 0)
          {

               int x = pop(&s).data.int_value;
               int y = pop(&s).data.int_value;

               push(&s, STACK_INT, y ^ x);
          }
          else if (strcmp(token, "~") == 0)
          {

               int x = pop(&s).data.int_value;
               push(&s, STACK_INT, ~x);
          }

          else if (strcmp(token, "l") == 0)
          {
              char* value;
              scanf("%s"), &value;
              push(&s, STACK_POINTER, value);
          }

          else if(strcmp(token, "p") == 0)
          {
              stack_elem top = peek(&s);

              if(top.type == STACK_CHAR)
              {
                printf("%c\n", top.data.char_value);
              }

              else if(top.type == STACK_POINTER)
              {
                printf("%s\n", top.data.string_value);
              }

              else if(top.type == STACK_INT)
              {
                  printf("%i\n", top.data.int_value);
              }

              else if(top.type == STACK_LONG)
              {
                  printf("%i\n", top.data.long_value);
              }

              else if(top.type == STACK_FLOAT)
              {
                  printf("%f\n", top.data.float_value);
              }

              else if(top.type == STACK_DOUBLE)
              {
                  printf("%f\n", top.data.string_value);
              }

              else
                printf("ERRO: topo da stack com formato desconhecido.");

          }


          token = strtok(NULL, delim);

          // TODO: Fazer função para ver os tipos dos 2 primeiros elementos
          // TODO: Usar esse tipo na conversão de dados e forçar a ser INT
          // Como está, dá 100% guião 1.
     }

     // push(&s, STACK_CHAR, 'a');
     // printf("Pushed 'a' to the stack.\n");

     // push(&s, STACK_INT, 20);
     // printf("Pushed 20 to the stack.\n");

     // push(&s, STACK_POINTER, "ola");
     // printf("Pushed 'ola' to the stack.\n");

     // push(&s, STACK_FLOAT, 10.10);
     // printf("Pushed 10.10 to the stack.\n\n");

     // pop(&s);

     dumpStack(&s);
     // printf("\n");

     // pop(&s);

     // int status = stackStatus(&s);
     // printf("Stack Status: %d\nStack pointer: %d\n", status, s.pointer);
}
