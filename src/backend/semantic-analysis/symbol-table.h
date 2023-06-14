#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "../support/shared.h"

#define HASH_TABLE_SIZE 4096

typedef enum {
    VARTYPE_IMAGE,
    VARTYPE_FILTER,
    VARTYPE_SET,
    VARTYPE_FOR_IMAGE
} VarType;

struct SymbolNode {
    char * varname;
    VarType type;
    char * path;
};

typedef struct SymbolNode * Symbol;

void InsertInSymbolTable(char * varname, VarType type, char * path);
void DeleteFromSymbolTable(char * key);
Symbol GetFromSymbolTable(char * key);
boolean SymbolTableContains(char * key);
void StepIntoScope();
void LeaveScope();

#endif