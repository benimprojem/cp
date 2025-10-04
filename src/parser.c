#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper: Token öncelik seviyeleri
static int get_precedence(TokenType type) {
    switch (type) {
        case TOKEN_OR: return 1;
        case TOKEN_AND: return 2;
        case TOKEN_EQ:
        case TOKEN_NE: return 3;
        case TOKEN_GT:
        case TOKEN_LT:
        case TOKEN_GTE:
        case TOKEN_LTE: return 4;
        case TOKEN_PLUS:
        case TOKEN_MINUS: return 5;
        case TOKEN_MUL:
        case TOKEN_DIV:
        case TOKEN_MOD: return 6;
        case TOKEN_DOT: return 7;
        default: return 0;
    }
}

static int is_operator(TokenType type) {
    return get_precedence(type) > 0;
}

ASTNode* create_ast_node(ASTNodeType type, const char* value) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value ? strdup(value) : NULL;
    node->children = NULL;
    node->childCount = 0;
    node->line = 0;
    return node;
}

void add_child(ASTNode* parent, ASTNode* child) {
    parent->children = (ASTNode**)realloc(parent->children, sizeof(ASTNode*) * (parent->childCount + 1));
    parent->children[parent->childCount++] = child;
}

Parser* create_parser(Token* tokens, int size) {
    Parser* parser = (Parser*)malloc(sizeof(Parser));
    parser->tokens = tokens;
    parser->current = 0;
    parser->size = size;
    return parser;
}

void destroy_parser(Parser* parser) {
    free(parser);
}

Token* current_token(Parser* parser) {
    if (parser->current < parser->size)
        return &parser->tokens[parser->current];
    static Token eofToken = {TOKEN_EOF, NULL, 0};
    return &eofToken;
}

void advance(Parser* parser) {
    if (parser->current < parser->size)
        parser->current++;
}

int match(Parser* parser, TokenType type) {
    if (current_token(parser)->type == type) {
        advance(parser);
        return 1;
    }
    return 0;
}

void expect(Parser* parser, TokenType type, const char* errorMsg) {
    if (current_token(parser)->type != type) {
        printf("Hata: %s | Satır: %d\n", errorMsg, current_token(parser)->line);
        exit(1);
    }
    advance(parser);
}

// İfade parse
ASTNode* parse_expression(Parser* parser, int minPrecedence) {
    ASTNode* left = parse_primary(parser);
    while (is_operator(current_token(parser)->type) && get_precedence(current_token(parser)->type) >= minPrecedence) {
        Token* opToken = current_token(parser);
        int precedence = get_precedence(opToken->type);
        advance(parser);
        ASTNode* right = parse_expression(parser, precedence + 1);
        ASTNode* opNode = create_ast_node(AST_BINARY_OP, opToken->lexeme);
        add_child(opNode, left);
        add_child(opNode, right);
        left = opNode;
    }
    return left;
}

// Primary
ASTNode* parse_primary(Parser* parser) {
    Token* token = current_token(parser);
    switch (token->type) {
        case TOKEN_NUMBER:
            {
                ASTNode* node = create_ast_node(AST_LITERAL, token->lexeme);
                advance(parser);
                return node;
            }
        case TOKEN_IDENTIFIER:
            {
                ASTNode* node = create_ast_node(AST_IDENTIFIER, token->lexeme);
                advance(parser);
                return node;
            }
        case TOKEN_LPAREN:
            {
                advance(parser);
                ASTNode* expr = parse_expression(parser, 0);
                expect(parser, TOKEN_RPAREN, "')' bekleniyor");
                return expr;
            }
        case TOKEN_MINUS:
        case TOKEN_NOT:
            {
                Token* opToken = current_token(parser);
                advance(parser);
                ASTNode* operand = parse_primary(parser);
                ASTNode* unaryNode = create_ast_node(AST_UNARY_OP, opToken->lexeme);
                add_child(unaryNode, operand);
                return unaryNode;
            }
        default:
            printf("Hata: Beklenmeyen token %d\n", token->type);
            exit(1);
    }
    return NULL; // Ulaşılmaz
}

