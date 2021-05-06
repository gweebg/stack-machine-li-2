#ifndef ARRAY_H
#define ARRAY_H

/**
 * \brief Cria um array com os elementos da stack dada. 
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */
void printArray(stack *s);

/**
 * \brief Lê o input e devolve-o em forma de string.
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */
void multipleLines(stack *s);

/**
 * \brief Inicializa um array e coloca-o na stack.
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */
void initArray(stack *s);

/**
 * \brief Devolve o output da getInside para a Stack. 
 * @param[in] s Stack a ser alterada.
 * @param[in] line String.
 * @return Não devolve nada.
 */
void parseArray(stack *s, char *line);

/**
 * \brief Retira os elementos da string dentro dos []. 
 * @param[in] line String.
 * @return Não devolve nada.
 */
char* getInside(char *line);

/**
 * \brief Atualiza o token. 
 * @param[in] line String.
 * @return Não devolve nada.
 */
char* getRestToken(char *line);

/**
 * \brief Atualiza o token (para Strings). 
 * @param[in] line String.
 * @return Não devolve nada.
 */
char* getRestTokenS(char *line);

/**
 * \brief Coloca na stack todos os elementos do array.
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */
void dumpArray(stack *s);

/**
 * \brief Push do elemento de acordo com o seu tipo.
 * @param[in] s Stack a ser alterada.
 * @param[in] elem Elemento que irá para o topo da stack.
 * @return Não devolve nada.
 */
void typePush(stack *s, stack_elem elem);

/**
 * \brief Devolve o tamanho do array. 
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */
void arrayRange(stack *s);

/**
 * \brief Cria um array de N elementos.
 * @param[in] s Stack a ser alterada.
 * @param[in] size Número de elementos do array.
 * @return Não devolve nada.
 */
void spawnArray(stack *s, int size);

/**
 * \brief Dá push ao valor cujo o índice se encontra no topo da stack.
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */
void getValueByIndex(stack *s);

/**
 * \brief Devolve o output da getString para a Stack. 
 * @param[in] s Stack a ser alterada.
 * @param[in] line String.
 * @return Não devolve nada.
 */
void parseString(stack *s, char *line);

/**
 * \brief Retira os elementos da string dentro dos " ". 
 * @param[in] line String.
 * @return Não devolve nada.
 */
char* getString(char *line);

/**
 * \brief Devolve um determinado número de elementos do início do array.
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 * @example [ 0 1 2 3 4 ] 3 >  --> [012]
 */ 
void getElemsInit(stack *s); 

/**
 * \brief Devolve um determinado número de elementos do fim do array.
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 * @example [ 0 1 2 3 4 ] 3 >  --> [234]
 */ 
void getElemsEnd(stack *s);

/**
 * \brief Remove o primeiro elemento do array e coloca-o na stack após o array.
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */ 
void removeInit(stack *s);

/**
 * \brief Remove o último elemento do array e coloca-o na stack após o array.
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */ 
void removeEnd(stack *s);

/**
 * \brief Procura uma substring na string e devolve o seu índice ou -1 se não encontrar.
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */ 
void stringSearch(stack *s);

/**
 * \brief Separa uma string por whitespace/newlines.
 * @param[in] s Stack a ser alterada.
 * @param[in] delim Whitespace/newlines.
 * @return Não devolve nada.
 */ 
void stripString(stack *s, char *delim);

/**
 * \brief Separa uma string por uma substring e devolve o resultado em forma de array. 
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */ 
void splitSub(stack *s);

#endif