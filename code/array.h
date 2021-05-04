#ifndef ARRAY_H
#define ARRAY_H

void printArray(stack *s);
void splitString(stack *s, char *string);
void multipleLines(stack *s);
void initArray(stack *s);
void parseArray(stack *s, char *line);
char* getInside(char *line);
char* getRestToken(char *line);
void dumpArray(stack *s);
void typePush(stack *s, stack_elem elem);
void arrayRange(stack *s);
void spawnArray(stack *s, int size);
void getValueByIndex(stack *s);

#endif