// Statement
ASTNode* parse_statement(Parser* parser) {
    Token* token = current_token(parser);
    switch (token->type) {
        case TOKEN_IF:
            return parse_if(parser);
        case TOKEN_WHILE:
            return parse_while(parser);
        case TOKEN_FOR:
            return parse_for(parser);
        case TOKEN_RETURN:
            return parse_return(parser);
        case TOKEN_LBRACE:
            return parse_block(parser);
        case TOKEN_STRUCT:
            return parse_struct(parser);
        case TOKEN_ENUM:
            return parse_enum(parser);
        case TOKEN_IDENTIFIER:
            // Atama veya fonksiyon çağrısı
            return parse_assignment_or_func_call(parser);
        default:
            return parse_expression(parser, 0);
    }
}

// {...}
ASTNode* parse_block(Parser* parser) {
    expect(parser, TOKEN_LBRACE, "'{' bekleniyor");
    ASTNode* blockNode = create_ast_node(AST_BLOCK, NULL);
    while (current_token(parser)->type != TOKEN_RBRACE && current_token(parser)->type != TOKEN_EOF) {
        ASTNode* stmt = parse_statement(parser);
        add_child(blockNode, stmt);
    }
    expect(parser, TOKEN_RBRACE, "'}' bekleniyor");
    return blockNode;
}

// if
ASTNode* parse_if(Parser* parser) {
    expect(parser, TOKEN_IF, "'if' bekleniyor");
    expect(parser, TOKEN_LPAREN, "'(' bekleniyor");
    ASTNode* cond = parse_expression(parser, 0);
    expect(parser, TOKEN_RPAREN, "')' bekleniyor");
    ASTNode* thenBranch = parse_statement(parser);
    ASTNode* ifNode = create_ast_node(AST_IF, NULL);
    add_child(ifNode, cond);
    add_child(ifNode, thenBranch);
    if (match(parser, TOKEN_ELSE))
        add_child(ifNode, parse_statement(parser));
    return ifNode;
}

// while
ASTNode* parse_while(Parser* parser) {
    expect(parser, TOKEN_WHILE, "'while' bekleniyor");
    expect(parser, TOKEN_LPAREN, "'(' bekleniyor");
    ASTNode* cond = parse_expression(parser, 0);
    expect(parser, TOKEN_RPAREN, "')' bekleniyor");
    ASTNode* body = parse_statement(parser);
    ASTNode* whileNode = create_ast_node(AST_WHILE, NULL);
    add_child(whileNode, cond);
    add_child(whileNode, body);
    return whileNode;
}

// for
ASTNode* parse_for(Parser* parser) {
    expect(parser, TOKEN_FOR, "'for' bekleniyor");
    expect(parser, TOKEN_LPAREN, "'(' bekleniyor");
    // For döngüsü detaylandırılmalı
    // Örnek: for (initial; condition; increment)
    ASTNode* forNode = create_ast_node(AST_FOR, NULL);
    // Atama veya ilk ifade
    ASTNode* init = parse_expression(parser, 0);
    add_child(forNode, init);
    expect(parser, TOKEN_SEMICOLON, "';' bekleniyor");
    // Koşul
    ASTNode* cond = parse_expression(parser, 0);
    add_child(forNode, cond);
    expect(parser, TOKEN_SEMICOLON, "';' bekleniyor");
    // Artış
    ASTNode* inc = parse_expression(parser, 0);
    add_child(forNode, inc);
    expect(parser, TOKEN_RPAREN, "')' bekleniyor");
    // Döngü gövdesi
    ASTNode* body = parse_statement(parser);
    add_child(forNode, body);
    return forNode;
}

// return
ASTNode* parse_return(Parser* parser) {
    expect(parser, TOKEN_RETURN, "'return' bekleniyor");
    ASTNode* expr = parse_expression(parser, 0);
    ASTNode* retNode = create_ast_node(AST_RETURN, NULL);
    add_child(retNode, expr);
    return retNode;
}

