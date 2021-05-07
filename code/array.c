#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "stack.h"
#include "array.h"
#include "parser.h"

// ===============================
// Parsing de arrays/strings.
// ===============================

void printArray(stack *s)
{
    printf("[");
    // printf("Stack Dump: ");
    for (int i = 0; i < s->pointer + 1; i++)
    {
        stack_elem elem = s->elems[i];
        stack_type type = elem.type;

        switch (type)
        {
        case STACK_CHAR:
            printf("%c", elem.data.char_value);
            break;

        case STACK_INT:
            printf("%d", elem.data.int_value);
            break;

        case STACK_LONG:
            printf("%ld", elem.data.long_value);
            break;

        case STACK_FLOAT:;
            printf("%g", elem.data.float_value);
            break;

        case STACK_DOUBLE:
            printf("%g", elem.data.double_value);
            break;

        case STACK_STRING:
            printf("%s", elem.data.string_value);
            break;
        
        case STACK_ARRAY:
            printArray(elem.data.array_value);
            break;

        default:
            fprintf(stderr, "unknown");
            exit(EXIT_FAILURE);
        }
  
    }
    printf("]");
}

void multipleLines(stack *s)
{
    char temp[10001]; // String temporária.
    char result[10001]; // String final onde tudo vai ser guardada.

    // Vamos ler as linhas enquanto o fgets não for null.
    while (fgets(temp, sizeof(temp), stdin))
    {
        // Para garantir que o tamanho não ultrapassa os 1024 bytes.
        assert(temp[strlen(temp) - 1] == '\n');
        strcat(result,temp); // Introduzimos a linha lida no result.
    }

    // Meter na stack a string acumulada.
    push(s, STACK_STRING, result);
}

void initArray(stack *s)
{

    stack_elem array; // Inicialização do array.
    array.type = STACK_ARRAY; // Tipo do elemento.
    array.data.array_value = (stack *)malloc(s->size * sizeof(stack)); // Alocação de memória para o array.

    array.data.array_value->size = s->size; // Tamanho do array
    array.data.array_value->pointer = -1; // Índice do elemento no topo do array.
    array.data.array_value->elems = (stack_elem *)malloc(s->size * sizeof(stack_elem)); // Alocação de memória para os elementos doa array.

    // Inicializar as variaveis
    varStart(array.data.array_value);

    push(s, STACK_ARRAY, array.data.array_value);
}

char* getInside(char *line)
{
    // Contagem de '[' e ']'.
    int count = 0;
    // O start indica-nos a primeira posição do char '[' e o end do ']'.
    int start = 0; int end = 0; int c = 0;
    // Variável temporária onde vamos guardar partes da linha orginial.
    char *string = (char *)malloc(strlen(line) * sizeof(char));

    // Posição do primeiro '['. [start]
    for (unsigned long i = 0; i < strlen(line); i++)
    {
        if (line[i] == '[')
        { 
            start = i; 
            break; // Temos de dar break pois queremos apenas a primeira ocorrência do '['.
        }
    }

    // printf("Indice do '[' : %d\n", start);

    // Posição do ']' coorespondente ao '[' definido acima. [end]
    for (unsigned long j = 0; j < strlen(line); j++)
    {
        if (line[j] == '[') count++; // Precisamos de saber a contagem dos '['. 
        else if (line[j] == ']') 
        {            
            if (count % 2 != 0) // Se o numero total de chars '[]' for ímpar significa que o proximo ']' fecha o primeiro '['.
            {
                end = j;
                break;
            }       

            count++;
        }
    }

    // Agora que temos a posição dos brackets, queremos extrair o seu conteúdo.
    // Começamos por remover o lixo na esquerda.
    for (int z = 0; z < end; z++)
    {
        string[c] = line[z];
        c++;
    }

    // printf("Linha depois do for : %s\n",string);

    // Agora removemos o lixo da direita.
    char *final = (char*)malloc(sizeof(char) * strlen(line));

    // Sabemos onde o char '[' está, assim podemos usar o strncpy para copiar para *final, a parte da string que começa do indíce do start+1. 
    strncpy(final, &string[start + 1], strlen(string) - start);
    free(string);
    // printf("[DEBUG]: %s\n", final);

    return final; // Finalmente retornamos a string modificada.
}

