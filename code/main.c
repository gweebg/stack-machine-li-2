# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>

void parser(char *line) {
   
   char* delim = " \t\n";
   char* token = strtok(line,delim); 

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
}

int main() {

    char input[10240];

    assert( fgets(input, 10240, stdin) != NULL);
    assert( input[strlen(input) - 1] == '\n' );

    parser(input);

    return 0;

}
