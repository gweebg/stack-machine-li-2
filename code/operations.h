/**
 * @file operations.h - Contém os prótotipos do módulo operations.c
 * Para melhor legibilidade do código, separou-se as operações da Stack num módulo separado.
 * @copyright Copyright (c) 2021
 */

#ifndef OPERATIONS_H
#define OPERATIONS_H

// * Funções básicas com inteiros
/**
 * \brief Soma os dois elementos no topo da Stack
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada
 */
void add(stack *s);

/**
 * \brief Subtrai o penúltimo elemento da stack pelo o elemento no topo.
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */
void sub(stack *s);

/**
 * \brief Múltiplica os dois elementos no topo da stack.
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */
void mult(stack *s);

/**
 * \brief Divide os o penúltimo elemento da stack pelo o elemento no topo.
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */
void division(stack *s);

/**
 * \brief Retira o último elemento e penúltimo elemento da Stack (x e y, respetivamente) e insere a potência de base y e expoente x no topo da stack.
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */
void power(stack *s);

/**
 * \brief Altera os dois elementos do topo da stack para o resto da divisão do penúltimo elemento pelo topo.
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */
void modulus(stack *s);

/**
 * \brief Soma uma unidade ao elemento do topo da Stack. Funciona com char, tendo em conta código ASCII
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */
void inc(stack *s);

/**
 * \brief Subtrai uma unidade ao elemento do topo da stack.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 */
void dec(stack *s);

/**
 * \brief Altera os dois elementos do topo da stack para um inteiro com o valor lógico da sua conjunção binária.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 * @note Só funciona se os dois elementos do topo da stack forem inteiros ou carateres.
 */
void and(stack *s);

/**
 * \brief Altera os dois elementos do topo da stack para um inteiro com o valor lógico da sua disjunção binária.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 * @note Só funciona se os dois elementos do topo da stack forem inteiros ou carateres.
 */
void or(stack *s);

/**
 * \brief Altera os dois elementos do topo da stack para um inteiro com o valor lógico da sua disjunção exclusiva (1 só se um e só um elemento for 1).
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 * @note Só funciona se os dois elementos do topo da stack forem inteiros ou carateres.
 */
void xor(stack *s);

/**
 * \brief Negação binária do topo da stack.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 * @note Só funciona se o elemento do topo da stack for um inteiro.
 */
void not(stack *s);

// * Funções direcionadas à stack.
/**
 * \brief Duplica o topo da stack.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 */
void duplicate(stack *s);

/**
 * \brief Troca os dos dois elementos do topo da stack.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 */
void swap(stack *s);

/**
 * \brief Troca as posições dos 3 elementos do topo da stack (os elementos rodam entre si).
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 * @example A B C --> B C A
 */
void swap_three(stack *s);

/**
 * \brief Adiciona um elemento ao topo da stack, tendo este um índice igual ao valor do topo da stack original.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 * @example 7 2 3 2 $ --> 7 2 3 7
 * @bug Erro para floats.
 */
void bring_top(stack *s);


// * Funções direcionadas ao IO
/**
 * \brief Lê a próxima uma linha como string e dá push a esse valor (como string).
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 */
void line_after(stack *s);

/**
 * \brief Retorna o elemento do topo da stack.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 */
void peek_stack(stack *s);


// * Funções para conversão de tipos.
/**
 * \brief Altera o tipo do elemento do topo da stack para um inteiro.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 */
void to_int(stack *s);

/**
 * \brief Altera o tipo do elemento do topo da stack para um double.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 */
void to_double(stack *s);

/**
 * \brief Altera o tipo do elemento do topo da stack para um carátere.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 */
void to_char(stack *s);

/**
 * \brief Altera o tipo do elemento do topo da stack para uma string.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 */
void to_string(stack *s);

/**
 * \brief Retira dois elementos da stack e dá push ao maior dos dois.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 */
void largest(stack *s);

/**
 * \brief Dado uma string, a função determina se é um caratere com um valor associado.
 * @param[in] s Stack a ser avaliada.
 * @param[in] var String a ser comparada.
 * @return Não devolve nada.
 */
void choose_var(stack *s, char *var);

#endif