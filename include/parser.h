#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

// AST node tipi
typedef enum {
    AST_NONE,
    AST_BINARY_OP,
    AST_UNARY_OP,
    AST_LITERAL,
    AST_IDENTIFIER,
    AST_FUNCTION_CALL,
    AST_GROUP_CALL,
    AST_ACCESS,
    AST_STRUCT,
    AST_ENUM,
    AST_STATEMENT,
    AST_IF,
    AST_ELSE,
    AST_WHILE,
    AST_FOR,
    AST_RETURN,
    AST_BLOCK,
    AST_VAR_DECL,
    AST_ASSIGN,
    AST_STRUCT_DECL,
    AST_ENUM_DECL,
    // Daha fazla genişletilebilir
} ASTNodeType;

typedef struct ASTNode {
    ASTNodeType type;
    char* value; // Operatör, isim, literal
    struct ASTNode** children;
    int childCount;
    int line;
} ASTNode;

typedef struct {
    Token* tokens;
    int current;
    int size;
} Parser;

// Prototipler
Parser* create_parser(Token* tokens, int size);
void destroy_parser(Parser* parser);

// Parse fonksiyonları
ASTNode* parse_expression(Parser* parser, int minPrecedence);
ASTNode* parse_statement(Parser* parser);
ASTNode* parse_block(Parser* parser);
ASTNode* parse_function(Parser* parser);
ASTNode* parse_group_function(Parser* parser);
ASTNode* parse_primary(Parser* parser);
ASTNode* parse_unary(Parser* parser);
ASTNode* parse_binary(Parser* parser, int precedence);
ASTNode* parse_if(Parser* parser);
ASTNode* parse_while(Parser* parser);
ASTNode* parse_for(Parser* parser);
ASTNode* parse_return(Parser* parser);
ASTNode* parse_struct(Parser* parser);
ASTNode* parse_enum(Parser* parser);
ASTNode* parse_variable_declaration(Parser* parser);
ASTNode* parse_assignment(Parser* parser);

// Yardımcı fonksiyonlar
int match(Parser* parser, TokenType type);
void expect(Parser* parser, TokenType type, const char* errorMsg);
Token* current_token(Parser* parser);
void advance(Parser* parser);
int get_precedence(TokenType type);
ASTNode* create_ast_node(ASTNodeType type, const char* value);
void add_child(ASTNode* parent, ASTNode* child);

#endif