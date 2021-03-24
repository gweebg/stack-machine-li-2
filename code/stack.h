/**
 * @file stack.h - Contém os prótotipos do módulo stack.c
 * @copyright Copyright (c) 2021
 */

/// SIZE é o valor do tamanho máximo da stack.
# define SIZE 10240

/**
 * @struct stack
 * @brief Estrutura da stack.
 * 
 * @var stack::elems
 * Array que contém os elementos da stack.
 * @var stack::pointer
 * Stack pointer, aponta sempre para o valor no topo da stack.
 */
typedef struct stack {

    long elems[SIZE];
    int pointer;

} stack;

/**
 * \brief Função que inicializa uma stack.
 * @returns Devolve a stack criada.
 */
stack create();

/**
 * \brief Função que verifica o estado da stack.
 * 
 * Determina o estado verificando o valor do stack pointer.
 * @param s Stack a ser avaliada.
 * @returns 
 * Devolve :
 * * 0, se a stack estiver vazia;
 * * 1, se a stack estiver cheia;
 * * 2, se a stack não estiver cheia nem vazia.
 */
int stackStatus(stack *s);

/**
 * \brief Retira o elemento no topo da stack.
 * 
 * A stack rege-se por "last in, first out", daí termos de retirar o primeiro elemento e decrementar o stack pointer.
 * @param s Stack a ser avaliada.
 * @returns
 * Devolve :
 * * O elemento retirado se a stack não estiver vazia;
 * * 1, se a stack estiver vazia.
 */
int push(stack *s, int value);

/**
 * \brief Adiciona um elemento no topo da stack.
 * 
 * @param s Stack a ser avaliada.
 * @param value Valor a ser adicionado à stack.
 * @returns
 * Devolve :
 * * 0, se foi possivel adiconar o elemento;
 * * 1, se a stack estiver cheia.
 */
int pop(stack *s);

/**
 * \brief Esta função despeja todos os elementos contidos na stack.
 * 
 * @param s Stack a ser avaliada.
 * @returns 
 * Escreve a stack no ecrã, porém não devolve nada, sendo que é do tipo void.
 */
void dumpStack(stack *s);