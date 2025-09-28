#ifndef CP_IO_H
#define CP_IO_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// CP Language I/O Library
// Standard input/output functions for CP programs

// Print functions
void cp_print_i32(int32_t value);
void cp_print_i64(int64_t value);
void cp_print_f32(float value);
void cp_print_f64(double value);
void cp_print_char(char value);
void cp_print_string(const char* value);
void cp_print_newline(void);
void cp_print_tab(void);

// Echo function - formatted printing with escape sequences
void cp_echo(const char* format);

// Input functions
int32_t cp_input_i32(void);
int64_t cp_input_i64(void);
float cp_input_f32(void);
double cp_input_f64(void);
char cp_input_char(void);
char* cp_input_string(char* buffer, int max_length);

// File I/O functions
FILE* cp_file_open(const char* filename, const char* mode);
void cp_file_close(FILE* file);
char* cp_file_read_line(FILE* file, char* buffer, int max_length);
bool cp_file_write_line(FILE* file, const char* line);
bool cp_file_exists(const char* filename);
long cp_file_size(const char* filename);

// Utility functions
void cp_clear_screen(void);
void cp_pause(void);
void cp_set_color(int color);
void cp_reset_color(void);

// Color constants for Windows console
#ifdef WINDOWS
#define CP_COLOR_BLACK   0
#define CP_COLOR_BLUE    1
#define CP_COLOR_GREEN   2
#define CP_COLOR_CYAN    3
#define CP_COLOR_RED     4
#define CP_COLOR_MAGENTA 5
#define CP_COLOR_YELLOW  6
#define CP_COLOR_WHITE   7
#define CP_COLOR_GRAY    8
#define CP_COLOR_LIGHT_BLUE    9
#define CP_COLOR_LIGHT_GREEN   10
#define CP_COLOR_LIGHT_CYAN    11
#define CP_COLOR_LIGHT_RED     12
#define CP_COLOR_LIGHT_MAGENTA 13
#define CP_COLOR_LIGHT_YELLOW  14
#define CP_COLOR_BRIGHT_WHITE  15
#endif

#endif // CP_IO_H
