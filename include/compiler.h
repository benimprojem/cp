#ifndef CP_COMPILER_H
#define CP_COMPILER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// Forward declarations
typedef struct Token Token;
typedef struct ASTNode ASTNode;
typedef struct Symbol Symbol;
typedef struct SymbolTable SymbolTable;

// Token types for CP language
typedef enum {
    // Literals
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_CHAR,
    TOKEN_IDENTIFIER,
    
    // Data types
    TOKEN_I8, TOKEN_I16, TOKEN_I32, TOKEN_I64, TOKEN_I128, TOKEN_I256, TOKEN_I512,
    TOKEN_U8, TOKEN_U16, TOKEN_U32, TOKEN_U64, TOKEN_U128, TOKEN_U256, TOKEN_U512,
    TOKEN_F8, TOKEN_F16, TOKEN_F32, TOKEN_F64, TOKEN_F128, TOKEN_F256, TOKEN_F512,
    TOKEN_CHAR_TYPE, TOKEN_STR, TOKEN_ARR, TOKEN_ARRAY,
    TOKEN_INT, TOKEN_VOID, TOKEN_CONST,
    
    // Keywords
    TOKEN_DEF, TOKEN_NEW, TOKEN_CONTINUE, TOKEN_BREAK, TOKEN_GOTO,
    TOKEN_FUNC, TOKEN_RETURN, TOKEN_NOT, TOKEN_OR, TOKEN_AND, TOKEN_XOR,
    TOKEN_IF, TOKEN_ELSE, TOKEN_ELSEIF, TOKEN_SWITCH, TOKEN_GROUP,
    TOKEN_WHILE, TOKEN_FOR, TOKEN_FOREACH,
    TOKEN_STRUCT, TOKEN_ENUM,
    TOKEN_TRUE, TOKEN_FALSE,
    TOKEN_PRINT, TOKEN_ECHO, TOKEN_INPUT,
    TOKEN_MEMNEW, TOKEN_MEMDEL,
    TOKEN_SIZEOF, TOKEN_ARRLEN, TOKEN_STRLEN,
    
    // Operators
    TOKEN_PLUS, TOKEN_MINUS, TOKEN_MULTIPLY, TOKEN_DIVIDE, TOKEN_MODULO,
    TOKEN_INCREMENT, TOKEN_DECREMENT,
    TOKEN_ASSIGN, TOKEN_PLUS_ASSIGN, TOKEN_MINUS_ASSIGN,
    TOKEN_MULTIPLY_ASSIGN, TOKEN_DIVIDE_ASSIGN, TOKEN_MODULO_ASSIGN,
    TOKEN_AND_ASSIGN, TOKEN_OR_ASSIGN, TOKEN_XOR_ASSIGN,
    TOKEN_LEFT_SHIFT_ASSIGN, TOKEN_RIGHT_SHIFT_ASSIGN,
    
    // Comparison
    TOKEN_EQUAL, TOKEN_NOT_EQUAL, TOKEN_GREATER, TOKEN_LESS,
    TOKEN_GREATER_EQUAL, TOKEN_LESS_EQUAL,
    
    // Logical
    TOKEN_LOGICAL_AND, TOKEN_LOGICAL_OR, TOKEN_LOGICAL_NOT,
    
    // Bitwise
    TOKEN_BITWISE_AND, TOKEN_BITWISE_OR, TOKEN_BITWISE_XOR,
    TOKEN_LEFT_SHIFT, TOKEN_RIGHT_SHIFT, TOKEN_BITWISE_NOT,
    
    // Punctuation
    TOKEN_LPAREN, TOKEN_RPAREN, TOKEN_LBRACE, TOKEN_RBRACE,
    TOKEN_LBRACKET, TOKEN_RBRACKET, TOKEN_SEMICOLON, TOKEN_COMMA,
    TOKEN_DOT, TOKEN_ARROW, TOKEN_COLON, TOKEN_QUESTION,
    
    // Special
    TOKEN_EOF, TOKEN_NEWLINE, TOKEN_WHITESPACE,
    TOKEN_COMMENT, TOKEN_INCLUDE, TOKEN_DEFINE,
    TOKEN_ELLIPSIS, // ...
    
    // Error
    TOKEN_ERROR,
    TOKEN_UNKNOWN
} TokenType;

// Token structure
struct Token {
    TokenType type;
    char* value;
    int line;
    int column;
    size_t length;
};

