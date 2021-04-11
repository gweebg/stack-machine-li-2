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
/**
 * \brief Adiciona um elemento ao topo da stack,sendo este, igual ao topo da stack original.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 */
void duplicate(stack *s);
/**
 * \brief Troca os dos dois elementos do topo da stack.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 * @example 
 */
void swap(stack *s);
/**
 * \brief Altera as posições dos 3 elementos do topo da stack.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 * @example a b c --> b c a, sendo c o topo da stack original.
 */
void swap_three(stack *s);
/**
 * \brief Adiciona um elemento ao topo da stack, tendo este um índice igual ao valor do topo da stack original.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 * @example 7 2 3 2 $ --> 7237
 */
void bring_top(stack *s);

// Funções direcionadas ao IO
/**
 * \brief Lê a próxima linha do input.
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

// Funções para conversão de tipos.
/**
 * \brief Altera o tipo do elemento do topo da stack para um Int.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 */
void to_int(stack *s);
/**
 * \brief Altera o tipo do elemento do topo da stack para um Double.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 */
void to_double(stack *s);
/**
 * \brief Altera o tipo do elemento do topo da stack para um Char.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 */
void to_char(stack *s);
/**
 * \brief Altera o tipo do elemento do topo da stack para um Pointer de Char.
 * @param[in] s Stack a ser avaliada.
 * @return Não devolve nada.
 */
void to_string(stack *s);