char* getRestToken(char *line)
{
    int count = 0; int end = 0;

    char *result = (char*)malloc(strlen(line) * sizeof(char));

    for (unsigned long j = 0; j < strlen(line); j++)
    {
        if (line[j] == '[') count++; // Precisamos de saber a contagem dos '['. 
        else if (line[j] == ']') 
        {            
            if (count % 2 != 0) // Se o numero total de chars '[]' for ímpar significa que o proximo ']' fecha o primeiro '['.
            {
                end = j;
                break;
            }       

            count++;
        }
    }

    strncpy(result, &line[end + 1], strlen(line) - end);
    // printf("[DEBUG]: %s\n", result);

    return result;
}

char* getRestTokenS(char *line)
{
    int count = 0; int end = 0;

    char *result = (char*)malloc(strlen(line) * sizeof(char));

    for (unsigned long i = 0; i < strlen(line); i++) 
    {
        if (line[i] == '\"') count++; // Significa que é o primeiro ".
        if (count == 2) 
        {
            end = i;
            break;
        }
    }

    strncpy(result, &line[end + 1], strlen(line) - end);
    // printf("[DEBUG]: %s\n", result);

    return result;
}

void parseArray(stack *s, char *line)
{
    initArray(s); // Iniciamos o array, pois encontramos o char '['. 
    // varStart(s); Inicializar as variaveis.
    // printf("\nLinha passada : %s\n",line);

    char *parsed = getInside(line); // parsed passa a ser a string com o conteudo do array que vai ser processado pelo parser.
    // printf("A string é : %s\n", parsed);

    stack_elem array = peek(s); // Isto vai nos dar o array.
    // printf("[Array pointer] : %d\n",array.data.array_value->pointer);

    parser(parsed, array.data.array_value);
    // printf("Executou o parser.\n");
}

char* getString(char *line)
{
    // Strings não aparecem aninhadas, daí este algoritmo ser mais simples do que o dos arrays.
    // Vamos usar o mesmo método da getInside().
    int start = 0; int end = 0; int c = 0;
    char *string = (char *)malloc(strlen(line) * sizeof(char));

    // Indice do primeiro char '\"'.
    for (unsigned long i = 0; i < strlen(line); i++)
    {
        if (line[i] == '\"') 
        {
            start = i;
            break;
        }
    } // Após este ciclo já temos o indice do primeiro " na variavel start.

     // Indice do segundo char '\"'.
    for (unsigned long i = start + 1; i < strlen(line); i++)
    {
        if (line[i] == '\"') 
        {
            end = i;
            break;
        }
    } // Após este ciclo já temos o indice do segundo " na variavel end.

    // Daqui para baixo fazemos o mesmo processo da getInside().
    for (int z = 0; z < end; z++)
    {
        string[c] = line[z];
        c++;
    }

    // Agora removemos o lixo da direita.
    char *final = (char*)malloc(sizeof(char) * strlen(line));

    // Sabemos onde o char '[' está, assim podemos usar o strncpy para copiar para *final, a parte da string que começa do indíce do start+1. 
    strncpy(final, &string[start + 1], strlen(string) - start);
    free(string);
    // printf("[DEBUG]: %s\n", final);

    return final; // Finalmente retornamos a string modificada.
}

void parseString(stack *s, char *line)
{

    stack_elem string;
    string.type = STACK_STRING;
    string.data.string_value = getString(line);

    push(s, STACK_STRING, string.data.string_value);
}

// ===============================
// Operações com arrays/strings.
// ===============================

