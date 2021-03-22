/************************************************
 * @file Header file para o ficheiro \a stack.c \a .
 ***********************************************/

# define SIZE 10240

typedef struct stack {

    long elems[SIZE];
    int pointer;

} stack;

stack create();
int stackStatus(stack *s);
int push(stack *s, int value);
int pop(stack *s);
void dumpStack(stack *s);