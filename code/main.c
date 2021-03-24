/**
 * @file main.c - Ficheiro principal
 * @author Grupo 3 PL4
 * @date 2021-03-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>

# include "parser.h"
# include "stack.h"


/**
 * @brief Esta é a função principal, responsável por receber o input do utilizador.
 * 
 * @return 0, se o input foi lido e parsed com sucesso. 
 */
int main() {

    char input[10240]; // Tamanho máximo que a string pode tomar.

    assert( fgets(input, 10240, stdin) != NULL); // Usa o fgets para extrair do input do stdin e guarda na variavel input (usa o assert para garantir que algo é introduzido).
    assert( input[strlen(input) - 1] == '\n' ); // Verifica se o tamanho da string não ultrapassa os 10k.

    // Chama o parser para fazer o parsing da string (parser.c).
    parser(input); 

    return 0;

}
