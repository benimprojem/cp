// semantic.h
#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "parser.h"

typedef enum {
    TYPE_I8,
    TYPE_I16,
    TYPE_I32,
    TYPE_I64,
    TYPE_I128,
    TYPE_U8,
    TYPE_U16,
    TYPE_U32,
    TYPE_U64,
    TYPE_U128,
    TYPE_F16,
    TYPE_F32,
    TYPE_F64,
    TYPE_F128,
    TYPE_INT,
    TYPE_CHAR,
    TYPE_STR,
    TYPE_FLOAT,
    TYPE_VOID
} VarType;

typedef struct Symbol {
    char name[256];
    VarType type;
    struct Symbol *next;
} Symbol;

void initSymbolTable();
Symbol* addSymbol(const char *name, VarType type);
Symbol* findSymbol(const char *name);
int checkNameRules(const char *name);
int checkTypeCompatibility(Node *node);

#endif