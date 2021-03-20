# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>

# include "parser.h"

int main() {

    char input[10240];

    assert( fgets(input, 10240, stdin) != NULL);
    assert( input[strlen(input) - 1] == '\n' );

    parser(input);

    return 0;

}
