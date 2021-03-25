/**
 * @file parser.c - Módulo responsável por analisar e decompor o input do utilizador
 * @copyright Copyright (c) 2021
 */

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>
# include <math.h>

# include "parser.h"
# include "stack.h"

void parser(char *line) {

    stack s = create();
    // printf("Stack criada com sucesso!\n");
   
    char* delim = " \t\n";
    char* token = strtok(line,delim);  // Divide a string tendo em conta delimitadores (definidos em delim).
    
    char* endptr;
    long value;       

    // Queremos iterar sobre todos os tokens na string dada.
    // Mudar isto para outro módulo / função, está feio assim.
    while (token != NULL) {
                 
        value = strtol(token, &endptr, 10);
 
        if (strlen(endptr) == 0) {
     
             // printf("Pushed %ld (INT) to the stack.\n",value);
             push(&s,value);
     
        }
        else if (strcmp(token, "+") == 0) {
     
             int x = pop(&s);
             int y = pop(&s);
             push(&s, x+y);
            // printf("%d + %d = %d\n", x, y, (x+y));
     
        }
        else if (strcmp(token, "-") == 0) {
  
             int x = pop(&s);
             int y = pop(&s);
             push(&s, y-x);
             // printf("%d - %d = %d\n", y, x, (y-x));
  
        }
        else if (strcmp(token, "*") == 0) {
  
             int x = pop(&s);
             int y = pop(&s);
             push(&s, x*y);
             // printf("%d * %d = %d\n", x, y, (x*y));
  
        }
        else if (strcmp(token, "/") == 0) {
  
             int x = pop(&s);
             int y = pop(&s);
             push(&s, y/x);
             // printf("%d / %d = %d\n", x, y, (y/x));
  
        }
        else if (strcmp(token, "(") == 0) {
  
             int x = pop(&s);
             push(&s, x-1);
             // printf("%d-- = %d\n", x, x-1);
  
        }
        else if (strcmp(token, ")") == 0) {
     
             int x = pop(&s);
             push(&s, x+1);
             // printf("%d++ = %d\n", x, x+1);
     
        }
        else if (strcmp(token, "%") == 0) {
     
             int x = pop(&s);
             int y = pop(&s);
             push(&s, y % x);
             // printf("%d mod %d = %d\n", y, x, (y%x)); 
     
        }
        else if (strcmp(token, "#") == 0) {
     
              int x = pop(&s);
              int y = pop(&s);
              push(&s, pow(y,x));
              // printf("%d ^ %d = %f\n", y, x, pow(y,x));
     
        }
        else if (strcmp(token, "&") == 0) {
     
              int x = pop(&s);
              int y = pop(&s);
              push(&s, y & x);
              // printf("%d & %d = %d\n", y, x, y&x);
     
        } 
        else if (strcmp(token, "|") == 0) {
        
              int x = pop(&s);
              int y = pop(&s);
              push(&s, y | x);
              // printf("%d | %d = %d\n", y,x,y|x);
        
        }
        else if (strcmp(token, "^") == 0) {
        
              int x = pop(&s);
              int y = pop(&s);
              push(&s, y ^ x);
              // printf("%d ^ %d = %d\n", y,x,y^x);
        
        }
        else if (strcmp(token, "~") == 0) {
        
              int x = pop(&s);
              push(&s, ~x);
              // printf("not %d = %d\n",x,!x);
        
        }
   
        token = strtok(NULL,delim);
 
    }

    dumpStack(&s);
    
    /*
    Debug - podem apagar na boa são só testes

    push(&s, 10);
    pop(&s);
    push(&s, 20);

    printf("Resultado: %d\n", pop(&s));

    int status = stackStatus(&s);
    printf("Stack Status: %d\nStack pointer: %d\n",status, s.pointer);
    */
}
