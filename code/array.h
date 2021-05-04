#ifndef ARRAY_H
#define ARRAY_H

void splitString(stack *s, char *string);
void multipleLines(stack *s);
void initArray(stack *s);
void parseArray(stack *s, char *line);
char* getInside(char *line);
char* getRestToken(char *line);

#endif