void typePush(stack *s, stack_elem elem)
{
    switch (elem.type)
    {
        case STACK_INT: push(s, STACK_INT, elem.data.int_value); break; 
        case STACK_FLOAT:push(s, STACK_FLOAT, elem.data.float_value); break; 
        case STACK_CHAR: push(s, STACK_CHAR, elem.data.char_value); break; 
        case STACK_STRING: push(s, STACK_STRING, elem.data.string_value); break; 
        case STACK_ARRAY: push(s, STACK_ARRAY, elem.data.array_value); break; 
        default: fprintf(stderr, "Erro na funçao [typePush] em array.c : switch to default.\n"); exit(EXIT_FAILURE); break;
    }
}

void dumpArray(stack *s) // ~ Colocar na stack todos os elementos do array
{
    stack_elem array = pop(s); 

    if (array.type == STACK_ARRAY) // Só para ter a certeza que é um array.
    {
        for (int i = 0; i < array.data.array_value->pointer + 1; i++)
        {
            // A função typePush dá push do elemento para a stack de acordo com o tipo do elemento.
            typePush(s, array.data.array_value->elems[i]);
        }
    }
}

void spawnArray(stack *s, int size)
{

    initArray(s); // Criar um novo array na nossa stack.
    stack_elem array = pop(s); // Vamos aceder ao nosso array.
    // printf("Tipo : %d\n", array.type);

    for (int i = 0; i < size; i++) push(array.data.array_value, STACK_INT, i);
    
    push(s, STACK_ARRAY, array.data.array_value); // Voltamos a inserir o array na stack.
}

void arrayRange(stack *s)
{
    // Primeira coisa a ser verificada é se o elemento anterior é um array ou um inteiro.
    // Caso seja inteiro n, criamos um array com n elementos. 
    // Caso seja um array, pushamos para a stack o tamanho do array.

    stack_elem elem = pop(s);

    switch(elem.type)
    {
        case STACK_INT: spawnArray(s, elem.data.int_value); break;
        case STACK_ARRAY: push(s, STACK_INT, (elem.data.array_value->pointer) + 1); break;
        case STACK_STRING: push(s, STACK_INT, strlen(elem.data.string_value)); break;
        default: fprintf(stderr, "Erro na funçao [typePush] em array.c : tipo inválido.\n"); exit(EXIT_FAILURE); break;
    } 
}

void getValueByIndex(stack *s)
{
    // Número do índice.
    stack_elem index = pop(s);
    // Esta função só se aplica a arrays, por isso temos a certeza que ao dar pop(s) vamos obter um array.
    stack_elem array = pop(s);

    switch(array.type)
    {
        case STACK_ARRAY:
            typePush(s, array.data.array_value->elems[index.data.int_value]);
            break;
        
        case STACK_STRING:
            push(s, STACK_CHAR, array.data.string_value[index.data.int_value]);
            break;

        default: fprintf(stderr, "Erro na função [getValueByIndex] : data-type inválido!\n"); exit(EXIT_FAILURE); break;
    }
}

void getElemsInit(stack *s)
{

    // printf("Entrou na função certa.\n");
    // Obter o número de elementos que queremos.
    stack_elem num = pop(s);
    // Obter o nosso elemento, se esta função está a ser executada, temos a certeza ou é uma string ou um array.
    stack_elem x = pop(s);
    int times;
    // Nova string que vai levar o output.
    char *new_string = malloc(sizeof(char) * strlen(x.data.string_value));

    switch(x.type) // Fazemos um caso para cada tipo.
    {
        case STACK_ARRAY: // * Já foi testado.
            // [ 1 2 3 4 ] 3 < <==> [ 1 2 3 ]
            times = (x.data.array_value->pointer + 1) - num.data.int_value;

            // Vamos retirar times elementos ao array. Apenas podemos fazer desta maneira pois queremos os elementos a contar do início.
            for (int i = 0; i < times; i++)
            {
                pop(x.data.array_value); // Retira o elemento.
            }

            // Voltamos a introduzir o array (agora alterado) na stack.
            push(s, STACK_ARRAY, x.data.array_value);
            break;

        case STACK_STRING: // * Já foi testado.
            // "planetas" 3 < <==> "pla"

            // Agora copiamos apenas os primeiros x chars para uma nova string.
            for (int j = 0; j < num.data.int_value; j++)
            {
                new_string[j] = x.data.string_value[j];
            }

            printf("O loop deu : %s\n", new_string);
            // Metemos a string alterada na stack.
            push(s, STACK_STRING, new_string);

            break;

        default: fprintf(stderr, "Erro na função [getElemesInit] em array.c : data-type inválido.\n"); exit(EXIT_FAILURE); break;
    }

}