// AST Node types
typedef enum {
    AST_PROGRAM,
    AST_FUNCTION,
    AST_VARIABLE_DECLARATION,
    AST_ASSIGNMENT,
    AST_BINARY_OPERATION,
    AST_UNARY_OPERATION,
    AST_FUNCTION_CALL,
    AST_IF_STATEMENT,
    AST_WHILE_LOOP,
    AST_FOR_LOOP,
    AST_GROUP_STATEMENT,
    AST_RETURN_STATEMENT,
    AST_BLOCK,
    AST_EXPRESSION,
    AST_LITERAL,
    AST_IDENTIFIER,
    AST_ARRAY_ACCESS,
    AST_STRUCT_ACCESS,
    AST_POINTER_DEREFERENCE,
    AST_ADDRESS_OF,
    AST_ARRAY_DECLARATION,
    AST_STRUCT_DECLARATION,
    AST_ENUM_DECLARATION
} ASTNodeType;

// AST Node structure
struct ASTNode {
    ASTNodeType type;
    Token* token;
    struct ASTNode** children;
    int child_count;
    int capacity;
    
    // Type information
    char* data_type;
    bool is_pointer;
    int pointer_depth;
    
    // Additional data
    union {
        int int_value;
        double float_value;
        char* string_value;
        char char_value;
    } value;
};

// Data type information
typedef enum {
    TYPE_VOID,
    TYPE_I8, TYPE_I16, TYPE_I32, TYPE_I64, TYPE_I128, TYPE_I256, TYPE_I512,
    TYPE_U8, TYPE_U16, TYPE_U32, TYPE_U64, TYPE_U128, TYPE_U256, TYPE_U512,
    TYPE_F8, TYPE_F16, TYPE_F32, TYPE_F64, TYPE_F128, TYPE_F256, TYPE_F512,
    TYPE_CHAR, TYPE_STRING, TYPE_ARRAY,
    TYPE_STRUCT, TYPE_ENUM, TYPE_FUNCTION,
    TYPE_POINTER,
    TYPE_UNKNOWN
} DataType;

// Symbol table for variables and functions
struct Symbol {
    char* name;
    DataType type;
    bool is_pointer;
    int pointer_depth;
    bool is_const;
    bool is_function;
    int scope_level;
    ASTNode* declaration;
    struct Symbol* next;
};

struct SymbolTable {
    Symbol* symbols;
    struct SymbolTable* parent;
    int scope_level;
};

// Error reporting
typedef enum {
    ERROR_LEXICAL,
    ERROR_SYNTAX,
    ERROR_SEMANTIC,
    ERROR_TYPE,
    ERROR_UNDEFINED_SYMBOL,
    ERROR_REDEFINED_SYMBOL,
    ERROR_INCOMPATIBLE_TYPES,
    ERROR_INVALID_OPERATION,
    ERROR_MEMORY,
    ERROR_IO
} ErrorType;

typedef struct {
    ErrorType type;
    char* message;
    char* filename;
    int line;
    int column;
} CompilerError;

// Compiler context
typedef struct {
    char* filename;
    char* source_code;
    Token* tokens;
    int token_count;
    int current_token;
    ASTNode* ast;
    SymbolTable* symbol_table;
    CompilerError* errors;
    int error_count;
    bool has_errors;
} CompilerContext;

// Function declarations

// Lexer functions
Token* tokenize(const char* source, int* token_count);
void free_tokens(Token* tokens, int count);
const char* token_type_to_string(TokenType type);

// Parser functions
ASTNode* parse(Token* tokens, int token_count, CompilerContext* context);
ASTNode* create_ast_node(ASTNodeType type, Token* token);
void add_child(ASTNode* parent, ASTNode* child);
void free_ast(ASTNode* node);

// Semantic analysis
bool semantic_analysis(ASTNode* ast, CompilerContext* context);
SymbolTable* create_symbol_table(SymbolTable* parent);
Symbol* add_symbol(SymbolTable* table, const char* name, DataType type);
Symbol* lookup_symbol(SymbolTable* table, const char* name);
void free_symbol_table(SymbolTable* table);

// Code generation
bool generate_code(ASTNode* ast, const char* output_file, CompilerContext* context);

// Error handling
void add_error(CompilerContext* context, ErrorType type, const char* message, int line, int column);
void print_errors(CompilerContext* context);
void free_errors(CompilerContext* context);

// Utility functions
char* read_file(const char* filename);
bool write_file(const char* filename, const char* content);
DataType token_to_data_type(TokenType token_type);
const char* data_type_to_string(DataType type);
int get_type_size(DataType type);
bool is_numeric_type(DataType type);
bool is_integer_type(DataType type);
bool is_float_type(DataType type);

// Compiler main functions
CompilerContext* create_compiler_context(const char* filename);
void free_compiler_context(CompilerContext* context);
bool compile_file(const char* input_file, const char* output_file);

#endif // CP_COMPILER_H
