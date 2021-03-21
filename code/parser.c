# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>

# include "parser.h"
# include "stack.h"

void parser(char *line) {

    stack s = create();
    printf("Stack criada com sucesso!\n");
   
    char* delim = " \t\n";
    char* token = strtok(line,delim);  // Divide a string tendo em conta delimitadores (definidos em delim).
 
    char* endptr;
    long value;
 
    while (token != NULL) {
     
     value = strtol(token, &endptr, 10);
 
     if (strlen(endptr) == 0) {
 
         printf("%ld --> INT\n",value);
         // push(value);
 
     }
     else{
 
         printf("%s\n", token);
 
     }
 
     token = strtok(NULL,delim);
 
    }
    
    // Debug - podem apagar na boa são só testes

    push(&s, 10);
    pop(&s);
    push(&s, 20);

    int status = stackStatus(&s);
    printf("Stack Status: %d\nStack pointer: %d\n",status, s.pointer);
}
