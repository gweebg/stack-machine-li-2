/**
 * @file block.h - Contém os protótipos das funções de block.c .
 * @copyright Copyright (c) 2021
 */

#ifndef BLOCK_H
#define BLOCK_H

#include "stack.h"

/**
  * \brief Quando é encontrado o char '{', esta função é executada e retorna a parte da string coorespondente ao bloco.
  * @param[in] line Linha onde o bloco está contido.
  * @return Devolve a parte da string coorespondente ao bloco.
  */
char* readBlock(char *line);

/**
  * \brief Dá push para a stack do bloco dado pela função readBlock().
  * @param[in] s Stack a ser avaliada.
  * @param[in] full_string String completa dada pelo utilizador no stdin.
  * @return Função do tipo void, não devolve nada.
  */
void pushBlock(stack *s, char *full_string);

/**
  * \brief Retira o primeiro e último char de um bloco (armazenado como string).
  * A pushBlock() mete na stack o bloco como uma string e inclui as chavetas, por isso, quando formos executar o bloco temos de lhe retirar o primeiro e último char.
  * @param[in] full_block Linha com o bloco dado pela readBlock().
  * @return Devolve a parte da string coorespondente ao bloco sem as chavetas.
  */
char* parseBlock(char *full_block);

/**
  * \brief Executa o bloco.
  * @param[in] full_block Linha com o bloco dado pela readBlock().
  * @return Devolve a parte da string coorespondente ao bloco sem as chavetas.
  */
void executeBlock(stack *s);

/**
 * \brief Esta função serve para atualizar o token após um bloco ter sido executado. 
 * Funciona do mesmo mode que a função getRestToken().
 * @param[in] line String que vai ser cortada.
 * @return Função do tipo void, não devolve nada.
 */
char* getRestTokenB(char *full_string);

#endif