/**
 * @file operations.h - Contém os prótotipos do módulo operations.c
 * Para melhor legibilidade do código, separou-se as operações da Stack num módulo separado.
 * @copyright Copyright (c) 2021
 */

#ifndef OPERATIONS_H
#define OPERATIONS_H

// * Função de decisão de tipo.

/**
 * \brief Verifica as combinações possíveis dos tipos dos dois elementos.
 * @param[in] s Stack a ser alterada.
 * @return Devolve um inteiro coorespondente à combinação
 * Tabela de valores:
 * * 0 - Int - Int
 * * 1 - Int - Float
 * * 2 - Float - Int
 * * 3 - Float - Float
 */
int operationType(stack_elem x, stack_elem y);

// * Funções básicas com inteiros
/**
 * \brief Soma os dois elementos no topo da Stack
 * @param[in] s Stack a ser alterada.
 * @return Função é do tipo void
 */
void add(stack *s);

/**
 * \brief Subtrai o penúltimo elemento da stack pelo o elemento no topo.
 * @param[in] s Stack a ser alterada.
 * @return Função é do tipo void.
 */
void sub(stack *s);

/**
 * \brief Múltiplica os dois elementos no topo da stack.
 * @param[in] s Stack a ser alterada.
 * @return Função é do tipo void.
 */
void mult(stack *s);

/**
 * \brief Divide os o penúltimo elemento da stack pelo o elemento no topo.
 * @param[in] s Stack a ser alterada.
 * @return Função é do tipo void.
 */
void division(stack *s);

/**
 * \brief Retira o último elemento e penúltimo elemento da Stack (x e y, respetivamente) e insere a potência de base y e expoente x no topo da stack.
 * @param[in] s Stack a ser alterada.
 * @return Função é do tipo void.
 */
void power(stack *s);

/**
 * \brief Altera os dois elementos do topo da stack para o resto da divisão do penúltimo elemento pelo topo.
 * @param[in] s Stack a ser alterada.
 * @return Função é do tipo void.
 */
void modulus(stack *s);

/**
 * \brief Soma uma unidade ao elemento do topo da Stack. Funciona com char, tendo em conta código ASCII
 * @param[in] s Stack a ser alterada.
 * @return Função é do tipo void.
 */
void inc(stack *s);

/**
 * \brief Subtrai uma unidade ao elemento do topo da stack.
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 */
void dec(stack *s);

/**
 * \brief Altera os dois elementos do topo da stack para um inteiro com o valor lógico da sua conjunção binária.
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 * @note Só funciona se os dois elementos do topo da stack forem inteiros ou carateres.
 */
void and (stack * s);

/**
 * \brief Altera os dois elementos do topo da stack para um inteiro com o valor lógico da sua disjunção binária.
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 * @note Só funciona se os dois elementos do topo da stack forem inteiros ou carateres.
 */
void or (stack * s);

/**
 * \brief Altera os dois elementos do topo da stack para um inteiro com o valor lógico da sua disjunção exclusiva (1 só se um e só um elemento for 1).
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 * @note Só funciona se os dois elementos do topo da stack forem inteiros ou carateres.
 */
void xor (stack * s);

/**
 * \brief Negação binária do topo da stack.
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 * @note Só funciona se o elemento do topo da stack for um inteiro.
 */
void not(stack * s);

// * Funções direcionadas à stack.
/**
 * \brief Duplica o topo da stack.
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 */
void duplicate(stack *s);

/**
 * \brief Troca os dos dois elementos do topo da stack.
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 */
void swap(stack *s);

/**
 * \brief Troca as posições dos 3 elementos do topo da stack (os elementos rodam entre si).
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 * @example A B C --> B C A
 */
void swap_three(stack *s);

/**
 * \brief Adiciona um elemento ao topo da stack, tendo este um índice igual ao valor do topo da stack original.
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 * @example 7 2 3 2 $ --> 7 2 3 7
 * @bug Erro para floats.
 */
void bring_top(stack *s);