void getElemsEnd(stack *s)
{
    stack_elem num = pop(s); // Número de elementos a retirar do fim.
    stack_elem elem = pop(s); // Ou é um array ou uma string.
    stack_elem temp; // Vai servir para guardar um array temporário.

    int ignore = 0; // Contador para ver quando elementos foram transpostos.
    char *new_string = (char*)malloc(strlen(elem.data.string_value) * sizeof(char)); // Nova linha que vai ter as alterações necessárias.

    switch(elem.type)
    {
        case STACK_ARRAY: // ? Semi testado.
            // [ 1 2 3 ] 2 >        [ 2 3 ]
            initArray(s); // Cria um novo array vazio na stack.
            temp = pop(s); // Queremos modificar esse array.

            ignore = elem.data.array_value->pointer + 1 - num.data.int_value;
            for (int i = ignore; i < elem.data.array_value->pointer + 1; i++)
            {
                typePush(temp.data.array_value, elem.data.array_value->elems[i]);
            }

            push(s, STACK_ARRAY, temp.data.array_value); // Metemos o array atualiazdo na stack.
            break;
            
        case STACK_STRING:;
            // "kainé" 3 >      "iné"
            // Segue o mesmo raciocínio que o case acima.
            ignore = strlen(elem.data.string_value) - num.data.int_value;
            int c = 0;
            
            for (unsigned long j = ignore; j < strlen(elem.data.string_value); j++)
            {
                new_string[c] = elem.data.string_value[j];
                c++;
            }

            // printf("O loop deu : %s\n", new_string);
            push(s, STACK_STRING, new_string); // Push da string para a stack.
            break;

        default: fprintf(stderr, "Erro na função [getElemesEnd] em array.c : data-type inválido.\n"); exit(EXIT_FAILURE); break;
    }

}

void removeInit(stack *s)
{
    // Assumimos que o topo da stack é ou um array ou uma string.
    stack_elem elem = pop(s);

    switch(elem.type)
    {
        case STACK_ARRAY:
            initArray(s); // Criamos um novo array.
            stack_elem array = pop(s); // array agora é um stack_elem do tipo STACK_ARRAY.

            for (int i = 1; i < elem.data.array_value->pointer + 1; i++)
            {
                typePush(array.data.array_value, elem.data.array_value->elems[i]);
            }

            push(s, STACK_ARRAY, array.data.array_value);
            typePush(s, elem.data.array_value->elems[0]);
            break;

        case STACK_STRING:;
            int index = 0; // Queremos remover o primeiro char.
            char* word = elem.data.string_value; // Está atribuido a word, por questões de legibilidade.
            char init = word[0];
            // Copia o char em 0 para outro sitio qualquer.
            memmove(&word[index], &word[index + 1], strlen(word) - index);
            push(s, STACK_STRING, word);
            push(s, STACK_CHAR, init);
            break;

        default: fprintf(stderr, "Erro na função [removeInit] : data-type inválido.\n"); exit(EXIT_FAILURE); break;
    }
}

