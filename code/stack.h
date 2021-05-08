/**
 * @file stack.h - Contém os prótotipos do módulo stack.c
 * @copyright Copyright (c) 2021
 */

#ifndef STACK_H
#define STACK_H

/**
 * É o tamanho inicial que a nossa stack toma.
 */
#define SIZE 100

/**
 * Vamos usar uma stack auxiliar para simular um array.
 */
typedef struct stack stack;

// ===========================================
// DEFINIÇÃO DA STACK
// ===========================================

/**
 * \brief Tipos exclusivos aos elementos da stack.
 * @enum stack_type
 */
typedef enum stack_type
{

    STACK_CHAR, /**< Equivale ao tipo char. */
    STACK_INT, /**< Equivale ao tipo int. */
    STACK_LONG, /**< Equivale ao tipo long. */
    STACK_FLOAT, /**< Equivale ao tipo float. */
    STACK_DOUBLE, /**< Equivale ao tipo double. */
    STACK_STRING, /**< Equivale ao tipo char* (string). */
    STACK_ARRAY /**< Equivale ao tipo stack* (é usada uma stack auxiliar para a simulação de um array). */

}stack_type;

/**
 * \brief Estrutura dos elementos da stack.
 * @struct stack_elem
 * @see stack_type
 */
typedef struct stack_elem
{
    /*@{*/
    enum stack_type type; /**< Temos de chamar o enum stack_type para podermos associar os elementos no union. Com isto também conseguimos aceder ao tipo do elemento do array. */
    /*@}*/
    union data
    {

        /*@{*/
        char char_value; /**< STACK_CHAR -> char */
        int int_value; /**< STACK_INT -> int */
        long long_value; /**< STACK_LONG -> long */
        float float_value; /**< STACK_FLOAT -> float */
        double double_value; /**< STACK_DOUBLE -> double */
        char *string_value; /**< STACK_STRING -> char* */
        stack *array_value; /**< STACK_ARRAY -> stack* */
        /*@}*/

    } data; /**< Criamos este parâmetro para poder aceder aos valores dos elementos da stack. */
}stack_elem;

/**
 * \brief Estrutura da stack.
 * @struct stack
 * Este array é composta por stack_elem e tem um tamanho fixo de 10240 bytes. Server para armazenar os valores na stack.
 */
struct stack
{
    int size; /**< Tamanho do array, este tamanho vai variar caso seja necessária re-alocação de memória. */
    int pointer; /**< Número inteiro que nos indica o número de elemntos da stack. */
    stack_elem vars[26]; /**< Este array armazena todas as variáveis possíveis, neste caso são 26 uma para cada letra maiúscula do alfabeto.*/
    stack_elem *elems; /**< Aqui é onde os elementos da stack ficam guardados. Estes podem ser acedidos usando os parâmentros definidos na strutc stack_elem.  */
};

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
 * @returns Devolve um valor de acordo com o estado da stack.
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
 * @returns É uma função do tipo void, daí não devolver nada.
 * @see pop()
 */
void push(stack *s, const enum stack_type type, ...);

/**
 * \brief Adiciona um elemento no topo da stack.
 *
 * @param[in] s Stack a ser avaliada.
 * @returns Devole o elemento da stack que foi retirado.
 * @see push()
 */
stack_elem pop(stack *s);

/**
 * \brief Esta função despeja todos os elementos contidos na stack.
 * @param[in] s Stack a ser avaliada.
 * @returns Escreve a stack no ecrã, porém não devolve nada, sendo que é do tipo void.
 * @see pop() push()
 */
void dumpStack(stack *s);

/**
 * \brief Esta função é usada para ver qual elemento está no topo da stack.
 * @param[in] s Stack a ser avaliada.
 * @returns Devolve um elemento da stack no topo.
 */
stack_elem peek(stack *s);

/**
 * \brief Esta função é usada na recolocação de valores nas variáveis disponíveis.
 * Reescreve o valor das variáveis pelo valor do elemento no topo da stack.
 * @param[in] s Stack a ser avaliada.
 * @param[in] var_letter Letra a qual o valor vai estar associado.
 * @note Ler código para explicação de como funciona a conversão de letra / ASCII / índice.
 */
void pushVar(stack *s, char var_letter);

/**
 * \brief Esta função inicializa as variáveis default da stack
 * Esta inicialização apenas incluí os valores padrões, qualqueres outros valores poderão ser adicionados conforme o utilizador desejar
 * Por exemplo: 'A' começa com o valor 10, 'U' não tem nenhum valor (poderá vir a ter).
 * Esta função é executada sempre após a criação de uma nova stack.
 * @param[in] s Stack na qual as variáveis serão adicionadas.
 * @note Qualquer outra variável poderá ser inicializada por qualquer letra maiúscula do alfabeto.
 */
void varStart(stack *stack);

/**
 * \brief Esta função adiciona na stack o valor da variável cuja letra é dada
 * A letra dada serve-nos como índice do array de variáveis, sabemos que a letra 'A' tem obrigatóriamente o valor de índice 0, daí podemos concluir que o valor do índice no array vai ser o valor da letra em ASCII - 65
 * Assim, só precisamos de aceder ao array, mais especificamente ao índice var_letter - 65 e usar a função push para introduzir o valor na stack.
 * @param[in] s Stack a ser avaliada.
 * @param[in] var_letter Letra da variável, cujo valor vai ser extraido.
 * @note Qualquer outra variável poderá ser inicializada por qualquer letra maiúscula do alfabeto.
 */
void getVar(stack *s, char var_letter);

/**
 * \brief Esta função verifica o tipo do penúltimo elemento da stack.
 * @param[in] s Stack a ser avaliada.
 * @return Devolve o tipo do elemento.
 */
stack_type getSecondType(stack *s);

/**
 * \brief Esta função copia o conteúdo das variáveis de uma stack para um array.
 * @param[in] s Stack a ser avaliada.
 * @return É uma função do tipo void, daí não devolver nada.
 */
void copyVarStack(stack *s);

/**
 * \brief Esta função copia o conteúdo das variáveis de um array para uma stack.
 * @param[in] s Stack a ser avaliada.
 * @return É uma função do tipo void, daí não devolver nada.
 */
void copyVarArray(stack *s);

#endif
