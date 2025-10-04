#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Karakter kontrolleri için

// Token tiplerini tanımlıyoruz.
// Her token, programdaki bir dil öğesini temsil eder (örneğin, operatör, sayı, anahtar kelime).
typedef enum {
    TOKEN_EOF,            // Dosya sonu
    TOKEN_NUMBER,         // Sayı
    TOKEN_IDENTIFIER,     // Değişken isimleri, fonksiyon isimleri
    TOKEN_PLUS,           // +
    TOKEN_MINUS,          // -
    TOKEN_STAR,           // *
    TOKEN_SLASH,          // /
    TOKEN_PERCENT,        // %
    TOKEN_INCREMENT,      // ++
    TOKEN_DECREMENT,      // --
    TOKEN_ASSIGN,         // =
    TOKEN_PLUS_ASSIGN,    // +=
    TOKEN_MINUS_ASSIGN,   // -=
    TOKEN_STAR_ASSIGN,    // *=
    TOKEN_SLASH_ASSIGN,   // /=
    TOKEN_PERCENT_ASSIGN, // %=
    TOKEN_EQ,             // ==
    TOKEN_NEQ,            // !=
    TOKEN_GT,             // >
    TOKEN_LT,             // <
    TOKEN_GTE,            // >=
    TOKEN_LTE,            // <=
    TOKEN_AND,            // &&
    TOKEN_OR,             // ||
    TOKEN_NOT,            // !
    TOKEN_LPAREN,         // (
    TOKEN_RPAREN,         // )
    TOKEN_LBRACE,         // {
    TOKEN_RBRACE,         // }
    TOKEN_SEMICOLON,      // ;
    TOKEN_COMMA,          // ,
    TOKEN_STRING,         // "..."
    TOKEN_CHAR,           // '...'
    TOKEN_KEYWORD,        // if, else, return vb.
    TOKEN_UNKNOWN         // Tanımsız veya bilinmeyen token
} TokenType;

// Token yapısı, tokenin tipi ve lexeme'sini tutar.
// Lexer tarafından üretilir.
typedef struct {
    TokenType type;       // Token tipi
    char lexeme[256];     // Tokenin metinsel karşılığı
    int line;             // Satır numarası (hata raporları için)
} Token;

// Lexer yapısı, kaynak kodu ve pozisyon bilgisi içerir.
typedef struct {
    const char *src;      // Kaynak kodu gösteren işaretçi
    size_t pos;           // Mevcut karakter pozisyonu
    int line;             // Satır sayısı
} Lexer;

// Lexer'ı başlatır, kaynak kodu ve başlangıç durumu ayarlanır.
void initLexer(Lexer *lexer, const char *source);

// Bir sonraki tokeni üretir ve döner.
Token getNextToken(Lexer *lexer);

// Token bilgisini ekrana yazdırır (test ve hata ayıklama için)
void printToken(Token token);

#endif // LEXER_H