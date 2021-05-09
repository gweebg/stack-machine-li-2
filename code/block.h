/**
 * @file block.h - Contém os protótipos das funções de block.c .
 * @copyright Copyright (c) 2021
 */

#ifndef BLOCK_H
#define BLOCK_H

#include "stack.h"

char* readBlock(char *line);
void pushBlock(stack *s, char *full_string);

char* parseBlock(char *full_block);
void executeBlock(stack *s);

#endif