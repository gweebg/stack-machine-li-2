/**
 * @file parser.h - Contém os prótotipos do módulo parser.c
 * @copyright Copyright (c) 2021
 */

#ifndef PARSER_H
#define PARSER_H

/**
 * \brief Esta função é responsável por tanto analisar o input como realizar as operações necessárias.
 * 
 * @param[in] line Input dado pelo utilizador em main.c
 * @return Não devolve nada.
 * @see main.c
 */
void parser(char *line, stack *s);

/**
 * \brief Esta função é responsável por verificar se um dado caráter está reservado a um comando ou não.
 * 
 * @param[in] c Caráter dado pelo utilizador.
 * @return 
 * Devolve :
 * * True, se o caráter for reservado.
 * * False, se o caráter não for reservado.
 */
bool check_reserved(char c);

/**
 * \brief Esta função é responsável por verificar se uma dada string está reservada a um comando ou não.
 * 
 * @param[in] s String dado pelo utilizador.
 * @return 
 * Devolve :
 * * True, se a string for reservada.
 * * False, se a string não for reservada.
 */
bool check_reserved_string(char *s);

bool is_in_string(char *token, char *chars);

#endif