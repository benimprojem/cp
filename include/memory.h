#ifndef CP_MEMORY_H
#define CP_MEMORY_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// CP Language Memory Management Library
// Handles dynamic memory allocation and deallocation

// Memory allocation functions (corresponds to memnew/memdel)
void* cp_memnew(size_t size);
void* cp_memnew_array(size_t element_size, size_t count);
void cp_memdel(void* ptr);
void cp_memdel_array(void* ptr);

// Memory utility functions
void* cp_memcpy(void* dest, const void* src, size_t size);
void* cp_memset(void* ptr, int value, size_t size);
int cp_memcmp(const void* ptr1, const void* ptr2, size_t size);
void* cp_memrealloc(void* ptr, size_t new_size);

// Memory debugging and tracking
typedef struct MemoryBlock {
    void* ptr;
    size_t size;
    const char* file;
    int line;
    struct MemoryBlock* next;
} MemoryBlock;

// Memory tracking functions (for debugging)
void cp_memory_tracking_enable(void);
void cp_memory_tracking_disable(void);
void cp_memory_print_leaks(void);
size_t cp_memory_get_allocated_bytes(void);
size_t cp_memory_get_allocation_count(void);

// Safe memory functions with bounds checking
void* cp_safe_malloc(size_t size, const char* file, int line);
void* cp_safe_calloc(size_t count, size_t size, const char* file, int line);
void* cp_safe_realloc(void* ptr, size_t size, const char* file, int line);
void cp_safe_free(void* ptr, const char* file, int line);

// Macros for safe memory operations with debug info
#ifdef DEBUG
#define CP_MALLOC(size) cp_safe_malloc(size, __FILE__, __LINE__)
#define CP_CALLOC(count, size) cp_safe_calloc(count, size, __FILE__, __LINE__)
#define CP_REALLOC(ptr, size) cp_safe_realloc(ptr, size, __FILE__, __LINE__)
#define CP_FREE(ptr) cp_safe_free(ptr, __FILE__, __LINE__)
#else
#define CP_MALLOC(size) malloc(size)
#define CP_CALLOC(count, size) calloc(count, size)
#define CP_REALLOC(ptr, size) realloc(ptr, size)
#define CP_FREE(ptr) free(ptr)
#endif

// Memory pool management for better performance
typedef struct MemoryPool {
    void* memory;
    size_t block_size;
    size_t block_count;
    size_t used_blocks;
    bool* used_flags;
} MemoryPool;

MemoryPool* cp_memory_pool_create(size_t block_size, size_t block_count);
void* cp_memory_pool_alloc(MemoryPool* pool);
void cp_memory_pool_free(MemoryPool* pool, void* ptr);
void cp_memory_pool_destroy(MemoryPool* pool);

// Stack-based allocation for temporary objects
typedef struct StackAllocator {
    void* memory;
    size_t size;
    size_t offset;
} StackAllocator;

StackAllocator* cp_stack_allocator_create(size_t size);
void* cp_stack_alloc(StackAllocator* allocator, size_t size);
void cp_stack_reset(StackAllocator* allocator);
void cp_stack_allocator_destroy(StackAllocator* allocator);

// Memory alignment utilities
void* cp_aligned_alloc(size_t alignment, size_t size);
void cp_aligned_free(void* ptr);
bool cp_is_aligned(void* ptr, size_t alignment);

#endif // CP_MEMORY_H
