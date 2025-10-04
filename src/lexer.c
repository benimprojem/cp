#include "lexer.h"

// Boşluk ve yeni satır karakterlerini atlar, satır sayısını günceller
static void skipWhitespace(Lexer *lexer) {
    while (isspace(lexer->src[lexer->pos])) {
        if (lexer->src[lexer->pos] == '\n') {
            lexer->line++;
        }
        lexer->pos++;
    }
}

// Harf veya alt çizgi karakterlerini kontrol eder
static int isAlpha(char c) {
    return (isalpha(c) || c == '_');
}

// Rakam karakterlerini kontrol eder
static int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Lexer'ı başlatır, kaynak kodu ve durumu sıfırlar
void initLexer(Lexer *lexer, const char *source) {
    lexer->src = source;
    lexer->pos = 0;
    lexer->line = 1;
}

// Bir sonraki tokeni üretir
Token getNextToken(Lexer *lexer) {
    Token token;
    token.line = lexer->line;

    // Boşlukları ve boşluk karakterlerini atla
    skipWhitespace(lexer);

    // Son karakter null ise, EOF
    char c = lexer->src[lexer->pos];
    if (c == '\0') {
        token.type = TOKEN_EOF;
        strcpy(token.lexeme, "EOF");
        return token;
    }

    // Sayı ise
    if (isDigit(c)) {
        int start = lexer->pos;
        while (isDigit(lexer->src[lexer->pos])) lexer->pos++;
        int len = lexer->pos - start;
        strncpy(token.lexeme, &lexer->src[start], len);
        token.lexeme[len] = '\0';
        token.type = TOKEN_NUMBER;
        return token;
    }

    // Kimlik veya anahtar kelime
    if (isAlpha(c)) {
        int start = lexer->pos;
        while (isAlpha(lexer->src[lexer->pos]) || isDigit(lexer->src[lexer->pos])) lexer->pos++;
        int len = lexer->pos - start;
        strncpy(token.lexeme, &lexer->src[start], len);
        token.lexeme[len] = '\0';

         // Anahtar kelimeleri kontrol et
        if (strcmp(token.lexeme, "int") == 0 ||
            strcmp(token.lexeme, "char") == 0 ||
            strcmp(token.lexeme, "str") == 0 ||
            strcmp(token.lexeme, "arr") == 0 ||
            strcmp(token.lexeme, "const") == 0 ||
            strcmp(token.lexeme, "true") == 0 ||
            strcmp(token.lexeme, "false") == 0 ||
            strcmp(token.lexeme, "void") == 0 ||
            strcmp(token.lexeme, "nl") == 0 ||
            strcmp(token.lexeme, "tl") == 0) {
            token.type = TOKEN_KEYWORD;
        } else {
        // sadece identifier olarak alıyoruz.
            token.type = TOKEN_IDENTIFIER;
        }
        return token;
		
    }
	
	// String literal
    if (c == '\"') {
        lexer->pos++;
        int start = lexer->pos;
        while (lexer->src[lexer->pos] != '\"' && lexer->src[lexer->pos] != '\0') {
            if (lexer->src[lexer->pos] == '\\') {
                lexer->pos += 2; // kaçış dizisi
            } else {
                lexer->pos++;
            }
        }
        int len = lexer->pos - start;
        strncpy(token.lexeme, &lexer->src[start], len);
        token.lexeme[len] = '\0';
        if (lexer->src[lexer->pos] == '\"') lexer->pos++;
        token.type = TOKEN_STRING;
        return token;
    }

    // Char literal
    if (c == '\'') {
        lexer->pos++;
        token.lexeme[0] = lexer->src[lexer->pos];
        token.lexeme[1] = '\0';
        lexer->pos++;
        if (lexer->src[lexer->pos] == '\'') lexer->pos++;
        token.type = TOKEN_CHAR;
        return token;
    }
	
    // İşaret ve operatörleri tanımla
    switch (c) {
        case '+':
            if (lexer->src[lexer->pos + 1] == '+') {
                lexer->pos += 2;
                token.type = TOKEN_INCREMENT;
                strcpy(token.lexeme, "++");
            } else {
                lexer->pos++;
                token.type = TOKEN_PLUS;
                strcpy(token.lexeme, "+");
            }
            return token;

        case '-':
            if (lexer->src[lexer->pos + 1] == '-') {
                lexer->pos += 2;
                token.type = TOKEN_DECREMENT;
                strcpy(token.lexeme, "--");
            } else {
                lexer->pos++;
                token.type = TOKEN_MINUS;
                strcpy(token.lexeme, "-");
            }
            return token;

        case '*':
            lexer->pos++;
            token.type = TOKEN_STAR;
            strcpy(token.lexeme, "*");
            return token;

        case '/':
            lexer->pos++;
            token.type = TOKEN_SLASH;
            strcpy(token.lexeme, "/");
            return token;

        case '%':
            lexer->pos++;
            token.type = TOKEN_PERCENT;
            strcpy(token.lexeme, "%");
            return token;

        case '=':
            if (lexer->src[lexer->pos + 1] == '=') {
                lexer->pos += 2;
                token.type = TOKEN_EQ;
                strcpy(token.lexeme, "==");
            } else {
                lexer->pos++;
                token.type = TOKEN_ASSIGN;
                strcpy(token.lexeme, "=");
            }
            return token;

        case '!':
            if (lexer->src[lexer->pos + 1] == '=') {
                lexer->pos += 2;
                token.type = TOKEN_NEQ;
                strcpy(token.lexeme, "!=");
            } else {
                lexer->pos++;
                token.type = TOKEN_NOT;
                strcpy(token.lexeme, "!");
            }
            return token;

        case '<':
            if (lexer->src[lexer->pos + 1] == '=') {
                lexer->pos += 2;
                token.type = TOKEN_LTE;
                strcpy(token.lexeme, "<=");
            } else {
                lexer->pos++;
                token.type = TOKEN_LT;
                strcpy(token.lexeme, "<");
            }
            return token;

        case '>':
            if (lexer->src[lexer->pos + 1] == '=') {
                lexer->pos += 2;
                token.type = TOKEN_GTE;
                strcpy(token.lexeme, ">=");
            } else {
                lexer->pos++;
                token.type = TOKEN_GT;
                strcpy(token.lexeme, ">");
            }
            return token;

        case '&':
            if (lexer->src[lexer->pos + 1] == '&') {
                lexer->pos += 2;
                token.type = TOKEN_AND;
                strcpy(token.lexeme, "&&");
            }
            return token;

        case '|':
            if (lexer->src[lexer->pos + 1] == '|') {
                lexer->pos += 2;
                token.type = TOKEN_OR;
                strcpy(token.lexeme, "||");
            }
            return token;

        case '(':
            lexer->pos++;
            token.type = TOKEN_LPAREN;
            strcpy(token.lexeme, "(");
            return token;

        case ')':
            lexer->pos++;
            token.type = TOKEN_RPAREN;
            strcpy(token.lexeme, ")");
            return token;

        case '{':
            lexer->pos++;
            token.type = TOKEN_LBRACE;
            strcpy(token.lexeme, "{");
            return token;

        case '}':
            lexer->pos++;
            token.type = TOKEN_RBRACE;
            strcpy(token.lexeme, "}");
            return token;

        case ';':
            lexer->pos++;
            token.type = TOKEN_SEMICOLON;
            strcpy(token.lexeme, ";");
            return token;

        case ',':
            lexer->pos++;
            token.type = TOKEN_COMMA;
            strcpy(token.lexeme, ",");
            return token;

        case '\"': // string literal
            lexer->pos++;
            int start = lexer->pos;
            while (lexer->src[lexer->pos] != '\"' && lexer->src[lexer->pos] != '\0') {
                lexer->pos++;
            }
            int len = lexer->pos - start;
            strncpy(token.lexeme, &lexer->src[start], len);
            token.lexeme[len] = '\0';
            token.type = TOKEN_STRING;
            if (lexer->src[lexer->pos] == '\"') lexer->pos++; // closing quote
            return token;

        case '\'':
            // char literal
            lexer->pos++;
            token.lexeme[0] = lexer->src[lexer->pos];
            token.lexeme[1] = '\0';
            lexer->pos++;
            if (lexer->src[lexer->pos] == '\'') lexer->pos++;
            token.type = TOKEN_CHAR;
            return token;

        default:
            // bilinmeyen karakter
            lexer->pos++;
            token.type = TOKEN_UNKNOWN;
            strcpy(token.lexeme, &c);
            return token;
    }
}

// Token bilgisini yazdırır, hatalarda kullanılır.
void printToken(Token token) {
    const char *typeNames[] = {
        "EOF", "Number", "Identifier", "Plus", "Minus", "Star", "Slash", "Percent",
        "Increment", "Decrement", "Assign", "PlusAssign", "MinusAssign", "StarAssign",
        "SlashAssign", "PercentAssign", "Equal", "NotEqual", "Greater", "Less",
        "GreaterEqual", "LessEqual", "And", "Or", "Not", "LParen", "RParen",
        "LBrace", "RBrace", "Semicolon", "Comma", "String", "Char", "Unknown"
    };

    printf("Token: %-15s Lexeme: %s (Line: %d)\n", 
        typeNames[token.type],
        token.lexeme,
        token.line
    );
}
