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

/**
 * \brief Esta função é responsável por verificar o tipo de operação que vai ser realizada
 * Visto ao detalhe, esta função quando dada duas strings compara-as para ver se, pelo menos, um char do argumento chars está presente no argumento token. 
 * @param[in] token String na qual vamos verificar a existência do operador.
 * @param[in] chars Conjunto de símbolos de operações. Por exemplo '+/-%#'.
 * @return Devolve um valor booleano. Sendo este verdadeiro caso existam chars em comum.
 */
bool is_in_string(char *token, char *chars);

/**
 * \brief Esta função é responsável por executar a operação pedida.
 * Executa a operação de uma determinada categoria, neste caso, operações ariteméticas. 
 * @param[in] s Stack dada pelo utilizador.
 * @param[in] token Operador a ser utilizado na operação.
 * @return É uma função do tipo void, daí não devolver nada.
 */
void arit_op(stack *s, char* token);

/**
 * \brief Esta função é responsável por executar as operações binárias.
 * @param[in] s Stack dada pelo utilizador.
 * @param[in] token Operador a ser utilizado na operação.
 * @return É uma função do tipo void, daí não devolver nada.
 */
void bin_op(stack *s, char* token);

/**
 * \brief Esta função é responsável por executar as operações direcionas à stack. Por exemplo, duplicar elementos, pop, rodar elementos, etc.
 * @param[in] s Stack dada pelo utilizador.
 * @param[in] token Operador a ser utilizado na operação.
 * @return É uma função do tipo void, daí não devolver nada.
 */
void stack_op(stack *s, char* token);

/**
 * \brief Esta função é responsável por executar as operações de input/output
 * Funções de leitura de dados são executadas nesta função. Por exemplo, ler uma linha ou ler múltiplas linhas.
 * @param[in] s Stack dada pelo utilizador.
 * @param[in] token Operador a ser utilizado na operação.
 * @return É uma função do tipo void, daí não devolver nada.
 */
void io_op(stack *s, char* token);

/**
 * \brief Esta função é responsável por executar as operações de conversão de dados
 * Por exmpleo conversão de char para inteiro.
 * @param[in] s Stack dada pelo utilizador.
 * @param[in] token Operador a ser utilizado na operação.
 * @return É uma função do tipo void, daí não devolver nada.
 */
void convert_op(stack *s, char* token);

/**
 * \brief Esta função é responsável por executar as operações lógicas simples
 * São consideradas funções lógicas simples as funções que não precisam de adicionar novos elementos na stack.
 * @param[in] s Stack dada pelo utilizador.
 * @param[in] token Operador a ser utilizado na operação.
 * @return É uma função do tipo void, daí não devolver nada.
 */
void logic_op(stack *s, char* token);

/**
 * \brief Esta função é responsável por executar as operações lógicas complexas
 * São consideradas funções lógicas simples as funções que adicionam um elemento anterior na stack.
 * @param[in] s Stack dada pelo utilizador.
 * @param[in] token Operador a ser utilizado na operação.
 * @return É uma função do tipo void, daí não devolver nada.
 */
void logicPush_op(stack *s, char* token);

#endif