void removeEnd(stack *s) 
{

    // Obter o elemento no topo da stack : string | array.
    stack_elem elem = pop(s);

    switch(elem.type)
    {
        case STACK_ARRAY:;
            // Retiramos o último elemento.
            stack_elem x = pop(elem.data.array_value);
            push(s, STACK_ARRAY, elem.data.array_value); // Push da lista sem o ultimo elemento.
            typePush(s, x); // Push do elemento retirado.

            break;

        case STACK_STRING:;
            // Segue exatamente o mesmo método que a função acima.
            char* word = elem.data.string_value; // Está atribuido a word, por questões de legibilidade.
            int index = strlen(word) - 1; // Queremos remover o último char.
            char last = word[strlen(word)-1]; // Ultimo char da string.

            // Copia o char em 0 para outro sitio qualquer.
            memmove(&word[index], &word[index + 1], strlen(word) - index);
            push(s, STACK_STRING, word);
            push(s, STACK_CHAR, last);
            break;

        default: fprintf(stderr, "Erro na função [removeEnd] : data-type inválido.\n"); exit(EXIT_FAILURE); break;

    }

}

void stringSearch(stack *s)
{
    // Assumimos que o ambos elementos no topo da stack sejam strings.
    stack_elem string_in = pop(s);
    stack_elem string_base = pop(s);

    // Para procurar por substring podemos usar a função strstr.
    char *sub = strstr(string_base.data.string_value, string_in.data.string_value);
    // Esta função devolve-nos um pointer para a primeira ocorrência da string.

    // Ao fazer isto obtemos o índice do início da substring (pointer subtraction).
    if (sub != NULL)
    {
        int index = sub - string_base.data.string_value;
        push(s, STACK_INT, index);
    }
    else push(s, STACK_INT, -1);
}

void stripString(stack *s, char* delim)
{   
    //! BUG
    // Obter a string.
    stack_elem string = pop(s);
    // Iniciar um array.
    initArray(s); 
    stack_elem array = peek(s);

    char *part = strtok(string.data.string_value, delim);

    while(part != NULL)
    {
        // printf("%s ",part);
        push(array.data.array_value, STACK_STRING, part);
        part = strtok(NULL, delim);
    }
}

void splitSub(stack *s)
{
    // Assumimos que o ambos elementos no topo da stack sejam strings.
    stack_elem string_in = pop(s);
    stack_elem string_base = pop(s);
    initArray(s); stack_elem array = peek(s); // Criamos um novo array.
    char *temp = (char*)malloc(strlen(string_base.data.string_value) * sizeof(char));
    char *temp_ = (char*)malloc(strlen(string_base.data.string_value) * sizeof(char));
    
    // Para procurar por substring podemos usar a função strstr.
    char *sub = strstr(string_base.data.string_value, string_in.data.string_value);

    int index_start  = sub - string_base.data.string_value; // Dá-nos o índice do primeiro char da substring.
    int index_end = index_start + strlen(string_in.data.string_value); // Ao somarmos o tamanho da substring obtemos o indice do ultimo char da substring.

    strncpy(temp, &string_base.data.string_value[0], index_start);
    push(array.data.array_value, STACK_STRING, temp);

    strncpy(temp_, &string_base.data.string_value[index_end], strlen(string_base.data.string_value) - index_end);
    push(array.data.array_value, STACK_STRING, temp_);

}

void concatSolo(stack *s)
{
    // Obter o elemento do topo da stack : inteiro (número de vezes a concatenar).
    stack_elem num = pop(s);
    int i = num.data.int_value;
    // Obter o array/string da stack.
    stack_elem elem = pop(s);

    switch(elem.type)
    {
        case STACK_ARRAY:;
            initArray(s);
            stack_elem array = pop(s);
            for(; (i>0); i--){
                for(int j = 0; j< (elem.data.array_value->pointer)+1; j++)
                    typePush(array.data.array_value,elem.data.array_value->elems[j]);
            }
            push(s, STACK_ARRAY, array.data.array_value); 
            break;   
        case STACK_STRING:;
            for(; (i>0); i--){
                push(s, STACK_STRING, elem.data.string_value);
            } break;
        default: fprintf(stderr, "Erro na função [concatSolo] : data-type inválido./n" ); exit(EXIT_FAILURE); break;
    }
}   