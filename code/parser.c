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

#include "stack.h"
#include "parser.h"
#include "operations.h"
#include "array.h"

bool check_reserved(char c)
{

     char reserved[60] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ:+-*/()%#&|^~_;\\@$ltpifcs=<>!?[\",";
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
     char reserved[35][6] = {"e&", "e|", "e<", "e>", ":A", ":B", ":C", 
                             ":D", ":E", ":F",":G", ":H", ":I",":N", 
                             ":S", ":X", ":Y", ":U", ":V", ":W", ":X", 
                             ":J", ":K", ":L", ":M", ":O", ":P", ":Q", 
                             ":R", ":T", "S/", "N/"};

     for (int i = 0; i < 35; i++)
     {
          if (strcmp(s, reserved[i]) == 0) return true;
     }

     return false;
}

bool is_in_string(char *token, char *chars)
{
     
     // Queremos verificar se ambas string têm um char em comum.
     // O argumento chars poderá ser "+-/*%#()" que representam as funções aritméticas.
     int i = 0;

     while (chars[i] != '\0')
     {

          char r = chars[i];

          if (token[0] == r)
               return true; // True se é reservado

          i++;
     }

     return false; // False se não é reservado
}

bool check_logic(char* token)
{    
     // Conjunto de operadores lógico "avançados".
     char reserved[6][6] = {"e&", "e|", "e<", "e>"};

     for (int i = 0; i < 6; i++) // Vamos verificar se o token pertence a este grupo.
     {
          if (strcmp(token, reserved[i]) == 0) return true; // Devolve true se pertencer.

     }
     return false; // Devolve false, caso contrário.
}

bool check_array(char* token)
{    
     // Conjunto de operadores lógico "avançados".
     char reserved[2][6] = {"S/", "N/"};

     for (int i = 0; i < 2; i++) // Vamos verificar se o token pertence a este grupo.
     {
          if (strcmp(token, reserved[i]) == 0) return true; // Devolve true se pertencer.

     }
     return false; // Devolve false, caso contrário.
}

bool saveValues(stack *s, char* token)
{    
     bool pushed = true;

     char *endptr_int, *endptr_float;
     long int_value; float float_value;

     int_value = strtol(token, &endptr_int, 10);
     float_value = strtof(token, &endptr_float);

     // Push dos diferentes tipos para a stack.
     if (strlen(endptr_int) == 0) push(s, STACK_INT, int_value);
     else if (strlen(endptr_float) == 0) push(s, STACK_FLOAT, float_value);
     else if (strlen(token) == 1 && !check_reserved(token[0])) push(s, STACK_CHAR, token[0]);
     else if (strlen(token) > 1 && !check_reserved_string(token) && token[0] != '\"') push(s, STACK_STRING, token);
     else pushed = false;                                           // Precisamos para não dar push duplicados.

     return pushed;
}

void normal_arit(stack *s, char *token)
{
     if (strcmp(token, "+") == 0) add(s);
     else if (strcmp(token, "-") == 0) sub(s);
     else if (strcmp(token, "*") == 0) mult(s);
     else if (strcmp(token, "/") == 0) division(s);
     else if (strcmp(token, "#") == 0) power(s);
     else if (strcmp(token, "%") == 0) modulus(s);
     else if (strcmp(token, "(") == 0) dec(s);
     else inc(s);
}

void other_arit(stack *s, char *token)
{
     if (strcmp(token,"(") == 0) removeInit(s);
     else if (strcmp(token,")") == 0) removeEnd(s);
     else if (strcmp(token, "#") == 0) stringSearch(s);
     else if (strcmp(token, "/") == 0) splitSub(s);
     else if (strcmp(token, "*") == 0) concatSolo(s);
     else exit(EXIT_FAILURE);
}

void arit_op(stack *s, char* token)
{
     // Funções dedicadas a operações aritméticas.

     // Primeiro precisamos de verificar se o operador se refere a um array ou a um número.
     if (peek(s).type == STACK_STRING) other_arit(s,token);
     else if (peek(s).type == STACK_ARRAY) other_arit(s, token); // Se o elemento no topo não for um array, então procedemos com as funções ariteméticas.
     else if (getSecondType(s) == STACK_ARRAY) other_arit(s, token);
     else normal_arit(s, token);
}

void bin_op(stack *s, char* token)
{
     // Funções dedicadas a operações binárias.
     // Mais uma vez existem chars coicidentes com as operações dedicadas às arrays. O char ~.
     // Assim, é preciso verificar que o elemento no topo da stack não é um array.
     if (peek(s).type != STACK_ARRAY)
     {
          // printf("Entrei no if.");
          if (strcmp(token, "&") == 0) and(s);
          else if (strcmp(token, "|") == 0) or(s);
          else if (strcmp(token, "^") == 0) xor(s);
          else not(s);
     }
     else // Significa que o elemento no topo da stack é um array.
     {
          // Se entrou neste else, temos a certeza que o char pertence a "&|^~" e como o '~' é a única operação válida, não precisamos de fazer a verificação.
          // ~ Colocar na stack todos os elementos do array.
          // printf("Entrei no else.");
          dumpArray(s);
     }

}

