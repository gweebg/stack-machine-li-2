/**
 * @file stack.h - Contém os prótotipos do módulo stack.c
 * @copyright Copyright (c) 2021
 */

/** 
 * SIZE é o valor do tamanho máximo da stack.
 * @note A ser mudado para memória automática.
 */
#define SIZE 10240

/**
 * \brief Tipos exclusivos aos elementos da stack.
 * @enum stack_type
 * Este enumerador contém todos os possíveis tipos de valores que a stack pode receber:
 * *STACK_CHAR => char
 * *STACK_INT => int
 * *STACK_FLOAT => float
 * *STACK_LONG => long
 * *STACK_DOUBLE => double
 * *STACK_POINTER => char *
 */
typedef enum stack_type
{

    STACK_CHAR,
    STACK_INT,
    STACK_LONG,
    STACK_FLOAT,
    STACK_DOUBLE,
    STACK_POINTER

}stack_type;

/**
 * \brief Estrutura dos elementos da stack.
 * @struct stack_elem
 * @var stack::type
 * O type é um objeto do tipo stack_type e é-nos útil para aceder ao tipo do valor da stack.
 * @var stack::data 
 * Esta estrura é uma union mostra como os valores serão guardados na stack. Para além disso garante-nos a possibilidade de aceder ao valor guardado. 
 * @see stack_type
 */
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

/**
 * \brief Estrutura da stack.
 * @struct stack
 * @var stack::pointer
 * O pointer contém o valor de um inteiro, este aponta sempre para o topo da stack.
 * @var stack::elems 
 * Esta array é composta por stack_elem e tem um tamanho fixo de 10240 bytes. Server para armazenar os valores na stack.
 */
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
 * \brief Esta função é usada para ver quail elemento está no topo da stack.
 * 
 * @param[in] s Stack a ser avaliada.
 * @returns Devolve um elemento da stack (stack_elem).
 */
stack_elem peek(stack *s);
