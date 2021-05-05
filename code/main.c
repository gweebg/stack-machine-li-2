/**
 * @file main.c - Módulo mestre
 * @copyright Copyright (c) 2021
 */

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>
# include <stdbool.h>

# include "stack.h"
# include "parser.h"
# include "array.h"

/**
 * @brief Esta é a função principal, responsável por receber o input do utilizador.
 * A função main é essencial para que o interpretador funcione, não só lê o input do utilizador como chama as funções contidas no módulo parser.c para analizar e realizar as operações necessárias de modo a fornecer um output válido.
 * @return 0, se o input foi lido e parsed com sucesso.
 * @see parser.c
 */
int main() {

    stack s = create(); // Criação da stack
    varStart(&s); // Inicialização das variáveis default.

    char input[10240]; // Tamanho máximo que a string pode tomar. Mudar para malloc

    // Usa o fgets para extrair do input do stdin e guarda na variavel input (usa o assert para garantir que algo é introduzido).
    assert( fgets(input, 10240, stdin) != NULL);

    // Verifica se o tamanho da string não ultrapassa os 10k.
    assert( input[strlen(input) - 1] == '\n' );

    // Chama o parser para fazer o parsing da string.
    parser(input, &s);

    // [DEBUG]
    // char *xd = getRestToken("[ 1 2 3 ] [ 4 5 6 ]");
    // char *x1 = getRestToken("[ 1 2 3 ] ola adeus");
    // char *x2 = getInside("[ [ 1 2 3 ] ]");
    char *x3 = getRestToken("[ 1 2 3 ] [ 4 5 6 ] x3 ");
    // char *x4 = getRestToken("[ 1 2 3 ] [ 4 5 6 ] [ 4 5 6 ] x4");
    // char *x5 = getRestToken("[ [ 1 2 3 ]  [ 1 2 3 ]] [ 4 5 6 ] x5");

    // printf("rest : %s\n",x1);
    // printf("dentro : %s\n",x2);
    printf("\n\nduas : %s\n",x3);
    // printf("tres : %s\n",x4);
    // printf("dentro dentro : %s\n",x5);

    //Print do estado final da stack.
    dumpStack(&s);

    return 0;

}