void stack_op(stack *s, char* token)
{
     // Funções dedicadas à manipulação da stack.
     // Acontece a mesma coisa nesta função.
     if (peek(s).type != STACK_ARRAY)
     {
          if (strcmp(token, "_") == 0) duplicate(s);
          else if (strcmp(token, ";") == 0) pop(s);
          else if (strcmp(token, "\\") == 0) swap(s);
          else if (strcmp(token, "$") == 0) bring_top(s);
          else swap_three(s);
     }

}

void io_op(stack *s, char* token)
{
     // Funções dedicadas à leitura de dados.
     if (strcmp(token, "l") == 0) line_after (s);
     else if (strcmp(token, "p") == 0) peek_stack (s);
     else if (strcmp(token, "i") == 0) to_int(s);
     else if (strcmp(token, "f") == 0) to_double(s);
     else if (strcmp(token, "c") == 0) to_char(s);
     else if (strcmp(token, "s") == 0) to_string(s);
     else if (strcmp(token, "t") == 0) multipleLines(s); // A adicionar mais funções.
}

void logic_array(stack *s, char* token)
{
     switch(peek(s).type)
     {
          case STACK_INT:
               if (strcmp(token, "=") == 0) getValueByIndex(s);
               else if (strcmp(token, "<") == 0) getElemsInit(s); 
               else getElemsEnd(s);
               break;

          case STACK_STRING:
               if (strcmp(token, "=") == 0) equal(s);
               else if (strcmp(token, "<") == 0) less(s); 
               else greater(s);
               break;

          default: break;
     }
}

void logic_op(stack *s, char* token)
{
     // Funções dedicadas a operações lógicas básicas.
     // O char '=' é comum em duas operações, por isso é preciso verificar com que tipo estamos a trabalhar.
     if (getSecondType(s) != STACK_ARRAY && getSecondType(s) != STACK_STRING)
     {
          if (strcmp(token, "=") == 0) equal(s);
          else if (strcmp(token, "<") == 0) less(s);
          else if (strcmp(token, ">") == 0) greater(s);
          else if (strcmp(token, "!") == 0) invertBool(s);
          else ifThenElse(s);
     }
     else logic_array(s, token);
}

void logicPush_op(stack *s, char* token)
{
     // Funções dedicadas a operações lógicas.
     if (strcmp(token, "e<") == 0) smallest(s);
     else if (strcmp(token, "e>") == 0) largest(s);
     else if (strcmp(token, "e&") == 0) pushAnd(s);
     else pushOr(s); // (strcmp(token, "e|") == 0) 
}

int array_op(stack *s, char* token, char* line)
{    
     int e = 1;
     // printf("Entrou nas array_op!");
     if (strcmp(token, "[") == 0) { parseArray(s, line); e = 0; } 
     else if (token[0] == '\"') { parseString(s, line); e = 2; }
     else if (strcmp(token, ",") == 0) arrayRange(s);
     else if (strcmp(token, "S/") == 0) stripString(s, " "); // !BUG
     else if (strcmp(token, "N/") == 0) stripString(s, "\n"); // !BUG

     return e;
}

void parser(char *line, stack *s)
{    
     char *full_string = (char *)malloc(strlen(line) * sizeof(char));
     strcpy(full_string, line);

     char *delim = " \t\n";
     char *token = strtok(line, delim); // Divide a string tendo em conta delimitadores (definidos em delim).

     while (token != NULL)
     {
          int decide = 1;
          // printf("Token atual = %s\n",token);

          // Função que dá push dos diferentes elementos de diferentes tipos para a stack.
          bool pushed = saveValues(s,token);
          
          // Operações com números.
          if (is_in_string(token, "+-*/#%()")) arit_op(s, token);
          else if (is_in_string(token, "&|^~")) bin_op(s,token);

          // Operações com a stack.
          else if (is_in_string(token, "_;\\$@")) stack_op(s, token);
          
          // Operações de IO + conversão de tipos.
          else if (is_in_string(token, "lptifcs")) io_op(s, token);
          
          // Funções lógicas.
          else if (is_in_string(token, "=<>!?")) logic_op(s, token);
          else if (check_logic(token)) logicPush_op(s, token);

          // Funções com arrays.             // Guardo um valor inteiro em decide, isto vai indicar ao parser se esta função foi executada ou não.
          else if (is_in_string(token, "[,\"")) decide = array_op(s, token, full_string); // Passo a linha toda para poder retirar o que quero.
          else if (check_array(token)) array_op(s, token, full_string);

          // Handle de variáveis.
          else if (token[0] == ':') pushVar(s, token[1]);
          else if (!pushed) getVar(s, token[0]);

          if (decide == 0) { char *rest = getRestToken(full_string); parser(rest, s); break; }    
          if (decide == 2) { char *rest_ = getRestTokenS(full_string); parser(rest_, s); break; }    
          else { token = strtok(NULL, delim); } 
          
     }

}
