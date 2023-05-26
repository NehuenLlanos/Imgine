#ifndef GARBAGE_COLLECTOR_HEADER
#define GARBAGE_COLLECTOR_HEADER

#include <stdlib.h>

void * Malloc(size_t size);
void * Realloc(void * ptr, size_t size);
void * Calloc(size_t nitems, size_t size);
void Free(void * ptr);
void FreeAll();

#endif