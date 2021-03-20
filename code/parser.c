# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>

# include "parser.h"

// Cenas da stack, depois passar para outro módulo (stack.c && stack.h)

int stack[512]; // Stack
int SIZE = 512;
int sp = -1; // Stack pointer

int stackStatus() {

    int r;

    if (sp == -1) {

        r = 0; // Retorna 0 caso a stack esteja vazia

    }
    else if (sp == SIZE) {

        r = 1; // Retorna 1 caso a stack esteja cheia

    }
    else {

        r = 2; // Retorna 2 caso a stack não esteja cheia nem vazia

    }

    return r;

}

int pop() {

    int r; 
    int status = stackStatus();

    if(status != 0) {

        r = stack[sp]; // Guarda o valor do topo no stack pointer (sp)
        sp -= 1; // Decrementa o sp, pois retiramos um elemento
        return r;

    }
    else {

        return 1; // Retorna 1 caso a stack esteja vazia

    }

}

int push(int value) {

    int status = stackStatus();

    if(status != 1) {

        sp += 1; // Incrementa 1 no stack pointer pois estamos a adicionar um elemento na stack
        stack[sp] = value; // Adiciona o valor na stack

    }
    else{

        return 1; // Retorna 1 caso a stack esteja cheia

    }

}

void parser(char *line) {
   
   char* delim = " \t\n";
   char* token = strtok(line,delim);  // Divide a string tendo em conta delimitadores (definidos em delim).

   char* endptr;
   long value;

   while (token != NULL) {
    
    value = strtol(token, &endptr, 10);

    if (strlen(endptr) == 0) {

        printf("%ld --> INT\n",value);

    }
    else{

        printf("%s\n", token);

    }

    token = strtok(NULL,delim);

   }
    
    // Debug

    // push(12);
    // push(23);
    // push(32);    

    // pop();
    // pop();

    // int status = stackStatus();
    // printf("Stack Status: %d\n",status);
}
