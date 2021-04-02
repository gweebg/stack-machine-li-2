/**
 * @file stack.h - Contém os prótotipos do módulo stack.c
 * @copyright Copyright (c) 2021
 */

/** SIZE é o valor do tamanho máximo da stack. */
#define SIZE 10240

typedef enum stack_type
{

    STACK_CHAR,
    STACK_INT,
    STACK_LONG,
    STACK_FLOAT,
    STACK_DOUBLE,
    STACK_POINTER

}stack_type;

typedef struct stack_elem
{

    enum stack_type type;
    union data
    {

        char char_value;
        int int_value;
        long long_value;
        float float_value;
        double double_value;
        char *string_value;

    } data;
}stack_elem;

typedef struct stack
{

    int pointer;
    stack_elem elems[SIZE];

} stack;

/**
 * \brief Função que inicializa/cria uma stack.
 * @returns Devolve a stack criada.
 * @note O tamanho máximo da stack é 10240 bytes.
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
 * @warning Todas as stacks dadas como parâmetro têm de ser criadas utilizando a função create()
 * @see create()
 */
int stackStatus(stack *s);

/**
 * \brief Retira o elemento no topo da stack.
 * A stack rege-se por "last in, first out", daí termos de retirar o primeiro elemento e decrementar o stack pointer.
 * @param[in] s Stack a ser avaliada.
 * @param[in] value Valor a ser adicionado na stack.
 * @returns
 * Devolve :
 * * O elemento retirado se a stack não estiver vazia;
 * * 1, se a stack estiver vazia.
 * @see pop()
 */
void push(stack *s, const enum stack_type type, ...);

/**
 * \brief Adiciona um elemento no topo da stack.
 * 
 * @param[in] s Stack a ser avaliada.
 * @returns
 * Devolve :
 * * 0, se foi possivel adiconar o elemento;
 * * 1, se a stack estiver cheia.
 * @see push()
 */
stack_elem pop(stack *s);

/**
 * \brief Esta função despeja todos os elementos contidos na stack.
 * 
 * @param[in] s Stack a ser avaliada.
 * @returns Escreve a stack no ecrã, porém não devolve nada, sendo que é do tipo void.
 * @see pop() push()
 */
void dumpStack(stack *s);

/**
 * \brief Esta função é usada para ver quais elementos estão no topo da stack.
 * 
 * @param[in] s Stack a ser avaliada.
 * @param[in] level Level : 1 | 0, 1 vê os primeiros dois elementos, 0 vê apenas o primeiro elemento.
 * @returns Devolve uma stack_elem array contendo os elementos.
 * @note No máximo só são vistos 2 elementos da stack.
 */
stack_elem peek(stack *s);
