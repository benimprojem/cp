#ifndef CP_STRING_H
#define CP_STRING_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

// CP Language String Library
// String manipulation functions for CP programs

// Basic string functions
size_t cp_strlen(const char* str);
char* cp_strcpy(char* dest, const char* src);
char* cp_strncpy(char* dest, const char* src, size_t n);
char* cp_strcat(char* dest, const char* src);
char* cp_strncat(char* dest, const char* src, size_t n);
int cp_strcmp(const char* str1, const char* str2);
int cp_strncmp(const char* str1, const char* str2, size_t n);
char* cp_strchr(const char* str, int c);
char* cp_strrchr(const char* str, int c);
char* cp_strstr(const char* haystack, const char* needle);

// String creation and destruction
char* cp_string_create(size_t length);
char* cp_string_create_from(const char* source);
char* cp_string_create_from_chars(char c, size_t count);
void cp_string_destroy(char* str);

// Dynamic string operations
char* cp_string_append(char* dest, const char* src);
char* cp_string_prepend(char* dest, const char* src);
char* cp_string_insert(char* dest, size_t pos, const char* src);
char* cp_string_remove(char* str, size_t pos, size_t length);
char* cp_string_replace(char* str, const char* old_substr, const char* new_substr);
char* cp_string_substring(const char* str, size_t start, size_t length);

// String manipulation
char* cp_string_trim(char* str);
char* cp_string_trim_left(char* str);
char* cp_string_trim_right(char* str);
char* cp_string_to_upper(char* str);
char* cp_string_to_lower(char* str);
char* cp_string_reverse(char* str);

// String searching and replacing
int cp_string_find(const char* str, const char* substr);
int cp_string_find_last(const char* str, const char* substr);
int cp_string_count(const char* str, const char* substr);
bool cp_string_starts_with(const char* str, const char* prefix);
bool cp_string_ends_with(const char* str, const suffix);
bool cp_string_contains(const char* str, const char* substr);

// String splitting and joining
char** cp_string_split(const char* str, const char* delimiter, int* count);
char* cp_string_join(char** strings, int count, const char* separator);
void cp_string_array_free(char** strings, int count);

// String conversion functions
int32_t cp_string_to_i32(const char* str, bool* success);
int64_t cp_string_to_i64(const char* str, bool* success);
float cp_string_to_f32(const char* str, bool* success);
double cp_string_to_f64(const char* str, bool* success);
char* cp_i32_to_string(int32_t value);
char* cp_i64_to_string(int64_t value);
char* cp_f32_to_string(float value, int precision);
char* cp_f64_to_string(double value, int precision);

// String formatting (similar to sprintf)
char* cp_string_format(const char* format, ...);
int cp_string_format_buffer(char* buffer, size_t size, const char* format, ...);

// String validation
bool cp_string_is_empty(const char* str);
bool cp_string_is_whitespace(const char* str);
bool cp_string_is_numeric(const char* str);
bool cp_string_is_integer(const char* str);
bool cp_string_is_float(const char* str);
bool cp_string_is_alpha(const char* str);
bool cp_string_is_alphanumeric(const char* str);

// Unicode and encoding support (basic)
bool cp_string_is_utf8(const char* str);
size_t cp_string_utf8_length(const char* str);
char* cp_string_utf8_substring(const char* str, size_t start, size_t length);

// String hashing
uint32_t cp_string_hash(const char* str);
uint64_t cp_string_hash64(const char* str);

// String builder for efficient concatenation
typedef struct {
    char* buffer;
    size_t length;
    size_t capacity;
} StringBuilder;

StringBuilder* cp_string_builder_create(size_t initial_capacity);
void cp_string_builder_destroy(StringBuilder* sb);
void cp_string_builder_append(StringBuilder* sb, const char* str);
void cp_string_builder_append_char(StringBuilder* sb, char c);
void cp_string_builder_append_format(StringBuilder* sb, const char* format, ...);
char* cp_string_builder_to_string(StringBuilder* sb);
void cp_string_builder_clear(StringBuilder* sb);
size_t cp_string_builder_length(StringBuilder* sb);

// String constants and utilities
#define CP_STRING_EMPTY ""
#define CP_STRING_NEWLINE "\n"
#define CP_STRING_TAB "\t"
#define CP_STRING_SPACE " "

// Error codes for string operations
typedef enum {
    CP_STRING_SUCCESS = 0,
    CP_STRING_ERROR_NULL_POINTER,
    CP_STRING_ERROR_OUT_OF_MEMORY,
    CP_STRING_ERROR_INDEX_OUT_OF_BOUNDS,
    CP_STRING_ERROR_INVALID_FORMAT,
    CP_STRING_ERROR_BUFFER_TOO_SMALL
} StringError;

#endif // CP_STRING_H
