// semantic.c
#include "semantic.h"
#include <string.h>
#include <stdio.h>

static Symbol *symbolTable = NULL;

void initSymbolTable() {
    symbolTable = NULL;
}

Symbol* addSymbol(const char *name, VarType type) {
    if (findSymbol(name) != NULL) {
        printf("Semantic Error: %s zaten tanımlı\n", name);
        return NULL;
    }
    Symbol *sym = malloc(sizeof(Symbol));
    strcpy(sym->name, name);
    sym->type = type;
    sym->next = symbolTable;
    symbolTable = sym;
    return sym;
}

Symbol* findSymbol(const char *name) {
    Symbol *curr = symbolTable;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) return curr;
        curr = curr->next;
    }
    return NULL;
}

int checkNameRules(const char *name) {
    // İsimler harf, rakam ve alt çizgi
    if (!isalpha(name[0]) && name[0] != '_') {
        printf("İsim kuralları ihlal: %s\n", name);
        return 0;
    }
    for (int i=0; name[i]!='\0'; i++) {
        if (!isalnum(name[i]) && name[i] != '_') {
            printf("İsim kuralları ihlal: %s\n", name);
            return 0;
        }
    }
    // Anahtar kelime kontrol (örneğin "int", "char" vb.)
    if (strcmp(name, "int") ==0 || strcmp(name, "char") ==0 || strcmp(name, "str")==0 || strcmp(name, "void")==0) {
        printf("İsim olarak anahtar kelime kullanılamaz: %s\n", name);
        return 0;
    }
    return 1;
}

int checkTypeCompatibility(Node *node) {
    // Basit tip kontrolü
    if (node->type == NODE_IDENTIFIER) {
        Symbol *sym = findSymbol(node->identifier.name);
        if (!sym) {
            printf("Semantic Error: Tanımsız değişken %s\n", node->identifier.name);
            return 0;
        }
        return sym->type;
    }
    // Diğer tipler
    return 1;
}

//?
int isValidType(const char *typeStr) {
    return (strcmp(typeStr, "i8") == 0 || strcmp(typeStr, "i16") == 0 || strcmp(typeStr, "i32") == 0 ||
            strcmp(typeStr, "i64") == 0 || strcmp(typeStr, "i128") == 0 || strcmp(typeStr, "u8") == 0 ||
            strcmp(typeStr, "u16") == 0 || strcmp(typeStr, "u32") == 0 || strcmp(typeStr, "u64") == 0 ||
            strcmp(typeStr, "u128") == 0 || strcmp(typeStr, "f16") == 0 || strcmp(typeStr, "f32") == 0 ||
            strcmp(typeStr, "f64") == 0 || strcmp(typeStr, "f128") == 0);
}

VarType getVarType(const char *typeStr) {
    if (strcmp(typeStr, "i8") == 0) return TYPE_I8;
    if (strcmp(typeStr, "i16") == 0) return TYPE_I16;
    if (strcmp(typeStr, "i32") == 0) return TYPE_I32;
    if (strcmp(typeStr, "i64") == 0) return TYPE_I64;
    if (strcmp(typeStr, "i128") == 0) return TYPE_I128;
    if (strcmp(typeStr, "u8") == 0) return TYPE_U8;
    if (strcmp(typeStr, "u16") == 0) return TYPE_U16;
    if (strcmp(typeStr, "u32") == 0) return TYPE_U32;
    if (strcmp(typeStr, "u64") == 0) return TYPE_U64;
    if (strcmp(typeStr, "u128") == 0) return TYPE_U128;
    if (strcmp(typeStr, "f16") == 0) return TYPE_F16;
    if (strcmp(typeStr, "f32") == 0) return TYPE_F32;
    if (strcmp(typeStr, "f64") == 0) return TYPE_F64;
    if (strcmp(typeStr, "f128") == 0) return TYPE_F128;
    // diğerleri
    return TYPE_VOID; // varsayılan
}
