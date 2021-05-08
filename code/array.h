#ifndef ARRAY_H
#define ARRAY_H

/**
 * \brief Escreve no ecrã os conteúdos de um array. 
 * Função muito, talvez demasiado, semelhante à dumpStack().
 * @param[in] s Stack a ser avaliada.
 * @return Função do tipo void, não devolve nada.
 */
void printArray(stack *s);

/**
 * \brief Lê o input de várias linhas e mete o seu conteúdo na stack como string.
 * @param[in] s Stack a ser avaliada
 * @return Função do tipo void, não devolve nada.
 */
void multipleLines(stack *s);

/**
 * \brief Inicializa um array e coloca-o na stack.
 * @param[in] s Stack a ser alterada.
 * @return Função do tipo void, não devolve nada.
 */
void initArray(stack *s);

/**
 * \brief Faz o parse de um array, obtém o seu conteúdo e mete-lo na stack.
 * @param[in] s Stack a ser alterada.
 * @param[in] line Linha inicial dada pelo user, que vai ser parsed.
 * @return Função do tipo void, não devolve nada.
 */
void parseArray(stack *s, char *line);

/**
 * \brief Retira o contéudo de uma string, mais especificamente de algo delimitado por '[]'.
 * @param[in] line Linha inicial dada pelo user.
 * @return Função do tipo void, não devolve nada.
 */
char* getInside(char *line);

/**
 * \brief Esta função serve para atualizar o token após um array ter sido adicionado na stack.
 * Ao receber uma string, esta função devolve uma outra cuja parte coorespondente ao array foi retirada. Por exemplo : [ 1 2 3 ] 2 2 + passa a 2 2 + .
 * @param[in] line String que vai ser cortada.
 * @return Função do tipo void, não devolve nada.
 */
char* getRestToken(char *line);

/**
 * \brief Esta função serve para atualizar o token após uma string ter sido adicionado na stack. 
 * Funciona do mesmo mode que a função getRestToken().
 * @param[in] line String que vai ser cortada.
 * @return Função do tipo void, não devolve nada.
 */
char* getRestTokenS(char *line);

/**
 * \brief Coloca na stack todos os elementos do array.
 * @param[in] s Stack a ser alterada.
 * @return Função do tipo void, não devolve nada.
 */
void dumpArray(stack *s);

/**
 * \brief Push do elemento para a stack de acordo com o seu tipo.
 * @param[in] s Stack a ser alterada.
 * @param[in] elem Elemento que irá para o topo da stack.
 * @return Função do tipo void, não devolve nada.
 */
void typePush(stack *s, stack_elem elem);

/**
 * \brief Devolve o tamanho do array ou cria um caso o elemento anterior não seja um array mas sim um inteiro.
 * Por exemplo : {[ 1 2 3 ] ,} dá-nos 3 enquanto que {3 ,} dá-nos [ 0 1 2 ].
 * @param[in] s Stack a ser alterada.
 * @return Função do tipo void, não devolve nada.
 */
void arrayRange(stack *s);

/**
 * \brief Cria um array de N elementos.
 * @param[in] s Stack a ser alterada.
 * @param[in] size Número de elementos do array.
 * @return Função do tipo void, não devolve nada.
 */
void spawnArray(stack *s, int size);

/**
 * \brief Dá push ao elemento de um array cujo o índice é o valor que se encontra no topo da stack.
 * @param[in] s Stack a ser alterada.
 * @return Função do tipo void, não devolve nada.
 */
void getValueByIndex(stack *s);

/**
 * \brief Esta função tem o mesmo objetivo que a função parseArray(), retirar o conteúdo que está entre aspas.
 * @param[in] s Stack a ser alterada.
 * @param[in] line String inicial dada pelo user ao correr o programa.
 * @return Função do tipo void, não devolve nada.
 */
void parseString(stack *s, char *line);

/**
 * \brief Retira os elementos da string dentro das aspas. 
 * @param[in] line String inicial dada pelo user ao correr o programa.
 * @return Função do tipo void, não devolve nada.
 */
char* getString(char *line);

/**
 * \brief Devolve um determinado número de elementos do início do array.
 * @param[in] s Stack a ser alterada.
 * @return Função do tipo void, não devolve nada.
 * @example [ 0 1 2 3 4 ] 3 >  dá  [ 0 1 2 ] 
 */ 
void getElemsInit(stack *s); 

/**
 * \brief Devolve um determinado número de elementos do fim do array.
 * @param[in] s Stack a ser alterada.
 * @return Função do tipo void, não devolve nada.
 * @example [ 0 1 2 3 4 ] 3 >  dá  [ 2 3 4 ]
 */ 
void getElemsEnd(stack *s);

/**
 * \brief Remove o primeiro elemento do array e coloca-o na stack após o array.
 * @param[in] s Stack a ser alterada.
 * @return Função do tipo void, não devolve nada.
 */ 
void removeInit(stack *s);

/**
 * \brief Remove o último elemento do array e coloca-o na stack após o array.
 * @param[in] s Stack a ser alterada.
 * @return Função do tipo void, não devolve nada.
 */ 
void removeEnd(stack *s);

/**
 * \brief Procura uma substring na string e devolve o seu índice ou -1 se não encontrar.
 * @param[in] s Stack a ser alterada.
 * @return Função do tipo void, não devolve nada.
 */ 
void stringSearch(stack *s);

/**
 * \brief Separa uma string por whitespace/newlines dependento do seu argumento.
 * @param[in] s Stack a ser alterada.
 * @param[in] delim Whitespace : " " ou Newline : "\n".
 * @return Função do tipo void, não devolve nada.
 */ 
void stripString(stack *s, char *delim);

/**
 * \brief Separa uma string por uma substring e devolve o resultado em forma de array. 
 * @param[in] s Stack a ser alterada.
 * @return Função do tipo void, não devolve nada.
 */ 
void splitSub(stack *s);

/**
 * \brief Concatena uma string/array com ela própria u determinado número de vezes (topo da stack).  
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */ 
void concatSolo(stack *s);

/**
 * \brief Concatena dois elementos, destes um deles tem de ser obrigatóriamente uma string ou um array. 
 * Dá push do resultado para a stack.
 * @param[in] s Stack a ser alterada.
 * @return Não devolve nada.
 */ 
void concat(stack *s);

/**
 * \brief Esta função adicona um char ao início de uma string.
 * @param[in] s Stack a ser alterada.
 * @return Devolve o caracter após a conversão.
 */ 
char* append(char antes, char *string);

void concatXArray(stack *s, stack_elem x, stack_elem y);
void concatXString(stack *s, stack_elem x, stack_elem y);
void concatYArray(stack *s, stack_elem x, stack_elem y);
void concatYString(stack *s, stack_elem x, stack_elem y);
char* concatString(const char *s1, const char *s2);

#endif