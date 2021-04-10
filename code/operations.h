/**
 * @file operations.h - Contém os prótotipos do módulo operations.c
 * Para melhor legibilidade do código, separou-se as operações da Stack num módulo separado.
 * @copyright Copyright (c) 2021
 */

// Funções básicas com inteiros
/**
 * \brief Soma os dois elementos no topo da Stack
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada
 */
void add(stack *s);

/**
 * \brief Subtrai o elemento do topo da Stack ao elemento a seguir
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */
void sub(stack *s);
/**
 * \brief Multiplica os dois elementos no topo da Stack
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */
void mult(stack *s);
/**
 * \brief Divide o segundo elemento do topo da Stack e o elemento no topo da Stack
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */
void division(stack *s);
/**
 * \brief Retira o ultimo elemento e penultimo elemento da Stack (x e y, respetivamente). Insere a potência de base y e expoente x no topo da Stack
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 * @see parser.c
 */
void power(stack *s);
/**
 * \brief Altera os dois elementos do topo da Stack para o resto da divisão do penúltimo elemento pelo último
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
 * \brief Subtrai uma unidade ao elemento do topo da Stack. Funciona com char, tendo em conta código ASCII
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 */
void dec(stack *s);
/**
 * \brief Altera os dois elementos do topo da Stack para um Int com o valor lógico da sua conjunção
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 * @note Só funciona se os dois elementos do topo da Stack forem do tipo Int
 */
void and(stack *s);
/**
 * \brief Altera os dois elementos do topo da Stack para um Int com o valor lógico da sua disjunção
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 * @note Só funciona se os dois elementos do topo da Stack forem do tipo Int
 */
void or(stack *s);
/**
 * \brief Altera os dois elementos do topo da Stack para um Int com o valor lógico da sua disjunção exclusiva (1 só se um e só um elemento for 1)
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 * @note Só funciona se os dois elementos do topo da Stack forem do tipo Int
 */
void xor(stack *s);
/**
 * \brief Altera o elemento do topo da Stack para a sua negação
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 * @note Só funciona se o elemento do topo da Stack for do tipo Int
 */
void not(stack *s);

// Funções direcionadas à stack.
void duplicate(stack *s);
void swap(stack *s);
void swap_three(stack *s);
void bring_top(stack *s);

// Funções direcionadas ao IO
void line_after(stack *s);
void peek_stack(stack *s);

// Funções para conversão de tipos.
void to_int(stack *s);
void to_double(stack *s);
void to_char(stack *s);
void to_string(stack *s);