// struct
ASTNode* parse_struct(Parser* parser) {
    expect(parser, TOKEN_STRUCT, "'struct' bekleniyor");
    Token* nameToken = current_token(parser);
    if (nameToken->type != TOKEN_IDENTIFIER) {
        printf("Hata: Struct ismi bekleniyor\n");
        exit(1);
    }
    advance(parser);
    expect(parser, TOKEN_LBRACE, "'{' bekleniyor");
    ASTNode* structNode = create_ast_node(AST_STRUCT, nameToken->lexeme);
    while (current_token(parser)->type != TOKEN_RBRACE && current_token(parser)->type != TOKEN_EOF) {
        // Üye tanımları
        // Örnek: int a;
        ASTNode* member = parse_variable_declaration(parser);
        add_child(structNode, member);
        expect(parser, TOKEN_SEMICOLON, "';' bekleniyor");
    }
    expect(parser, TOKEN_RBRACE, "'}' bekleniyor");
    return structNode;
}

// enum
ASTNode* parse_enum(Parser* parser) {
    expect(parser, TOKEN_ENUM, "'enum' bekleniyor");
    Token* nameToken = current_token(parser);
    if (nameToken->type != TOKEN_IDENTIFIER) {
        printf("Hata: Enum ismi bekleniyor\n");
        exit(1);
    }
    advance(parser);
    expect(parser, TOKEN_LBRACE, "'{' bekleniyor");
    ASTNode* enumNode = create_ast_node(AST_ENUM, nameToken->lexeme);
    while (current_token(parser)->type != TOKEN_RBRACE && current_token(parser)->type != TOKEN_EOF) {
        // Üye isimleri
        if (current_token(parser)->type != TOKEN_IDENTIFIER) {
            printf("Hata: Enum üyesi isimleri bekleniyor\n");
            exit(1);
        }
        ASTNode* member = create_ast_node(AST_ENUM_DECL, current_token(parser)->lexeme);
        advance(parser);
        add_child(enumNode, member);
        if (match(parser, TOKEN_COMMA))
            continue;
        else
            break;
    }
    expect(parser, TOKEN_RBRACE, "'}' bekleniyor");
    return enumNode;
}

// Variable declaration
ASTNode* parse_variable_declaration(Parser* parser) {
    // Basit: tip yok, isim
    // Geliştirilmiş: tip, isim, başlangıç değeri
    if (current_token(parser)->type != TOKEN_IDENTIFIER) {
        printf("Hata: Değişken ismi bekleniyor\n");
        exit(1);
    }
    Token* nameToken = current_token(parser);
    advance(parser);
    // İsim
    ASTNode* varDecl = create_ast_node(AST_VAR_DECL, nameToken->lexeme);
    return varDecl;
}

// Atama veya fonksiyon çağrısı
ASTNode* parse_assignment_or_func_call(Parser* parser) {
    // Bu örnekte, sadece isim ve ardından '=' veya '('
    if (current_token(parser)->type != TOKEN_IDENTIFIER) {
        printf("Hata: Beklenmeyen başlangıç\n");
        exit(1);
    }

    Token* nameToken = current_token(parser);
    advance(parser);
    if (match(parser, TOKEN_ASSIGN)) {
        // Atama
        ASTNode* assignNode = create_ast_node(AST_ASSIGN, NULL);
        ASTNode* varNode = create_ast_node(AST_IDENTIFIER, nameToken->lexeme);
        ASTNode* expr = parse_expression(parser, 0);
        add_child(assignNode, varNode);
        add_child(assignNode, expr);
        return assignNode;
    } else if (match(parser, TOKEN_LPAREN)) {
        // Fonksiyon çağrısı
        ASTNode* callNode = create_ast_node(AST_FUNCTION_CALL, nameToken->lexeme);
        // parametreler
        if (current_token(parser)->type != TOKEN_RPAREN) {
            do {
                ASTNode* param = parse_expression(parser, 0);
                add_child(callNode, param);
            } while (match(parser, TOKEN_COMMA));
        }
        expect(parser, TOKEN_RPAREN, "')' bekleniyor");
        return callNode;
    } else {
        printf("Hata: Beklenmeyen token sonrası\n");
        exit(1);
    }
}