// * Funções direcionadas ao IO
/**
 * \brief Lê a próxima uma linha como string e dá push a esse valor (como string).
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 */
void line_after(stack *s);

/**
 * \brief Retorna o elemento do topo da stack.
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 */
void peek_stack(stack *s);

// * Funções para conversão de tipos.
/**
 * \brief Altera o tipo do elemento do topo da stack para um inteiro.
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 */
void to_int(stack *s);

/**
 * \brief Altera o tipo do elemento do topo da stack para um double.
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 */
void to_double(stack *s);

/**
 * \brief Altera o tipo do elemento do topo da stack para um carátere.
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 */
void to_char(stack *s);

/**
 * \brief Altera o tipo do elemento do topo da stack para uma string.
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 */
void to_string(stack *s);

/**
 * \brief Verifica se um dado elemento é inteiro.
 * @param[in] s Stack a ser avaliada.
 * @param[in] n Número inteiro dado.
 * @return Devolve um inteiro, que é usado para calculo de condições.
 */
int checkNbool(stack *s, int n);

/**
  * \brief Verifica se duas strings são iguais e dá push a 1 caso sejam.
  * @param[in] s Stack a ser avaliada.
  * @param[in] x Elemento 1.
  * @param[in] y Elemento 2.
  * @return Devolve um inteiro para indicar se a função foi executada para duas strings.
  */
int equalString(stack *s, stack_elem x, stack_elem y);

/**
  * \brief Verifica uma string é menor do que outra e dá push a 1 caso sejam.
  * @param[in] s Stack a ser avaliada.
  * @param[in] x Elemento 1.
  * @param[in] y Elemento 2.
  * @return Devolve um inteiro para indicar se a função foi executada para duas strings.
  */
int lessString(stack *s, stack_elem x, stack_elem y);

/**
  * \brief Compara dois elementos da stack.Se forem iguais, retorna 1(Verdadeiro); caso contrário, retorna 0.
  * @param[in] s Stack a ser avaliada.
  * @return Função é do tipo void.
  */
void equal(stack *s);

/**
 * \brief Compara dois elementos da stack.Se o primeiro for menor, retorna 1(Verdadeiro); caso contrário, retorna 0.
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 * @example 7 2 < --> 0
 */
void less(stack *s);

/**
 * \brief Compara dois elementos da stack.Se o primeiro for maior, retorna 1(Verdadeiro); caso contrário, retorna 0.
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 * @example 7 2 > --> 1
 */
void greater(stack *s);

/**
 * \brief Retira um elemento da stack.Caso seja 0, retorna 1; caso contrário retorna 0.
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 */
void no(stack *s);

/**
 * \brief Retira dois elementos da stack e dá push ao menor dos dois.
 * @param[in] s Stack a ser avaliada.
 * @return 0 se o valor da esquerda for menor, 1 caso contrário.
 */
int smallest(stack *s);

/**
 * \brief Retira dois elementos da stack e dá push ao maior dos dois.
 * @param[in] s Stack a ser avaliada.
 * @return 0 se o valor da esquerda for maior, 1 caso contrário.
 */
int largest(stack *s);

/**
 * \brief Inverte o valor lógico do elemento do topo da stack
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 */
void invertBool(stack *s);

/**
 * \brief Analisa o valor lógico do 3º elemento da Stack. Se V, imprime o 2º valor, se falso, imprime o 1º
 * @param[in] s Stack a ser avaliada.
 * @return Função é do tipo void.
 */
void ifThenElse(stack *s);

/**
  * \brief Analisa o valor lógico da conjunção dos dois elementos do topo da Stack. Devolve 0 se falso, o valor do elemento do topo se for verdade
  * @param[in] s Stack a ser avaliada.
  * @return Função é do tipo void.
  */
void pushAnd(stack *s);

/**
  * \brief Analisa o valor lógico da disjunção dos dois elementos do topo da Stack. Devolve 0 se falso, o penultimo valor se for !=0, o topo da Stack se o abaixo for 0
  * @param[in] s Stack a ser avaliada.
  * @return Função é do tipo void.
  */
void pushOr(stack *s);

#endif
